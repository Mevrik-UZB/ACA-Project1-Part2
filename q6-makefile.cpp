// Name: Shukhratbek
// Subject: ADVANCED COMPUTER ARCHITECTURE (2024 Fall)
// Assignment: Project1-Part2
// Data: Oct 16 2024

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

SRCS = q6-main.cpp q6-pipeline.cpp q6-instruction.cpp q6-branchpredictor.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = processor_simulator

all: $(EXEC)

$(EXEC): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $<

clean:
    rm -f $(OBJS) $(EXEC)