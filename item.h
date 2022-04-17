#ifndef ITEM_H
#define ITEM_H
#include "Header.h"
#include<string>

using namespace std;

class item {
   public: 
      int getID(){
        return id;
      }
      int setID(int idNum){
        id = idNum;
      }
      double getPrice(){
        return price; 
      }
      void setPrice(double p){
        price = p; 
      }
      
      int getStock(){
         return stock;
      }
   
      void setStock(int s){
         stock = s;
      }
   
      string getName(){
         return name;
      }
   
      void setName(string n){
         name = n;
      }
  
  protected:
    int id;
    int stock;
    double price;
    string name;
}

#endif // !ITEM_H
