#include <iostream>
#include <string>

using namespace std;

char countAO(char *str) {
	int coutntA = 0, coutntO = 0;

	for (int i = 0; i < strlen(str); i++){
		if (str[i] == 'a') coutntA++;  // use char code i`m know
		else if (str[i] == 'o') coutntO++;

	}
	if (coutntA > coutntO)
		return 'a';
	else
		return 'o';
}




void counter(char *str) {
	int letters = 0;
	int numbers = 0;
	int symbols = 0;

	for (int i = 0; i < strlen(str); i++){
		
		if (48 < int(str[i]) && int(str[i]) < 57) numbers++;
		else if (65 < int(str[i]) && int(str[i]) < 90 || 97 < int(str[i]) && int(str[i]) < 122) letters++;
		else if (32 < int(str[i]) && int(str[i]) < 47) symbols++;

	}


	cout << "Letters: " << letters << " Numbers: " << numbers << " Symbols: " << symbols;


}



void title(char *str) {
	for (int i = 0; i < strlen(str); i++){
		if (65 < int(str[i]) && int(str[i]) < 90) {
			str[i] = char(int(str[i]) + 32);
		} else if (97 < int(str[i]) && int(str[i]) < 122) {
			str[i] = char(int(str[i]) - 32);
		}
	}
}




void append(char* s, char c) {
	int len = strlen(s);
	s[len] = c;
	s[len + 1] = '\0';
}

char* delLetter(char str[], char letter){
	char new_str[255];
	for (int i = 0; i < strlen(str); i++){
		cout << str[i] << " ";
		if (str[i] != letter) append(new_str, str[i]);

	}
	return new_str;
}


int main() {
	char str[255] = "HeLLo My Name Is";

	delLetter(str, 'L');
	cout << str;




	cout << "\n\n\n";
	system("pause");
	return 0;
}
