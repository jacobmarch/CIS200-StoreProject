#include<iostream>
#include<fstream>

using namespace std;

class shopping {
private:
	int pcode;
	float price;
	string pname;

public:
	void menu();
	void administrator();
	void customer();
	void add();
	void edit();
	void rem();
	void list();
	void receipt();

};

void shopping::menu() {
	m:
	int choice;
	string email;
	string password;

	cout << "\t\t\t\t____________________________________\n";
	cout << "\t\t\t\t              Main Menu             \n";
	cout << "\t\t\t\t____________________________________\n";
	cout << "\t\t\t\t                                    \n";
	cout << "\t\t\t\t    1) Administrator                \n";
	cout << "\t\t\t\t    2) Customer                     \n";
	cout << "\t\t\t\t    3) Exit                         \n";
	cout << "\t\t\t\t                                    \n";
	cout << "\t\t\t\t    Enter your choice(1-3): ";
	cin >> choice;

	switch (choice) {
	case 1:
		cout << "\n\t\t\t Login \n";
		cout << "\t\t\t Enter email: ";
		cin >> email;
		cout << "\n\t\t\t Password: ";
		cin >> password;

		if (email == "group5@cis200.com" && password == "groupfive") {
			administrator();
		}
		else {
			cout << "Invalid email/password.\n";
		}
		
		break;

	case 2:
		customer();
		break;

	case 3:
		exit(0);
		break;

	default :
		cout << "Invalid input. Try again (1-3).\n";
	}
	goto m;
}

void shopping::administrator() {
	m:
	int choice;
	cout << "\n\n\n\t\t\t Administrator menu";
	cout << "\n\t\t\t 1) Add product";
	cout << "\n\t\t\t 2) Modify product";
	cout << "\n\t\t\t 3) Delete product";
	cout << "\n\t\t\t 4) Exit to main menu";
	cout << "\n\n\t Enter your choice:";
	cin >> choice;

	switch (choice) {
	case 1:
		add();
		break;
	
	case 2:
		edit();
		break;

	case 3:
		rem();
		break;

	case 4:
		menu();
		break;

	default:
		cout << "Invalid input. Try again (1-4).\n";
	}
	goto m;
}

void shopping::customer() {
	m:
	int choice;
	cout << "\n\t\t\t      Customer      \n";
	cout << "\t\t\t____________________\n\n";
	cout << "\t\t\t1) Buy product \n";
	cout << "\t\t\t2) Go back \n\n";
	cout << "\t\t\tEnter your choice: ";
	cin >> choice;

	switch (choice) {
	case 1: 
		receipt();
		break;

	case 2:
		menu();
		break;

	default:
		cout << "Invalid input.";
	}
	goto m;
}

void shopping::add() {
m:
	fstream data;
	int c;
	int token = 0;
	float p;
	string n;

	cout << "\n\n\t\t\t Add new product";
	cout << "\n\n\t Product code: ";
	cin >> pcode;
	cout << "\n\n\t Product name: ";
	cin >> pname;
	cout << "\n\n\t Product price: ";
	cin >> price;

	data.open("database.txt", ios::in);

	if (!data) {
		data.open("database.txt", ios::app | ios::out);
		data << " " << pcode << " " << pname << " " << price << "\n";
		data.close();
	}
	else {
		data >> c >> n >> p;

		while (!data.eof()) {
			if (c == pcode) {
				token++;
			}
			data >> c >> n >> p;
		}
		data.close();
	

		if (token == 1) {
			goto m;
		}
		else {
			data.open("database.txt", ios::app | ios::out);
			data << " " << pcode << " " << pname << " " << price << "\n";
			data.close();
		}
	}
	cout << "\n\n\t\t Record inserted.";
}

