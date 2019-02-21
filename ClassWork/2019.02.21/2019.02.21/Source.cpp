#include <iostream>
#include <ctime>

using namespace std;

void fillArray(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) arr[i] = rand() % 10;
}

void printArray(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";
}

void sumArr(int arrA[], int arrB[], int arr[], const int SIZE) {
	for (int i = 0; i < SIZE + SIZE; i++) arr[i] = (i < 5) ? arrA[i] : arrB[i - SIZE];
}


void printInd(int arrA[], int arrB[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
		for (int s = 0; s < SIZE; s++)
			if (arrA[i] == arrB[s]) cout << arrA[i] << " ";	

}

void printNO(int arrA[], int arrB[], const int SIZE) {
	for (int i = 0; i < SIZE; i++){
		bool is = false;
		for (int s = 0; s < SIZE; s++){	
			if (is) break;
			is =  (arrA[i] == arrB[s]);
		}
		if (!is) cout <<" > " <<  arrA[i];
	}
}


int main() {
	srand(time(0));
	const int SIZE = 5;
	int arrA[SIZE] = {};
	int arrB[SIZE] = {};
	int arrSum[SIZE + SIZE] = {};

	fillArray(arrA, SIZE);
	fillArray(arrB, SIZE);

	cout << "\narr A\n";
	printArray(arrA, SIZE);
	cout << "\narr B\n";
	printArray(arrB, SIZE);

	sumArr(arrA, arrB, arrSum, SIZE);
	cout << "\nSUM ARRR: ";
	printArray(arrSum, 10);

	cout << "\nInd  \n";

	printInd(arrA, arrB, SIZE);

	cout << "\nArr A: ";
	printNO(arrA, arrB, SIZE);
	cout << "\nArr B: ";
	printNO(arrB, arrA,  SIZE);


	// TASK  Створити 3 динамічних змінних різного типу. Запо...

	int *a = new int;
	long *b = new long;
	float *c = new float;

	*a = rand() % 10 + 1;
	*b = rand() % 10 + 1;
	*c = rand() % 10 + 1;
	cout << "\n\n\na: "<< *a << " b: " << *b << " c: " << *c << endl;

	cout << "Dob: " << *a * *b * *c << endl;

	delete a, b, c;




	// TASK end
	cout << "\n\n";

	int arrs[SIZE] = {};
	int *indx = new int;


	fillArray(arrs, SIZE);
	printArray(arrs, SIZE);

	cout << "Enter index: ";
	cin >> *indx;

	
	cout << "Num: " << arrs[*indx] << " | Adress: " << &arrs[*indx] << "\n";


	cout << "\n\n";
	system("pause");
	return 0;
}