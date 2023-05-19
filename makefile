movie : main.o movie.o
	g++ main.o movie.o -o movie

main.o : main.cpp
	g++ -c main.cpp

movie.o : movie.cpp movie.hpp
	g++ -c  movie.cpp movie.hpp

clean : 
	rm *.o movie movie.hpp.gch
