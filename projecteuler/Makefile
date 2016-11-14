include gccCompilationOptions.mk

CXXFLAGS += -I src/

# Don't print executed commands
.SILENT:

# Keep make from removing intermediate files
.PRECIOUS: out/%

test:
	./runTests.sh

out/my_libs.o: src/my_libs/*.cpp
	[ -d out/ ] || mkdir out
	g++ $(CXXFLAGS) -o out/my_libs.o -c $<

out/%: src/%.cpp out/my_libs.o
	[ -d out/ ] || mkdir out
	g++ $(CXXFLAGS) -o out/$* src/$*.cpp out/my_libs.o

%: out/%
	[ ! -z $(COMPILE_ONLY) ] || out/$*
