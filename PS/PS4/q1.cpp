/* library */
#include <iostream>
#include <cstdlib>

using namespace std;

/* Class defined */
class vector2d
{	
public: 
	vector2d();  
	vector2d(int _x, int _y); 
	void set_x_y(int _x, int _y);
	int get_x();
	int get_y(); 
	int operator *(const vector2d &other);
	
private:
	int x,y;
};

/* Constructor */
vector2d::vector2d()
{
	x=0;
	y=0;
}

vector2d::vector2d(int _x, int _y)
{
	x=_x;
	y=_y;
}

void vector2d::set_x_y(int _x, int _y)
{
	x=_x;
	y=_y;
}

int vector2d::get_x()
{
	return x;
}
int vector2d::get_y()
{
	return y;
}

/* Dot Product */
int vector2d::operator *(const vector2d &other)
{ 
	return (this->x^other.x) + (this->y^other.y);    
}

int main()
{
	/* Some test vectors */
	vector2d v1(8,0), v2(0,8), v3(4,4), v4(3,2);
	cout << "(" << v1.get_x() << "," << v1.get_y() << ") * (" << v2.get_x()
	<< "," << v2.get_y() << ") = " << v1*v2 << endl;
	cout << "(" << v2.get_x() << "," << v2.get_y() << ") * (" << v3.get_x()
	<< "," << v3.get_y() << ") = " << v2*v3 << endl;
	cout << "(" << v3.get_x() << "," << v3.get_y() << ") * (" << v4.get_x()
	<< "," << v4.get_y() << ") = " << v3*v4 << endl;
	return 0;
}
