main : main.o
	g++ -o main v1.1.cpp *.o -O3
main.o :
	g++ -c cppFiles/*.cpp
clean :
	del *.exe *.o

# mingw32-make