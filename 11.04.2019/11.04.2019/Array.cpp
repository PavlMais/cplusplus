#include "Array.h"
#include <stdlib.h>
#include <iostream>

#include <string.h>




Array::Array(int size)
{
	arrSize = (int*)malloc(sizeof(int));
	*arrSize = size;
	arrData = (int*)calloc(size, sizeof(int));

}

void Array::set(int index, int val)
{
	arrData[index] = val;
}

int Array::get(int index)
{
	return arrData[index];
}




void Array::append(int val)
{
	*arrSize += 1;

	arrData = (int*)realloc(arrData, *arrSize * sizeof(int));
	arrData[*arrSize - 1] = val;
}




void Array::insert(int index, int val)
{

	arrData = (int*)realloc(arrData, (*arrSize + 1) * sizeof(int));

	memmove(arrData + index + 1, arrData + index, (*arrSize - index) * sizeof(int));

	*arrSize += 1;

	arrData[index] = val;
}

void Array::remove(int index){
	memmove(arrData + index, arrData + index + 1, (*arrSize - index) * sizeof(int));
	*arrSize -= 1;
	arrData = (int*)realloc(arrData, (*arrSize) * sizeof(int));
}

int Array::getSize()
{
	return *arrSize;
}

int Array::pop(int index)
{
	int val = arrData[*arrSize - 1];

	*arrSize -= 1;

	arrData = (int*)realloc(arrData, *arrSize);

	return val;

}


Array::~Array()
{
	free(arrData);
	free(arrSize);
}




1234   2

134
