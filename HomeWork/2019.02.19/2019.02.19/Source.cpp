#include <iostream>


using namespace std;

// ���� ������������� ����������� �����. ��������� ����, ������� �� �����
// � ������� �� ����������� ������� �� ���������� ���� �������� � ������������� ���������.
void fillArray(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) arr[i] = (rand() % 80) + 10;
}

void printArray(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";
	cout << "\n";
	for (int i = SIZE - 1; i > -1; i--) cout << arr[i] << " ";
}

int sumArray(int arr[], const int SIZE) {
	int sum = 0;
	for (int i = 0; i < SIZE; i++) sum += arr[i];
	return sum;
}



// ���� ����������� �����.������ �������� �� �������� �������� � ����� �� ������� �� � ����� ������.������� ������������ ����� �� ����� � ������������� ���������.
void getMaxMinArrayAndSwap(int arr[], const int SIZE, int &max, int &min) {
	max = 0;
	min = 1000;
	int max_id = 0;
	int min_id = 0;

	for (int i = 0; i < SIZE; i++){
		if (arr[i] > max) {
			max = arr[i];
			max_id = i;
		}
		if (arr[i] < min) {
			min = arr[i];
			min_id = i;
		}
	}
	
	int buffer = arr[max_id];
	arr[max_id] = arr[min_id];
	arr[min_id] = buffer;
}


// ���� ����������� �����.������� ������ �� ���� ��������(���� ����� �� ������� �������, �� ����������� ������� ���������� �� ���� � ������������� ���������
void reversArray(int arr[],int newArr[], const int SIZE) {
	

	for (int i = 0; i < SIZE; i++) newArr[SIZE - i] = arr[i];
	

}


int main() {
	const int SIZE = 10;
	int arr[SIZE] = {};

	fillArray(arr, SIZE);
	printArray(arr, SIZE);
	cout << "\nSum array: " << sumArray(arr, SIZE);

	int max;
	int min;

	getMaxMinArrayAndSwap(arr, SIZE, max, min);
	cout << "\nMax: " << max << "  Min: " << min << endl;
	printArray(arr, SIZE);


	int newArr[SIZE] = {};

	reversArray(arr, newArr, SIZE);
	cout << "\nRevers:\n";
	printArray(newArr, SIZE);


	system("pause");
	return 0;
}