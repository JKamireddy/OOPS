assign5: assign5.o String.o
	g++ -o  assign5 assign5.o String.o
assign5.o: assign5.cc String.h
	g++ -c -std=c++11 assign5.cc
String.o:String.cc String.h
	g++ -c  -std=c++11 String.cc
clean :
	rm -f *.o assign5
