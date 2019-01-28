#include <iostream>
#include <string>
using namespace std;

float sum(float a, float b) {
	return a + b;
}
float sub(float a, float b) {
	return a - b;
}
float mult(float a, float b) {
	return a * b;
}
float div(float a, float b) {
	if (a != 0 && b != 0) return a / b;
	cout << "\n\t\tDevidion by zero!!!";
	return 0;
}


void menu() {
	float fistr_num, second_num, result;
	char option;
	system("cls");
	cout << "\n\n\t\tEnter first namber: ";
	cin >> fistr_num;
	cout << "\n\t\tEnter op( +, -, /, * ): ";
	cin >> option;
	cout << "\n\t\tEnter second namber: ";
	cin >> second_num;

	switch (option)
	{
	case '+':
		result = sum(fistr_num, second_num);
		break;
	case '-':
		result = sub(fistr_num, second_num);
		break;
	case '*':
		result = mult(fistr_num, second_num);
		break;
	case '/':
		result = div(fistr_num, second_num);
		break;
	default:
		cout << "\n\t\tNo operator";
		break;
	}
	cout << "\n\t\tResult: " << result << "\n\n\n";
	system("pause");
	menu();
}




int main() {

	menu();
	cout << endl;
	system("pause");
	return 0;
}

