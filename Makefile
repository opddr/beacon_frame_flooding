all: test1

test1 : main.cpp
	g++ -g -o test1 main.cpp -ltins -std=c++11

clean: 
	rm -rf *.o
	rm -rf test1

