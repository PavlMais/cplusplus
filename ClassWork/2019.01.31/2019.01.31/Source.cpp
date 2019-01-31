#include <iostream>
#include <ctime>

using namespace std;

int Plus(int a, int b);
int Plus(int a, int b, int c);

void FillArr(int arr[], const int size);
void FillArr(int arr[], const int size, int a);
void PrintArr(int arr[], const int size);
int getNegative(int arr[], const int size);
int getAverageOrMax(int arr[], const int size);
int getAverageOrMax(int arr[], const int size, int start, int stop);

void printArr2d(int arr[5][5], const int SIZE, int column);

void printArr2d(int arr[5][5], const int SIZE);

void fillArr2d(int arr[5][5], const int SIZE);



int FoundNam(int arr[], const int SIZE, int num);

void MixArr(int arr[], const int SIZE);

void sortArr(int arr[], const int size);

void sortArr(int arr[], const int size, int a);



int main() {
	srand(time(0));

	cout << "Task 1 =====================\n";
	cout << "21 + 90 = " << Plus(21, 90);
	cout << "\n24 + 55 + 53 = " <<Plus(24, 55, 53);

	//========================== 
	//Task 2
	cout << "\n\nTask 2 ===================\n";
	const int SIZE1 = 10;
	int arr1[SIZE1] = {};

	FillArr(arr1, SIZE1);
	cout << "\nArray: ";
	PrintArr(arr1, SIZE1);
	cout <<"\nNeagtive: " << getNegative(arr1, SIZE1);


	cout << "\nAverage: " << getAverageOrMax(arr1, SIZE1);
	cout << "\nMax on 5 -7: " << getAverageOrMax(arr1, SIZE1, 5, 7);

	//==========================
	//Task 3
	cout << "\n\nTask 3 ======================\n";
	
	const int SIZE = 5;
	int arr3[SIZE][SIZE] = {};

	fillArr2d(arr3, SIZE);
	printArr2d(arr3, SIZE);
	cout << "\nLine: 3 \n";
	printArr2d(arr3, SIZE, 2);



	//=============================
	//Task 4
	cout << "\nTask 4 =========================\n";
	const int SIZE4 = 10;
	int arr4[SIZE4] = {};
	FillArr(arr4, SIZE4);

	cout << "\nArray: ";
	PrintArr(arr4, SIZE4);

	sortArr(arr4, SIZE4);

	cout << "\nArray: ";
	PrintArr(arr4, SIZE4);

	sortArr(arr4, SIZE4, 1);

	cout << "\nArray: ";
	PrintArr(arr4, SIZE4);


	//==================================
	// Task 5

	cout << "\nTask 5 =========================\n";
	const int SIZE5 = 20;
	int arr5[SIZE5] = {};

	FillArr(arr5, SIZE5, 1);
	cout << "\nNormal arr: ";
	PrintArr(arr5, SIZE5);
	MixArr(arr5, SIZE5);
	cout << "\nMix  Array: ";
	PrintArr(arr5, SIZE5);



	cout << "\n\n\n";


	system("pause");
	return 0;
}



void printArr2d(int arr[5][5], const int SIZE){
	for (int i = 0; i < SIZE; i++) {
		for (int a = 0; a < SIZE; a++)
			cout << " " << arr[i][a];
		cout << "\n";
	}
}

void printArr2d(int arr[5][5], const int SIZE, int column){
	for (int a = 0; a < SIZE; a++)
		cout << " " << arr[column][a];
	cout << "\n";
}


void fillArr2d(int arr[5][5], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
		for (int a = 0; a < SIZE; a++)
			arr[i][a] = rand() % 30;
}


int FoundNam(int arr[], const int SIZE, int num) {
	for (int i = 0; i < SIZE; i++) if (arr[i] == num) return i;
}

void MixArr(int arr[], const int SIZE) {
		
	for (int  i = 0; i < SIZE * 2; i++)
	{
		int cut = rand() % SIZE;
		int paste = rand() % SIZE;

		int buffer = arr[cut];
		arr[cut]   = arr[paste];
		arr[paste] = buffer;
	}

}

void sortArr(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) 
		for (int a = 0; a < SIZE - i - 1; a++)
			if (arr[a] > arr[a + 1]) {
				int buffer = arr[a];
				arr[a] = arr[a + 1];
				arr[a+1] = buffer;
			}
}
void sortArr(int arr[], const int SIZE, int a) {
	for (int i = 0; i < SIZE; i++)
		for (int a = SIZE - i - 1; a > 0; a--)
			if (arr[a] > arr[a - 1]) {
				int buffer = arr[a];
				arr[a] = arr[a - 1];
				arr[a - 1] = buffer;
			}
}

int Plus(int a, int b) {
	return a + b;
}

int Plus(int a, int b, int c) {
	return a + b + c;
}
void FillArr(int arr[], const int size) {
	for (int i = 0; i < size; i++) arr[i] = 20 - rand() % 40;
}
void FillArr(int arr[], const int size, int a) {
	for (int i = 0; i < size; i++) arr[i] = i + 1;
}

void PrintArr(int arr[], const int size) {
	for (int i = 0; i < size; i++) cout << arr[i] << " ";
}

int getNegative(int arr[], const int size) {
	int counter = 0;
	for (int i = 0; i < size; i++) if (arr[i] < 0) counter++;
	return counter;
}
int getAverageOrMax(int arr[], const int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) sum += arr[i];
	return sum / size;
}
int getAverageOrMax(int arr[], const int size, int start, int stop) {
	int max = 0;
	for (int i = start; i < stop; i++) if (arr[i] > max) max += arr[i];
	return max;
}