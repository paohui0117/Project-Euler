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