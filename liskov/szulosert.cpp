#include<iostream>
class Rectangle
{
public:
int m_width;
int m_height;
Rectangle(int width, int height) {
m_width = width;
m_height = height;
}
int getWidth(){
return m_width;
}
int getHeight(){
return m_height;
}
};
class Square : public Rectangle
{
public:
Square(int side): Rectangle(side, side)
{
m_width = side;
m_height = side;
}
int getArea(){
    return m_width * m_height;
}
};
int main ()
{
Rectangle* r = new Square(10);
Square* s = new Square(10);
std::cout << s->getArea() << r->getArea() << std::endl;;
}