#pragma once
#include <set>
#include <vector>
#include "../CommonFun.h"
#include <map>
#include "../BigInt.h"
using namespace std;
#include "../CProblem.h"
class CProblem51 : public CProblem
{
public:
	CProblem51(){};
	virtual ~CProblem51(){};
public:
	
	virtual void CalcProblem(int n) override;
private:
	bool CheckAllPossible(char no);
	bool Check(int ncur);
	set<char> m_temp;
	vector<char> m_vectemp;
	set<int> m_setChecked;
};


class CProblem52 : public CProblem
{
public:
	CProblem52() {};
	virtual ~CProblem52() {};
public:
	virtual void CalcProblem(int n) override;
private:
	bool Check(int& n);
	set<char>	m_setTemp;
};


class CProblem53 : public CProblem
{
public:
	CProblem53() {};
	virtual ~CProblem53() {};
public:
	virtual void CalcProblem(int n) override;
private:
	vector<BigInt>	m_vecFactorial;
};

