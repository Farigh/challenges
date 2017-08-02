#! /bin/bash

resolved_script_path=`readlink -f $0`
current_script_dir=`dirname ${resolved_script_path}`
current_full_path=`readlink -e ${current_script_dir}`

RESET_COLOR=`echo -e "\e[0m"`
RED_COLOR=`echo -e "\e[31m"`
GREEN_COLOR=`echo -e "\e[32m"`

##############################
###    EXPECTED RESULTS    ###
##############################

declare -A test_results

function addResult()
{
    local exercice_nb=$1
    local expected_output=$2

    local array_key="problem${exercice_nb}"
    if [ "${test_results[$array_key]}" != "" ]; then
        echo "${RED_COLOR}Error${RESET_COLOR}: Problem number ${exercice_nb} registered twice"
        exit 1
    fi

    test_results[$array_key]="${expected_output}"
}

addResult 1  "sum = 233168"
addResult 2  "evenSum = 4613732"
addResult 3  "6857"
addResult 4  "906609"
addResult 5  "232792560"
addResult 6  "25164150"
addResult 7  "104743"
addResult 8  "23514624000"
addResult 9  "31875000"
addResult 10 "142913828922"
addResult 11 "70600674"
addResult 12 "76576500"
addResult 13 "5537376230"
addResult 14 "837799"
addResult 15 "137846528820"
addResult 16 "1366"

##############################
###          MAIN          ###
##############################

echo "Running test suite ..."

failedCompile=0
failedTests=0
successTests=0

# Use -1v to sort numerically
for test in $(IFS=" " ls -1v ${current_full_path}/src/*.cpp); do
    # Extract test name part
    test=$(echo $(basename $test) | sed "s#\(problem[0-9]*\)\.cpp#\1#")

    printf "   %-12s => " "$test"

    if [ ! -f "${current_full_path}/out/${test}" ]; then
        ((failedCompile++))
        echo "[${RED_COLOR}FAIL COMPILE${RESET_COLOR}]"
        continue
    fi

    result=$(${current_full_path}/out/${test})

    if [ "${result}" != "${test_results[$test]}" ]; then
        echo "[${RED_COLOR}FAILED${RESET_COLOR}]"
        echo "        expected : ${test_results[$test]}"
        echo "           found : ${result}"
        ((failedTests++))
    else
        echo "[${GREEN_COLOR}SUCCESS${RESET_COLOR}]"
        ((successTests++))
    fi
done

echo "Done"

# Print summary

success_color="${GREEN_COLOR}"
failed_color="${RED_COLOR}"
failed_compile_color="${RED_COLOR}"

if [ $successTests -eq 0 ]; then
    success_color="${RED_COLOR}"
fi

if [ $failedTests -eq 0 ]; then
    failed_color="${GREEN_COLOR}"
fi

if [ $failedCompile -eq 0 ]; then
    failed_compile_color="${GREEN_COLOR}"
fi

echo "Summary :"
echo "         Success : ${success_color}${successTests}${RESET_COLOR}"
echo "          Failed : ${failed_color}${failedTests}${RESET_COLOR}"
echo "   Compile error : ${failed_compile_color}${failedCompile}${RESET_COLOR}"

exit $(($failedTests + $failedCompile))
