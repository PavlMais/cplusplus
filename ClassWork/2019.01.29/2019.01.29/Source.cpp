#include <iostream>
#include <ctime>
using namespace std;


// Написати функцію, яка приймає три аргументи: години, хвилини, секунди.
// Функція повинна повертати еквівалент переданого їй тимчасового значення в секундах 
inline int getSeconds(int hours , int minutes  = 0, int seconds = 0) {
	if(hours > 0 && hours < 25 && minutes > 0 && minutes < 61 && seconds > 0 && seconds < 61)
		return hours * 60 * 60 + minutes * 60 + seconds;
	else {
		cout << "Invalid args!\n\n";
		return 0;
	}
}


// Написать функцию Dohod, которая вычисляет доход по вкладу.
// Исходными данными для функции являются: величина вклада, процентная ставка (годовых) и срок вклада (количество дней).

inline float dohod(float money, float procent, int days) {
	if (money < 0) return 0;
	return money * procent * days / 365 / 100;
}


// Написать функцию frame, которая выводит на экран рамку.В качестве параметров функции должны передаваться размер рамки.
void freame(int hight, int width = 0) {
	if (!width) width = hight;

	for (int i = 0; i < hight; i++){
		for (int a = 0; a < width; a++){
			if (a == 0 || i == 0 || a == width - 1 || i == hight - 1) cout << "#";
			else cout << " ";
		}
		cout << endl;
	}
}

void game() {
	srand(time(0));
	int cartU[10];
	int cartC[10];
	int select;
	int index = 2;
	cartU[0] = rand() % 11;
	cartU[1] = rand() % 11;
	cartC[0] = rand() % 11;
	cartC[1] = rand() % 11;
	int sum = 0;

	cout << "You got: " << cartU[0] << " and " << cartU[1]<<"\n\n\t1 Get cart 2 View all cart";
	cin >> select;
	while (select == 1) {
		cartU[index] = rand() % 11;
		index++;
		cout << "\n\tYou got: " << cartU[index] << "\n\n\t1 Get cart 2 View all cart";
		cin >> select;
	}
	for (int i = 0; i < index; i++) sum += cartU[i];
	
	cout << "comp all: " + cartC[0] + cartC[1] << "You all: " << sum;
	if (sum == 21) {
		cout << "You WIN!";
	}else if(cartC[0] + cartC[1]) {
		cout << "PC WIN!";
	}else{

	}




}


int main() {
	int a, b, c;
	cout << "Enter (hours minutes seconds):\n";
	cin >> a;
	cin >> b;
	cin >> c;

	cout << "Seconds: " << getSeconds(a,b,c) << "\n\n";
	cout << "Dohod: " << dohod(1000, 9.2, 30) << "\n\n";


	freame(10, 30); //draw box

	game();

	system("pause");
	return 0;
}
