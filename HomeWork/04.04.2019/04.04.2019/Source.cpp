#include <iostream>
#include <string>
using namespace std;

struct Human {
	string first_name;
	string second_name;
	int age;

	string info() {
		return first_name + " " + second_name + " " + to_string(age);
	}

};


Human* newHuman(Human* humans, int *size) {
	*size += 1;
	Human* new_humans = new Human[*size];

	for (int i = 0; i < *size - 1; i++) new_humans[i] = humans[i];
	delete[] humans;
	
	Human new_human;

	cout << "Enter first name: ";
	cin >> new_human.first_name;
	cout << "Enter second name: ";
	cin >> new_human.second_name;
	cout << "Enter age: ";
	cin >> new_human.age;


	new_humans[*size - 1] = new_human;
	return new_humans;

}
void showHumans(Human* humans, int *size) {
	cout << "First name Second name Age\n";
	for (int i = 0; i < *size; i++) cout << humans[i].info() << endl;
}

int main() {
	int sel;

	int* size = new int(0);
	Human* humans = new Human[*size];



	while (true)
	{
		cout << " 1 NEW human  2 ALL humans: ";
		cin >> sel;
		switch (sel)
		{
		case 1: humans = newHuman(humans, size); break;
		case 2: showHumans(humans, size); break;
		}
	}


	system("pause");
	return 0;
}