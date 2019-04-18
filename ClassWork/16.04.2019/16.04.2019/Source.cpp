#include <iostream>
#include <string>

using namespace std;

struct Time {
	unsigned int seconds : 6;
	unsigned int minuts  : 6;
	unsigned int hours   : 5;
	unsigned int day     : 5;
	unsigned int month   : 4;
	unsigned int year : 11;

	void set() {
		int buf;
		cout << "Enter Year: ";
		cin >> buf;
		year = buf;

		cout << "\nEnter month: ";
		cin >> buf;
		month = buf;
		:123
		cout << "\nEnter day: ";
		cin >> buf;
		day	= buf;

		cout << "\nEnter hours: ";
		cin >> buf;
		hours = buf;

		cout << "\nEnter minuts: ";
		cin >> buf;
		minuts = buf;

		cout << "\nEnter seconds: ";
		cin >> buf;
		seconds	= buf;


	}

	void show() {
		cout << "\nYear: "   << year;
		cout << "\nMonth: "  << month;
		cout << "\nDay: "    << day;
		cout << "\nHours: "  << hours;
		cout << "\nMinutes:" << minuts;
		cout << "\nSeconds: "<< seconds;
	}
};
int main() {

	Time time;
	
	time.set();
	time.show();

	cout << "\n\n\n";
	system("pause");
	return 0;
}