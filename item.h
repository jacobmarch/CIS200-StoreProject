#include "Header.h"

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
  
  protected:
    int id;
    int stock;
    double price;
}
