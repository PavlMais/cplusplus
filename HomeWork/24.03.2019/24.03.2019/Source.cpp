//1) Написати функції для роботи з динамічним одновимірним масивом :
//a) Функція створення динамічного масиву вказаного розміру і його заповнення випадковими числами в діапазоні[-12..56].Функція повертає адресу створеного масиву.
//b) Виводу масиву
//c) Доповнення масиву одним елементом.Функція отримує адресу масиву, розмір та елемент для доповнення.
//
//* Для тих зто все зробив на парі
//
//*) Написати функцію, яка отримує матрицю дробових чисел і повертає ссилку(посилання) на елемент матриці, найближчий до середнього арифметичного матриці.За допомогою функції :
//a) Вивести елемент, найближчий до середнього
//b) Змінити знак елемента, найближчий до середнього, на протилежний
//


#include <iostream>
#include <ctime>
using namespace std;

float randFloat(){
	return ((10 - 90) * ((float)rand() / RAND_MAX)) + 10;
}

void fillArray(float *arr, int SIZE) {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
		
			arr[i * SIZE + j] = randFloat();
}
void printArray(float *arr, int SIZE) {
	cout << "\nArray: \n";
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			cout << arr[i * SIZE + j] << " ";
		cout << "\n";
	}
}


void Sort(float arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) 
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

float* getAverage(float* arr, int const SIZE) {
	// Converto to 1D Array from 2D
	float *oArr = new float[SIZE*SIZE];
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			oArr[i+j] = arr[i * SIZE + j];
		
	// Sort  array
	Sort(oArr, SIZE * SIZE);

	int indx = (SIZE * SIZE) / 2;
	


	// Negative to positive or positive to negative
	if (oArr[indx] > 0) oArr[indx] = fabs(oArr[indx]);
	else oArr[indx] = -oArr[indx];
	

	// return avg~ num
	return &oArr[indx];
}

int main() {
	srand(unsigned(time(0)));
	const int SIZE = 5;
	float* arr = new float[SIZE * SIZE];


	fillArray(arr, SIZE);
	printArray(arr, SIZE);


	cout << "\n\nAVG: " << *getAverage(arr, SIZE) << endl;;




	system("pause");
	return 0;
}