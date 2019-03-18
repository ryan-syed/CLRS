#pragma once
#include <vector>

class InsertionSort
{
public:
	InsertionSort(std::vector<int> list);
	void performSort();
	void sort();
	void printList();
private:
	std::vector<int> m_list;
};

