main : compile
	g++ -o main *.o -O3
compile :
	g++ -c v1.5.cpp cppFiles/*.cpp -O3
clean :
	del *.exe *.o

# mingw32-make