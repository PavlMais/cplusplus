#include <iostream>


using namespace std;

void decript(char str[], int step){
	for (int i = 0; i < strlen(str); i++)
		str[i] = char(int(str[i]) - step);
}


void cript(char str[], int step){
	for (int i = 0; i < strlen(str); i++)
		str[i] = char(int(str[i]) + step);
	
}




int main() {

	int sel, code;
	char str[255];

	while (true)
	{
		cout << "\n1 Crypt 2 decrypt: ";
		cin >> sel;

		cout << "\nEnter line: ";
		cin >> str;

		cout << "\nEnter code: ";
		cin >> code;
		if (sel == 1) {
			cript(str, code);


		}
		else if (sel == 2) {
			decript(str, code);
		}


		cout << str;



	}
	






	system("pause");



	return 0;
	//int size, num;

	//cout << "Enter cvount latter";
	//cin >> size;

	//int *arr = new int[size];

	//for (int i = 0; i < size; i++){
	//	cout << "Enter num char:";
	//	cin >> num;
	//	while (!(num > 65 && num < 90 || num > 97 && num < 123)) {
	//		cout << "error";
	//		cout << "Enter num char:";
	//		cin >> num;
	//	}
	//	arr[i] = num;
	//}


	//for (int i = 0; i < size; i++){
	//	cout << char(arr[i]) << " ";
	//}

	//char str[] = "";
	//cout << "Enter string";
	//cin >> str;



	//for (int i = 0; i < strlen(str); i++)
	//{
	//	cout << int(str[i]) << " ";
	//}





	//cout << "\n";
	//system("pause");
	//return 0;
}


