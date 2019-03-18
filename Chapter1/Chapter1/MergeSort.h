#pragma once
#include <vector>
class MergeSort
{
public:
	MergeSort(std::vector<int> list);
	void performSort();
	void merge(int p, int q, int r);
	void sort(int p, int r);
	void printList();
private:
	std::vector<int> m_list;
};

