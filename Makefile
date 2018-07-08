CXX = g++
CXXFLAGS = -std=c++0x

OBJS = Ant.o menu.o main.o

SRCS = Ant.cpp menu.cpp main.cpp

HEADERS = Ant.hpp menu.hpp

assignment1: ${OBJS} ${HEADERS}
	${CXX} ${SRCS} -o langtonSimulation
	
${OBJS}: ${SRCS}
	${CXX} ${CSSFLAGS} -c $(@:.o=.cpp)
	
clean:
	rm ${OBJS}