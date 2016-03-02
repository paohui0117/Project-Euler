#include "stdafx.h"
#include "Problem61_70.h"
#include <fstream>
#include "../CommonFun.h"


void CProblem61::CalcProblem(int nn)
{
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