#include "pch.h"
#include "AddTwoBinary.h"
#include <iostream>

using namespace std;

AddTwoBinary::AddTwoBinary(std::vector<int> num1, std::vector<int> num2): m_num1(num1), m_num2(num2)
{
	m_result.resize(m_num1.size() + 1);
}

std::vector<int> AddTwoBinary::performAdd()
{
	if (add() == Status::FAIL) {
		cout << "Either one your input is empty or not of the same size of elements" << endl;
		return {};
	}
	printResult();
	return m_result;
}

/*
#########      PSEUDOCODE       ################

1 1 1


ADD-TWO-BINARY(A, B)
	N = A.length
	C[0 ... N]
	carry = 0
	for i = N-1 to 0
		C[i+1] = (A[i] + B[i] + carry) % 2
		carry = (A[i] + B[i] + carry) / 2
	C[N] = carry

################################################
*/

int AddTwoBinary::add()
{
	if (m_num1.empty() || m_num1.size() != m_num2.size())
		return Status::FAIL;
	int N = m_num1.size();
	int carry = 0;
	for (int i = N - 1; i >= 0; i--) {
		m_result[i + 1] = (m_num1[i] + m_num2[i] + carry) % 2;
		carry = (m_num1[i] + m_num2[i] + carry) / 2;
	}
	m_result[0] = carry;
	return Status::PASS;
}

void AddTwoBinary::printResult()
{
	cout << "Decimal value of num1 : " << convertToDecimal(m_num1) << endl;
	cout << "Decimal value of num2 : " << convertToDecimal(m_num2) << endl;
	cout << "Decimal value of result of sum : " << convertToDecimal(m_result) << endl;
	cout << "The sum of the two numbers in binary form is : ";
	for (int i = 0; i < m_result.size() ; i++)
		cout << m_result[i] << " ";
	cout << endl;
}

int AddTwoBinary::convertToDecimal(std::vector<int>& bin)
{
	int result = 0;
	for (int i = bin.size() - 1; i >= 0; i--)
		result += bin[i] * pow(2, bin.size() - 1 - i);
	return result;
}
