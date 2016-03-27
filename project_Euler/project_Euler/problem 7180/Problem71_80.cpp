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

void CProblem75::CalcProblem(int n)
{
	m_nRet = 0;
	uint32_t a, b, c;
	uint32_t mm;
	uint32_t nn;
	uint32_t cur;
	map<uint32_t, char>::iterator itor;
	int ntempp;
	for (size_t m = 2; m < sqrt(1500000 / 2); m++)
	{
		mm = m * m;
		for (size_t n = 1; n < m; n++)
		{
			if (Check(m, n) != 1 ||  (m - n) % 2 == 0)
				continue;
			nn = n * n;
			a = mm - nn;
			b = 2 * m * n;
			c = mm + nn;
			cur = a + b + c;
			uint32_t temp = cur;
			while (temp < 1500000)
			{
				itor = m_map.find(temp);
				if (itor == m_map.end())
				{
					m_nRet++;
					m_map.insert(pair<uint32_t, char>(temp, 0));
				}
				else
				{
					if (itor->second == 0)
					{
						m_nRet--;
						itor->second = 1;
					}
				}
				temp += cur;

			}
		}
	}
}

int CProblem75::Check(uint32_t a, uint32_t b)
{
	uint32_t max, min;
	if (a > b)
	{
		max = a;
		min = b;
	}
	else
	{
		max = b;
		min = a;
	}
	for (size_t i = min; i > 0; i--)
	{
		if (max % i == 0 && min % i == 0)
			return i;
	}
}

void CProblem76::CalcProblem(int n)
{
	uint32_t ret[101][101] = { 0 };
	ret[1][1] = 1;
	uint32_t ntempi, ntempj;
	for (size_t i = 2; i < 101; i++)
	{
		for (size_t j = 1; j < i + 1; j++)
		{
			if (i == j)
				ret[i][j] = 1;
			else
			{
				ntempi = i - j;
				ntempj = ntempi > j ? j : ntempi;
				for (size_t m = 1; m < ntempj + 1; m++)
				{
					ret[i][j] += ret[ntempi][m];
				}
			}
		}
	}
	for (size_t i = 1; i < 100; i++)
	{
		m_nRet += ret[100][i];
	}
}

void CProblem77::CalcProblem(int n)
{
	uint32_t nCur = 2;
	uint32_t nAll = 0;
	vector<uint32_t>	allPrimer;
	allPrimer.push_back(2);
	map<uint32_t, vector<uint32_t>> allData;
	allData.insert(pair<uint32_t, vector<uint32_t>>(nCur, vector<uint32_t>(3, 0)));
	allData[2][2] = 1;
	uint32_t ntempi, ntempj;
	while (true)
	{
		nCur++;
		nAll = 0;
		allData.insert(pair<uint32_t, vector<uint32_t>>(nCur, vector<uint32_t>(nCur + 1, 0)));
		
		for (size_t i = 0; i < allPrimer.size(); i++)
		{
			ntempi = nCur - allPrimer[i];
			if (ntempi == 1)
				break;
			else
			{
				ntempj = ntempi > allPrimer[i] ? allPrimer[i] : ntempi;
				for (size_t j = 2; j < ntempj + 1; j++)
				{
					allData[nCur][allPrimer[i]] += allData[ntempi][j];
					nAll += allData[ntempi][j];
				}
			}
		}
		if (Isprime(nCur))
		{
			allData[nCur][nCur] = 1;
			allPrimer.push_back(nCur);
		}
		if (nAll > 5000)
		{
			m_nRet = nCur;
			break;
		}
	}
}

void CProblem78::CalcProblem(int n)
{
	uint32_t nCur = 1;
	uint32_t nAll = 0;
	vector<vector<uint32_t>> allData;
	allData.push_back(vector<uint32_t>(0));
	allData.push_back(vector<uint32_t>(2));
	allData[1][1] = 1;
	uint32_t ntempi, ntempj;
	while (true)
	{
		nCur++;
		nAll = 0;
		allData.push_back(vector<uint32_t>(nCur + 1, 0));
		allData[nCur][1] = 1;
		nAll += 1;
		for (size_t i = 2; i < nCur; i++)
		{
			ntempi = nCur - i;
			
			ntempj = ntempi > i ? i : ntempi;
			for (size_t j = 1; j < ntempj + 1; j++)
			{
				allData[nCur][i] += allData[ntempi][j];
				nAll += allData[ntempi][j];
			}
			allData[nCur][i] %= 1000000;
			nAll %= 1000000;
		}
		allData[nCur][nCur] = 1;
		nAll += 1;
		if (nAll == 1000000)
		{
			m_nRet = nCur;
			break;
		}
	}
} 