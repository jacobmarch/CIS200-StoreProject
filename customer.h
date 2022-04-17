#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Header.h"

using namespace std;

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

#endif // !CUSTOMER_H
