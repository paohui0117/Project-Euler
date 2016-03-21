// myobjecttest.cpp : 定义控制台应用程序的入口点。
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

