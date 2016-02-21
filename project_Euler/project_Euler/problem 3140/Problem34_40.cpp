#include "stdafx.h"
#include "Problem34_40.h"
#include <set>
#include <map>

CProblem34::CProblem34() : n9(362880) //9!
{
	
}


CProblem34::~CProblem34()
{
}

void CProblem34::CalcProblem(int n)
{
	int nMax = GetMax();
	m_vecn.push_back(1);
	for (size_t i = 1; i < 10; i++)
	{
		if (i == 1)
			m_vecn.push_back(i);
		else
			m_vecn.push_back(m_vecn[i - 1] * i);
	}
	m_Sum = 0;
	for (size_t i = 3; i < nMax; i++)
	{
		if (i == GetSumOfFactorial(i))
		{
			m_Sum += i;
			m_vecRet.push_back(i);
		}
			
	}
}

int CProblem34::GetMax()
{
	int nret = n9;
	int ncur = 100000;
	int nc = 6;
	while (nret * nc > ncur)
	{
		nc++;
		ncur *= 10;
	}
	return nret * nc;
}

int CProblem34::GetSumOfFactorial(int ncur)
{
	if (ncur < 0)
		return 0;
	if (ncur < 10)
		return m_vecn[ncur];
	int nret = 0;
	int nc = 0;
	nc = ncur % 10;
	while(ncur > 0)
	{
		nret += m_vecn[nc];
		ncur /= 10;
		nc = ncur % 10;
	}
	return nret;
}
string CProblem34::GetString()
{
	char a[32] = {0};
	sprintf_s(a, "%d", m_Sum);
	return a;
}

CProblem35::CProblem35()
{
}

CProblem35::~CProblem35()
{
}

void CProblem35::CalcProblem(int n)
{
	m_nret = 0;
	m_vecPrime.clear();
	m_max = n;

	for (size_t i = 2; i < m_max; i++)
	{
		if (IsPrimeNumber(i))
		{
			if (IsCircularPrimes(i))
				m_nret++;
		}
	}
}

string CProblem35::GetString()
{
	char a[32] = { 0 };
	sprintf_s(a, "%d", m_nret);
	return a;
}

