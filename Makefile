vpath %.proto proto
vpath %.cc proto
vpath %.cpp test

SRCS:=$(wildcard test/*.cpp)

all: conan proto tests

conan: conaninfo.txt

proto: proto/nngrpc.pb.cc

tests: proto/nngrpc.pb.cc $(SRCS)
	g++ --std=c++17 -I./test -I./proto -I./ @conanbuildinfo.args $< $(SRCS) -o tests

conaninfo.txt: conanfile.txt
	conan install .

proto/nngrpc.pb.cc: proto/nngrpc.proto conaninfo.txt
	protoc $< --cpp_out=./

run: tests
	./tests

clean:
	git clean -df
