#pragma once
#include <vector>
class AddTwoBinary
{
public:
	AddTwoBinary(std::vector<int> num1, std::vector<int> num2);
	std::vector<int> performAdd();
private:
	std::vector<int> m_num1;
	std::vector<int> m_num2;
	std::vector<int> m_result;

	enum Status
	{
		FAIL,
		PASS
	};

	int add();
	void printResult();
	int convertToDecimal(std::vector<int>& bin);
};

