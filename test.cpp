#include <iostream>
#include <vector>
#include <cmath>
class Shape
{
protected:
    int a;
public:
    virtual int FindArea() = 0;
    virtual int Perimeter() = 0;
};
class Circle : public Shape
{
public:
    Circle(int radius)
    {
        this->a = radius;
    }
    int Perimeter() override
    {
        return 2 * 3.14 * this->a;
    }
    int FindArea() override
    {
        return 3.14 * this->a * this->a;
    }
};
class Triangle : public Shape
{
public:
    Triangle(int side)
    {
        this->a = side;
    }
    int Perimeter() override
    {
        return this->a * 3;
    }
    int FindArea() override
    {
        return ((this->a * this->a) * sqrt(3)) / 4;
    }
};

int main()
{
    Circle a(5);
    Triangle b(5);
    Shape* shape1 = &a;
    std::cout << shape1->Perimeter() << ' ';
    std::cout << shape1->FindArea() << '\n';
    Shape* shape2 = &b;
    std::cout << shape2->Perimeter() << ' ';
    std::cout << shape2->FindArea();
}

