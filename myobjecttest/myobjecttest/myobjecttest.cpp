// myobjecttest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "MyTest.h"
CMyTest TakeTest()
{
	CMyTest a;
	a.a = 10;
	return a;
}
int main()
{
	CMyTest b = TakeTest();
    return 0;
}

