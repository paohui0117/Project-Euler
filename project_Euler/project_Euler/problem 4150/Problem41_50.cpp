#include "stdafx.h"
#include "Problem41_50.h"
#include <fstream>
#include "../CommonFun.h"
void CProblem41::CalcProblem(int n)
{
	m_nRet = 0;
	for (size_t i = 7654321; i > 11; i--)
	{
		if (!Isprime(i))
			continue;
		if (IsPandigital(i))
		{
			m_nRet = i;
			break;
		}
	}
}

bool CProblem41::IsPandigital(int n)
{
	if (n < 12 || n > 7654321)
		return false;
	char temp[9] = {0};
	int nsize = 0;
	int ntemp = 0;
	int nmax = 7;
	while (n < pow(10, nmax - 1))
	{
		nmax--;
	}
	while (n > 0)
	{
		ntemp = n % 10;
		n /= 10;
		if (ntemp == 0 || ntemp > nmax)
			return false;
		if (temp[ntemp - 1] == 1)
			return false;
		temp[ntemp - 1] = 1;
		nsize++;
	}
	return true;
}

void CProblem42::CalcProblem(int n)
{
	CalcAllWords();
}

bool CProblem42::CalcAllWords()
{
	m_nRet = 0;
	char po = 'A' - 1;
	wchar_t* pFile = L"E:/C++/project_Euler/Debug/p042_words.txt";
	ifstream infile;
	infile.open(pFile);
	if (!infile.is_open())
		return false;
	char p;
	int ntemp = 0;
	bool bSWord = false;;
	while (infile.get(p))
	{
		if (p == '\"')
		{
			if (bSWord)
			{
				bSWord = false;
				if (IsTriangleWord(ntemp))
					m_nRet++;
			}
			else
			{
				bSWord = true;
				ntemp = 0;
			}
		}
		else
		{
			if (bSWord)
				ntemp += p - po;
			else
				continue;
		}
	}
	infile.close();
	return true;
}

bool CProblem42::IsTriangleWord(int n)
{
	int ntemp = sqrt(n * 2);
	return ntemp * (ntemp + 1) == n * 2;
}

void CProblem44::CalcProblem(int n)
{
	m_nRet = -1;
	int nCur = 1;
	int nSize = 100;
	bool bFind = false;
	uint32_t ntemp = 0;
	uint32_t nlast = 0;
	while (!bFind)
	{
		for (size_t i = nCur; i < 100 + nCur; i++)
		{
			nlast = ntemp;
			ntemp = i * (3 * i - 1) / 2;
			if (m_nRet != -1 && ntemp - nlast > m_nRet)
			{
				bFind = true;
				break;
			}
			m_All.push_back(ntemp);
		}
		int nmax = m_All[m_All.size() - 1];
		for (size_t i = 1; i < m_All.size() - 1; i++)
		{
			for (size_t j = nCur; j < m_All.size(); j++)
			{
				ntemp = m_All[i] + m_All[j];
				if (m_nRet != -1 && m_All[j] - m_All[i] > m_nRet)
					break;
				if (IsPentagonalNumbers(ntemp))
				{
					if (IsPentagonalNumbers(m_All[j] + ntemp))
					{
						if (m_nRet == -1)
							m_nRet = ntemp - m_All[j];
						else if (m_nRet > ntemp - m_All[j])
							m_nRet = ntemp - m_All[j];
					}
					else if (IsPentagonalNumbers(m_All[i] + ntemp))
					{
						if (m_nRet == -1)
							m_nRet = ntemp - m_All[i];
						else if (m_nRet > ntemp - m_All[i])
							m_nRet = ntemp - m_All[i];
					}
				}
			}
		}
		nCur += nSize;
	}
	
}

bool CProblem44::IsPentagonalNumbers(int n)
{
	int ntemp = n * 24 + 1;
	int nn = sqrt(ntemp);
	if (ntemp % nn != 0)
		return false;
	if ((nn + 1) % 6 != 0)
		return false;
	return true;
}

void CProblem45::CalcProblem(int n)
{
	uint64_t nn = 143;
	bool bFind = false;
	m_nRet = 0;
	uint64_t ntemp = 0;
	while (!bFind)
	{
		nn++;
		ntemp = nn * (2 * nn - 1);
		if (IsPentagonalNumbers(ntemp) && IsTriangle(ntemp))
		{
			m_nRet = ntemp;
			return;
		}
	}
}

bool CProblem45::IsPentagonalNumbers(uint64_t n)
{
	uint64_t ntemp = n * 24 + 1;
	uint64_t nn = sqrt(ntemp);
	if (ntemp % nn != 0)
		return false;
	if ((nn + 1) % 6 != 0)
		return false;
	return true;
}

//Triangle	 	Tn = n(n + 1) / 2	 	1, 3, 6, 10, 15, ...
bool CProblem45::IsTriangle(uint64_t n)
{
	uint64_t ntemp = n * 8 + 1;
	uint64_t nn = sqrt(ntemp);
	if (ntemp % nn != 0)
		return false;
	if ((nn - 1) % 2 != 0)
		return false;
	return true;
}
//Hexagonal	 	Hn = n(2n?1)	 	1, 6, 15, 28, 45, ...
bool CProblem45::IsHexagonal(uint64_t n)
{
	uint64_t ntemp = n * 8 + 1;
	uint64_t nn = sqrt(ntemp);
	if (ntemp % nn != 0)
		return false;
	if ((nn + 1) % 4 != 0)
		return false;
	return true;
}

