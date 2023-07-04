#Makefile

add-nbo: add-nbo.o
	g++ -o add-nbo add-nbo.o
add-nob.o: add-nbo.cpp
	g++ -c add-nbo.cpp
clean:
	rm *.o add-nbo
