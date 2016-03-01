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

class CProblem56 : public CProblem
{
public:
	CProblem56() {};
	virtual ~CProblem56() {};
public:
	virtual void CalcProblem(int n) override;
private:
};

class CProblem57 : public CProblem
{
public:
	CProblem57() {};
	virtual ~CProblem57() {};
public:
	virtual void CalcProblem(int n) override;
private:
	int GetDigits(uint64_t n);
};

class CProblem58 : public CProblem
{
public:
	CProblem58() {};
	virtual ~CProblem58() {};
public:
	virtual void CalcProblem(int n) override;
private:
	
};
//没有更好的方法
//碰巧算出的第一组就是答案  没有严密的数学推理  需要改进
class CProblem60 : public CProblem
{
public:
	CProblem60() {};
	virtual ~CProblem60() {};
public:
	virtual void CalcProblem(int n) override;
private:
	bool IsAllPrime(uint64_t a);
	uint64_t m_Temp[5];
	int m_Start[5];
	int m_ncur;
	vector<uint64_t> m_vecAll;
};

