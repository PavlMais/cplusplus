#include <iostream>

using namespace std;

void d(int &a) {
	a = a * a;
}

void dop_avg_min(int &a, int &b, int &c ) {
	cout << "\nDobutok: " << a * b * c;
	cout << " Avg: " << (a + b + c) / 3;
	if (a < b && a < c) cout << " Min: " << a;
	else if (b < a && b < c) cout << " Min: " << b;
	else cout << " Min: " << c;
}
void fillArr(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
		arr[i] = (rand() % 80) + 10;
}
void sumArr(int arrA[], int arrB[], int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) arr[i] = arrA[i];
	for (int i = SIZE; i < SIZE + SIZE; i++) arr[i] = arrB[i - SIZE];

}

void sortArr(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
		for (int a = 0; a < SIZE - i - 1; a++)
			if (arr[a] > arr[a + 1]) {
				int buffer = arr[a];
				arr[a] = arr[a + 1];
				arr[a + 1] = buffer;
			}
}

void printArr(int arr[], const int size) {
	for (int i = 0; i < size; i++) cout << arr[i] << " ";
}

template <typename T>
void checkTwoNum(T &a, T &b) {
	if (a < b) {
		cout << a;
		a += 10;
	}
	else {
		cout << b;
		b += 10;

	}

}

void swap(int &a, int &b) {
	int buffer = a;
	a = b;
	b = buffer;
}
int main() {

	int a = 5;
	cout << a << endl;
	d(a);
	
	cout << a;

	dop_avg_min(a, a, a);

	// TASK 3


	const int SIZE = 10;

	int arrA[SIZE] = {};
	int arrB[SIZE] = {};
	int arr[SIZE + SIZE] = {};

	fillArr(arrA, SIZE);
	fillArr(arrB, SIZE);
	cout << "\n";
	printArr(arrA, SIZE);
	cout << "\n";
	printArr(arrB, SIZE);
	sortArr(arrA, SIZE);
	sortArr(arrB, SIZE);
	cout << "\n";
	printArr(arrA, SIZE);
	cout << "\n";
	printArr(arrB, SIZE);

	sumArr(arrA, arrB, arr, SIZE);
	
	cout << "\n";
	printArr(arr, SIZE+SIZE);


	// TASK 4

	int aa, b;

	cout << "Enter a: ";
	cin >> aa;
	cout << "Enter b: ";
	cin >> b;

	checkTwoNum(aa, b);

	cout << aa << " | " << b;

	//TASK 5

	int s = 12;
	int c = 56;
	cout << "\nA: " << s << " B: " << c;
	swap(s, c);
	cout << "\nA: " << s << " B: " << c<< "\n\n";




	system("pause");
	return 0;
}