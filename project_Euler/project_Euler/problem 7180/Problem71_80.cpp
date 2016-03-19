#include "stdafx.h"
#include "Problem71_80.h"
#include <fstream>
#include "../CommonFun.h"


void CProblem71::CalcProblem(int n)
{
	int a, b;
	a = b = 0;
	int nreta, nretb;
	nreta = 1;
	double nCur = 1000000;
	double ntemp;
	for (b = 3; b < 1000000; b++)
	{
		for (a = nreta; a < b / 2 + 1; a++)
		{
			ntemp = (double)(3 * b - 7 * a) / (double)(7 * b);
			if (ntemp <= 0)
				break;
			else if (nCur > ntemp)
			{
				nCur = ntemp;
				nreta = a;
				nretb = b;
				
			}
		}
	}
	m_nRet = nreta;
}

void CProblem72::CalcProblem(int n)
{
	uint64_t *pall = new uint64_t[1000001];
	m_nRet = 0;
	for (size_t i = 0; i < 1000001; i++)
	{
		pall[i] = i;
	}
	for (size_t i = 2; i < 1000001; i++)
	{
		if (pall[i] == i)
		{
			for (size_t j = 0; j < 1000001; j+=i)
			{
				pall[j] = pall[j] / i * (i - 1);
			}
		}
		m_nRet += pall[i];
	}
}

void CProblem73::CalcProblem(int n)
{
	m_nRet = 0;
	uint32_t a, b, c, d, e, f;
	a = 1;
	b = 3;
	c = 4000;
	d = 11999;
	e = 0;
	f = 0;
	uint32_t temp;
	while (e != 1 && f != 2)
	{
		temp = (12000 + b) / d;
		e = temp * c - a;
		f = temp * d - b;
		a = c;
		b = d;
		c = e;
		d = f;
		m_nRet++;
	}
}

bool CProblem74::GetTerms(uint32_t big_int)
{
	uint64_t cur = 0;;
	uint64_t temp = big_int;
	uint64_t ntemp;
	bool bFine = false;
	int nCur = 1;
	uint64_t nn;
	while (!bFine)
	{
		ntemp = temp;
		if (temp < 1000000 && m_All[temp] != 0)
		{
			if (m_setTemp.find(m_All[temp]) != m_setTemp.end())
				return nCur == 60;
			else
			{
				m_setTemp.insert(m_All[temp]);
				temp = m_All[temp];
				nCur++;
			}
				
		}
		else
		{
			nn = temp;
			temp = 0;
			while (ntemp > 0)
			{
				temp += m_vec[ntemp % 10];
				ntemp /= 10;
			}
			if (m_setTemp.find(temp) != m_setTemp.end())
				return nCur == 60;
			else
			{
				m_setTemp.insert(temp);
				nCur++;
			}
			if (nn < 1000000)
				m_All[nn] = temp;
		}
		if (nCur > 60)
			return false;
	}
}

void CProblem74::CalcProblem(int n)
{
	m_vec.clear();
	uint32_t ntemp = 1;
	m_vec.push_back(1);
	m_All.resize(1000000, 0);
	m_All[169] = 363601;
	m_All[363601] = 1454;
	m_All[1454] = 169;
	m_All[871] = 45361;
	m_All[45361] = 871;
	m_All[872] = 45362;
	m_All[45362] = 872;
	for (size_t i = 1; i < 10; i++)
	{
		ntemp *= i;
		m_vec.push_back(ntemp);
	}
	for (size_t i = 1; i < 1000000; i++)
	{
		m_setTemp.insert(i);
		if (GetTerms(i))
			m_nRet++;
		m_setTemp.clear();
	}
}