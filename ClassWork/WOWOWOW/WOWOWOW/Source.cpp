//Home work 
//MazeGame v 1.0
//Creator: Pavlo Maistruk telegram: http://t.me/pavlmais
//Created: 12.01.2018~

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <string>
using namespace std;


void render(int map[100][100], int map_size_x, int map_size_y, int u_pos_x, int u_pos_y) {
	string rend = "";
	for (int x = 0; x < map_size_x; x++) {
		for (int y = -1; y < map_size_y; y++) {
			if (y == -1) if (x == 1) rend += "Start ->"; else rend += "\t";
			else if (map[x][y] == 1 || map[x][y] == 2) rend += char(178);
			else if (u_pos_x == x && u_pos_y == y) rend += "@";
			else rend += " ";
			if (x == 3 && y == map_size_y - 1) rend += "\t       Help";
			else if (x == 4 && y == map_size_y - 1) rend += "\t    @    - You";
			else if (x == 5 && y == map_size_y - 1) rend += "\t W,A,S,D - move";
			else if (x == 6 && y == map_size_y - 1) rend += "\t   ESC   - Exit";
			else if (x == map_size_x - 2 && y == map_size_y - 1) rend += " < - Exit";
		}
		rend += "\n";
	}
	system("cls");
	cout << rend;
}

void game(int g_difficulty, int theme, int mode_load) {
	const int MAP_SIZE_MAX = 100;
	int map[MAP_SIZE_MAX][MAP_SIZE_MAX] = {};
	int MAP_SIZE_X, MAP_SIZE_Y;
	int u_pos_x = 1, u_pos_y = 1; // for user
	int pos_x = 1, pos_y = 1; // for generator
	float need_cheked;
	float checed = 1;
	int last_curs = 5;
	int key_presed = 0;

	system("cls");
	cout << "Generate maze...";

	if (g_difficulty == 1) { // set map size 
		need_cheked = 100;
		MAP_SIZE_X = 21;
		MAP_SIZE_Y = 21;
	}
	else if (g_difficulty == 2) {
		need_cheked = 196;
		MAP_SIZE_X = 29;
		MAP_SIZE_Y = 29;
	}
	else if (g_difficulty == 3) {
		need_cheked = 406;
		MAP_SIZE_X = 29;
		MAP_SIZE_Y = 59;
	}

	// ========== Create map ==========
	// 0 empty
	// 1 box border
	// 2 border 
	// 3 cheked
	// 4 output
	// 5 YOU

	for (int x = 0; x < MAP_SIZE_X; x++) {
		for (int y = 0; y < MAP_SIZE_Y; y++) {
			if (x == 0 || y == 0 || x == MAP_SIZE_X - 1 || y == MAP_SIZE_Y - 1) map[x][y] = 1;
			else if (x % 2 == 0 || y % 2 == 0) map[x][y] = 2;
		}
	}
	map[1][1] = 3;

	// ============ Generate maze =============
	while (need_cheked != checed) { // if all checked  stop
		int border[4] = {};
		int curs;

		if (mode_load == 2) render(map, MAP_SIZE_X, MAP_SIZE_Y, u_pos_x, u_pos_y);

		if (map[pos_x - 1][pos_y] != 1) border[0] = 1;// check directions
		if (map[pos_x][pos_y + 1] != 1) border[1] = 1;//
		if (map[pos_x + 1][pos_y] != 1) border[2] = 1;//
		if (map[pos_x][pos_y - 1] != 1) border[3] = 1;//

		curs = rand() % 4;

		while (border[curs] == 0 || last_curs == curs) {
			curs++;
			if (curs > 3) curs = 0;
		}

		if (curs == 0) last_curs = 2;
		else if (curs == 1) last_curs = 3;
		else if (curs == 2) last_curs = 0;
		else if (curs == 3) last_curs = 1;

		switch (curs) {
		case 0:
			pos_x -= 2;
			if (map[pos_x][pos_y] != 3) {
				map[pos_x + 1][pos_y] = 0;
				map[pos_x][pos_y] = 3;
				checed++;
			}
			break;
		case 1:
			pos_y += 2;
			if (map[pos_x][pos_y] != 3) {
				map[pos_x][pos_y - 1] = 0;
				map[pos_x][pos_y] = 3;
				checed++;
			}
			break;
		case 2:
			pos_x += 2;
			if (map[pos_x][pos_y] != 3) {
				map[pos_x - 1][pos_y] = 0;
				map[pos_x][pos_y] = 3;
				checed++;
			}
			break;
		case 3:
			pos_y -= 2;
			if (map[pos_x][pos_y] != 3) {
				map[pos_x][pos_y + 1] = 0;
				map[pos_x][pos_y] = 3;
				checed++;
			}
			break;
		}
	}

	map[MAP_SIZE_X - 2][MAP_SIZE_Y - 1] = 4; // set end point
	map[1][1] = 5;

	// ================ GAME ================
	int start_game_time = time(0);

	while (true) {

		render(map, MAP_SIZE_X, MAP_SIZE_Y, u_pos_x, u_pos_y);

		if (map[u_pos_x][u_pos_y] == 4) {// finish
			system("cls");
			cout << "\n\n\t\tFINISH!!!\n\n\t\t Mode: ";

			if (g_difficulty == 1) cout << "Easy";
			else if (g_difficulty == 2) cout << "Normal";
			else if (g_difficulty == 3) cout << "Hard!";

			cout << "\n\n\t\tTime: " << time(0) - start_game_time << " sec\n\n\t\tKey presed: " << key_presed << "\n\n";
			break;
		}
		key_presed++;
		switch (_getch()) {
		case 119:
			if (map[u_pos_x - 1][u_pos_y] != 1 && map[u_pos_x - 1][u_pos_y] != 2) u_pos_x--;
			break;

		case 100:
			if (map[u_pos_x][u_pos_y + 1] != 1 && map[u_pos_x][u_pos_y + 1] != 2) u_pos_y++;
			break;

		case 115:
			if (map[u_pos_x + 1][u_pos_y] != 1 && map[u_pos_x + 1][u_pos_y] != 2) u_pos_x++;
			break;

		case 97:
			if (map[u_pos_x][u_pos_y - 1] != 1 && map[u_pos_x][u_pos_y - 1] != 2) u_pos_y--;
			break;

		case 27: // esc - exit game
			return;
		}
	}
	system("pause");
}





