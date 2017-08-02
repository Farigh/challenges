include gccCompilationOptions.mk

CXXFLAGS += -I src/

# Don't print executed commands
.SILENT:

# Keep make from removing intermediate files
.PRECIOUS: out/%

project_SRC := $(wildcard src/*.cpp)
project_SRC_noEXT=$(project_SRC:.cpp=)
project_BIN=$(notdir $(project_SRC_noEXT))

all: $(addprefix out/,$(project_BIN))

test:
	./runTests.sh

out/my_libs.o: src/my_libs/*.cpp
	[ -d out/ ] || mkdir out
	g++ $(CXXFLAGS) -o out/my_libs.o -c $^

out/%: src/%.cpp out/my_libs.o
	[ -d out/ ] || mkdir out
	echo [CXX] src/$*.cpp
	g++ $(CXXFLAGS) -o out/$* src/$*.cpp out/my_libs.o

%: out/%
	out/$*
