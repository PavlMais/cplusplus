#include <iostream>

using namespace std;

template<typename T>
void fillArray(T arr[], int *SIZE) {
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
	*size += 1;
	delete[] arr;
	return new_arr;
}
int *add_start(int *arr, int *size, int num) {
	int *new_arr = new int[*size + 1];
	for (int i = 1; i < *size + 1; i++) new_arr[i] = arr[i - 1];
	new_arr[0] = num;
	*size += 1;
	delete[] arr;
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
		if (i == index) iter--;
		else new_arr[iter] = arr[i];
		iter++;
	}
	*size -= 1;
	delete[] arr;

	return new_arr;
}
int *add_block_array(int *arr, int *size, int block[], int items) {
	int *new_arr = new int[*size + items];
	for (int i = 0; i < *size; i++) new_arr[i] = arr[i];
	for (int i = *size; i < *size + items; i++) new_arr[i] = block[i - *size];
	
	*size += items;
	delete[] arr;
	return new_arr;
}
int *insert_block_array(int *arr, int *size, int block[], int items, int index) {
	int *new_arr = new int[*size + items];
	int iter = 0;
	*size += items;
	
	for (int i = 0; i < *size; i++){
		if (i == index) {
			for (int s = 0; s < items; s++){
				new_arr[i + s] = block[s];
			}
			i += items - 1;
			iter--;	
		}
		else {
			new_arr[i] = arr[iter];
		}
		iter++;
	}
	delete[] arr;
	delete[] block;
	return new_arr;
}






//int *delete_block(int *arr, int *size, int block[], int items) {
//	int *new_arr = new int[*size - items];
//	bool is;
//	int indx = 0;
//	*size += items;
//
//	for (int i = 0; i < *size; i++)
//	{
//		for (int s = 0; s < items; s++) is = (i == block[s]);
//		cout << is << " " << i << " " << indx;
//		if (is) {
//			indx++;
//		}
//		new_arr[i] = arr[indx];
//		indx++;
//	}
//	return 0;
//}





int main() {
	int *size = new int;
	int num, index, cmd, items, pos;
	cout << "Enter size: ";
	cin >> *size;


	int *arr = new int[*size];


	fillArray(arr, size);

	printArray(arr, size);


	while (true)
	{

		cout << "\n1 PRINT\n2 ADD END\n3 ADD START\n4 ADD INDEX\n5 DELETE\n6 ADD BLOCK\n 7 INSERT BLOCK\n 8 DELETE BLOCK\n 9 EXIT\n> ";
		cin >> cmd;
		switch (cmd){
		case 1:
			cout << "\n\n Array: \n";
			printArray(arr, size);
			break;

		case 2:
			cout << "\nEnter idex: ";
			cin >> num;
			arr = append(arr, size, num);
			printArray(arr, size);


			
			break;
		case 3:
			cout << "\nEnter idex: ";
			cin >> num;
			arr = add_start(arr, size, num);
			printArray(arr, size);


			
			break;
		case 4:
			cout << "\nEnter idex: ";
			cin >> index;
			cout << "Enter num: ";
			cin >> num;

			arr = append_indx(arr, size, num, index);
			printArray(arr, size);

			break;
		case 5:
			cout << "\nEnter idex: ";
			cin >> index;

			arr = del_indx(arr, size, index);
			printArray(arr, size);


			break;
		

		case 7: {
			cout << "Enter count add items: ";
			cin >> items;
			int *block = new int[items];
			for (int i = 0; i < items; i++) {
				cout << "Enter " << items << " item: ";
				cin >> block[i];
			}
			cout << "Enter index pos: ";
			cin >> index;
			arr = insert_block_array(arr, size, block, items, index);
			printArray(arr, size);

			
		}
		break;
		case 6: {
			cout << "Enter count add items: ";
			cin >> items;
			int *block = new int[items];
			for (int i = 0; i < items; i++) {
				cout << "Enter " << items << " item: ";
				cin >> block[i];
			}

			arr = add_block_array(arr, size, block, items);
			printArray(arr, size);

			break;
		}
		case 8: {
			cout << "Enter count delete items: ";
			cin >> items;
			int *block = new int[items];
			for (int i = 0; i < items; i++) {
				cout << "Enter " << items << " idex for delete: ";
				cin >> block[i];
			}

			arr = delete_block(arr, size, block, items);
			printArray(arr, size);
		}
		break;
		
		}
	}

	system("pause");
	return 0;
}