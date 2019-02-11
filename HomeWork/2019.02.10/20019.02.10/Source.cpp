#include <iostream>

using namespace std;


void fillArray(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) arr[i] = rand() % 50;
}


// Написати функцію, яка отримує ціле шестизначне число і визначає чи є воно щасливим. 
// (Число є щасливим, якщо сума його перших трьох цифр = сумі останніх трох цифр.
//	Наприклад, 1331. 45154).
void checkHappyNamber(int arr[], const int SIZE) {
	int a = arr[0] + arr[1] + arr[2];
	int b = arr[3] + arr[4] + arr[5];

	if (a == b) cout << "\n\tHappy\n\n\n";
	else cout << "\n\tNo Happy\n\n\n";
}

// Написати функцію, яка отримує одновимірний масив, друкує прості числа,
// які зустрічаються у ньому та повертає їх кількість. Перевірити роботу функції. 
int checkNNambers(int arr[], const int SIZE) {
	int nNam[14] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,47 };
	int count = 0;

	for (int i = 0; i < SIZE; i++)
		for (int s = 0; s < 14; s++)
			if (nNam[s] == arr[i]){
				cout << arr[i] << " ";
				count++;
			}
		

	return count;
}


int main() {
	const int SIZE = 50;
	int arr[SIZE] = {};

	fillArray(arr, SIZE);


	cout <<"\nAll n numbers: "<< checkNNambers(arr, SIZE) << "/50\n\n";

	const int SIZEH = 6;
	int arrH[SIZEH] = {};
	for (int i = 0; i < SIZEH; i++)
	{
		cout << "\tEnter num " << i << "/6: ";
		cin >> arrH[i];
	}

	checkHappyNamber(arrH, SIZEH);





	system("pause");
	return 0;
}