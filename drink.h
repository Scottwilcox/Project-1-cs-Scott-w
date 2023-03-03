
#ifndef DRINK_H
#define DRINK_H

#include <iostream>

using namespace std;

class Drink{
char size; 
string drinkChoice; 

bool isAM; //(to tell if its am or pm)

public: 
    
        Drink();               //default constructor
        Drink(char, char);   //paramiterized constructor, to pass in variables 
        Drink(const Drink&);     //copy constructor, cant change the stuff being passed in. passing by reference. 
    
    
    char getSize();
    void setSize(char);
    
    string getDrink();
    void setDrink(string);

};
#endif