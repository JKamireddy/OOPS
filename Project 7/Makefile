assign7: assign7.o Amenity.o Functions.o AmenityHelper.o 
	g++ -o assign7 assign7.o Functions.o Amenity.o AmenityHelper.o 
AmenityHelper.o: AmenityHelper.cc AmenityHelper.h Amenity.h
	g++ -c -std=c++11 AmenityHelper.cc
Functions.o: Functions.cc assign7.h Amenity.h
	g++ -c -std=c++11 Functions.cc
assign7.o: assign7.cc assign7.h Amenity.h
	g++ -c -std=c++11 assign7.cc
Amenity.o: Amenity.cc Amenity.h 
	g++ -c -std=c++11 Amenity.cc
clean :
	rm -f *.o
