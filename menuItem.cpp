#include "menuItem.h"
#include <iostream> 
#include <fstream>
using namespace std; 


MenuItem::MenuItem(){}
MenuItem::MenuItem(float cost, string itemName, int pointWorth){}
MenuItem::MenuItem(const MenuItem &){}

float MenuItem::getCost(){
    return cost; 
}

void MenuItem::setcost(float price){
this->cost=price;
}

string MenuItem::getItemName(){
    return itemName; 
}
void MenuItem::setItemName(string product){
this->itemName=product;
} 

int MenuItem::getPointWorth(){
    return pointWorth;
}
void MenuItem::setPointWoth(int points){
this->pointWorth=points;
}