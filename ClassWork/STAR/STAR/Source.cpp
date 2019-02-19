#include <iostream>
#include <string>

using namespace std;


string names[50][2] = {
	{"mobile one", "1000"},
	{"Apple 1x",   "1231"},
	{"samsung oneS", "4324"},
	{"OnePlus 4",  "6541"},
	{"Huawei 3s",  "6546"},
	{"Xioami mi 3a", "2600"},
	{"Oppo 3g",     "2400"},
	{"rezor phone", "888800"},
	{"Fly 3000",  "87000"},
	{"Meizu 7",   "760"},
	{"Apple 5s ",  "650"},
	{"Apple 5 ",   "540"},
	{"Samsung Note", "4320"},
	{"Samsung 9s",   "23400"},
	{"Samsung 8",   "4230"},
	{"Xioami a3 lite", "42300"},
	{"Xioami mi 4",  "24300"},
	{"Xioami mix 2", "423"},
	{"Redmi note 7", "423"},
	{"Xioami mi 9 lite one", "43200"},
	{"Apple XS",     "43200"},
	{"Apple SS",     "42300"},
	{"Oppo r3 pro", "423000"},
	{"Oppo r3",      "34200"},
	{"Rezor phone 2", "2430"},
	{"Meizu 6 lite", "10020"},
	{"Meizu 5",      "30"},
	{"Meizu 5 lite", "5300"},
	{"Oppo p10",     "5430"},
	{"Oppo p20",     "1200"},
	{"Noname Phone", "15400"},

};

//
//bool check(string se, string name) {
//
//	for (int i = 0; i < 10; i++)
//	{
//		if (se = )
//	}
//
//
//}

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