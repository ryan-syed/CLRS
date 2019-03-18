#include "pch.h"
#include "InsertionSort.h"
#include <iostream>

using namespace std;

InsertionSort::InsertionSort(std::vector<int> list): m_list(list)
{
	
}

void InsertionSort::performSort()
{
	cout << "The values in the list/array before sorting are : ";
	printList();
	sort();
	cout << "The values in the list/array after sorting are : ";
	printList();
}

/*
#########    PSEUDOCODE     ########

INSERTION-SORT(A)
	for j = 1 to A.length - 1
		do key = A[j]
		do i = j - 1
		while i >= 0 and A[i] > key
			do A[i + 1] = A[i]
			do i = i - 1
		A[i+1] = key

#####################################
*/

void InsertionSort::sort()
{
	if (m_list.size() <= 1)
		return;
	for (int i = 1; i < m_list.size(); i++) {
		int key = m_list[i];
		int j = i - 1;
		while (j >= 0 && m_list[j] > key) {
			m_list[j + 1] = m_list[j];
			j--;
		}
		m_list[j + 1] = key;
	}
}

void InsertionSort::printList()
{
	for (auto num : m_list)
		cout << num << " ";
	cout << endl;
}

