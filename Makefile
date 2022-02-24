vpath %.proto proto
vpath %.cc proto
vpath %.cpp test

SRCS:=$(wildcard test/*.cpp)

all: conan proto tests

conan: conaninfo.txt

proto: nngrpc.pb.cc

tests: nngrpc.pb.cc $(SRCS)
	g++ --std=c++17 -I./ @conanbuildinfo.args proto/$< $(SRCS) -o tests

conaninfo.txt: conanfile.txt
	conan install .

nngrpc.pb.cc: nngrpc.proto conaninfo.txt
	protoc proto/nngrpc.proto --cpp_out=./

run: tests
	./tests

clean:
	git clean -df
