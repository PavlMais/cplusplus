#include <iostream>
#include <ctime>
using namespace std;


template<typename T>
void fillArray(T arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) arr[i] = rand() % 10;
}
template<typename T>
void fillArray(T arr[], const int SIZE, int fill) {
	for (int i = 0; i < SIZE; i++) arr[i] = fill;
}

template<typename T>
void printArray(T arr, const int SIZE) {
	for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";
}

template<typename T>
int getMin(T arr, const int SIZE) {
	int min = 1000;
	for (int i = 0; i < SIZE; i++) if (arr[i] < min) min = arr[i];
	return min;
}
template<typename T>
int getAVG(T arr, const int SIZE) {
	int sum = 0;
	for (int i = 0; i < SIZE; i++)  sum += arr[i];
	return sum;
}
template<typename T>
int getMax(T arr, const int SIZE) {
	int max = 1000;
	for (int i = 0; i < SIZE; i++) if (arr[i] > max) max = arr[i];
	return max;
}


void Task1() {
	const int SIZE5 = 5;
	const int SIZE14 = 14;

	int arr5[5] = {};
	double arr14[14] = {};

	fillArray(arr5, SIZE5);
	fillArray(arr14, SIZE14);


	cout << "\nPrint arr1: ";
	printArray(arr5, SIZE5);
	cout << "\nPrint arr2: ";

	printArray(arr14, SIZE14);

	cout << "\n\nmin: " << getMin(arr5, SIZE5);
	cout << "\navg: " << getAVG(arr5, SIZE5);
	cout << "\nmax: " << getMax(arr5, SIZE5);

	cout << "\n\nmin: " << getMin(arr14, SIZE14);
	cout << "\navg: " << getAVG(arr14, SIZE14);
	cout << "\nmax: " << getMax(arr14, SIZE14);
}

void swithArr(int arr[], const int SIZE, int count, int L_R) {


	if (L_R == 1) {
		for (int c = 0; c < count; c++) {
			for (int i = 0; i < SIZE - 1; i++) {
				int buffer = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = buffer;
			}
		}
	}
	else {
		for (int c = 0; c < count; c++) {
			for (int i = SIZE - 1; i > 0; i--) {
				int buffer = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = buffer;
			}
		}
	}
}

int searchFirst(int arr[], const int SIZE, int num) {
	for (int i = 0; i < SIZE; i++) if (arr[i] == num) return i;
}
int searchLast(int arr[], const int SIZE, int num) {
	int item = 0;
	for (int i = 0; i < SIZE; i++) if (arr[i] == num) item = i;
	return item;
}
void mixArray(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++){
		int cut = rand() % SIZE;
		int paste = rand() % SIZE;
		int buffer = arr[cut];
		arr[cut] = arr[paste];
		arr[paste] = buffer;
	}
}

void Task2() {
	const int SIZE = 15;
	int arr[SIZE] = {};
	int L_R;


	fillArray(arr, SIZE);
	cout << "\n\n";
	if (arr[0] % 2 == 0) {
		L_R = 1;
		cout << " right ";
	}
	else {
		L_R = 0;
		cout << " left ";
	}
	cout << " : " << arr[0] << "\n\n";
	printArray(arr, SIZE);
	cout << "\n\n";
	swithArr(arr, SIZE, arr[0], L_R);
	printArray(arr, SIZE);
	mixArray(arr, SIZE);
	cout << "\n";
	printArray(arr, SIZE);
	fillArray(arr, SIZE, 5);
	cout << "\n";
	printArray(arr, SIZE);

}

int main() {
	srand(time(0));
	Task1();
	cout << "\n\n\tTASK 2 \n\n";
	Task2();



	cout << endl;
	system("pause");
	return 0;
}