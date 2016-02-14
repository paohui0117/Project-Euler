#pragma once
class CProblem31
{
public:
	CProblem31();
	virtual ~CProblem31();
public:
	void CalcProblem(int n);
	std::string GetString();
private:
	void Calc(int n, int nRest);
private:
	int		nTotal;
};
struct ret
{
	int n1;
	int n2;
	int nProduct;
	ret()
	{
		n1 = n2 = nProduct = 0;
	}
	bool operator==(const ret& a)
	{
		if (a.nProduct == nProduct)
			return true;
		return false;
	}
};
class CProblem32
{
public:
	CProblem32();
	virtual ~CProblem32();
public:
	void CalcProblem(int n);
	std::string GetString();
private:
	bool Check(int a);	//�ж������Ƿ����ظ�
	bool GetNext(ret& a);	//��ȡ��һ�����ظ����ֵ�
private:
	int					ndigital;
	std::vector<ret>	vecRet;
};

