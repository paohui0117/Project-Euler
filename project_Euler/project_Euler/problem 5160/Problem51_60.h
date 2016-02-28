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
//不知道花色的具体大小排序
class CProblem54 : public CProblem
{
public:
	CProblem54() {};
	virtual ~CProblem54() {};
public:
	virtual void CalcProblem(int n) override;
private:
};
//本题是凑巧得出正确结果   需要bigint类型  uint64不能满足
class CProblem55 : public CProblem
{
public:
	CProblem55() {};
	virtual ~CProblem55() {};
public:
	virtual void CalcProblem(int n) override;
private:
	uint64_t Reverse(uint64_t n);
};

