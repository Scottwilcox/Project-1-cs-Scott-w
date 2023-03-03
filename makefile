meatMob:  menuItem.o customer.o driver2.o
	g++ -o meatMob  menuItem.o customer.o driver2.o

menuItem.o: menuItem.cpp menuItem.h
	g++ -c menuItem.cpp

customer.o: customer.cpp customer.h
	g++ -c customer.cpp

driver2.o: driver2.cpp
	g++ -c driver2.cpp

clean:
	rm *.o meatMob