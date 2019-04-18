#include <iostream>
#include <string>
#include <ctime>
using namespace std;


//Дана строка символов.Признак конца строки — символ 'n' (переход на новую строку).
//Строка состоит из слов, которые отделены друг от друга пробелами. Вывести самое длинное слово и его порядковый номер.
void getLongWord(string str) {
	int maxLen = 0, ids = 0;
	for (int i = 0, id = 0, buf = 0; str[i] != '\n'; i++){
		if (str[i] != ' ') buf++;
		else {
			if (maxLen < buf) {
				maxLen = buf;
				ids = id;
			}
			buf = 0;
			id++;
		}
	}

	cout << "Index: " << ids << "\nWord: ";

	
	for (int i = 0, ix = 0; str[i] != '\n'; i++){
		if (str[i] != ' ' && ix == ids) cout << str[i];
		else if (str[i] == ' ') ix++;
	}
}


//Дана строка символов, которая обязательно заканчивается символом точки.Удалить из строки первые буквы каждого слова.
void delFirstSymbol(string str) {
	string nstr(str.size(), ' ');

	for (int i = 1; str[i] != '.'; i++) if (str[i - 1] != ' ') nstr[i] = str[i];
	

	cout << "String: " << nstr;
}


//Дан массив размера n, заполнить его случайными числами, Найти все нечётные числа массива.
void fillArr() {
	const int SIZE = 10;
	int *arr = new int[SIZE];

	for (int i = 0; i < SIZE; i++) arr[i] = rand() % 20;

	for (int i = 0; i < SIZE; i++) if (arr[i] % 2 != 0) cout << " " << arr[i];
		
}


//Составить программу, которая будет генерировать случайные числа в интервале[a; b] и заполнять ими двумерный массив размером 10 на 10.
//В массиве необходимо найти номер строки с минимальным элементом.Поменять строки массива местами, строку с минимальным элементом и первую строку массива.Организовать удобный вывод на экран.
void print(int **arr, int col, int row) {
	for (int i = 0; i < row; i++) {
		for (int x = 0; x < col; x++) cout << arr[i][x] << " ";
		cout << "\n";
	}
}
void fill(int **arr, int col, int row) {
	for (int i = 0; i < row; i++) {
		for (int x = 0; x < col; x++) arr[i][x] = (rand() % 50) + 10;
		cout << "\n";
	}
}
void fillFindSwap3dArr() {
	int const X = 10;
	int const Y = 10;
	
	int maxFill  = 50;

	int **arr = new int*[X];
	for (int i = 0; i < X; ++i) arr[i] = new int[Y];

	fill(arr, X, Y);
	print(arr, X, Y);
 
	int min = maxFill;
	int rowMin = 0;

	for (int i = 0; i < X; i++)
		for (int x = 0; x < Y; x++) if (arr[i][x] < min) { rowMin = i; min = arr[i][x]; }


	cout << "Min: " << min;
	cout << "Row min: " << rowMin;

	int buffer;
	for (int i = 0; i < Y; i++){
		buffer = arr[rowMin][i];
		arr[rowMin][i] = arr[0][i];
		arr[0][i] =  buffer;
	}
		
	cout << "\n\n";
	print(arr, X, Y);
}


//Задача на динамическое выделение памяти.Изначально есть указатель на массив с одним элементом.
//Пользователь вводит число.Если оно больше 0 записываем его в массив.
//Далее пользователь вводит второе число, тут уже, если оно больше 0, надо пере выделять память для 2 - х элементов массива и записать в массив второе число.И так далее…
//для 3 - х элементов, для 4 - х…  пока пользователь не введет отрицательное число.
void NoName() {
	int *size = (int*)malloc(sizeof(int));
	*size = 0;
	int *arr = (int*)calloc(*size, sizeof(int));
	int buff;
	while (true){
		system("cls");
		cout << "\nArr: ";
		for (int i = 0; i < *size; i++) cout << " " << arr[i];
		
		cout << "\nEnter new item (or 0 for exit): ";
		cin >> buff;
		if (buff <= 0) return;

		*size += 1;
		arr = (int*)realloc(arr, *size * sizeof(int));
		arr[*size - 1] = buff;
	}
}



//Составить программу - тест  на экране по очереди появляются вопросы(вопросы выбираются программистом), с вариантами ответов.В конце работы программа выдает количество заработанных баллов по результатам ответа.
struct Question {
	string title;
	string answers[4];
	int trueAnswer;
};
void testMe() {
	Question question[5];

	question[0].title = "What is the most restrictive access modifier that will allow members of one class to have access to members of another class in the same package ? ";
	question[0].answers[0] = "public";
	question[0].answers[1] = "abstract";
	question[0].answers[2] = "protected";
	question[0].answers[3] = "synchronized";
	question[0].trueAnswer = 2;


	question[1].title = "You want a class to have access to members of another class in the same package.Which is the most restrictive access that accomplishes this objective ? ";
	question[1].answers[0] = "default access";
	question[1].answers[1] = "abstract";
	question[1].answers[2] = "protected";
	question[1].answers[3] = "synchronized";
	question[1].trueAnswer = 1;


	question[2].title = "Which collection class allows you to grow or shrink its size and provides indexed access to its elements, but whose methods are not synchronized?";
	question[2].answers[0] = "java.util.HashSet";
	question[2].answers[1] = "java.util.LinkedHashSet";
	question[2].answers[2] = "java.util.List";
	question[2].answers[3] = "java.util.ArrayList";
	question[2].trueAnswer = 1;



	int result = 0, sel;


	for (int i = 0; i < 3; i++){
		cout << "\n\nQuestion "<<i + 1<<": " << question[i].title << "\n\n";
		for (int s = 0; s < 3; s++)
			cout << s<< " Answer: " << question[i].answers[s] << "\n";
		
		cout << "Enter answer num: ";
		cin >> sel;
		if (sel == question[i].trueAnswer) result++;
	}
	cout << "\n\n\tResult correct: " << result;
	cout << "\n\n\n\n\n";
}






int main() {
	srand(unsigned(time(0)));
	cout << "\t\tTest\n\n";
	testMe();
	cout << "\n\n\n\t\tDynamic memory allocation\n\n";

	NoName();
	cout << "\n\n\n\t\t3D array \n\n";

	fillFindSwap3dArr();
	cout << "\n\n\n\t\t2D array \n\n";

	fillArr();
	cout << "\n\n\n\t\tdelete fisrt symbol from words\n\n";

	delFirstSymbol("The string test deleted.");
	cout << "\n\n\n\t\tFind long word\n\n";

	getLongWord("The basic idea here is to add each character to text\n");




	system("pause");
	return 0;
}