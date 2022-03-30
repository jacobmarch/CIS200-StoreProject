#include <vector>
#include <string>
#include <iostream>

using namespace::std;

class customer {
    public:
        void setCustomerID(int id){
            customerID = id;
        }
        int getCustomerID(){
            return customerID;
        }
        void setCustomerName(string name){
            customerName = name;
        }
        string getCustomerName(){
            return customerName;
        }
        int getNumPurchases(){
            return numberOfPurchases;
        }
    
    protected:
        int customerID;
        int numberOfPurchases;
        string customerName;
};