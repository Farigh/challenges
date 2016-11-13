.SILENT:

out/my_libs.o: src/my_libs/*.cpp
	[ -d out/ ] || mkdir out
	g++ -std=c++11 -I src/ -o out/my_libs.o -c $<

%: src/%.cpp out/my_libs.o
	[ -d out/ ] || mkdir out
	g++ -std=c++11 -I src/ -o out/$* src/$*.cpp out/my_libs.o
	out/$*
