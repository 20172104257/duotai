// duotai.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class CFeet
{
protected:
	int feet;
	int inches;
public:
	CFeet();
	virtual void display();//虚函数
	void setfeet(int f);
	void setinches(int i);
	int getfeet();
	int getinches();
};
CFeet::CFeet()
{
	feet = 0;
	inches = 0;
}
void CFeet::setfeet(int f)
{
	feet = f;
}
void CFeet::setinches(int i)
{
	inches = i % 12;
	feet = feet + i / 12;
}
void CFeet::display()
{
	cout << "基类" << feet << "英尺" << inches << "英尺" << endl;
}
int CFeet::getfeet()
{
	return feet;
}
int CFeet::getinches()
{
	return inches;
}
class CMyFeet :public CFeet
{
public:
	void display();
};
void CMyFeet::display()
{
	cout << "派生类" << feet << "英尺" << inches << "英尺" << endl;
}
int main()
{
	CFeet *p;//对象指针
	p = new CMyFeet;//CMyFeet AFeet;   p=&AFeet
	p->setfeet(4);
	p->setinches(9);
	p->display();
	p->CFeet::display();//P可以访问基类和派生类
	return 0;
}