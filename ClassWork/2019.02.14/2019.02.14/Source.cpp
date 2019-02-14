#include <iostream>

using namespace std;



void prin(int *a, int *b) {
	cout << "\nA Add: " << a << "Val: " << *a;
	cout << "\nB Add: " << b << "Val: " << *b;
}

int *getMax(int *pa, int *pb) {
	if (*pa > *pb) return pa;
	if (*pb > *pa) return pb;
	return 0;
}
void swiTch(int *pa, int *pb) {
	int *bufferA = pa;
	pa = pb;
	pb = bufferA;
	cout << "\n\nA Add: " << pa << "Val: " << *pa;
	cout << "\nB Add: " << pb << "Val: " << *pb;

}
int *add(int *a, int *b) {
	int sum = *a + *b;
	return &sum;
}
int *sub(int *a, int *b) {
	int sum = *a - *b;
	return &sum;
}


// ============= TASK 4 ==========================
void fillArr(int arr[10][10], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
		for (int a = 0; a < SIZE; a++)
			arr[i][a] = (rand() % 80) + 10;
}
void printArr(int arr[10][10], const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		for (int a = 0; a < SIZE; a++) cout << arr[i][a] << " ";
		cout << endl;
	}
}
int sumArr(int arr[10][10], const int SIZE) {
	int sum = 0;
	for (int i = 0; i < SIZE; i++) 
		for (int a = 0; a < SIZE; a++) sum += arr[i][a];
		
	return sum;
}
int getMaxArr(int arr[10][10], const int SIZE) {
	int max = 0;
	int max_id = 0;
	int bufferMax = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int s = 0; s < SIZE; s++)
		{
			bufferMax += arr[i][s];
		}
		if (bufferMax > max) {
			max = bufferMax;
			max_id = i;
		}
	}
	return max_id;
}


// ===========-  TASK 5 -======================================
void fill2DArr(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)	
		arr[i] = (rand() % 80) + 10;
}

void printReversArr(int arr[], const int SIZE) {
	cout << "\n2d arr:\n";
	for (int i = 0; i < SIZE; i++)  cout << arr[i] << " ";
	cout << "\narr revers:\n";

	for (int i = SIZE -1; i > -1; i--)  cout << arr[i] << " ";
	
}


int get_sum_arr(int arr[], const int SIZE) {
	int sum = 0;
	int *Psum = &sum;
	for (int i = 0; i < SIZE; i++) *Psum += arr[i];
	return *Psum;
}

// ===========-  TASK 6  -======================================


int main() {
	int a = 10;
	int b = 15;

	int *pa = &a;
	int *pb = &b;
	prin(pa, pb);

	swiTch(pa, pb);

	prin(pa, pb);


	cout <<"\nMax: "<< *getMax(pa, pb);
	cout << "\nAdd: " << *add(pa, pb);
	cout << "\nSun: " << *sub(pa, pb);

	// ===========-  TASK 4  -======================================
	const int SIZE = 10;
	int arr[SIZE][SIZE] = {};

	cout << "\n\n\t TASK 4 \nArray: \n";
	fillArr(arr, SIZE);
	printArr(arr, SIZE);
	cout << "\nSum: " << sumArr(arr, SIZE);
	cout << "\nMax arr index: " << getMaxArr(arr, SIZE);

	// ===========-  TASK 5  -======================================
	cout << "\n\n\tTASK 5\n";
	int arr2D[SIZE] = {};


	fill2DArr(arr2D, SIZE);
	printReversArr(arr2D, SIZE);
	cout << "\n\nSum 2d arr: " << get_sum_arr(arr2D, SIZE);

	// ===========-  TASK 6  -======================================






	cout << "\n\n";
	system("pause");
	return 0;
}