void main_menu(int g_difficulty, int theme, int mode_load) {
	int menu_select = 1;
	while (true) {
		system("cls");
		if (theme == 1) system("color 07");
		else if (theme == 2) system("color F0");
		else if (theme == 3) system("color 0A");
		cout << "\t\tMazeGame\n\n";
		if (menu_select == 1) cout << "\n\n\n\t    -> Start\n\n\t\tSetting\n\n\t\tAbout\n\n\t\tExit";
		else if (menu_select == 2) cout << "\n\n\n\t\tStart\n\n\t    -> Setting\n\n\t\tAbout\n\n\t\tExit";
		else if (menu_select == 3) cout << "\n\n\n\t\tStart\n\n\t\tSetting\n\n\t    -> About\n\n\t\tExit";
		else if (menu_select == 4) cout << "\n\n\n\t\tStart\n\n\t\tSetting\n\n\t\tAbout\n\n\t   -> Exit";
		cout << "\n\n\n\n        W / S - Up / Down  |  Enter";
		switch (_getch()) {
		case 119:
			menu_select--;
			if (menu_select < 1) menu_select = 4;
			break;
		case 115:
			menu_select++;
			if (menu_select > 4) menu_select = 1;
			break;
		case 13:
			if (menu_select == 1) game(g_difficulty, theme, mode_load);
			else if (menu_select == 2) {
				//===================== menu setting ========================
				int setting_select = 1;
				while (true) {
					system("cls");
					cout << "\t\tMazeGame\n\n      ========= Setting ==========================\n\n       Use W / S - up/down   |  A / S - set param\n\n\n\t";
					if (setting_select == 1) cout << "    -> Difficulty   ";
					else cout << "\tDifficulty   ";

					if (g_difficulty == 1) cout << "[EASY] Narmal Hard";
					else if (g_difficulty == 2) cout << "Easy [NORMAL] Hard";
					else if (g_difficulty == 3) cout << "Easy Narmal [HARD]";


					if (setting_select == 2) cout << "\n\n\t    -> Theme        ";
					else cout << "\n\n\t\tTheme        ";

					if (theme == 1) { cout << "[DARK] White Hacker"; system("color 07"); }
					else if (theme == 2) { cout << "Dark [WHITE] Hacker"; system("color F0"); }
					else if (theme == 3) { cout << "Dark White [HACKER]"; system("color 0A"); }

					if (setting_select == 3) cout << "\n\n\t    -> Mode load    ";
					else cout << "\n\n\t\tMode load    ";

					if (mode_load == 1) cout << "[NORMAL] View-map   <-- select it and start game";
					else cout << "Normal [VIEW-MAP]";

					if (setting_select == 4) cout << "\n\n\t    -> Back ";
					else cout << "\n\n\t\tBack";

					switch (_getch()) {
					case 119:
						setting_select--;
						if (setting_select < 1) setting_select = 4;
						break;
					case 115:
						setting_select++;
						if (setting_select > 4) setting_select = 1;
						break;
					case 97:
						if (setting_select == 1) g_difficulty--;
						else if (setting_select == 2) theme--;
						else if (setting_select == 3) mode_load = 1;
						break;
					case 100:
						if (setting_select == 1) g_difficulty++;
						else if (setting_select == 2) theme++;
						else if (setting_select == 3) mode_load = 2;
						break;
					case 13:
						main_menu(g_difficulty, theme, mode_load);
						break;
					}
					if (g_difficulty < 1) g_difficulty = 3;
					else if (g_difficulty > 3) g_difficulty = 1;
					else if (theme < 1) theme = 3;
					else if (theme > 3) theme = 1;
				}
			}
			else if (menu_select == 3) { //About menu
				system("cls");
				cout << "\t\tMazeGame v 1.0\n\n\tDev: Pavlo Maistruk\n\n\t\n\n\tDate create: 12.01.2019~\n\n\n";
				system("pause");
			}
			else if (menu_select == 4) { // exit game
				int r = 0;
				while (true) {
					system("cls");
					cout << "\t\tMazeGame\n\n\t======= Exit =======?";
					if (r % 2 == 0) cout << "\n\n\t   -> NO\n\n\t\tYes";
					else cout << "\n\n\t\tNo\n\n\t   -> YES";

					switch (_getch()) {
					case 13:
						if (r % 2 == 0) main_menu(g_difficulty, theme, mode_load);
						else exit(1);
					case 119:
					case 115:
						r++;
					}
				}
			}
		}
	}
}



