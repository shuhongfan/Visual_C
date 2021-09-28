// [例Ex_VirtualFunc] 虚函数的动态联编
#include <iostream>
using namespace std;
class CShape{
public:
	virtual float area()	
	{ 	return 0.0;	}							
};
class CTriangle:public CShape
{
public:
	CTriangle(float h = 0, float w = 0)	
	{ 	H = h;	 W = w;	}
	float area()
	{	return (float)(H * W * 0.5); }	
private:
	float H, W;
};
class CCircle:public CShape
{
public:
	CCircle(float r = 0)	
	{	R = r;	}
	virtual float area( )
	{	return (float)(3.14159265 * R * R);	}
private:
	float R;
};

int main()
{
	CTriangle tri( 3, 4 );
	cout<<"tri.area() = "<<tri.area()<<endl;
	CCircle cir(5);
	cout<<"cir.area() = "<<cir.area()<<endl;

	CShape *s1 = &tri;
	cout<<"s1->area() = "<<s1->area()<<endl;
	CShape &s2 = cir;
	cout<<"s2.area() = "<<s2.area()<<endl;	

	return 0;
}

