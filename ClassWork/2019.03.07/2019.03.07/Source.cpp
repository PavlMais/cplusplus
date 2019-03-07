#include <iostream>
#include <string>

using namespace std;



void fillArr(string *arr, int size) {
	string name, mark1, mark2, mark3;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter mark 1:";
		cin >> mark1;
		cout << "Enter mark 2:";
		cin >> mark2;
		cout << "Enter mark 3:";
		cin >> mark3;
		cout << name, mark1;

		
		
	}
}
void printArr() {
	for (int i = 0; i < SIZ; i++) {
		cout << "\nStudent " << i + 1;
		for (int s = 0; s < SIZEN; s++) {
			cout << "\nPredmet " << s + 1 << "rating: " << arr[i][s];
		}
	}
}
void printSort(int sort = 0) {
	cout << "Student N  predme1 predme2 predmet3";
	for (int i = 0; i < SIZ; i++){
		cout << "\nStudent " << i << "\t" << arr[i][0] << "\t" << arr[i][1] << "\t" << arr[i][2];
	}
}

string *data = new string[size];

int main() {
	int size;
	cout << "Enter count students: ";
	cin >> size;
	avg123name

	
	/*fillArr();
	printSort();
	printArr();*/


	system("pause");
	return 0;
}