assign5: assign5.o string.o
	g++ -o  assign5 assign5.o string.o
assign5.o: assign5.cc string.h
	g++ -c -std=c++11 assign5.cc
string.o:string.cc string.h
	g++ -c  -std=c++11 string.cc
clean :
	rm -f *.o assign5
