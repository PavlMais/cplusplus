#include <iostream>
#include "Array.h"

int main() {
	
	Array arr(5);

	arr.print();

	arr.fill();

	std::cout << "\n\n";

	arr.print();


	arr.append(2, 2);

	std::cout << "\n\n";
	arr.print();



	arr.remove(2);

	std::cout << "\n\n";
	arr.print();

	system("pause");
	return 0;
}