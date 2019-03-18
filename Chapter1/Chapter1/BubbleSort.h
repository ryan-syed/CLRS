#pragma once
#include <vector>
class BubbleSort
{
public:
	BubbleSort(std::vector<int> list);
	void performSort();
	void sort();
	void printList();
private:
	std::vector<int> m_list;
};

