#include <iostream>
#include <string>

using namespace std;
//Написати програму, яка реалізує телефонну книгу з вказаною користувачем кількістю абонентів
//і всіма необхідними функціями. Використати вкладені структури (для адреси чи ПІБ). 
struct Name {
	string first;
	string second;
};

struct Addres {
	string counrtry;
	string region;
	string street;
	int houseNumber;
};

struct Contact {
	Name name;
	Addres addres;
	int phoneNamber;
};

void menu() {
	cout << "\n\n1 Add contacts";
}


Contact* addContact(Contact* contacts, int* contactsSize) {
	Contact newContact;
	string buf;

	cout << "\tAdd new contacn..\n\tEnter first name: ";
	cin >> newContact.name.first;

	cout << "\tEnter second name: ";
	cin >> newContact.name.second;

	cout << "\tEnter country:";
	cin >> newContact.addres.counrtry;

	cout << "\tEnter region:";
	cin >> newContact.addres.region;

	cout << "\tEnter house number:";
	cin >> buf;
	newContact.addres.houseNumber = stoi(buf);

	cout << "\tEnter photo number:";
	cin >> buf;
	newContact.phoneNamber = stoi(buf);

	*contactsSize += 1;
	Contact* upCont = new Contact[*contactsSize];

	if (*contactsSize - 1 > 0) for (int i = 0; i < *contactsSize; i++) upCont[i] = contacts[i];
	upCont[*contactsSize - 1] = newContact;
	return upCont;
}


void print(Contact* contacts, int contactsSize) {
	system("cls");
	cout << "First name Second name Country Region HouseNum Phone number\n";


	for (int i = 0; i < contactsSize; i++)
	{
		cout << contacts[i].name.first << " " << contacts[i].name.second << " "
			<< contacts[i].addres.counrtry << " " << contacts[i].addres.region
			<< " " << contacts[i].addres.houseNumber << " " << contacts[i].phoneNamber << endl;
	}

}

int main() {
	int *contactsSize = new int;
	*contactsSize = 0;
	Contact *contacts = new Contact[*contactsSize];
	int sel;
	while (true)
	{
		print(contacts, *contactsSize);
		menu();
		cin >> sel;
		switch (sel)
		{
			
		case 1:
				contacts = addContact(contacts, contactsSize);
				break;


		default:
			break;
		}



	}






	system("pause");
	return 0;
}