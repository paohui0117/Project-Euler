#include "stdafx.h"
#include "Problem31.h"
#include <set>
int CoinType[] = { 200,100,50,20,10,5,2,1 };
int nType = 8;
CProblem31::CProblem31()
{
	nTotal = 0;
}


CProblem31::~CProblem31()
{
}

void CProblem31::CalcProblem(int n)
{
	nTotal = 0;
	Calc(0, n);
}

std::string CProblem31::GetString()
{
	std::string str;
	str = nTotal;
	return str;
}

void CProblem31::Calc(int n, int nRest)
{
	if (n == nType -1 || nRest <= 0)
	{
		nTotal++;
		return;
	}
	int nMax = nRest / (CoinType[n]);
	for (int i = nMax; i > -1; i--)
	{
		Calc(n + 1, nRest - CoinType[n] * i);
	}
}

CProblem32::CProblem32()
{
}

CProblem32::~CProblem32()
{
}

void CProblem32::CalcProblem(int n)
{
	ndigital = n;
	if (n <= 0 || n > 9)
		return;
	ret a;
	for (size_t i = 1; i < 10000; i++)
	{
		if (Check(i))
		{
			a.n2 = i;
			a.n1 = 1;
			while (GetNext(a))
			{
				if (find(vecRet.begin(), vecRet.end(), a) == vecRet.end())
					vecRet.push_back(a);
			}
		}
	}
}

std::string CProblem32::GetString()
{
	std::set<int> myset;
	int n = 0;
	
	for (size_t i = 0; i < vecRet.size(); i++)
	{
		n += vecRet[i].nProduct;
	}
	char stemp[128] = { 0 };
	sprintf_s(stemp, "%d", n);
	return stemp;
}

bool CProblem32::Check(int a)
{
	std::string str;
	str = a;
	if (str.length() > 9)
		return false;
	if (str.find('0') != std::string::npos)
		return false;
	for (size_t i = 0; i < str.length() - 1; i++)
	{
		if (str.find(str[i], i) != std::string::npos)
			return false;
	}
	return true;
}

bool CProblem32::GetNext(ret& a)
{
	char stemp[128] = {0};
	std::string str3;
	bool bFind = false;
	for (size_t i = a.n1 + 1; i < 10000 ; i++)
	{
		if (i * a.n2 < 1000)
			continue;
		if (i * a.n2 > 10000)
			return false;
		if (Check(i))
		{
			sprintf_s(stemp, "%d%d%d", i, a.n2, i * a.n2);
			str3 = stemp;
			if (str3.length() != 9)
				continue;
			bFind = false;
			if (str3.find('0') != std::string::npos)
			{
				bFind = true;
				continue;
			}
				
			for (size_t j = 0; j < str3.length() - 1; j++)
			{
				if (str3.find(str3[j], j + 1) != std::string::npos)
				{
					bFind = true;
					break;
				}
			}
			if (!bFind)
			{
				a.n1 = i;
				a.nProduct = i * a.n2;
				return true;
			}
			
		};
	}
	return false;
}