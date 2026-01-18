CXX=g++
CXXFLAGS=-std=c++11 -Wall
LIBS=-lsqlite3

TARGET=studentdb
SRCS=$(wildcard src/*.cpp)

$(TARGET): $(SRCS)
$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

clean:
rm -f $(TARGET)
