#include "pch.h"
#include "MergeSort.h"
#include <iostream>

using namespace std;

MergeSort::MergeSort(std::vector<int> list) : m_list(list)
{

}

void MergeSort::performSort()
{
	cout << "The values in the list/array before sorting are : ";
	printList();
	sort(0, m_list.size() - 1);
	cout << "The values in the list/array after sorting are : ";
	printList();
}

void MergeSort::merge(int p, int q, int r)
{
	vector<int> B;
	copy(m_list.begin() + p, m_list.begin() + q + 1, back_inserter(B));
	vector<int> C;
	copy(m_list.begin() + q + 1, m_list.begin() + r + 1, back_inserter(C));

	int i = 0;
	int j = 0;

	for (int k = p; k <= r; k++) {
		if(i > q - p) {
			m_list[k] = C[j];
			j++;
		}
		else if (j > r - q - 1) {
			m_list[k] = B[i];
			i++;
		}
		else if (B[i] < C[j]) {
			m_list[k] = B[i];
			i++;
		}
		else {
			m_list[k] = C[j];
			j++;
		}
	}
}

/*
#########    PSEUDOCODE     ########

MERGE(A, p, q, r)
	B[0 ... q-p]
	C[0 ... r-q-1]
	i = 0
	j = 0
	k = 0
	while i <= q-p and j <= r-q-1
		if(B[i] < C[j])
			A[k] = B[i]
			i++
		else
			A[k] = C[j]
			j++
		k++

	while i <= q-p
		A[k] = B[i]
		i++
		k++
	while j <= r-q-1
		A[k] = C[j]
		j++
		k++
#####################################
*/

/*
	8 7 6 5 4 3 2 1

	0 7

				0 3					         4 7
      0 1                2 3             4 5       6 7
    0 0   1 1          2 2 3 3 
*/

void MergeSort::sort(int p, int r)
{
	if (p < r) {
		int q = p + (r - p) / 2;
		sort(p, q);
		sort(q + 1, r);
		merge(p, q, r);
	}
}

void MergeSort::printList()
{
	for (auto num : m_list)
		cout << num << " ";
	cout << endl;
}
