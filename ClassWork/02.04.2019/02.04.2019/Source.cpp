#include <iostream>

using namespace std;

#define MAX(a, b, c) (((a) > (b) && (b) > (c)) ? (a) : ((b) > (c)) ? (b) : (c))
#define CUB(a,b) ((a) * 3) + ((b) * 3)
#define SUM(a) for(int i = 0, int sum = 0; i < 5; i++) sum += a[i]

int main() {
	
	cout << MAX(1, 9, 8) << endl;
	cout << CUB(5, 5) << endl;
	int a[5] = { 1,2,3,5,4 };
	cout << SUM(a);

	cout << endl;
	system("pause");
	return  0;
}	