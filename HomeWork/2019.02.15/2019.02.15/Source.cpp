#include <iostream>

using namespace std;


// 1 �������� ���������� �������, ��� ������ ���� ����� � �������� ���� � ������� ������ ��������
int getBitNamber(int num) {
	//1 2 4 8 16 32 64 128 254 512
    
	// it in progress

	return num;
}


// 2 �������� ���������� ������ �������, ��� ��������
// �� ��������� � ������� ����� ������������� �� ����������(�� ���������).
bool checkSort(int arr[], const int SIZE, int step = 0) {
	if (step == SIZE - 1) return true;
	else if (arr[step] <= arr[step + 1]) return checkSort(arr, SIZE, step + 1);
	else return false;
}

int main() {
	const int SIZE = 5;
	int arr[5] = {3, 4, 6, 3, 7};



	cout << "Sorted: "<< checkSort(arr, SIZE);

	

	cout << "\n\n";
	system("pause");
	return 0;
}