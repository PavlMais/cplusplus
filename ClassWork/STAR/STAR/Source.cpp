#include <iostream>
#include <string>

using namespace std;

// Предметна область - спеціалізований магазин із продажу аудіо - , відеотехніки і деталей до них.
// Розв'язувані задачі: облік товарів. Реалізувати наступні сервіси: 
// Заповнення бази даних
// Перегляд даних про всі товари
// Доповнення бази даних товаром
// Видалення товару із бази даних
// Редагування запису про певний товар
// Упорядкування по полях : назва товару, ціна товару
// Пошук : наприклад, фірма ХХ і все, що з нею зв'язане; магнітофони УУ 
//  Вибірка : товари певного типу за ціною від X до Y
//	Обчислення : середня ціна на товари певного типу(наприклад, телевізори)
//	Корекція : видалення зведень про вказані товари; зміна ціни на товари вказаного типу(наприклад, телевізори фірми SONY на 5 % )
//	Табличний звіт : інформація про телевізори(марка, ціна, назва), впорядкування по полю “назва”
//	Додаткові вимоги : перевірка на введення ціни товару(повинна бути більше 0 грн.).

string names[50][3] = {
	{"mobile one", "1000", "mobile"},
	{"Apple 1x",   "1231", "Apple"},
	{"samsung oneS", "4324", "Samsung"},
	{"OnePlus 4",  "6541", "OnePlus"},
	{"Huawei 3s",  "6546", "Huawei"},
	{"Xioami mi 3a", "2600", "Xioami"},
	{"Oppo 3g",     "2400", "Oppo"},
	{"rezor phone", "888800", "Resor"},
	{"Fly 3000",  "87000", "Fly"},
	{"Meizu 7",   "760", "Meizu"},
	{"Apple 5s ",  "650", "Apple"},
	{"Apple 5 ",   "540", "Apple"},
	{"Samsung Note", "4320", "Samsung"},
	{"Samsung 9s",   "23400", "Saamsung"},
	{"Samsung 8",   "4230", "Saamsung"},
	{"Xioami a3 lite", "42300", "Xioami"},
	{"Xioami mi 4",  "24300", "Xioami"},
	{"Xioami mix 2", "423", "Xioami"},
	{"Redmi note 7", "423"},
	{"Xioami mi 9 lite one", "43200", "Xioami"},
	{"Apple XS",     "43200", "Apple"},
	{"Apple SS",     "42300", "Apple"},
	{"Oppo r3 pro", "423000", "Oppo"},
	{"Oppo r3",      "34200", "Oppo"},
	{"Rezor phone 2", "2430", "Rezor"},
	{"Meizu 6 lite", "10020", "Meizu"},
	{"Meizu 5",      "30", "Meizu"},
	{"Meizu 5 lite", "5300", "Meizu"},
	{"Oppo p10",     "5430", "Oppo"},
	{"Oppo p20",     "1200", "Oppo"},
	{"Noname Phone", "15400", "NoName"},

};


int check(string se, string name) {

	for (int i = 0; i < 10; i++)
	{
		if (se = )
	}


}

int main() {

	
	string cmd, searc;
	cout << "all ";
	cin >> cmd;
	
	cout << cmd[0] + cmd[2];


	if (cmd == "all") {
		cout << "N  Name \t\t Prise\n";
		for (int i = 0; i < 30; i++)
		{
			cout << i << " " << names[i][0] << " --- " << names[i][1] << endl;
		}
	}
	/*else if (cmd == "serch") {
		cin >> searc;

		for (int i = 0; i < 30; i++)
		{
			if (searc == numes[i])
		}

	}*/






	system("pause");
	return 0;
}