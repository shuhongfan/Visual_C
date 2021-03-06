// 例[Ex_Constructor] 设计类的构造函数
#include <iostream>
using namespace std;

class CPerson
{
public:	// 构造函数
	CPerson(char *str, float h, float w)
	{
		strcpy(name, str);		height = h;		weight = w;
	}
	CPerson(char *str)
	{
		strcpy(name, str);
	}
	CPerson(float h, float w = 120);
public:
	void print()
	{
		cout<<"姓名："<<name<<"\t身高："<<height<<"\t体重："<<weight<<endl;
	}
private:
	char  name[20];							// 姓名
	float  height;							// 身高
	float  weight;							// 体重
};

CPerson::CPerson(float h, float w)
{
	height = h;		weight = w;
}

int main()
{
	CPerson one("DING");
	one.print();
	CPerson two(170, 130);
	two.print();
	CPerson three("DING", 170, 130);
	three.print();
	return 0;
}