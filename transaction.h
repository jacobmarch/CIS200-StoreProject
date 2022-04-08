#include "Header.h"

class transaction {
    public:
        void updateAmount(double price){
            amount = amount + price;
            numItems += 1;
        }
        void setReturn(){
            isReturn = true;
        }
        void setDate(int d, int m, int y){
            day = d;
            month = m;
            year = y;
        }
        void returnInfo(){
            cout << "Date of Transaction: " << month << "/" << day << "/" << year << endl;
            if (isReturn == true){
                cout << "Type of Transaction: Return" << endl; 
            }
            else {
                cout << "Type of Transaction: Purchase" << endl;
            }
            cout << "Number of Items: " << numItems << endl;
            cout << "Amount: $" << amount << endl;
        }
    private:
        double amount;
        int day;
        int month;
        int year;
        int numItems;
        bool isReturn = false;

}