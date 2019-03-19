#include <iostream>
#include <ctime>
using namespace std;

void print(int **arr, int *col, int *row) {
	for (int i = 0; i < *row; i++){
		for (int x = 0; x < *col; x++) cout << arr[i][x] << " ";
		cout << "\n";
	}
}
void fill(int **arr, int *col, int *row) {
	for (int i = 0; i < *row; i++){
		for (int x = 0; x < *col; x++) arr[i][x] = (rand() % 90) + 10;
		cout << "\n";
	}
}

int** add_col(int **arr, int *col, int *row, int index = -1) {
	int **new_arr = new int*[*row];

	for (int i = 0; i < *row; ++i)
		new_arr[i] = new int[*col + 1];


	if (index == -1) {
		for (int i = 0; i < *row; i++)
			for (int s = 0; s < *col; s++)
				new_arr[i][s] = arr[i][s];

		for (int d = 0; d < *row; d++)
			new_arr[d][*col] = (rand() % 90) + 10;

	} else {

		int iter = 0;

		for (int i = 0; i < *col + 1; i++){
			if (i == index) {
				for (int s = 0; s < *row; s++) new_arr[s][i] = (rand() % 90) + 10;
				iter--;
			} else {
				for (int s = 0; s < *row; s++) new_arr[s][i] = arr[s][iter];
			}
			iter++;
		}
	}

	for (int i = 0; i < *row; ++i) {
		delete[] arr[i];
	}
	delete[] arr;

	*col += 1;
	return new_arr;
}


int** add_row(int **arr, int *col, int *row, int index  = -1) {
	int **new_arr = new int*[*row + 1];

	for (int i = 0; i < *row + 1; ++i)
		new_arr[i] = new int[*col];

	
	if (index == -1) {
		for (int i = 0; i < *row; i++)
			for (int s = 0; s < *col; s++)
				new_arr[i][s] = arr[i][s];

		for (int d = 0; d < *col; d++)
			new_arr[*row][d] = (rand() % 90) + 10;
	}
	else {
		int iter = 0;
		for (int i = 0; i < *row + 1; i++) {
			if (i == index) {
				for (int s = 0; s < *col; s++) new_arr[i][s] = (rand() % 90) + 10;
				iter--;
			}
			else {
				for (int s = 0; s < *col; s++) new_arr[i][s] = arr[iter][s];
			}
			iter++;
		}
	}	
	for (int i = 0; i < *row; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
	
	*row += 1;
	return new_arr;
}

int** del_col(int **arr, int *col, int *row, int index) {
	int **new_arr = new int*[*row];
	for (int i = 0; i < *row; ++i)
		new_arr[i] = new int[*col - 1];

	int iter = 0;

	
	for (int i = 0; i < *col; i++) {
		if (i == index) iter--;
		else for (int d = 0; d < *row; d++) new_arr[d][iter] = arr[d][i];
		iter++;
	}

	*col -= 1;
	for (int i = 0; i < *row; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
	return new_arr;
}


int** del_row(int **arr, int *col, int *row, int index) {
	int **new_arr = new int*[*row - 1];
	for (int i = 0; i < *row - 1; ++i)
		new_arr[i] = new int[*col];

	int iter = 0;

	for (int i = 0; i < *row; i++) {
		if (i == index) iter--;
		else for (int d = 0; d < *col; d++) new_arr[iter][d] = arr[i][d];
		iter++;
	}

	*row -= 1;
	for (int i = 0; i < *row; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
	return new_arr;
}


int main() {
	int index;
	int *col = new int;
	int *row = new int;

	cout << "\n\tEnter row: ";
	cin >> *row;
	cout << "\n\tEnter col: ";
	cin >> *col;

	int **arr = new int*[*row];
	for (int i = 0; i < *row; ++i) arr[i] = new int[*col];
	
	while (true){
		int cmd;
		system("cls");
		print(arr, col, row);
		cout << "\n\n1 Fill    2 Add row \n3 Add col 4 Del row\n5 Del col 0 Exit \t> ";
		cin >> cmd;

		switch (cmd){
		case 1:
			fill(arr, col, row);
			break;
		case 2:
			cout << "\n\tEnter index (-1 for last): ";
			cin >> index;
			
			arr = add_row(arr, col, row, index);
			break;
		case 3:
			cout << "\n\tEnter index (-1 for last): ";
			cin >> index;
	
			arr = add_col(arr, col, row, index);
			break;
		case 4:
			cout << "\n\t\tEenter index: ";
			cin >> index;
			
			arr = del_row(arr, col, row, index);
			break;
		case 5:
			cout << "\n\t\tEnter index: ";
			cin >> index;
		
			arr = del_col(arr, col, row, index);
			break;

		case 0:
			return 0;
		default:
			cout << "Error commend!";
			break;
		}
	}


	system("pause");
	return 0;
}