int main() {
	srand(time(0));
	system("mode 100, 30");

	int intro[6][38] = { {1,1,0,1,1,0,1,1,1,1,0,1,1,1,0,1,1,1,0, 1,1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,1,1,1},
						{1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,0, 1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0},
						{1,0,1,0,1,0,1,0,0,1,0,0,1,0,0,1,1,1,0, 1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,1,1},
						{1,0,1,0,1,0,1,1,1,1,0,1,0,0,0,1,0,0,0, 1,0,1,1,0,1,1,1,1,0,1,0,0,0,1,0,1,0,0},
						{1,0,0,0,1,0,1,0,0,1,0,1,1,1,0,1,1,1,0, 1,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,1,1,1},
						{1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };

	// ==================== Intro viewer =================================
	for (int d = -10; d < 38; d++)
	{
		string intr = "\n\n\n\n";

		for (int x = 0; x < 6; x++)
		{
			for (int y = -1; y < 38; y++)
			{
				if (y == -1) intr += "\t\t\t";
				else if (intro[x][y] == 1) {
					if (d - y >= 0) intr += char(178);
					else if (10 + (d - y) >= 0) intr += char(177);
					else if (5 - (d - y) >= 0) intr += char(176);
				}
				else intr += " ";
			}
			intr += "\n";
		}
		system("cls");
		cout << intr;
		Sleep(50);
	}
	Sleep(800);
	cout << "\n\n\n\t\t\t\t\tLoading...";
	Sleep(2000);
	for (int r = 0; r < 2; r++)
	{
		string intr = "\n\n\n\n";
		for (int x = 0; x < 6; x++)
		{
			for (int y = -1; y < 38; y++)
			{
				if (y == -1) intr += "\t\t\t";
				else if (intro[x][y] == 1) {
					if (r == 0) intr += char(177);
					else if (r == 1) intr += char(176);
				}
				else intr += " ";
			}
			intr += "\n";
		}
		system("cls");
		cout << intr;
		Sleep(500);
	}
	system("cls");
	Sleep(500);

	main_menu(1, 1, 1);

	return 0;
}
// 371 lines