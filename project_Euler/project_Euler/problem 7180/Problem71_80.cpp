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