#pragma once
#include <set>
using namespace std;
#include "../CProblem.h"
class CProblem41 : public CProblem
{
public:
	CProblem41(){};
	virtual ~CProblem41(){};
public:
	virtual void CalcProblem(int n) override;
private:
	bool IsPandigital(int n);
};

class CProblem42 : public CProblem
{
public:
	CProblem42() {};
	virtual ~CProblem42() {};
public:
	virtual void CalcProblem(int n) override;
private:
	bool CalcAllWords();
	bool IsTriangleWord(int n);
private:
	vector<string>	m_vecWords;	//所有的单词
};
class CProblem44 : public CProblem
{
public:
	CProblem44() {};
	virtual ~CProblem44() {};
public:
	virtual void CalcProblem(int n) override;
private:
	bool IsPentagonalNumbers(int n);
private:
	vector<int>		m_All;
};

class CProblem45 : public CProblem
{
public:
	CProblem45() {};
	virtual ~CProblem45() {};
public:
	virtual void CalcProblem(int n) override;
private:
	bool IsPentagonalNumbers(uint64_t n);
	bool IsTriangle(uint64_t n);
	bool IsHexagonal(uint64_t n);
private:

};

class CProblem46 : public CProblem
{
public:
	CProblem46() {};
	virtual ~CProblem46() {};
public:
	virtual void CalcProblem(int n) override;
private:
	bool IsCorrect(uint64_t n);
private:
	set<uint64_t>		m_setPrime;
	set<uint64_t>		m_set;
};

class CProblem47 : public CProblem
{
public:
	CProblem47() {};
	virtual ~CProblem47() {};
public:
	virtual void CalcProblem(int n) override;
private:
	int GetAllPrimeFactors(uint64_t n);
private:
	set<uint64_t>		m_set;
};

class CProblem48 : public CProblem
{
public:
	CProblem48() {};
	virtual ~CProblem48() {};
public:
	
	virtual void CalcProblem(int n) override;
	virtual string GetString() override;
private:
	void GetSelfPower(uint32_t n);
	void Multiplied(uint32_t n);
	void Add();
private:
	uint32_t	ret[10];
	uint32_t	cur[10];
};

class CProblem49 : public CProblem
{
public:
	CProblem49() {};
	virtual ~CProblem49() {};
public:
	int IsSameDigit(int itor, int itor2, int ntemp);
	virtual void CalcProblem(int n) override;
	virtual string GetString() override;
private:
private:
	set<int>	m_prime;
	string strret;
};

