#include <iostream>
#include <string>

using namespace std;



void fillArr(string *data, const int size) {
	int mark1, mark2, mark3, markA;
	cout << "\n\tNOT use space for names!!!\n";
	for (int i = 0; i < size; i++)
	{
		string name, line;
		
		cout << "\tStudent "<< i + 1 <<" name: ";
		cin >> name;
		cout << "\n\tEnter mark 1: ";
		cin >> mark1;
		cout << "\tEnter mark 2: ";
		cin >> mark2;
		cout << "\tEnter mark 3: ";
		cin >> mark3;
		
		markA = (mark1 + mark2 + mark3) / 3;


		line += (mark1 < 10) ? "0" + to_string(mark1) : to_string(mark1);
		line += (mark2 < 10) ? "0" + to_string(mark2) : to_string(mark2);
		line += (mark3 < 10) ? "0" + to_string(mark3) : to_string(mark3);
		line += (markA < 10) ? "0" + to_string(markA) : to_string(markA);

		line += name;

		data[i] = line;
		
		
		
	}
}

void printSort(string *data, int const size) {
	cout << "\nN Name    Matem  Fizuk  Englis   AVG";
	for (int i = 0; i < size; i++){

		cout << "\n" << i + 1 << " " << data[i].substr(8) << "\t\t" << data[i][0]<<data[i][1] << "\t" <<
		data[i][2] << data[i][3] << "\t" << data[i][4] << data[i][5] << "\t" << data[i][6] << data[i][7];
	}
}

void reset(string *data, int const size) {
	string user_name, str_mark;
	int predmet, new_mark, user_id = -1;
	
	do{
		user_name = "";
		cout << "\n\tEnter user name: ";
		cin >> user_name;



		for (int i = 0; i < size; i++)
			if (data[i].substr(8) == user_name) user_id = i;

		if (user_id == -1) cout << "\n\tUser name invalid!";
		
	} while (user_id == -1);
		
	do{
		cout << "\n\tEnter predmet id: ";
		cin >> predmet;
		
	} while (0 > predmet > 4);

	
	cout << "\n\tEnter new mark: ";
	cin >> new_mark;
	str_mark = (new_mark < 10) ? "0" + to_string(new_mark) : to_string(new_mark);

	switch (predmet){
	case 1:

		data[user_id] = str_mark + data[user_id].substr(3);

		break;
	case 2:
		break;
	case 3:
		break;
	default:
		cout << "\n\tNo predmet " << predmet;
		break;
	}

}
int main() {
	

	



	int size, select;
	cout << "\n\n\tEnter count students: ";
	cin >> size;
	
	string *data = new string[size];

	
	fillArr(data,  size);
	printSort(data, size);



	while (true)
	{
		cout << "\t1 Perezdacha\n";
		cin >> select;
		switch (select) {
		case 1:
			reset(data, size);

			break;
		



		}
	}
	

	cout << "\n\n";
	system("pause");
	return 0;
}



//  Написать программу «успеваемость».Пользователь вводит три оценки для каждого ученика.
//	Оценки с физики, математики и англ.языка.Средний бал записываем в масив средних баллов.В результате должно быть 10 средних баллов.
//	Реализовать меню для пользователя.Отсортировать тот массив, информация по котором нам сейчас нужна.
//	Связность оценок должна соблюдаться.Тоесть если math[0] = 5 и engl[0] = 8 то после сортировки массива с оценками за математику, 
//	массивы других оценок так же должны поменяться.
//	Вывод оценок(вывод содержимого массива)
//	Пересдача экзамена(пользователь вводит номер элемента массива и новую оценку)
//	Выходит ли стипендия(стипендия выходит, если средний бал не ниже 10.7)
//	Вывести все оценки самого успешного ученика по английскому языку.
//	Вывести все оценки самого неуспешного ученика в классе
//	Вывести все оценки самого успешного ученика с точных наук(физика и математика).