#include <iostream>

using namespace std;

void fillArray(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) arr[i] = (rand() % 50) - 25;
}

void printArray(int arr[], const int SIZE) {
	cout << "\nArray: ";
	for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";
}
//�������� �������, ��� ������ �� �䒺�� �������� ���������� ������ ������.
//�������!������� ������� ��������� ������ �� ������ �������

int replaceMin(int arr[], const int SIZE) {
	int countMin = 0;
	for (int i = 0; i < SIZE; i++) 
		if (arr[i] < 0) {
			arr[i] = 0;
			countMin++;
		}
	return countMin;
}

// �������� �������(��� ������), ��� ������ �� ������ �� ���� � ������ ���� �������.
// - �� ��������� �������� ������� ������� ������ � ������� ������ �� ������ �������.

void superSwap(int &a, int &b) {
	int buffer = a;
	a = b;
	b = buffer;
} 

// �������� �������, ��� ������ ����������� ����� � ������� ������ �� ��������� ������� ������.
// � ��������� ���� ������� ������� �� ����� ��������� ������� �� ������� ��������� ������� ������
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