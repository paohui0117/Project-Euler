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

void CProblem57::CalcProblem(int n)
{
	m_nRet = 0;
	BigInt a(1);
	BigInt b(2);
	BigInt ntemp(0);
	for (size_t i = 2; i < 1001; i++)
	{
		ntemp = b;
		b = b * 2;
		b += a;
		a = ntemp;
		ntemp += b;
		if (ntemp.GetDigitalNo() > b.GetDigitalNo())
			m_nRet++;
	}

}

int CProblem57::GetDigits(uint64_t n)
{
	int nret = 0;
	while (n > 0)
	{
		nret++;
		n /= 10;
	}
	return nret;
}

void CProblem58::CalcProblem(int n)
{
	m_nRet = 0;
	uint32_t nSideLength = 1;
	uint32_t nMax = 1;
	uint32_t ntemp;
	int nCur = 0;
	int nprime = 0;
	bool bFind = false;
	while (!bFind)
	{
		nCur = 0;
		nSideLength += 2;
		nMax = nSideLength * nSideLength;
		ntemp = nMax - nSideLength + 1;
		for (; nCur < 3; nCur++)
		{
			if (Isprime(ntemp))
				nprime++;
			ntemp -= nSideLength - 1;
		}
		if (nprime * 10 < nSideLength * 2 - 1)
		{
			m_nRet = nSideLength;
			bFind = true;
		}
			
	}
}

void CProblem60::CalcProblem(int n)
{
	memset(m_Start, 0, sizeof(int) * 5);
	m_nRet = 0;
	uint64_t ncur = 3;
	int nsize = 0;
	while (nsize < 2000)
	{
		if (Isprime(ncur))
		{
			m_vecAll.push_back(ncur);
			ncur++;
			nsize++;
		}
		else
			ncur++;
	}
	m_ncur = 0;
	bool bFind = false;
	while (m_ncur < 5 && m_Start[0] < m_vecAll.size() - 5)
	{
		bFind = false;
		for (size_t i = m_Start[m_ncur]; i < m_vecAll.size(); i++)
		{
			if (IsAllPrime(m_vecAll[i]))
			{
				m_Temp[m_ncur] = m_vecAll[i];
				m_Start[m_ncur] = i;
				if (m_ncur < 4)
					m_Start[m_ncur + 1] = i + 1;
				m_ncur++;
				bFind = true;
				break;
			}
			
		}
		if (!bFind)
		{
			m_ncur--;
			if (m_ncur < 0)
				m_ncur = 0;
			m_Start[m_ncur]++;
		}
		//
		if (m_ncur == 5)
		{
			m_ncur = 0;
			uint64_t temp = m_Temp[0] + m_Temp[1] + m_Temp[2] + m_Temp[3] + m_Temp[4];
			if (m_nRet == 0 || m_nRet > temp)
				m_nRet = temp;
			m_Start[0]++;
		}
		
	}
}

bool CProblem60::IsAllPrime(uint64_t a)
{
	bool bret = true;
	uint64_t ntemp1, ntemp2;
	int n1, n2;
	n2 = 1;
	ntemp2 = a;
	while (ntemp2 != 0)
	{
		n2 *= 10;
		ntemp2 /= 10;
	}
	ntemp2 = a;
	for (size_t i = 0; i < m_ncur; i++)
	{
		n1 = 1;
		ntemp1 = m_Temp[i];
		while (ntemp1 != 0)
		{
			n1 *= 10;
			ntemp1 /= 10;
		}
		ntemp1 = m_Temp[i];
		
		if (!Isprime(ntemp1 * n2 + ntemp2))
			return false;
		if (!Isprime(ntemp2 * n1 + ntemp1))
			return false;
	}
	return bret;
}