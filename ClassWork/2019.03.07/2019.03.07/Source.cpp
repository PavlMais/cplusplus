#include <iostream>
#include <string>



std::string *names;
float *marks;
int size;
int const PRDM = 5;




void fillmarks() {
	int buf_mark;
	for (int i = 0; i < size; i++){
		std::cout << "Enter student name: ";
		std::cin >> names[i];
		float sum = 0;
		std::cout << "Enter 3 mark (1 - 12)\n";
		for (int s = 0; s < 3; s++){
			std::cout << "\nMark " << s + 1 << " : ";

			std::cin >> buf_mark;
			while (buf_mark > 12 || buf_mark < 1) {
				std::cout << "\n   1 - 12 Please";
				std::cout << "\nMark " << s + 1 << " : ";

				std::cin >> buf_mark;

			}
			marks[i * PRDM + s] = buf_mark;

			sum += marks[i * PRDM + s];
		}
		marks[i * PRDM + 3] = sum / 3;
		if (marks[i * PRDM + 3] > 10.7) marks[i * PRDM + 4] = 1;
		else marks[i * PRDM + 4] = 0;
		
	}
}

void print() {

	std::cout << "ID  Name    Phys Math Engl AVG Stupedia";
	for (int i = 0; i < size; i++){
		std::cout << "\n" << i << " " << names[i];
		for (int s = 0; s < 5; s++){

			std::cout << "    " << marks[i * PRDM + s];
		}
	}
}

void retake() {
	int stud_id, thing_id, mark, sum = 0; 

	std::cout << "Enter student id: ";
	std::cin >> stud_id;
	std::cout << "\n0 Phys  1 Math  2 Engl\nEnter predmet id: ";
	std::cin >> thing_id;

	std::cout << "Enter new mark: ";
	std::cin >> mark;
	
	while (mark > 12 || mark < 1) {
		std::cout << "\n   1 - 12 Please";
		std::cout << "Enter new mark: ";
		std::cin >> mark;
	}
	


	marks[stud_id * PRDM + thing_id] = mark;

	for (int s = 0; s < 3; s++) sum += marks[stud_id * PRDM + s];
	

	marks[stud_id * PRDM + 3] = sum / 3;
	if (marks[stud_id * PRDM + 3] > 10.7) marks[stud_id * PRDM + 4] = 1;
	else marks[stud_id * PRDM + 4] = 0;

}



void printSort(int key = 0) {
	int max = 0;
	int max_id = 0;
	bool noCheck;
	int *cheched = new int[size];

	
	std::cout << "ID  Name    Phys Math Engl AVG Stupedia";

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			noCheck = true;
			for (int s = 0; s < size; s++)
			{
				if (cheched[s] == j) noCheck = false;
			}


			if (marks[j * PRDM + key] > max && noCheck) {

				max = marks[j * PRDM + key];
			}
		}


		cheched[i] = max_id;
		


		std::cout << "\n" << max_id << " " << names[max_id];
		for (int s = 0; s < PRDM; s++) {
			std::cout << "    " << marks[max_id * PRDM + s];
		}

	}



	
	



}


int main() {
	int cmd, arg;
	std::cout << "Enter count all students: ";
	std::cin >> size;
	
	names = new std::string[size];
	marks = new float[size * 5];
	

	fillmarks();
	print();




	while (true){
	std::cout << "\n\nMenu: 1 print  2 Retake  3 Sort(Bad work)  4 Exit\n > ";
	std::cin >> cmd;
		switch (cmd){

		case 1:
			print();
			break;
		case 2:
			retake();
			print();

			break;
		case 3:
			printSort(0);
			break;

		case 4:
			return 0;

		default:
			break;
		}

	}












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