CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Werror=vla -Wpedantic -MMD -g
EXEC = a4q1
OBJECTS = cell.o tblock.o zblock.o oblock.o sblock.o lblock.o jblock.o iblock.o block.o window.o score.o newblock.o observer.o board.o subject.o textdisplay.o graphicsdisplay.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
