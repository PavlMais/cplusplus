#include <iostream>
#include <ctime>




// 1. Написати шаблони функцій для роботи з двовимірним масивом:
// a.	введення(або заповнення випадковими числами) двовимірного масиву
// b.	виведення матриці на екран
// c.	перевірка чи всі(кожен) рядки матриці впорядковані за зростанням(шаблон функції повертає логічне значення).
// d.	перевірка чи заданий стовпець матриці впорядкований за спаданням

//Перевірити роботу шаблонів функцій

using namespace std;




template<typename T>
void fillArr(T arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++)
		for (int s = 0; s < SIZE; s++)
			arr[i][s] = rand() % 4;
}

template<typename T>
void showArr(T arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		for (int s = 0; s < SIZE; s++)
			cout << arr[i][s] << " ";
		cout << endl;
	}
}
template<typename T>
bool checkLineSort(T arr[5][5], const int SIZE, int line) {
	int max_value = 0;
	for (int i = 0; i < SIZE; i++) 
		if (arr[line][i] > max_value) max_value = arr[line][i];
	
	if (arr[line][0] != max_value) return 0;
	

	for (int i = 1; i < SIZE - 1; i++)
		if (arr[line][i] < arr[line][i + 1]) return 0;

	return 1;
}

template<typename T>
bool checkAllSort(T arr[5][5], const int SIZE) {
	for (int line = 0; line < SIZE; line++)
	{
		
		if (checkLineSort(arr, SIZE, line) == 0) return 0;
	}
	return 1;
}




int main() {
	srand(unsigned(time(0)));
	const int SIZE = 5;
	int arr[SIZE][SIZE] = {};


	fillArr(arr, SIZE);

	arr[1][0] = 5; // for testing
	arr[1][1] = 3; //
	arr[1][2] = 3; //
	arr[1][3] = 2; //
	arr[1][4] = 0; //

	cout << "Show Array: \n";
	showArr(arr, SIZE);
	
	cout << "\nCheck sort line 1: " << checkLineSort(arr, SIZE, 0);
	cout << "\nCheck sort line 2: " << checkLineSort(arr, SIZE, 1);
	cout << "\nCheck sort line 3: " << checkLineSort(arr, SIZE, 2);
	cout << "\nCheck sort line 4: " << checkLineSort(arr, SIZE, 3);
	cout << "\nCheck sort line 5: " << checkLineSort(arr, SIZE, 4);

	cout << "\nCheck sort all line: " << checkAllSort(arr, SIZE);



	cout << "\n\n";


	system("pause");
	return 0;
}
