#include "stdafx.h"
#include "Problem51_60.h"
#include <fstream>
#include "../CommonFun.h"

void CProblem51::CalcProblem(int n)
{
	m_nRet = 0;
	bool bFind = false;
	m_setChecked.clear();
	int ncur = 57001;
	while (!bFind)
	{
		if (Isprime(ncur))
		{
			bFind = Check(ncur);
			ncur += 2;
		}
		else
			ncur++;
	}
}

bool CProblem51::CheckAllPossible(char no)
{
	m_nRet = 0;
	if (m_vectemp.size() == 0)
		return false;
	int nmin = 0;
	if (no == m_vectemp[0])
		return false;
	if (no == m_vectemp[m_vectemp.size() - 1])
		nmin++;		//如果第一个重复了  就不能取0
	int n = 0;
	int m = nmin;
	int ncur = 0;
	int nnn = 1;
	for (size_t i = nmin; i < 10; i++)
	{
		ncur = 0;
		nnn = 1;
		for (size_t j = 0; j < m_vectemp.size(); j++)
		{
			if (m_vectemp[j] == no)
			{
				ncur += i * nnn;
			}
			else
				ncur += m_vectemp[j] * nnn;
			nnn *= 10;
		}
		if (Isprime(ncur))
		{
			n++;
			if (i == nmin)
				m_nRet = ncur;
		}
		else
			m++;
		if (n == 8)
			return true;
		else if (m == 3)
			return false;
	}
	return false;
}

bool CProblem51::Check(int ncur)
{
	int ntemp = 0;
	int nn;
	int m;
	m_temp.clear();
	m_vectemp.clear();
	while (ncur > 0)
	{
		nn = ncur % 10;
		m = ntemp & (1 << nn);
		if (m == 0)
		{
			ntemp |= 1 << nn;
		}
		else
		{
			m_temp.insert(nn); //装入重复的值
		}
		m_vectemp.push_back(nn);
		ncur /= 10;
	}
	if (m_temp.size() == 0)
		return false;
	set<char>::iterator itor = m_temp.begin();
	while (itor != m_temp.end())
	{
		if (CheckAllPossible( *itor))
			return true;
		itor++;
	}
	return false;
}

void CProblem52::CalcProblem(int n)
{
	m_nRet = 0;
	int nCur = 1234;
	bool bFind = false;
	while (!bFind)
	{
		bFind = Check(nCur);
		nCur++;
	}
}

bool CProblem52::Check(int&  nn)
{
	m_setTemp.clear();
	int n = nn;
	int ntemp;
	int nSize = 0;
	while (n > 0)
	{
		ntemp = n % 10;
		if (m_setTemp.find(ntemp) == m_setTemp.end())
			m_setTemp.insert(ntemp);
		n /= 10;
		nSize++;
	}
	for (size_t i = 6; i > 1; i--)
	{
		int nX = nn * i;
		if (i == 6 && nX > pow(10, nSize))
		{
			nn = pow(10, nSize) - 1;
			return false;
		}
		while (nX > 0)
		{
			ntemp = nX % 10;
			if (m_setTemp.find(ntemp) == m_setTemp.end())
				return false;
			nX /= 10;
		}
	}
	m_nRet = nn;
	return true;
}

void CProblem53::CalcProblem(int n)
{
	
	m_nRet = 0;
	int nStart = 0;
	bool bFind = false;
	BigInt base(1000000);
	base *= 1000000;
	m_vecFactorial.clear();
	m_vecFactorial.push_back(BigInt(1000000));
	for (size_t i = 1; i < 51; i++)
	{
		m_vecFactorial.push_back(m_vecFactorial[i - 1] * i);
		if (!bFind && m_vecFactorial[i] > base)
		{
			nStart = i;
			bFind = true;
		}
	}
	bool bEven = false;
	int ntemp;
	BigInt nCur(1);
	BigInt ntt(0);
	bool bGreat = false;
	for (size_t i = nStart; i < 101; i++)
	{
		bEven = (i % 2 == 0);
		ntemp =  i / 2 ;
		for (size_t j = 1; j < ntemp + 1; j++)
		{
			nCur = 1;
			bGreat = false;
			for (size_t k = i; k > i - j; k--)
			{
				nCur *= k;
				
				if (nCur >  m_vecFactorial[j])
				{
					if (!bEven)
						m_nRet += 2;
					else
					{
						if (j == ntemp)
							m_nRet += 1;
						else
							m_nRet += 2;
					}
					break;
				}
			}
		}
	}
}

void CProblem54::CalcProblem(int n)
{


}

void CProblem55::CalcProblem(int n)
{
	m_nRet = 0;
	int nCur = 0;
	bool bFind = false;
	uint64_t temp;
	for (size_t i = 1; i < 10001; i++)
	{
		uint64_t cur = i;
		temp = Reverse(cur);
		bFind = false;
		nCur = 0;
		while (!bFind && nCur < 50)
		{
			cur += temp;
			temp = Reverse(cur);
			if ((i > 9) || (temp > 10))
			{
				if (temp == cur)
				{
					m_nRet++;
					break;
				}
			}
			nCur++;
		}
	}
	m_nRet = 10000 - m_nRet;
}

uint64_t CProblem55::Reverse(uint64_t n)
{
	uint64_t temp = 0;
	while (n > 0)
	{
		temp *= 10;
		temp += n % 10;
		n /= 10;
	}
	return temp;
}

void CProblem56::CalcProblem(int n)
{
	m_nRet = 0;
	uint64_t ncur = 0;
	for (size_t i = 2; i < 100; i++)
	{
		BigInt temp(i);
		for (size_t j = 1; j < 100; j++)
		{
			temp *= i;
			ncur = temp.GetDigitalSum();
			if (m_nRet < ncur)
				m_nRet = ncur;
		}
	}
}