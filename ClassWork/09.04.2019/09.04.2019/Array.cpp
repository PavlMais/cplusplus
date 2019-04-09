#include "Array.h"
#include <iostream>
#include <ctime>

Array::Array(int size){
	srand(unsigned(time(0)));
	arrSize = new int(size);
	arrData = new int[size];
}

void Array::fill(){
	for (int i = 0; i < *arrSize; i++) arrData[i] = rand() % 20;
	
}

void Array::print(){
	for (int i = 0; i < *arrSize; i++) std::cout << arrData[i];
	
}

void Array::append(int val, int index){
	*arrSize += 1;

	int *new_arr = new int[*arrSize];
	
	int iter = 0;
	for (int i = 0; i < *arrSize; i++) {
		if (i == index) {
			new_arr[i] = val;
			iter--;
		}
		else new_arr[i] = arrData[iter];
		iter++;
	}
	arrData = new_arr;
}

void Array::remove(int index){
	int *new_arr = new int[*arrSize - 1];
	int iter = 0;
	for (int i = 0; i < *arrSize; i++) {
		if (i == index) iter--;
		else new_arr[iter] = arrData[i];
		iter++;
	}
	*arrSize -= 1;
	arrData = new_arr;
	
}

Array::~Array(){
	delete[] arrData;
	delete arrSize;
}
