#pragma once
#include <set>
#include <vector>
#include "../CommonFun.h"
#include <map>
#include "../BigInt.h"
using namespace std;
#include "../CProblem.h"
class CProblem61 : public CProblem
{
public:
	CProblem61(){};
	virtual ~CProblem61(){};
public:
	virtual void CalcProblem(int n) override;
private:
	bool IsTriangle(uint64_t n);
	bool IsSquare(uint64_t n);
	bool IsPentagonal(uint64_t n);
	bool IsHexagonal(uint64_t n);
	bool IsHeptagonal(uint64_t n);
	bool IsOctagonal(uint64_t n);
private:
	set<uint32_t> m_set[6];
	uint32_t m_ret[6];
};
//Ì«Âý  ÒªÓÅ»¯
class CProblem62 : public CProblem
{
public:
	CProblem62() {};
	virtual ~CProblem62() {};
public:
	virtual void CalcProblem(int n) override;
private:
	bool SameDigits(uint64_t	n);
	void GetAllDigits(uint64_t n);
	char					m_Digitals[10];
	uint64_t				m_nMax;
	uint64_t				m_nMin;
};


class CProblem63 : public CProblem
{
public:
	CProblem63() {};
	virtual ~CProblem63() {};
public:
	virtual void CalcProblem(int n) override;

};

class CProblem64 : public CProblem
{
public:
	CProblem64() {};
	virtual ~CProblem64() {};
public:
	virtual void CalcProblem(int n) override;
private:
	int GePteriod(int n);
private:
};

class CProblem65 : public CProblem
{
public:
	CProblem65() {};
	virtual ~CProblem65() {};
public:
	virtual void CalcProblem(int n) override;
private:

};

class CProblem66 : public CProblem
{
public:
	CProblem66();
	virtual ~CProblem66() {};
public:
	virtual void CalcProblem(int n) override;
private:
	void GetFractions(int n);
	vector<uint32_t>	m_vecSquare;
	vector<uint8_t>		m_vecFractions;
	BigInt				m_cur;
};

