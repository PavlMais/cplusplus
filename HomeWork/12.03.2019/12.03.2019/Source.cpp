#include <iostream>

using namespace std;


void fillArray(int arr[], int *SIZE) {
	for (int i = 0; i < *SIZE; i++) arr[i] = (rand() % 60) - 12;
}


void printArray(int *arr, int *SIZE) {
	cout << "\nArray: ";
	for (int i = 0; i < *SIZE; i++) cout << arr[i] << " ";
}

void addNegativeCountToSize(int *arr, int *SIZE) {
	int counter = 0;
	for (int i = 0; i < *SIZE; i++)
		if (arr[i] < 0) counter++;
	*SIZE += counter - 1;
}

int main() {
	int *size = new int;
	*size = 20;


	int *arr = new int[*size];

	fillArray(arr, size);
	printArray(arr, size);


	addNegativeCountToSize(arr, size);

	int *new_arr = new int[*size];

	int iter = 0;
	for (int i = 0; i < *size; i++)
	{
		if (arr[i] < 0) {
			new_arr[i] = arr[iter];

			new_arr[i + 1] = arr[iter] - arr[iter] * 2;
			i++;
		}
		else {
			new_arr[i] = arr[iter];
		}
		iter++;
		
	}
	printArray(new_arr, size);
	*size = *size / 2;

	int *f_arr = new int[*size];
	iter = 0;
	for (int i = 0; i < *size; i++){
		f_arr[i] = new_arr[iter];
		iter += 2;
	}


	printArray(f_arr, size);



	delete[] arr;
	delete[] new_arr;
	delete[] f_arr;


	cout << "\n\n";
	

	system("pause");
	return 0;
}