#include "pch.h"
#include "SelectionSort.h"
#include <iostream>

using namespace std;

SelectionSort::SelectionSort(std::vector<int> list) : m_list(list)
{

}

void SelectionSort::performSort()
{
	cout << "The values in the list/array before sorting are : ";
	printList();
	sort();
	cout << "The values in the list/array after sorting are : ";
	printList();
}

/*
#########    PSEUDOCODE     ########

SELECTION-SORT(A)
	for i = 0 to N-2
		min = i
		for j = i + 1 to N-1
			if A[j] < A[min]
				min = j
		swap elements at index i & min

#####################################
*/

void SelectionSort::sort()
{
	int N = m_list.size();
	for (int i = 0; i < N; i++) {
		int min = i;
		for (int j = i + 1; j < N; j++) {
			if (m_list[j] < m_list[min])
				min = j;
		}
		if (i != min) {
			int temp = m_list[i];
			m_list[i] = m_list[min];
			m_list[min] = temp;
		}
	}
}

void SelectionSort::printList()
{
	for (auto num : m_list)
		cout << num << " ";
	cout << endl;
}


