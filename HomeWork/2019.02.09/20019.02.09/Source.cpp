#include <iostream>
#include <ctime>
using namespace std;


// �������� ���������, ����������� ���� "21".
// �������� �� ������ ��������� ����� ������ � ���������� ���������� � ���� �������

int getCard() {
	return rand() % 20;	
}


int main() {
	srand(unsigned(time(0)));
	int cardUser = 0;
	int cardAI = 0;
	int select;

	cardAI += getCard();
	do {
		cardUser += getCard();
		cout << " You card: " << cardUser;

		cout << " Get card? 1 yes 2 no : ";
		cin >> select;
	} while (select == 1);

	cout << "\n   ==== All card ===== \n\n\tYou card: " << cardUser << "\n\tAI card: " << cardAI;



	if (cardUser == 21) cout << "\n\tYou WIN!";
	else if (cardAI == 21) cout << "\n\tAI WIN!";
	else if (cardUser > cardAI && cardUser < 21) cout << "\n\tYou WIN!";
	else if (cardAI > cardUser && cardAI << 21) cout << "\n\tAI WIN!";
	else "\n\tDraw";


	cout << "\n\n\n";
	

	system("pause");
	return 0;
}