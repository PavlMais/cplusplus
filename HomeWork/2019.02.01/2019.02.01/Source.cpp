#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

int getRating() {
	int rating;
	cout << "\n\tYour rating: ";
	cin >> rating;
	return rating;
}
int getRatingBot(int index) {
	int rating = rand() % 10;
	cout << "\n\tBot " << index << " rating: " << rating;
	return rating;
}
int getAvg(int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) sum += arr[i];
	return sum / 4;
}
void TASK1() {
	int avg[3] = {};
	int rating[4] = {};
	int rating1[4] = {};
	int rating2[4] = {};
	cout << "\n\n\tArtist 1\n\n";
	rating[0] = getRating();
	rating[1] = getRatingBot(1);
	rating[2] = getRatingBot(2);
	rating[3] = getRatingBot(3);
	cout << "\n\n\tArtist 2\n\n";
	rating1[0] = getRating();
	rating1[1] = getRatingBot(1);
	rating1[2] = getRatingBot(2);
	rating1[3] = getRatingBot(3);
	cout << "\n\n\tArtist 3\n\n";
	rating2[0] = getRating();
	rating2[1] = getRatingBot(1);
	rating2[2] = getRatingBot(2);
	rating2[3] = getRatingBot(3);


	avg[0] = getAvg(rating, 4);
	cout << "\n\tTotal:\n\n\tArtist 1: " << avg[0];

	avg[1] = getAvg(rating1, 4);
	cout << "\n\tArtist 2: " << avg[1];

	avg[2] = getAvg(rating2, 4);
	cout << "\n\tArtist 3: " << avg[2];

	if      (avg[0] >= avg[1] && avg[0] >= avg[2]) cout << "\n\n\tWin artist 1\n\n\n";
	else if (avg[1] >= avg[0] && avg[1] >= avg[2]) cout << "\n\n\tWin artist 2\n\n\n";
	else if (avg[2] >= avg[1] && avg[2] >= avg[0]) cout << "\n\n\tWin artist 3\n\n\n";
}




void RockPaperScissors() {
	int score = 0;
	int AI = 0;
	int US = 0;

	AI = rand() % 4	;
	cout << AI << " SELECT";
	cout << "\nRaund 1\n\n\tAi selected!\n\t1 Paper 2 Scissors 3 Rock\n\n\tYou select:";
	cin >> US;
	if (AI == 1 && US == 2 || AI == 2 && US == 3 || AI == 3 && US == 1) { cout << "\n\n\tYou WIN!"; score++; }
	else if (AI == 1 && US == 1 || AI == 2 && US == 2 || AI == 3 && US == 3) cout  << "\n\n\tDraw";
	else cout << "\n\n\tAI WIN!";

	AI = rand() % 4;
	cout << AI << " SELECT";
	cout << "\nRaund 2\n\n\tAi selected!\n\t1 Paper 2 Scissors 3 Rock\n\n\tYou select:";
	cin >> US;
	if (AI == 1 && US == 2 || AI == 2 && US == 3 || AI == 3 && US == 1) { cout << "\n\n\tYou WIN!"; score++; }
	else if (AI == 1 && US == 1 || AI == 2 && US == 2 || AI == 3 && US == 3) cout << "\n\n\tDraw";
	else cout << "\n\n\tAI WIN!";

	AI = rand() % 4;
	cout << AI << " SELECT";
	cout << "\nRaund 3\n\n\tAi selected!\n\t1 Paper 2 Scissors 3 Rock\n\n\tYou select:";
	cin >> US;
	if (AI == 1 && US == 2 || AI == 2 && US == 3 || AI == 3 && US == 1) { cout << "\n\n\tYou WIN!"; score++; }
	else if (AI == 1 && US == 1 || AI == 2 && US == 2 || AI == 3 && US == 3) cout << "\n\n\tDraw";
	else cout << "\n\n\tAI WIN!";
	
}

int main() {
	srand(time(0));




	//1. На шоу Пошук Зірок судді кожному учаснику виставляють оцінку від 0 до 10(оцінка може бути дробовим числом). 
	//Знайти підсумкову оцінку кожного учасника, яка обчислюється як середнє арифметичне, але без врахування найкращої та
	//	найгіршої оцінок.Виконати задачу з розбиттям на функції.
	TASK1();






	//=================================================================================
	/*2. Rock, Paper, Scissors Game.Write a program that lets the user play the game of Rock, Paper, Scissors against the computer.The program should work as follows.
		1. When the program begins, a random number in the range of 1 through 3 is generated.If the number is 1, then the computer has chosen rock.If the number is 2,
		then the computer has chosen paper.If the number is 3, then the computer has chosen scissors. (Don’t display the computer’s choice yet.)
		2. The user enters his or her choice of rock, paper, or scissors at the keyboard.
		(You can use a menu if you prefer.)
		3. The computer’s choice is displayed.
		4. A winner is selected according to the following rules :
		If one player chooses rock and the other player chooses scissors, then rock
		wins. (The rock smashes the scissors.)
			If one player chooses scissors and the other player chooses paper, then scissors
		wins. (Scissors cuts paper.)
			If one player chooses paper and the other player chooses rock, then paper wins. (Paper wraps rock.)*/

	RockPaperScissors();




	system("pause");
	return 0;
}




