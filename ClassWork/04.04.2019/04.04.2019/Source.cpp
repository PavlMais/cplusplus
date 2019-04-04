#include <iostream>
#include <fstream>

#include <string>

using namespace std;

const string PATH_FILE = "file.txt";


void readFile() {

	ifstream file;

	file.open(PATH_FILE);

	system("cls");

	if (!file.is_open()) {
		cout << "File not exist!";
		return;
	}

	cout << "\t\tFile: \n";
	string str;
	while (getline(file, str)) cout <<"\t" <<  str << endl;


	file.close();
}

void writeFile() {

	ofstream file;

	file.open(PATH_FILE, ofstream::app);

	cout << "\nEnter text: ";


	string str;

	getline(cin, str);
	
	
	file << str << endl;

	file.close();

}



int main() {
	string sel;
	while (true)
	{
		readFile();
		cout << "Enter 1 for new: ";

		getline(cin, sel);

		if (sel == "1") {
			writeFile();

		}




	}





	system("pause");

	return 0;
}