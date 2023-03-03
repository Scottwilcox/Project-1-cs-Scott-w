#include "customer.h"
using namespace std; 
#include <iostream> 



Customer::Customer(){} 
Customer::Customer(int lotaltyNum, string firstName, string LastName, int numLoyaltyPoints){}
Customer::Customer(const Customer&){}

string Customer::getCustomerFirst(){
    return customerFirst; 
}
void Customer::setCustomerFirst(string first){
this->customerFirst=first;
}
string Customer::getCustomerLast(){
    return customerLast; 
}
void Customer::setCustomerLast(string last){
this->customerLast=last;
}


int Customer::getLoyaltyNumber(){
return loyaltyNumber;
}

void Customer::setLoyaltyNumber(int LoyalNum){
this->loyaltyNumber=LoyalNum;

}

 int Customer::getNumberLoyaltyPoints(){
    return numberLoyaltyPoints; 
}
void Customer::setNumberLoyaltyPoints(int numLoyaltyPoints){
    this->numberLoyaltyPoints=numLoyaltyPoints;
}	
MenuItem* 	Customer::getCurrentOrder(){
    return currentOrder[0]; 
}
void Customer::addItemToOrder(MenuItem* menuTemp){
numItemsInOrder++;
currentOrder[numItemsInOrder] = menuTemp; 
}
 
int Customer::getNumItemsInOrder(){
return  numItemsInOrder;
}
void Customer::setNumItemsInOrder(int num){
numItemsInOrder = num; 
}
 
float Customer::calculateCost(){ //sums each item's cost from the current 
//order and applies a 8.27% tax to it, which is returned as the customer's total.
float total =0; 
for(int i = 0; 1 < numItemsInOrder; i++){
total += currentOrder[i]->getCost();

}
float tax = total * .0827;
total = total + tax;  
    return total; 
}

void Customer::displayOrder(){
    int total; 
for(int i = 0; 1 < numItemsInOrder; i++){
cout << currentOrder[i]->getItemName() << endl; 
}
cout << calculateCost() << endl; 
}
 
void Customer::displayCustomerInformation(){
  cout <<"\n\t                        ------ Welcome back!------                        \n\n";
  cout << "********************************************************************************\n"
       << "*** Your points: " << getNumberLoyaltyPoints() << "                                                         ***\n"
       << "********************************************************************************\n"; 

}


