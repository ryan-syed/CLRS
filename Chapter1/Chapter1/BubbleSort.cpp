#include "pch.h"
#include "BubbleSort.h"
#include <iostream>

using namespace std;

BubbleSort::BubbleSort(std::vector<int> list) : m_list(list)
{

}

void BubbleSort::performSort()
{
	cout << "The values in the list/array before sorting are : ";
	printList();
	sort();
	cout << "The values in the list/array after sorting are : ";
	printList();
}

/*
#########    PSEUDOCODE     ########

BUBBLE-SORT(A)
	for j = 0 to A.length - 2
		for i = A.length - 1 to j + 1
			if A[i] < A[i - 1]
				swap A[i] and A[i - 1]

#####################################
*/

void BubbleSort::sort()
{
	if (m_list.size() <= 1)
		return;
	for (int i = 0; i < m_list.size() - 1; i++) {
		for (int j = m_list.size() - 1; j >= i + 1; j--) {
			if (m_list[j] < m_list[j - 1]) {
				swap(m_list[j], m_list[j - 1]);
			}
		}
	}
}

void BubbleSort::printList()
{
	for (auto num : m_list)
		cout << num << " ";
	cout << endl;
}

