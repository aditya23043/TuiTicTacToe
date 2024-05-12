CC	=	g++
all:	tictactoe
tictactoe:	tictactoe.o
	${CC} -o tictactoe tictactoe.o
tictactoe.o:	tictactoe.cpp
	${CC} -c tictactoe.cpp
clean:
	rm tictactoe.o tictactoe
backup:
	cp tictactoe.cpp backup
run:
	./tictactoe
