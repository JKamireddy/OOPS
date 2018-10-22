#/*******************************************
#COURSE: CSCI689
#NAME: SAHITHI KAMIREDDY
#ZID: z1831177
#INSTRUCTOR: KIRK DUFFIN
#TA : NITHIN DEVANG
#*******************************************/

#/*********** ASSIGNMENT 2 *************/

CC=g++ 
CCFLAGS= -Wall 
prog2:assign2.o Functions.o
	$(CC) -o assign2 assign2.o Functions.o
assign2.o:assign2.cc Functions.h
	$(CC) $(CCFLAGS) -c assign2.cc
Functions.o:Functions.cc Functions.h
	$(CC) $(CCFLAGS) -c Functions.cc
clean: 
	-rm *.o prog2

