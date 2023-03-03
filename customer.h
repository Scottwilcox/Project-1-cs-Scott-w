#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#define MAX_SIZE_ORDER 50
#include "menuItem.h"
using namespace std;

class Customer{
    
    public: 
string 	customerFirst;

string customerLast;

int loyaltyNumber; 

int numberLoyaltyPoints;

int numItemsInOrder;

MenuItem* currentOrder[MAX_SIZE_ORDER];
 
Customer(); 
Customer(int lotaltyNum, string firstName, string LastName, int numLoyaltyPoints); //pass the customer array here did we even make it lmao? 
Customer(const Customer&);

string getCustomerFirst();

void setCustomerFirst(string first);

string getCustomerLast();

void setCustomerLast(string last);


int getLoyaltyNumber();

void setLoyaltyNumber( int LoyalNum);

int getNumberLoyaltyPoints();

void setNumberLoyaltyPoints( int numLoyaltyPoints);

MenuItem* 	getCurrentOrder();
void addItemToOrder(MenuItem* menuTemp);
 
int getNumItemsInOrder();
void setNumItemsInOrder(int num);
 
float calculateCost();

void displayOrder();
 
void displayCustomerInformation();


};
#endif