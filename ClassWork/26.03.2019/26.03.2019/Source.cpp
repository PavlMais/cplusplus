#include <iostream>
#include <string>
using namespace std;

struct Animal {
	string name;
	string class_;
	unsigned short int age;
	void create(string Sname, string Sclass_, int Sage) {
		if (0 < age < 100) {
			name = Sname;
			class_ = Sclass_;
			age = Sage;
		}
		else {
			cout << "\nAge invaid!";
		}
	}
	void say() {
		cout << "SAY!" << endl;
	}
	void getInfo() {
		cout << "Name: " << name << "\nClass: " << class_ << "\nAge: " << age << endl;
	}

};


int main() {

	Animal cat;

	cat.create("Cat", "Class", 5);

	cat.say();
	cat.getInfo();

	

	system("pause");
	return 0;
}




