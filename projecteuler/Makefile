.SILENT:

# Keep make from removing intermediate files
.PRECIOUS: out/%

test:
	./runTests.sh

out/my_libs.o: src/my_libs/*.cpp
	[ -d out/ ] || mkdir out
	g++ -std=c++11 -I src/ -o out/my_libs.o -c $<

out/%: src/%.cpp out/my_libs.o
	[ -d out/ ] || mkdir out
	g++ -std=c++11 -I src/ -o out/$* src/$*.cpp out/my_libs.o

%: out/%
	[ ! -z $(COMPILE_ONLY) ] || out/$*