bool CProblem35::IsPrimeNumber(int n)
{
	if (n < 0)
		return false;
	if (n < 4)
		return true;
	int nn = sqrt(n);
	nn++;
	for (size_t i = 2; i < nn; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

bool CProblem35::IsCircularPrimes(int n)
{
	if (n < 10)
		return true;
	m_vecCur.clear();
	int ntemp;
	int ncur = n;
	int nsize = 1;
	while (n > 10)
	{
		ntemp = n % 10;
		if (ntemp % 2 == 0 || ntemp % 5 == 0)
			return false;
		m_vecCur.push_back(n % 10);
		n /= 10;
		nsize++;
	}
	int nn = pow(10, nsize - 1);
	while (nsize > 1)
	{
		nsize--;
		ntemp = ncur / nn;
		ncur = ncur % nn * 10 + ntemp;
		if (!IsPrimeNumber(ncur))
			return false;
	}
	return true;
}

CProblem36::CProblem36()
{
}

CProblem36::~CProblem36()
{
}

void CProblem36::CalcProblem(int n)
{
	m_nRet = 0;
	for (size_t i = 1; i < n + 1; i++)
	{
		if (i & 1 == 1)
		{
			if (IsPalindromic10(i) && IsPalindromic2(i))
			{
				m_vec.push_back(i);
				m_nRet += i;
			}
				
		}
	}
}

string CProblem36::GetString()
{
	char a[32] = { 0 };
	sprintf_s(a, "%d", m_nRet);
	return a;
}

bool CProblem36::IsPalindromic10(int n)
{
	if (n < 1)
		return false;
	int nlast = n;
	int ncur = 0;
	while (n > 0)
	{
		ncur *= 10;
		ncur += n % 10;
		n /= 10;
	}
	return nlast == ncur;
}

bool CProblem36::IsPalindromic2(int n)
{
	if (n < 1)
		return false;
	int nlast = n;
	int ncur = 0;
	while (n > 0)
	{
		ncur <<= 1;
		ncur += n & 1;
		n >>= 1;
	}
	return nlast == ncur;
}

void CProblem37::CalcProblem(int n)
{
	int ncur = 0;
	int i = 10;
	m_nRet = 0;
	while (ncur < 11)
	{
		if (IsTruncatablePrimes(i))
		{
			m_vec.push_back(i);
			ncur++;
			m_nRet += i;
		}
		i++;
	}
}

string CProblem37::GetString()
{
	char a[32] = { 0 };
	sprintf_s(a, "%d", m_nRet);
	return a;
}

bool CProblem37::IsTruncatablePrimes(int n)
{
	if  (n < 10)
		return false;
	//right to left
	int ncur = n;
	while(ncur > 0)
	{
		if (!Isprime(ncur))
			return false;
		ncur /= 10;
	}
	ncur = n;
	//left to right
	int nn = 10;
	while (ncur / nn > 10)
	{
		nn *= 10;
	}
	ncur %= nn;
	while (ncur > 0)
	{
		if (!Isprime(ncur))
			return false;
		nn /= 10;
		ncur %= nn;
	}
	return true;
}

void CProblem38::CalcProblem(int n)
{
	m_nRet = 0;
	int nmax = 9876;
	vector<int> vecTemp;
	int ncur = 0;
	int ndigit = 0;
	int ntemp = 0;
	for (size_t i = 0; i < 9; i++)
	{
		vecTemp.push_back(pow(10, i));
	}
	for (size_t i = 2; i < 9876; i++)
	{
		int nn = 9;
		ncur = 0;
		for (size_t j = 1; j < 10; j++)
		{
			ntemp = i * j;
			ndigit = GetDigit(ntemp);
			nn -= ndigit;
			if (nn < 0)
				break;
			ncur += ntemp * vecTemp[nn];
			if (nn == 0)
			{
				if (IsConcatenatedProduct(ncur) && ncur > m_nRet)
					m_nRet = ncur;
			}
		}
	}
}

string CProblem38::GetString()
{
	char a[32] = { 0 };
	sprintf_s(a, "%d", m_nRet);
	return a;
}

bool CProblem38::IsConcatenatedProduct(int n)
{
	if (n < 123456789 || n > 987654321)
		return false;
	set<int> temp;
	int ntemp;
	while (n > 0)
	{
		ntemp = n % 10;
		if (ntemp == 0)
			return false;
		if (!temp.insert(ntemp).second)
		{
			return false;
		}
		n /= 10;
	}
	return true;
}

void CProblem39::CalcProblem(int n)
{
	m_nRet = 0;
	int ntemp = 0;
	if (GetAllRightAngleTriangle(n / 2 - 1))
	{
		map<int, int> temp;
		map<int, int>::iterator itemp;

		for (size_t i = 0; i < m_vecTriangle.size(); i++)
		{
			itemp = temp.find(m_vecTriangle[i].d);
			if (itemp == temp.end())
			{
				temp.insert(pair<int, int>(m_vecTriangle[i].d, 1));
				if (ntemp < 1)
				{
					ntemp = 1;
					m_nRet = m_vecTriangle[i].d;
				}
			}
			else
			{
				itemp->second++;
				if (ntemp < itemp->second)
				{
					ntemp = itemp->second;
					m_nRet = m_vecTriangle[i].d;
				}
			}
		}
	}
}

string CProblem39::GetString()
{
	char a[32] = { 0 };
	sprintf_s(a, "%d", m_nRet);
	return a;
}

bool CProblem39::GetAllRightAngleTriangle(int n)
{
	m_set.clear();
	if (n < 1)
		return false;
	for (size_t i = 1; i < n + 1; i++)
	{
		m_set.insert(i * i);
	}
	set<int>::iterator itor1 = m_set.begin();
	set<int>::iterator itor2 = itor1;
	set<int>::iterator itemp;
	MyStruct temp;
	while (itor1 != m_set.end())
	{
		itor2 = itor1;
		while (itor2 != m_set.end())
		{
			itemp = m_set.find(*itor1 + *itor2);
			if (itemp != m_set.end())
			{
				temp.a = sqrt(*itor1);
				temp.b = sqrt(*itor2);
				temp.c = sqrt(*itemp);
				temp.d = temp.a + temp.b + temp.c;
				if (temp.d > 1000)
					break;
				m_vecTriangle.push_back(temp);
			}
			itor2++;
		}
		itor1++;
	}
	return true;
}

void CProblem40::CalcProblem(int n)
{
	m_nRet = 1;
	m_nRet *= GetNthDigit(1);
	m_nRet *= GetNthDigit(10);
	m_nRet *= GetNthDigit(100);
	m_nRet *= GetNthDigit(1000);
	m_nRet *= GetNthDigit(10000);
	m_nRet *= GetNthDigit(100000);
	m_nRet *= GetNthDigit(1000000);
}

string CProblem40::GetString()
{
	char a[32] = { 0 };
	sprintf_s(a, "%d", m_nRet);
	return a;
}

int CProblem40::GetNthDigit(int n)
{
	if (n < 1)
		return 0;
	if (n < 10)
		return n;
	int ncur = 9;
	int nn = 1;
	int nsize = 9;
	while (ncur < n)
	{
		nn++;
		nsize = nsize * 10;
		ncur += nn * nsize;
	}
	int nl = nn * nsize - ncur + n;
	int ni = nl % nn;
	int nj = nl / nn;
	if (ni == 0)
		return (nj - 1) % 10;
	else
	{
		int ntemp = pow(10, nn - 1) + nj;
		int nnn = nn - ni;
		ntemp /= pow(10, nnn);
		return ntemp % 10;
	}
}