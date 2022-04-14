#include "Header.h"

using namespace std;

int input;
//This variable can be used to track the user's input to access the different pieces of our program


int main(){
  while (input != -1){
    cout << "What would you like to access?" << endl;
    cout << "1) Make a Purchase" << endl;
    cout << "2) Make a Return" << endl;
    cout << "3) Edit an Item" << endl;
    cout << "4) Edit Inventory" << endl;
    cout << endl;
    cin >> input;
    switch (input) {
      case 1:
        cout << "Purchase Selected" << endl;
        break;
      case 2:
        cout << "Return Selected" << endl;
        break;
      case 3:
        cout << "Edit Item" << endl;
        break;
      case 4:
        cout << "Edit Inventory" << endl;
        cout << "1) Add Inventory" << endl;
        cout << "2) Remove Inventory" << endl;
        cin >> input;
        switch (input) {
          case 1:
            break;
          case 2:
            break;
        }
        break;
      default:
        cout << "Invalid Choice" << endl;
        break;

    }
    

  }
  
  system("Pause");
  return 0;
}
