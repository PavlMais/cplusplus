#pragma once
class Array
{
public:
	Array(int);

	void fill();
	void print();
	void append(int, int);
	void remove(int);

	~Array();

private:
	int* arrData;
	int* arrSize;
};

