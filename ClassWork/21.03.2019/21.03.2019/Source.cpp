#include <iostream>
#include <string>

using namespace std;


void fillArr(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) arr[i] = 10 + rand() % 50;
}

void printArr(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) std::cout << arr[i] << " ";
}



void bigger(int& a, int& b) {
	if (a > b) swap(a, b);
}
void smaller(int& a, int& b) {
	if (a < b) swap(a, b);
}
void sort_arr(int *arr, const int SIZE, void(*swaper)(int&, int&)) {
	for (int i = 0; i < SIZE; i++)
		for (int s = 0; s < SIZE - i - 1; s++)
			swaper(arr[s], arr[s + 1]);
}


int* createArr(int size) {
	int *arr = new int[size];
	fillArr(arr, size);
	return arr;
}

int *append(int *arr, int *size, int num) {
	int *new_arr = new int[*size + 1];
	for (int i = 0; i < *size; i++) new_arr[i] = arr[i];
	new_arr[*size] = num;
	*size += 1;
	delete[] arr;
	return new_arr;
}

int main()
{

	const int size = 10;
	int *arr = new int[10];

	fillArr(arr, size);
	printArr(arr, size);
	cout << "\nSORI\n";

	sort_arr(arr, size, smaller);
	printArr(arr, size);

	// ===============- TASK 2 -===================

	cout << "\n\n\t TASK 2 \n\n";
	int *size2 = new int;
	*size2 = 10;


	int *arr2 = createArr(*size2);

	printArr(arr2, *size2);

	arr2 = append(arr2, size2, 5);

	cout << "\nAPPEND\n";

	printArr(arr2, *size2);

	cout << " \n";
	system("pause");
	return 0;
}