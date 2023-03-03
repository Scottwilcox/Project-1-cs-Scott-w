
#ifndef MENUITEM_H
#define MENUITEM_H
#define MAX_NUMBER_INGREDIENTS = 50
using namespace std; 
#include <string>




class MenuItem{

float cost;
string itemName;
int pointWorth;

public:

MenuItem(); 
MenuItem(float cost, string itemName, int pointWorth); 
MenuItem(const MenuItem&); 

float getCost(); 
void setcost(float cost);

string getItemName(); 
void setItemName(string itemName); 

int getPointWorth();
void setPointWoth(int pointWorth);


};
#endif