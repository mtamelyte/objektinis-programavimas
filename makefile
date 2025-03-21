main: funkcijos.o
	g++ -o main main.cpp funkcijos.o

funkcijos: 
	g++ funkcijos.cpp

run: main
	./main.exe

clean:
	del *.o main.exe