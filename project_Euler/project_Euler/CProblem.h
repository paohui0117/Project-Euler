#pragma once
using namespace std;
class CProblem
{
public:
	CProblem() { m_nRet = 0; };
	virtual ~CProblem() {};
public:
	virtual void CalcProblem(int n) = 0;
	virtual string GetString()
	{
		char a[32] = { 0 };
		sprintf_s(a, "%llu", m_nRet);
		return a;
	}
protected:
	uint64_t		m_nRet;
};
