#pragma once
#include <vector>
#include "../CommonFun.h"
using namespace std;
//Problem34
//145 is a curious number, as 1!+ 4!+ 5!= 1 + 24 + 120 = 145.
//Find the sum of all numbers which are equal to the sum of the factorial of their digits.
//Note: as 1!= 1 and 2!= 2 are not sums they are not included.
class CProblem34
{
public:
	CProblem34();
	virtual ~CProblem34();
public:
	void CalcProblem(int n);
	string GetString();
private:
	int	GetMax();
	int GetSumOfFactorial(int ncur);
	
private:
	const int n9;
	vector<int>		m_vecn;
	vector<int>		m_vecRet;
	int				m_Sum;
};

class CProblem35
{
public:
	CProblem35();
	virtual ~CProblem35();
public:
	void CalcProblem(int n);
	string GetString();
private:
	bool IsPrimeNumber(int n);
	bool IsCircularPrimes(int n);
private:
	int				m_max;
	vector<int>		m_vecPrime;
	vector<int>		m_vecCur;
	vector<int>		m_ret;
	int				m_nret;
};

class CProblem36
{
public:
	CProblem36();
	virtual ~CProblem36();
public:
	void CalcProblem(int n);
	string GetString();
private:
	bool IsPalindromic10(int n);
	bool IsPalindromic2(int n);
private:
	int		m_nRet;
	vector<int>	m_vec;
};

class CProblem37
{
public:
	CProblem37(){};
	virtual ~CProblem37(){};
public:
	void CalcProblem(int n);
	string GetString();
private:
	bool IsTruncatablePrimes(int n);
private:
	int		m_nRet;
	vector<int>	m_vec;
};

class CProblem38
{
public:
	CProblem38() {};
	virtual ~CProblem38() {};
public:
	void CalcProblem(int n);
	string GetString();
private:
	bool IsConcatenatedProduct(int n);
private:
	int			m_nRet;
	vector<int>	m_vec;
};

