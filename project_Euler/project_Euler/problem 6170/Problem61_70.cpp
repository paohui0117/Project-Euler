#include "stdafx.h"
#include "Problem61_70.h"
#include <fstream>
#include "../CommonFun.h"


void CProblem61::CalcProblem(int nn)
{
	//·ÇµÝ¹é
	m_nRet = 0;
	uint32_t nCur = 0;
	uint32_t nLast = 0;
	uint32_t ntemp = 0;
	bool bFind = false;
	bool bUse[6];
	memset(bUse, 0, sizeof(bUse));
	for (size_t i = 1010; i < 10000; i++)
	{
		if (IsTriangle(i))
			m_set[0].insert(i);
		if (IsSquare(i))
			m_set[1].insert(i);
		if (IsPentagonal(i))
			m_set[2].insert(i);
		if (IsHeptagonal(i))
			m_set[3].insert(i);
		if (IsOctagonal(i))
			m_set[4].insert(i);
		if (IsHexagonal(i))
			m_set[5].insert(i);
	}
	int n = 0;
	int nFind = 0;
	bool bcurfind = false;
	int nbFinded = 0;
	uint32_t nStart;
	auto itor = m_set[0].begin();
	while (!bFind)
	{
		m_ret[0] = *itor;
		nStart = *itor;
		bUse[0] = true;
		nLast = *itor / 100;
		nFind = 1;
		while (true)
		{
			nCur = nStart % 100;
			nCur *= 100;
			while (bUse[n])
			{
				n++;
				if (n == 6)
					n = 0;
			}
			bcurfind = false;
			nbFinded++;
			for (size_t i = 10; i < 100; i++)
			{
				ntemp = nCur + i;
				if (m_set[n].find(ntemp) != m_set[n].end())
				{
					if (nFind == 5)
					{
						if (nLast == i)
						{
							m_ret[nFind] = ntemp;
							for (size_t k = 0; k < 6; k++)
							{
								m_nRet += m_ret[k];
							}
							return;
						}
						else
							continue;
					}
					else
					{
						nbFinded = 0;
						bcurfind = true;
						m_ret[nFind] = ntemp;
						nStart = ntemp;
						nFind++;
						bUse[n] = true;
						break;
					}
				}
			}
			if (!bcurfind && nFind == 5)
			{
				memset(bUse, 0, sizeof(bUse));
				nbFinded = 0;
				break;
			}
				
			if (nbFinded + nFind >= 6)
			{
				memset(bUse, 0, sizeof(bUse));
				nbFinded = 0;
				break;
			}
				
			n++;
			if (n == 6)
				n = 0;
		}
		itor++;
	}

}

bool CProblem61::IsTriangle(uint64_t n)
{
	uint64_t ntemp = n * 8 + 1;
	uint64_t nn = sqrt(ntemp);
	if (ntemp % nn != 0)
		return false;
	if ((nn - 1) % 2 != 0)
		return false;
	return true;
}

bool CProblem61::IsSquare(uint64_t n)
{
	uint64_t nn = sqrt(n);
	return nn * nn == n;
}

bool CProblem61::IsPentagonal(uint64_t n)
{
	uint64_t ntemp = n * 24 + 1;
	uint64_t nn = sqrt(ntemp);
	if (ntemp % nn != 0)
		return false;
	if ((nn + 1) % 6 != 0)
		return false;
	return true;
}

bool CProblem61::IsHexagonal(uint64_t n)
{
	uint64_t ntemp = n * 8 + 1;
	uint64_t nn = sqrt(ntemp);
	if (ntemp % nn != 0)
		return false;
	if ((nn + 1) % 4 != 0)
		return false;
	return true;
}
//n(5n?3) / 2
bool CProblem61::IsHeptagonal(uint64_t n)
{
	uint64_t ntemp = n * 40 + 9;
	uint64_t nn = sqrt(ntemp);
	if (ntemp % nn != 0)
		return false;
	if ((nn + 3) % 10 != 0)
		return false;
	return true;
}
//n(3n?2)
bool CProblem61::IsOctagonal(uint64_t n)
{
	uint64_t ntemp = n * 3 + 1;
	uint64_t nn = sqrt(ntemp);
	if (ntemp % nn != 0)
		return false;
	if ((nn + 1) % 3 != 0)
		return false;
	return true;
}

void CProblem62::CalcProblem(int n)
{
	m_nRet = 0;
	bool bFind = false;
	uint64_t nCur = 405;
	uint64_t nTemp = 0;
	int nCurFind = 0;
	while (!bFind)
	{
		nCur++;
		nTemp = nCur * nCur * nCur;
		GetAllDigits(nTemp);
		uint64_t ntry = 0;
		nCurFind = 0;
		for (uint64_t i = nCur + 1; i < nCur * 3; i++)
		{
			ntry = i * i * i;
			if (ntry > m_nMax)
				break;
			if (SameDigits(ntry))
			{
				nCurFind++;
			}
			if (nCurFind == 4)
			{
				m_nRet = nTemp;
				return;
			}
		}
	}
}

