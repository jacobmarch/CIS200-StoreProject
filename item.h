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
  
  protected:
    int id;
    double price;
}
