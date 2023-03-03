
#define MAX_NUMBER_INGREDIENTS = 30
#ifndef FOOD_H
#define FOOD_H
#include "menuItem.h"
#include <iostream>
using namespace std;

class Food{
string 	ingredients[MAX_NUMBER_INGREDIENTS];
 
int numberIngredients;

public: 
    
        Food();               //default constructor
        Food(string* ,int);   //paramiterized constructor, to pass in variables 
        Food(const Food&);     //copy constructor, cant change the stuff being passed in. passing by reference. 
    
    
    string* getIngredients();
    void addIngredient(string); 

    int getNumberIngredients();


};
#endif