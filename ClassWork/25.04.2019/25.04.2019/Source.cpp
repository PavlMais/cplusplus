#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

struct User {
	string login;
	string password;
	int group;
	string toString() {
		return login + "[l]" + password + "[p]" + to_string(group) + "[g]";
	}
};

User parse_user(string data) {
	int indx1 = data.find("[l]") + 3;
	int indx2 = data.find("[p]") + 3;
	int indx3 = data.find("[g]") + 3;
	User user;

	user.login = data.substr(0, indx1 - 3);
	user.password = data.substr(indx1, indx2 - indx1 - 3);
	user.group = stoi(data.substr(indx2, indx3 - indx2 - 3));

	return user;
}




bool login(User* users, int usersSize, User &activeUser) {
	
	string login, password;
	bool users_exists = false;
	User check_user;
	int left_try = 3;

	do {
		std::cout << "\n\n\t\tEnter login: ";
		std::cin >> login;


		for (int i = 0; i < usersSize; i++) {
			std::cout << users[i].login;

			if (users[i].login == login) {
				check_user = users[i];
				users_exists = true;
				break;
			}
		}
		system("cls");
		if (!users_exists) std::cout << "\n\n\t\tUser not exists!";

	} while (!users_exists);


	int key;
	do {
		password = "";
		while (true)
		{
			std::cout << "\n\t\tTrying: " << left_try << "\n\t\tEnter password: ";
			for (int i = 0; i < password.size(); i++) std::cout << char(249);
			
			key = _getch();

			if (key == 13) break;
			else if (key == 8) password = password.substr(0, password.size() - 1);
			else password += char(key);

			system("cls");
		}

		if (password == check_user.password) {
			activeUser = check_user;
			break;
		}

		left_try--;
		if (left_try <= 0) return false;
		system("cls");
		std::cout << "\n\n\t\tPasswort incorect";
	} while (true);


	std::cout << "you login";
	return true;
}



bool forAdmin() {
	char sel;
	int first, second, out;
	while (true)
	{
		cout << "Calculator \n 1 Enter: + - / * l: ";
		cin >> sel;

		cout << "Enter first num: ";
		cin >> first;
		cout << "Enter second num: ";
		cin >> second;

		switch (sel)
		{
		case '+': out = first + second; break;
		case '-': out = first - second; break;
		case '/': out = first / second; break;
		case '*': out = first * second; break;
		case 'l': return true;

		default: cout << "Error select!\n"; continue;

		}
		cout << "\n" << first << " " << sel << " " << first << " = " << out << "\n\n";
		system("pause");
		system("cls");

	}
}

bool forNormal() {
	char sel;
	int first, second, out;
	while (true)
	{
		cout << "Calculator \n 1 Enter: + - l : ";
		cin >> sel;

		cout << "Enter first num: ";
		cin >> first;
		cout << "Enter second num: ";
		cin >> second;

		switch (sel) {
			case '+': out = first + second; break;
			case '-': out = first - second; break;
			case 'l': return true;

			default: cout << "Error select!\n"; continue;

		}
		cout << "\n" << first << " " << sel << " " << first << " = " << out << "\n\n";
		system("pause");
		system("cls");

	}
}

bool forNoobs() {
	char sel;
	int first, second, out;
	while (true)
	{
		cout << "Calculator \n 1 Enter: + l : ";
		cin >> sel;

		cout << "Enter first num: ";
		cin >> first;
		cout << "Enter second num: ";
		cin >> second;

		switch (sel) {
			case '+': out = first + second; break;
			case 'l': return true;
			default: cout << "Error select!\n"; continue;
		}
		cout << "\n" << first << " " << sel << " " << first << " = " << out << "\n\n";
		system("pause");
		system("cls");

	}
}




int main() {
	const string PATH_DB = "db.txt";
	std::ifstream file(PATH_DB);

	if (!file.good()) {
		std::cout << "File not exist\nCreate file..";
		std::ofstream file(PATH_DB);
		file << "file txt" << std::endl;
	}



	string buffer;

	getline(file, buffer);




	int usersSize = stoi(buffer);
	User* users = new User[usersSize];

	for (int i = 0; i < usersSize; i++) {
		getline(file, buffer);
		users[i] = parse_user(buffer);
	}

	User userActive;




	if (!login(users, usersSize, userActive))  return 0; 



	system("cls");
	cout << "\tYou login!\n\tYour name: " << userActive.login <<"\n\tYour group: " << userActive.group << "\n\n";





	

	while (true)
	{
		switch (userActive.group) {
		case 0: forAdmin(); break;
		case 1: forNormal(); break;
		case 2: forNoobs(); break;
		}
		system("cls");
		login(users, usersSize, userActive);
	}


	system("pause");
	return 0;
}