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

