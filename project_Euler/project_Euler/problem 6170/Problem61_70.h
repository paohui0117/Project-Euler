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

