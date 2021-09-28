// ��[Ex_Constructor] �����Ĺ��캯��
#include <iostream>
using namespace std;

class CPerson
{
public:	// ���캯��
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
		cout<<"������"<<name<<"\t��ߣ�"<<height<<"\t���أ�"<<weight<<endl;
	}
private:
	char  name[20];							// ����
	float  height;							// ���
	float  weight;							// ����
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