void CProblem46::CalcProblem(int n)
{
	m_set.clear();
	m_set.insert(2);
	uint64_t ncur = 3;
	bool bFind = false;
	while (!bFind)
	{
		if (Isprime(ncur))
		{
			m_set.insert(ncur);
		}
		else
		{
			if (!IsCorrect(ncur))
			{
				bFind = true;
				m_nRet = ncur;
				return;
			}
		}
		ncur += 2;
	}
}

bool CProblem46::IsCorrect(uint64_t n)
{
	set<uint64_t>::iterator itor = m_set.begin();
	uint64_t temp;
	uint64_t temp2;
	while (itor != m_set.end())
	{
		if (n < *itor)
			return false;
		temp = n - *itor;
		if (temp % 2 != 0)
		{
			itor++;
			continue;
		}
			
		temp /= 2;
		temp2 = sqrt(temp);
		if (temp2 * temp2 == temp)
			return true;
		itor++;
	}
	return false;
}

void CProblem47::CalcProblem(int n)
{
	m_nRet = 0;
	int ncur = 0;
	uint64_t ntemp = 2;
	while (ncur < 4)
	{
		if (Isprime(ntemp))
		{
			ncur = 0;
			m_set.insert(ntemp);
		}
		else
		{
			if (GetAllPrimeFactors(ntemp) == 4)
				ncur++;
			else
				ncur = 0;
		}
		ntemp++;
	}
	m_nRet = ntemp - 4;
}

int CProblem47::GetAllPrimeFactors(uint64_t n)
{
	set<uint64_t> temp;
	set<uint64_t>::iterator itor = m_set.begin();
	bool bfinish = false;
	while (!bfinish)
	{
		itor = m_set.begin();
		while (n % *itor != 0)
		{
			itor++;
		}
		temp.insert(*itor);
		n /= *itor;
		if (m_set.find(n) != m_set.end())
		{
			temp.insert(n);
			bfinish = true;
		}
	}
	return temp.size();
}

void CProblem48::CalcProblem(int n)
{
	memset(ret, 0, sizeof(ret));
	for (size_t i = 1; i < 1001; i++)
	{
		GetSelfPower(i);
		Add();
	}
}

string CProblem48::GetString()
{
	char p[11] = { 0 };
	for (size_t i = 0; i < 10; i++)
	{
		p[i] = ret[i] + '0';
	}
	return p;
}

void CProblem48::GetSelfPower(uint32_t n)
{
	memset(cur, 0, sizeof(cur));
	int ncur = 0;
	uint32_t ntemp = n;
	while (ntemp > 0)
	{
		cur[9 - ncur] = ntemp % 10;
		ntemp /= 10;
		ncur++;
	}
	for (size_t i = 1; i < n; i++)
	{
		Multiplied(n);
	}
}

void CProblem48::Multiplied(uint32_t n)
{
	int ntemp = 0;
	for (int i = 9; i > -1; i--)
	{
		cur[i] *= n;
		cur[i] += ntemp;
		ntemp = cur[i] / 10;
		cur[i] %= 10;
	}
}

void CProblem48::Add()
{
	int ntemp = 0;
	for (int i = 9; i > -1; i--)
	{
		ret[i] += cur[i];
		ret[i] += ntemp;
		ntemp = ret[i] / 10;
		ret[i] %= 10;
	}
}

int CProblem49::IsSameDigit(int itor, int itor2, int n3)
{
	short size1 = 0;
	short size2 = 0;
	short size3 = 0;
	short temp = 0;
	short temp2 = 0;
	short temp3 = 0;
	int ntemp = 0;
	while (itor > 0)
	{
		ntemp = itor % 10;
		if (ntemp != 0)
			temp |= 1 << ntemp;
		else
			size1++;
		itor /= 10;
	}
	while (itor2 > 0)
	{
		ntemp = itor2 % 10;
		if (ntemp != 0)
			temp2 |= 1 << ntemp;
		else
			size2++;
		itor2 /= 10;
	}
	while (n3 > 0)
	{
		ntemp = n3 % 10;
		if (ntemp != 0)
			temp3 |= 1 << ntemp;
		else
			size3++;
		n3 /= 10;
	}
	return (temp == temp2 && temp2 == temp3 && size1 == size2 && size2 == size3);
}

void CProblem49::CalcProblem(int n)
{
	m_prime.clear();
	int namx = 0;
	for (size_t i = 1000; i < 9999; i++)
	{
		if (Isprime(i))
		{
			m_prime.insert(i);
			namx = i;
		}
	}
	set<int>::iterator itor = m_prime.begin();
	set<int>::iterator itor2;
	
	int ntemp = 0;
	int nret = 0;
	while (itor != m_prime.end())
	{
		itor2 = itor;
		itor2++;
		while (itor2 != m_prime.end())
		{
			ntemp = *itor2 - *itor;
			ntemp = *itor2 + ntemp;
			if (ntemp > namx || ntemp == 8147)
				break;
			else if (m_prime.find(ntemp) != m_prime.end())
			{
				nret = IsSameDigit(*itor, *itor2, ntemp);
				if (nret == -1)
					break;
				else if (nret == 1)
				{
					char str[13];
					sprintf_s(str, "%d%d%d", *itor, *itor2, ntemp);
					strret = str;
					return;
				}
				else
					itor2++;
			}
			else
				itor2++;
		}
		itor++;
	}
}

string CProblem49::GetString()
{
	return strret;
}