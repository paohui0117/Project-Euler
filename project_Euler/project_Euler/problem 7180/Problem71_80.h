#pragma once
#include <set>
#include <vector>
#include "../CommonFun.h"
#include <map>
#include "../BigInt.h"
using namespace std;
#include "../CProblem.h"
class CProblem71 : public CProblem
{
public:
	CProblem71(){};
	virtual ~CProblem71(){};
public:
	virtual void CalcProblem(int n) override;
private:


};

class CProblem72 : public CProblem
{
public:
	CProblem72() {};
	virtual ~CProblem72() {};
public:
	virtual void CalcProblem(int n) override;
private:


};
//法雷数列
class CProblem73 : public CProblem
{
public:
	CProblem73() {};
	virtual ~CProblem73() {};
public:
	virtual void CalcProblem(int n) override;
private:
};

//太慢  需优化
class CProblem74 : public CProblem
{
public:
	CProblem74() {};
	virtual ~CProblem74() {};
public:
	bool GetTerms(uint32_t big_int);
	virtual void CalcProblem(int n) override;
private:
	vector<uint32_t>	m_vec;
	set<uint64_t>	m_setTemp;
	vector<uint32_t>	m_All;
};


class CProblem75 : public CProblem
{
public:
	CProblem75() {};
	virtual ~CProblem75() {};
public:
	virtual void CalcProblem(int n) override;
private:
	map<uint32_t, char>	m_map;
	int Check(uint32_t a, uint32_t b);
};

class CProblem76 : public CProblem
{
public:
	CProblem76() {};
	virtual ~CProblem76() {};
public:
	virtual void CalcProblem(int n) override;
private:
	
};
//动态规划
class CProblem77 : public CProblem
{
public:
	CProblem77() {};
	virtual ~CProblem77() {};
public:
	virtual void CalcProblem(int n) override;
private:

};

//动态规划
class CProblem78 : public CProblem
{
public:
	CProblem78() {};
	virtual ~CProblem78() {};
public:
	virtual void CalcProblem(int n) override;
private:

};