#include <iostream>

using namespace std;

template<typename T>
void fillArray(T arr[],int *SIZE) {
	for (int i = 0; i < *SIZE; i++) arr[i] = rand() % 10;
}


void printArray(int *arr, int *SIZE) {
	cout << "\nArray: ";
	for (int i = 0; i < *SIZE; i++) cout << arr[i] << " ";
}


int *append(int *arr, int *size, int num) {
	int *new_arr = new int[*size + 1];
	for (int i = 0; i < *size; i++) new_arr[i] = arr[i];
	new_arr[*size] = num;
	*size+=1;
	delete [] arr;
	return new_arr;
}

int *append_indx(int *arr, int *size, int num, int index) {
	int *new_arr = new int[*size + 1];
	int iter = 0;
	*size += 1;
	for (int i = 0; i < *size; i++) {
		if (i == index) {
			new_arr[i] = num;
			iter--;

		}
		else {
			new_arr[i] = arr[iter];
		}
		iter++;
	}
	delete[] arr;

	return new_arr;
}


int *del_indx(int *arr, int *size, int index) {
	int *new_arr = new int[*size - 1];
	int iter = 0;
	for (int i = 0; i < *size; i++) {
		if v(i == index) iter--;
		else new_arr[iter] = arr[i];
		iter++;
	}
	*size -= 1;
	delete[] arr;

	return new_arr;
}



int main() {
	int *size = new int;
	int num, index, cmd;
	cout << "Enter size: ";
	cin >> *size;


	int *arr = new int[*size];


	fillArray(arr, size);

	printArray(arr, size);
	

	while (true)
	{

		cout << "\n1 add 2 add_index 3 del: ";
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			cout << "\nenter new item: ";
			cin >> num;
			cout << "Adree: " << arr;
			arr = append(arr, size, num);
			cout << "\nAdree: " << arr;

			printArray(arr, size);
			break;
		case 2:
			cout << "\nenetr idex: ";
			cin >> index;
			cout << "enter num: ";
			cin >> num;

			arr = append_indx(arr, size, num, index);
			printArray(arr, size);
			break;
		case 3:
			cout << "\nenetr idex: ";
			cin >> index;
			
			arr = del_indx(arr, size, index);
			printArray(arr, size);

			break;
	
		case 0:
			return 0;
		default:
			break;
		}


		

		
	}

	system("pause");
	return 0;
}