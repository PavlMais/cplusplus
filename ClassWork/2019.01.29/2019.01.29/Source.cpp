# include <iostream>
// Написати функцію, яка приймає три аргументи: години, хвилини, секунди.
// Функція повинна повертати еквівалент переданого їй тимчасового значення в секундах 

using namespace std;

inline int getSeconds(int hours , int minutes  = 0, int seconds = 0) {
	if(hours > 0 && hours < 25 && minutes > 0 && minutes < 61 && seconds > 0 && seconds < 61)
		return hours * 60 * 60 + minutes * 60 + seconds;
	else {
		cout << "Invalid args!\n\n";
		return 0;
	}
}


int main() {
	int a, b, c;
	cout << "Enter (hours minutes seconds):\n";
	cin >> a;
	cin >> b;
	cin >> c;

	cout << "Seconds: " << getSeconds(a,b,c) << "\n\n";

	system("pause");
	return 0;
}
