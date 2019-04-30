#include <iostream>
#include <string>
#include <fstream>
#include <string>
using namespace std;

const string PATHDB = "card.txt";

class  Card {
private:
	int money;
	int cashback;
	bool isActive;

public:
	Card(int m, int c, bool i) {
		money = m;
		cashback = c;
		isActive = i;
	}
	void getMoney(int value) {
		if (money < value || ! isActive) {
			cout << "Not enough money or card no active!\n\n";
		}
		else {
			cout << "You got " << value << "money\n";
			if (value >= 1000) {
				cout << " + cashback 10%\n";
				value -= value * cashback / 100;
				
			}
			money -= value;
			
		}
	}
	void append(int value) {
		cout << "You append " << value << "money!\n";
		money += value;
	}

	string getData() {
		return to_string(money) + "\n" + to_string(cashback) + "\n" + to_string(isActive);
	}
	string getInfo() {
		return "Money: "+ to_string(money) + "\nCashBack: " + to_string(cashback) + "\nIs Active: " + to_string(isActive) + "\n";

	}

};

Card loadCard() {



	std::fstream file(PATHDB);


	int money, cashback;
	bool isActive;
	string buffer;

	getline(file, buffer);
	money = stoi(buffer);
	getline(file, buffer);
	cashback = stoi(buffer);
	getline(file, buffer);
	isActive = stoi(buffer);


	file.close();




	Card card(money, cashback, isActive);

	return card;
}




void saveCard(Card card) {
	std::ofstream file(PATHDB);

	file << card.getData();
	file.close();
}

int main() {

	
	Card card = loadCard();
	int sel, value;
	while (true) {
		cout << card.getInfo();
		cout << "\n1 get money  2 add money : ";
		cin >> sel;
		cout << "Enter value: ";
		cin >> value;
		switch (sel)
		{

		case 1: card.getMoney(value); break;
		case 2: card.append(value); break;

			
		}
		saveCard(card);
	}




	system("pause");
	return 0;
}
