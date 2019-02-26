#include <iostream>

using namespace std;

void fillArray(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) arr[i] = (rand() % 50) - 25;
}

void p(int arr[], const int SIZE) {
	cout << "\nArray: ";
	for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";
}

void printArray(int *arr, const int SIZE) {
	cout << "\nArray: ";
	for (int i = 0; i < SIZE; i++)
		cout << *(arr + i) << " ";
	

	
}

void printPar(int *threeNum, const int SIZE) {
	cout << "\nArray: ";

	for (int i = 1; i < SIZE; i += 2) 
		cout << *(threeNum - 2 + i) << " ";
	
}


void getRandom(int *sum, int *avg) {
	for (int i = 0; i < 10; i++){
		int a = rand() % 17;
		cout << a << " ";
		*sum += a;
		*avg = *avg * a;
	}
}

int getMaxArray(int arr[10][10], const int SIZE) {
	int max = 0;
	for (int i = 0; i < SIZE; i++)
		for (int d = 0; d < SIZE; d++)
			if (arr[i][d] > max) max = arr[i][d];
	return max;
}

void swapArray(int arr[10][10], int cut, int paste, const int SIZE) {
	for (int i = 0; i < SIZE; i++){
		int buffer = arr[cut][i];
		arr[cut][i] = arr[paste][i];
		arr[paste][i] = buffer;
	}
}
void clearArray(int arr[10][10], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
		for (int d = 0; d < SIZE; d++)
			arr[i][d] = 0;
}

void fill3dArray(int arr[10][10], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
		for (int d = 0; d < SIZE; d++)
			arr[i][d] = (rand() % 80) + 10;
}
void print3dArray(int arr[10][10], const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		cout << "\n" << i << " - ";
		for (int d = 0; d < SIZE; d++)
			cout << " " << arr[i][d];
	}
}
int main() {
	const int SIZE = 10;
	int arrS[SIZE] = {};

	fillArray(arrS, SIZE);
	p(arrS, SIZE);
	printArray(arrS, SIZE);
	printPar(arrS + 2, SIZE);


	int sum = 0;
	int avg = 2;

	cout << "\n\n";
	getRandom(&sum, &avg);


	cout << "\nSum: " << sum << "  Avg: " << avg;



	cout << "\n\n\n\tARRAY\n";
	int cmd, cut, paste;
	
	int arr[SIZE][SIZE] = {};

	do {

		cout << "\n\n1 fill  2 print  3 max  4 swap  5 clear  0 exit\n";
		cin >> cmd;

		switch (cmd){
			case 1: // Fill ARR
				fill3dArray(arr, SIZE);
				cout << "\nFilled!";
			break;
			case 2: // PRINT ARR
				print3dArray(arr, SIZE);
				
				break;
			case 3: // get max
				cout << "MAX: " <<  getMaxArray(arr, SIZE);

				break;

			case 4: //SWAP lines
				cout << "Cut line: ";
				cin >> cut;
				cout << "Paste line: ";
				cin >> paste;


				swapArray(arr, cut, paste, SIZE);
				break;
			case 5:
				clearArray(arr, SIZE);
	
				break;
		default:
			return 0;
			break;
		}



	} while (cmd != 0);


	system("pause");
	return 0;
}
