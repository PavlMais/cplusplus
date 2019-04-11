#pragma once
class Array
{
public:
	Array(int size);
	void set(int index, int val);
	int get(int index);
	void append(int val);
	void insert(int index, int val);
	void remove(int index);
	int getSize();
	int pop(int index);
	~Array();


private:
	int* arrData;
	int* arrSize;
};

