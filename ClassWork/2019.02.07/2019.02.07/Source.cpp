#include <iostream>

using namespace std;

// Написати функцію, яка рекурсивно обчислює суму чисел в переданому діапазоні  

int sumer(int a, int b, int sum = 0) {
	if (a == b) return sum + b;
	sumer(a + 1, b, sum + a);
}


// Написати програму для виводу на екран чисел Фібоначчі: (1,1,2,3,5,8... xn = xn-1 + xn-2), менших заданого числа Q.
int fib(int x) {
	if (x == 1 || x == 2)
		return 1;
	else
		return (fib(x - 1) + fib(x - 2));
}


int main() {

	cout << sumer(1, 3);
	cout << fib(9);


	system("pause");
	return 0;
}





