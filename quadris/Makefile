CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Werror=vla -Wpedantic -MMD -g
EXEC = quadris
OBJECTS =  cell.o tblock.o zblock.o oblock.o window.o interp.o sblock.o lblock.o jblock.o iblock.o block.o score.o newblock.o observer.o board.o subject.o textdisplay.o graphicsdisplay.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
