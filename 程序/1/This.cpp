// [例Ex_This] 使用this指针
#include <iostream>
using namespace std;

class CPoint
{
public:
	CPoint( int x = 0, int y = 0 ) 	
	{ 	
		this->xPos = x; 		this->yPos = y; 	
	} 
public:	// 加操作
	void Copy( CPoint one)
	{
		*this = one;			// 直接通过this赋值
	}

public:
	void  Print() 	
	{ 
		cout<<"Point("<<xPos<<", " <<yPos<<")"<< endl; 	
	}  
private:    
	int xPos,  yPos;
};

int main()
{
	CPoint pt1(10, 20), pt2(30, 40);
	pt1.Print();
	pt1.Copy(pt2);
	pt1.Print();
	return 0;
}

