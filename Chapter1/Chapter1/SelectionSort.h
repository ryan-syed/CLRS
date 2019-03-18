#pragma once
#include <vector>
class SelectionSort
{
public:
	SelectionSort(std::vector<int> list);
	void performSort();
	void sort();
	void printList();
private:
	std::vector<int> m_list;
};

