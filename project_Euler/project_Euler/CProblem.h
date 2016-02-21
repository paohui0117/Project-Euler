#pragma once
using namespace std;
class CProblem
{
public:
	CProblem() {};
	virtual ~CProblem() {};
public:
	virtual void CalcProblem(int n) = 0;
	virtual string GetString()
	{
		char a[32] = { 0 };
		sprintf_s(a, "%d", m_nRet);
		return a;
	}
protected:
	int		m_nRet;
};