bool CProblem62::SameDigits(uint64_t n)
{
	
	char templist[10];
	memcpy(templist, m_Digitals, 10);
	int ntemp = 0;
	map<int, int>::iterator itor;
	while (n > 0)
	{
		ntemp = n % 10;
		n /= 10;
		if (templist[ntemp] <= 0)
			return false;
		else
		{
			templist[ntemp]--;
		}
	}
	return true;
}

void CProblem62::GetAllDigits(uint64_t n)
{
	memset(m_Digitals, 0, sizeof(char) * 10);
	int ntemp = 0;
	int nSize = 0;
	uint64_t nMax = 0;
	m_nMax = 1;
	map<int, int>::iterator itor;
	while (n > 0)
	{
		ntemp = n % 10;
		m_Digitals[ntemp]++;
		m_nMax *= 10;
		n /= 10;
		nSize++;
	}
	m_nMin = m_nMax / 10;
}

void CProblem63::CalcProblem(int n)
{
	m_nRet = 0;
	bool bFine = false;
	//uint64_t ncur = 0;
	int ntemp = 1;
	int ncurDigit;
	BigInt ncur(1);
	for (size_t i = 1; i < 10; i++)
	{
		bFine = false;
		ntemp = 1;
		ncur = 1;
		while (!bFine)
		{
			ncur *= i;
			ncurDigit = ncur.GetDigitalNo();
			if (ntemp == ncurDigit)
				m_nRet++;
			else if (ntemp > ncurDigit)
				break;
			ntemp++;
		}
	}
}

void CProblem64::CalcProblem(int n)
{
	m_nRet = 0;
	for (size_t i = 2; i < 10001; i++)
	{
		if (GePteriod(i) & 1 == 1)
			m_nRet++;
	}
}

int CProblem64::GePteriod(int n)
{
	if (n < 1)
		return 0;
	int	ncurPos = 0;
	int m = 0;
	int d = 1;
	int a = sqrt(n);
	if (a *a == n)
		return 0;
	int nTempA = a;
	int ntemp = a * 2;
	while (nTempA != ntemp)
	{
		m = nTempA * d - m;
		d = (n - m *m) / d;
		nTempA = (a + m) / d;
		ncurPos++;
	}
	return ncurPos;
}

void CProblem65::CalcProblem(int nn)
{
	int ncur = (99 / 3) * 2;
	BigInt n(0);
	BigInt m(1);
	BigInt temp(0);
	for (size_t i = 0; i < 33; i++)
	{
		//1
		temp = m;
		m += n;
		n = temp;
		//2x
		temp = m;
		m = m * ncur;
		m += n;
		n = temp;
		//1
		temp = m;
		m += n;
		n = temp;
		ncur -= 2;
	}
	temp = m * 2;
	temp += n;
	m_nRet = temp.GetDigitalSum();
}

CProblem66::CProblem66():m_cur(0)
{
}

void CProblem66::CalcProblem(int n)
{
	m_nRet = 0;
	uint32_t nTemp = 2;
	uint32_t nCur = 2;
	while (nTemp < 1001)
	{
		nTemp = nCur * nCur;
		m_vecSquare.push_back(nTemp);
		nCur++;
	}
	nCur = 0;
	for (size_t i = 2; i < 1001; i++)
	{
		if (i == m_vecSquare[nCur])
		{
			nCur++;
			continue;
		}
		GetFractions(i);
	}
}

void CProblem66::GetFractions(int n)
{
	uint32_t a0 = sqrt(n);
	uint32_t m = 0;
	uint32_t d = 1;
	uint32_t ntempA = a0;
	uint64_t ntemp = a0 * 2;
	m_vecFractions.clear();
	while (ntempA != ntemp)
	{
		m = ntempA * d - m;
		d = (n - m *m) / d;
		ntempA = (a0 + m) / d;
		m_vecFractions.push_back(ntempA);
	}
	BigInt x(1);
	BigInt y(1);
	BigInt x2(1);
	BigInt y2(1);
	int ncur = 1;
	bool bFind = false;
	int nCurTemp = 0;
	int nSize = m_vecFractions.size();
	BigInt h0(a0);
	BigInt k0(1);
	BigInt h1 (m_vecFractions[0] * a0 + 1);
	BigInt k1 (m_vecFractions[0]);
	if (h1*h1 == k1*k1*n + 1)
	{
		x = h1;
		bFind = true;
	}
	while (!bFind)
	{
		nCurTemp = ncur % nSize;
		ncur++;
		x = h1 * m_vecFractions[nCurTemp] + h0;
		y = k1 * m_vecFractions[nCurTemp] + k0;
		h0 = h1;
		h1 = x;
		k0 = k1;
		k1 = y;
		x2 = x;
		y2 = y;
		x2 *= x;
		y2 *= y;
		y2 *= n;
		y2 += 1;
		bFind = x2 == y2;
	}
	if (x > m_cur )
	{
		m_cur = x;
		m_nRet = n;
	}
		
}