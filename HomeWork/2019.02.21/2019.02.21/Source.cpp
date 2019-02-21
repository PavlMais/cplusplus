#include <iostream>

using namespace std;

void fillArray(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) arr[i] = (rand() % 50) - 25;
}

void printArray(int arr[], const int SIZE) {
	cout << "\nArray: ";
	for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";
}
//Написати функцію, яка замінює всі від’ємні елементи переданого масиву нулями.
//Примітка!Функція повинна повертати ссилку на відємний елемент

int replaceMin(int arr[], const int SIZE) {
	int countMin = 0;
	for (int i = 0; i < SIZE; i++) 
		if (arr[i] < 0) {
			arr[i] = 0;
			countMin++;
		}
	return countMin;
}

// Написать функцію(або шаблон), яка приймає дві ссилки на змінні і виконує обмін значень.
// - За допомогою написаної функції поміняти місцями у матриці перший та другий стовпці.

void superSwap(int &a, int &b) {
	int buffer = a;
	a = b;
	b = buffer;
} 

// Написати функцію, яка отримує одновимірний масив і повертає ссилку на найменший елемент масиву.
// а допомогою цієї функції вивести на екран найменший елемент та подвоїти найменший елемент масиву
int* getMinArray(int arr[], const int SIZE) {
	int *min = new int;
	*min = 1000;
	for (int i = 0; i < SIZE; i++){
		if (arr[i] < *min) min = &arr[i];
	}
	return min;
}

int main() {
	const int SIZE = 10;

	int arr[SIZE] = {};

	fillArray(arr, SIZE);
	printArray(arr, SIZE);
	cout << "\nMin: " << *getMinArray(arr, SIZE);
	cout << "\nvid: " <<replaceMin(arr, SIZE);
	printArray(arr, SIZE);


	int a = 5;
	int b = 20;


	cout << "\n\nSWAP\n";
	cout << "\nA: " << a << "  B: " << b;
	superSwap(a, b);
	cout << "\nA: " << a << "  B: " << b;


	cout << "\n\n";
	system("pause");
	return 0;
}