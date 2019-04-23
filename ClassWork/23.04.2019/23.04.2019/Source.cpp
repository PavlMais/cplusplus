#include <iostream>
#include <string>
using namespace std;



class Point {
public:
	int x, y;
	void show() {
		cout << "Point x " << x << ", y " << y << "\n\n";
	}
};



class Account {
	float money = 0;
	char currency = 'U';
	bool accountIsOpen = false;
	int sale = 0;


public:
	int getMoney(int count) {
		if (count <= money && accountIsOpen) {
			if (count > 1000) {
				int nSale = count * sale / 100;
				cout << "Sale: " << sale << "%  -" << nSale;
				count -= nSale;
				
			}
			
			money -= count;
			return count;
			
		}
		else {
			cout << "Account is closed or not meney!\n";
			return -1;
		}
	}

	void appendMoney(int count) {
		money += count;
	}

	void openAccount() {

		accountIsOpen = true;
	}
	void setSale(int s) {
		if (s > 100) cout << "Error";
		else sale = s;
	}
	void closeAccount() {

		accountIsOpen = false;
	}
	void showMoney() {
		cout << "Money: " << money << "\n";
	}

};




int main() {
	Point point;
	
	int buf;

	cin >> buf;
	point.x = buf;
	
	cin >> buf;
	point.y = buf;

	point.show();


	Account acc;
	acc.setSale(10);
	acc.openAccount();
	acc.appendMoney(10000);
	acc.showMoney();
	acc.getMoney(50);
	acc.showMoney();
	acc.getMoney(1500);
	acc.closeAccount();

	system("pause");
	return 0;
}
