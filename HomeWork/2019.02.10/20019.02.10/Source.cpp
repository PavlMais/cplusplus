#include <iostream>

using namespace std;

int checkHappyNamber(int n) {



}

int getNaturalNambers(int arr[], const int SIZE) {
	int count = 0;
	for (int i = 0; i < SIZE; i++){
		for (int j = 2; j <= sqrt((double)arr[i]); j++){
			if (arr[i] % j == 0 && arr[i] != j){
				arr[i] = 0;
				break;
			}
		}
		if (arr[i] != 0){
			std::cout << arr[i] << " ";
			count++;
		}
	}
	return count;
}


int main() {



	system("pause");
	return 0;
}