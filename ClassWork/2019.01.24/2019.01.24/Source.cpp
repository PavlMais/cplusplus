#include <iostream>
#include <ctime>

void fillArr(int arr[], const int SIZE );
void printArr(int arr[], const int SIZE);
int  foundLeft(int arr[], const int SIZE);
void reversArr(int arr[], const int SIZE, int a, int b);
int  foundRight(int arr[], const int SIZE);

int main() {
	srand(time(0));
	const int SIZE = 10;
	int arr[SIZE] = {};

	fillArr(arr, SIZE);
	printArr(arr, SIZE);
	int left_i  = foundLeft(arr, SIZE);
	int right_i = foundRight(arr, SIZE);
	reversArr(arr, SIZE, left_i, right_i);
	std::cout << std::endl;
	printArr(arr, SIZE);

	system("pause");
	return 0;
}

void fillArr(int arr[], const int SIZE){
	for (int i = 0; i < SIZE; i++) arr[i] = 30 - rand() % 50;
}

void printArr(int arr[], const int SIZE){
	for (int i = 0; i < SIZE; i++) std::cout << arr[i] << " ";
}

int foundLeft(int arr[], const int SIZE){
	for (int i = 0; i < SIZE; i++) if (arr[i] < 0) return i;
}

int foundRight(int arr[], const int SIZE){
	for (int i = SIZE - 1; i > 0; i--) if (arr[i] < 0) return i;
}

void reversArr(int arr[], const int SIZE, int a, int b){
	int buffer = arr[a];
	arr[a] = arr[b];
	arr[b] = buffer;
}
