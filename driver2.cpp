#include <iostream> 
#include "customer.h"
#include "menu.h"
#include <fstream>
#include <string>
using namespace std; 
#define 	MAX_NUM_CUSTOMERS   1000
#define 	MAX_MENU_ITEMS   10
//declarations 


//Customer* customerArray[]; 
Customer* customerArray[MAX_NUM_CUSTOMERS]; 
MenuItem* itemArray[MAX_MENU_ITEMS];

int getLoyaltyDatabase(*Customer name);  //and array of pointers. // call differently? 
int check();
void createDefaultCustomer();
void createCustomer();
void displayMemberJoin();
 
 void getUserCharChoice(char choice);
 int printData();
 void getUserIntChoice(int choice);
 void displayMenuItems();
 void placeOrder();
 void createMenu();
 

int currentUser = -1; 
int numItems = 3;
int countUser; 


void createMenu(){
   // cout << "1. tea 3.00 7" << endl; 
    //cout << "2. coffee 5.00 5" << endl; 
    //cout << "3. ramen 8.00 9" << endl;
   MenuItem tempItem = MenuItem (3.00, "tea", 7);
    itemArray[0] = &tempItem;

    tempItem = MenuItem(5.00, "coffee", 5);
    itemArray[1] =  &tempItem;

    tempItem = MenuItem(8.00, "ramen", 9);
    itemArray[2] = &tempItem;
}

int main(){ 
char choice; 
createMenu();
countUser = getLoyaltyDatabase(customerArray);
  cout <<"\n\t            ------ WELCOME TO MEATMOD LOYALTY DATABASE ------           \n\n";


  cout << "********************************************************************************\n"
       << "********************************************************************************\n"
       << "***                                                                          ***\n"
       << "***                       Are you already a member?                          ***\n"
       << "***                                 y/n                                      ***\n"
       << "***                                                                          ***\n"
       << "********************************************************************************\n"
       << "********************************************************************************\n";

    cin >> choice; 
    getUserCharChoice(choice);

   // displayMemberJoin(); //calling

    return 0; 
    }


    int getLoyaltyDatabase(Customer* customerArray){

    int count = 0; 
    string temp;


    ifstream fin("loyalty.txt");
    if(fin.is_open()){

        while(!fin.eof())
        {
            string firstName; 
            string lastName; 
            int loyatlyNum, loyatyPoints; 
    string temp; 
    fin >> temp; 
    loyatlyNum = stoi(temp); 
    fin >> firstName; 
    fin >> lastName; 
    fin >> temp; 
    loyatyPoints = stoi(temp); 

    cout << firstName << endl; 
    cout << loyatlyNum << endl; 
        Customer newCustomer = Customer(loyatlyNum, firstName, lastName, loyatyPoints);
        customerArray[count] = newCustomer; 

    
        count++;
    
        }
             fin.close(); 
        }
    return count; 
                                                }


    /*void displayMemberJoin(){
    int selection;
 
  cout <<"\n\t                  ------       Main Menu      ------                       \n\n";
  cout << "********************************************************************************\n"
       << "********************************************************************************\n"
       << "***  New Order - 1                                                           ***\n"
       << "***  See Points - 2                                                          ***\n"
       << "***  See Menu - 3                                                            ***\n"
       << "***  Exit - 4                                                                ***\n"
       << "********************************************************************************\n"
       << "********************************************************************************\n"; 
                   cin >> selection; 
 getUserIntChoice(selection);
}*/

int check(){
    string first, last; 
    cout << "First and Last Name: ";
    cin >> first;
    cin >> last; 
    //int count = printData();  

   // int count = getLoyaltyDatabase(customerArray); 
 
  for(int i=0; i < countUser; i++){
    cout << customerArray[i]->getCustomerFirst() << endl; 
     if(customerArray[i]->getCustomerFirst()== first && customerArray[i]->getCustomerLast()== last){
            currentUser = i;
            cout << currentUser << endl; 
        return i; 
                                                                                                 }
    } 
    return -1; 
}
    //bool match = false;
 //string temp = "";
     //   while(getline(file, temp)){
        
          //  if(temp == first, " ", last){

        //cout<<"Login sucsessful\n";
           //match = true;
           //     break;
      //                                   }
        
       // if(match == false)
      //  {
        //    cout<<"Name not found\n";
      //  }
  //  }



