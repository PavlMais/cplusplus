#include <iostream>
#include <ctime>

using namespace std;

void fillArr(int arr[], const int SIZE);
int getAVG(int arr[], const int SIZE);

void printArr(int arr[], const int SIZE);

int getMax(int arr[], const int SIZE);
int getMin(int arr[], const int SIZE);

int main() {
	srand(unsigned(time(0)));

	const int SIZE = 5;

	int arrRating[SIZE][SIZE] = {};

	for (int i = 0; i < SIZE; i++) fillArr(arrRating[i], SIZE);
	

	for (int i = 0; i < SIZE; i++) {
		cout << "\n\n\tStudent: " << i;
		printArr(arrRating[i], SIZE);
		cout << "\n\t\t   AVG: " << getAVG(arrRating[i], SIZE);
		cout << "\n\t\t   Min: " << getMin(arrRating[i], SIZE);
		cout << "\n\t\t   Max: " << getMax(arrRating[i], SIZE);
	}
	
	



	cout << "\n\n";
	system("pause");
	return 0;
}


void fillArr(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
		arr[i] = rand() % 12;
}

int getAVG(int arr[], const int SIZE) {
	int sum = 0;
	for (int i = 0; i < SIZE; i++) sum += arr[i];
	return sum / SIZE;
}

void printArr(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) 
		cout <<"\nRating for predmet - "<< i + 1 <<": "<<arr[i];
}

int getMax(int arr[], const int SIZE) {
	int max = 0;
	for (int i = 0; i < SIZE; i++) 
		if (arr[i] > max) max = arr[i];
	
	return max;
}

int getMin(int arr[], const int SIZE) {
	int min = 1000;
	for (int i = 0; i < SIZE; i++) 
		if (arr[i] < min) min = arr[i];
	
	return min;
}



//int main() {
//
//	int a = 5;
//	int b = 5;
//	int c = 25;
//
//	int *P_a = &a;
//	int *P_b = &b;
//	int *P_c = &c;
//
//	int dob = *P_a * *P_b * *P_c;
//
//	int avg = (*P_a + *P_b + *P_c) / 3;
//	cout << "dob " << dob << endl;
//	cout << "avg " << avg << endl;
//
//	int min = 100;
//
//	if      (*P_a <= *P_b && *P_a <= *P_c) cout << "min a " << *P_a;
//	else if (*P_b <= *P_a && *P_b <= *P_c) cout << "min b " << *P_b;
//	else cout << "min c " << *P_c;
//
//
//	cout << endl;
//	system("pause");
//	return 0;
//}