OBJS = complex.o complexMatrix.o main.o matrix.o realMatrix.o
CC = g++ -std=c++11
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

complex : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o complex

complex.o : complex.h complex.cpp
	$(CC) $(CFLAGS) complex.cpp

complexMatrix.o : complexMatrix.h complex.h matrix.h complexMatrix.cpp
	$(CC) $(CFLAGS) complexMatrix.cpp

matrix.o : complex.h matrix.h matrix.cpp
	$(CC) $(CFLAGS) matrix.cpp

realMatrix.o : matrix.h realMatrix.h complex.h realMatrix.cpp
	$(CC) $(CFLAGS) realMatrix.cpp

main.o : complex.h complexMatrix.h realMatrix.h matrix.h main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm *.o