void shopping::edit() {
	fstream data, data1;
	int pkey;
	int token = 0;
	int c;
	float p;
	string n;

	cout << "\n\t\t\t Modify the record ";
	cout << "\n\t\t\t Product code: ";
	cin >> pkey;

	data.open("database.txt", ios::in);
	if (!data) {
		cout << "\n\nFile doesn't exist. ";
	}
	else {
		data1.open("database1.txt", ios::app | ios::out);
		data >> pcode >> pname >> price;

		while (!data.eof()) {
			if (pkey == pcode) {
				cout << "\n\t\t New product code: ";
				cin >> c;
				cout << "\n\t\t Product name: ";
				cin >> n;
				cout << "\n\t\t Price: ";
				cin >> p;
				data1 << " " << c << " " << n << " " << p << endl;
				cout << "\n\t\t Record edited.";
				token++;
			}
			else {
				data1 << " " << pcode << " " << pname << " " << price << endl;
			}
			data >> pcode >> pname >> price;
		}
		data.close();
		data1.close();

		remove("database.txt");
		rename("database1.txt", "database.txt");

		if (token == 0) {
			cout << "\n\n Record not found.";
		}
	}
}

void shopping::rem() {
	fstream data, data1;
	int pkey;
	int token = 0;
	
	cout << "\n\n\t Delete product ";
	cout << "\n\t Product code: ";
	cin >> pkey;
	data.open("database.txt", ios::in);
	
	if (!data) {
		cout << "\n\nFile doesn't exist.";
	}
	else {
		data1.open("database1.txt", ios::app | ios::out);
		data >> pcode >> pname >> price;

		while (!data.eof()) {
			if (pcode == pkey) {
				cout << "\n\n Product deleted successfully.";
				token++;
			}
			else {
				data1 << " " << pcode << " " << pname << " " << price << endl;
			}
			data >> pcode >> pname >> price;
		}
		data.close();
		data1.close();

		remove("database.txt");
		rename("database1.txt", "database.txt");

		if (token == 0) {
			cout << "\n\nRecord not found.";
		}
	}
}

void shopping::list() {
	fstream data;
	data.open("database.txt", ios::in);
	cout << "\n\n_________________________________________\n";
	cout << "Pro No\t\tName\t\tPrice\n";
	cout << "\n\n_________________________________________\n";
	data >> pcode >> pname >> price;

	while (!data.eof()) {
		cout << pcode << "\t\t" << pname << "\t\t" << price << endl;
		data >> pcode >> pname >> price;
	}
	data.close();
}

void shopping::receipt() {
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c = 0;
	float amount = 0;
	float total = 0;

	cout << "\n\n\t\t\t\t RECEIPT ";
	data.open("database.txt", ios::in);
	if (!data) {
		cout << "\n\n Empty database.";
	}
	else {
		data.close();

		list();
		cout << "\n_______________________________________\n";
		cout << "\n                                       \n";
		cout << "\n       Please place the order!         \n";
		cout << "\n                                       \n";
		cout << "\n_______________________________________\n";

		do {
			m:
			cout << "\n\nEnter product code: ";
			cin >> arrc[c];
			cout << "\n\nEnter product quantity: ";
			cin >> arrq[c];
			
			for (int i = 0; i << c; ++i) {
				if (arrc[c] == arrc[i]) {
					cout << "\n\n Duplicate product code. Please try again.";
					goto m;
				}
			}
			c++;
			cout << "\n\n Do you want to buy another product? Enter (y/n): ";
			cin >> choice;
		}
		while (choice == 'y');
		
		cout << "\n\n\t\t\t_________________RECEIPT__________________\n";
		cout << "\nProduct No\t Product Name\t Quantity\t Price\t Amount\n";

		for (int i = 0; i < c; ++i) {
			data.open("database.txt", ios::in);
			data >> pcode >> pname >> price;

			while (!data.eof()) {
				if (pcode == arrc[i]) {
					amount = price * arrq[i];
					cout << endl << pcode <<"\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << amount;
				}
				data >> pcode >> pname >> price;
			}
		}
		data.close();
	}
	cout << "\n\n\n________________________________________________";
	cout << "\n Total amount: " << amount;
}

int main() {
	shopping s;
	s.menu();
}