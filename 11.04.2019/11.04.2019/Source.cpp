#include <iostream>
#include <stdlib.h>
#include "array.h"
using namespace std;

int main() {








	Array arr(5);

	for (int i = 0; i < arr.getSize(); i++) cout << arr.get(i) << " ";
	
	for (int i = 0; i < arr.getSize(); i++) arr.set(i,i);

	for (int i = 0; i < arr.getSize(); i++) cout << arr.get(i) << " ";


	cout  << "\n";
	cout << arr.getSize() << endl;
	arr.append(99);
	cout << arr.getSize() << endl;

	cout << "\n";
	for (int i = 0; i < arr.getSize(); i++) cout << arr.get(i) << " ";



	arr.insert(4, 88);


	cout << "\n";

	for (int i = 0; i < arr.getSize(); i++) cout << arr.get(i) << " ";




	arr.remove(2);



	cout << "\n";

	for (int i = 0; i < arr.getSize(); i++) cout << arr.get(i) << " ";




	system("pause");
	return 0;
}