void getUserCharChoice(char choice){
int selection;
    if(choice == 'y'){ 
        cout << currentUser << endl;

    if(currentUser == -1){
    currentUser =  check();
                            }
    cout <<"\n\t                        ------ Welcome back!------                        \n\n";
    cout << "********************************************************************************\n"
       << "********************************************************************************\n"
       << "***  New Order - 1                                                           ***\n"
       << "***  See Points - 2                                                          ***\n"
       << "***  See Menu - 3                                                            ***\n"
       << "***  Exit - 4                                                                ***\n"
       << "********************************************************************************\n"
       << "********************************************************************************\n"; 
                   cin >> selection; 
                  
                   
if(selection == 1){ 
    placeOrder();
}
else if(selection == 2){
cout << customerArray[currentUser]->getNumberLoyaltyPoints(); 
getUserCharChoice('y'); 
}
else if(selection == 3){
displayMenuItems(); 
getUserCharChoice('y'); 

}
else if(selection ==4){
    exit(0);
}

    }
    else if(choice == 'n'){
  cout <<"\n\t                      ------ Nice to meet you ------                       \n\n";
  cout << "********************************************************************************\n"
       << "********************************************************************************\n"
       << "***                                                                          ***\n"
       << "***  Continue as a guest - Enter 5                                           ***\n"
       << "***  Create account - Enter 6                                                ***\n"
       << "***  Exit Program - Enter 7                                                  ***\n"
       << "********************************************************************************\n"
       << "********************************************************************************\n";
            cin >> selection; 

           if(selection == 5){
            createDefaultCustomer();
            getUserCharChoice('y');
        
           }
           else if(selection == 6){
            createCustomer();
            getUserCharChoice('y');
           }

            else if(selection ==7){
                exit(0);
            }

    }
}


void getUserIntChoice(int selection){

    while(true){

    if(selection == 1){
      placeOrder();
    }

    else if(selection == 2){
   customerArray[currentUser]->displayCustomerInformation();
    }

    else if(selection == 3){
    displayMenuItems(); 
    }
    else if(selection == 5){
    createDefaultCustomer();
    }
    else if(selection == 6){
    createCustomer();
    }
   else if(selection == 4){
        break;
    }
                  }
}


void overwriteLoyaltyDatabase(char customerArray[], int countCustomers){
//unclear where update is supposed to happen , ask sara. 

}

void createCustomer(){
    ofstream fin;
    string first, last;
    

    cout << "First and Last Name: ";
    cin >> first; 
    cin >> last; 
                             // input stream || extracting
    fin.open("loyalty.txt");
    cout << first << endl; 
    cout << last << endl; 
    string memberId = "";
    for(int r=0;r<6;r++){
        memberId += std::to_string(rand()%7); 
    }
    fin << endl << memberId << " " ;
    fin << first << " " << last;
    countUser = countUser+1;

    for(int i = 0; i < countUser; i++){
        if(customerArray[i]->getCustomerFirst()== first && customerArray[i]->getCustomerLast()== last){
            currentUser = i; 
            fin.close(); 
            return;
        }
    }
    fin << " " << "0";
    cout << " Welcome!";
    
    Customer newCustomer = Customer(stoi(memberId), first, last, 0);
        customerArray[countUser] = &newCustomer; 
        currentUser = countUser; 
    fin.close();
}



void createDefaultCustomer(){
    string first, last, memberId;
    ofstream fin;
    first = "first"; 
    last = "last";

    fin.open("loyalty.txt", std::ios_base::app);
    for(int r=0;r<6;r++){
        memberId += std::to_string(rand()%10); 
    }
    fin << endl << memberId << " " ;
    fin << first << " " << last;
    fin << " " << "0";
    cout << " Welcome!";
    
    Customer newCustomer = Customer(stoi(memberId), first, last, 0);
     countUser = countUser+1; 
        customerArray[countUser] = &newCustomer; 
        currentUser = countUser; 
    fin.close();
}


int printData(){
    ifstream myfile;

    string STRING;
                                    // input stream || extracting
    myfile.open("loyalty.txt");
    int count = 0;
    while(!myfile.eof()){
        if(count == 4){
        cout << endl;
        }
       // myfile >> STRING;
        //cout << STRING << " " ;
       // count ++;
}
    myfile.close();
return count; 

}

void placeOrder(){
    cout << "place order" << endl; 
    displayMenuItems();
    int selection; 
    while(selection != numItems){

    cin >> selection; 
    customerArray[currentUser]->addItemToOrder(itemArray[selection-1]);

    displayMenuItems();
    }
}
void displayMenuItems(){
cout << "Select Item:  " << endl; 
for(int i = 0; i < numItems; i++ ){
   cout << itemArray[i]->getItemName() << endl; 
    cout << (i + 1) << " : " << itemArray[i]->getItemName() << " "<< itemArray[i]->getCost() <<" "<< itemArray[i]->getPointWorth()<< endl;
}
    cout << (numItems+1) << " : " << "exit" << endl; 
    
    }


