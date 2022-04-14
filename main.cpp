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
      case 2:
      case 3:
      case 4:

    }
    

  }
  
  system("Pause");
  return 0;
}
