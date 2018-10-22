assign3: assign3.o Athelete.o Country.o Sport.o Event.o
	g++ -o assign3 assign3.o
assign3.o: assign3.cc Athelete.h Country.h Sport.h Event.h
	g++ -c -std=c++11 -Wall assign3.cc
clean:
	rm -f *.o assign3
