#include <iostream>
#include <memory.h>

using namespace	std;

class Shape
{
public:
	virtual void SetShape() = 0;
};

class Circle : public Shape
{
public:
	void SetShape()
	{
		cout << "Drawing a circle" << endl;
	}
};

class Rectangle : public Shape
{
public:
	void SetShape()
	{
		cout << "Drawing a rectangle" << endl;
	}
};

class Color
{
public:
	virtual void fill() = 0;
};

class RedColor : public Color
{
public:
	void fill()
	{
		cout << "Filling with red color" << endl;
	}
};

class YellowColor : public Color
{
public:
	void fill()
	{
		cout << "Filling with yellow color" << endl;
	}
};
class ShapSize
{
public:
	virtual void setSize() = 0;
};

class SmallSize : public ShapSize
{
public:
	void setSize()
	{
		cout << "Setting size to small" << endl;
	}
};

class MediumSize : public ShapSize
{
public:
	void setSize()
	{
		cout << "Setting size to medium" << endl;
	}
};

class LargeSize : public ShapSize
{
public:
	void setSize()
	{
		cout << "Setting size to large" << endl;
	}
};
class Graphic
{
private:
	Shape* shape = nullptr;
	Color* color = nullptr;
	ShapSize* size = nullptr;
public:
	Graphic(Shape* s, Color* c, ShapSize* sz)
	{
		shape = s;
		color = c;
		size = sz;
	}
	~Graphic()
	{
		delete shape;
		delete color;
		delete size;
	}
	void draw()
	{
		shape->SetShape();
		color->fill();
		size->setSize();
	}
};

class GraphicFactory
{
public:
	GraphicFactory()
	{
	}
	virtual unique_ptr<Graphic> createGraphic() = 0;

	//unique_ptr<Graphic> graphic;
};

class ErrorGraphicFactory : public GraphicFactory
{
public:
	unique_ptr<Graphic> createGraphic()
	{
		return make_unique<Graphic>(new Circle(), new RedColor(), new LargeSize());
	}
};

class WarningGraphicFactory : public GraphicFactory
{
public:
	unique_ptr<Graphic> createGraphic()
	{
		return make_unique<Graphic>(new Rectangle(), new YellowColor(), new MediumSize());
	}
};

int main()
{
	unique_ptr<GraphicFactory> errorFactory = make_unique<ErrorGraphicFactory>();
	unique_ptr<Graphic> errorGraphic = errorFactory->createGraphic();
	errorGraphic->draw();
	unique_ptr<GraphicFactory> warningFactory = make_unique<WarningGraphicFactory>();
	unique_ptr<Graphic> warningGraphic = warningFactory->createGraphic();
	warningGraphic->draw();

	getchar();
	return 0;
}