.SILENT:

%: src/%.cpp
	[ -d out/ ] || mkdir out
	g++ -std=c++11 -o out/$* src/$*.cpp
	out/$*