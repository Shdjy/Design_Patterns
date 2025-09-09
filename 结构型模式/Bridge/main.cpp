#include <iostream>
#include <memory>

using namespace std;

class Color
{
public:
    virtual void setColor() = 0;
    virtual ~Color() {}
};

class Red : public Color
{ 
    void setColor() override
    {
        cout << "Red color" << endl;
    }
};

class Green : public Color
{
    void setColor() override
    {
        cout << "Green color" << endl;
    }
};

class Shape
{
protected:
    shared_ptr<Color> m_color;
public:
    Shape(shared_ptr<Color> color): m_color(color) {}
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
public:
	Circle(shared_ptr<Color> color) : Shape(color)
    {
          
    }
    void draw() override
    {
        cout << "Drawing Circle with ";
        m_color->setColor();
        cout << endl;
    }
    ~Circle() {}
};

class Square : public Shape
{
public:
    Square (shared_ptr<Color> color): Shape(color)
    {
       
    }
    void draw() override
    {
        cout << "Drawing Square with ";
        m_color->setColor();
        cout << endl;
    }
};

int main()
{
    shared_ptr<Color> red(new Red);
    shared_ptr<Shape> circle = make_shared<Circle>(red);
    circle->draw();

    shared_ptr<Color> green(new Green);
    shared_ptr<Shape> square = make_shared<Square>(green);
    square->draw();

    getchar();
    return 0;
}