#include <iostream>
#include <map>
#include <memory>
#include <string>
using namespace std;

//抽象享元类+具体享元类+享元工厂类
struct FontIntrinsic
{
    string fontName;
    int width = 0;
    string style;

    string ToKey()
    {
        return fontName + to_string(width) + style;
    }
};

class Font
{
public:
    virtual void Display(int size, string color) = 0;
};

class ConcreteFont : public Font
{
private:
    shared_ptr<FontIntrinsic> intrinsic;

public:
    ConcreteFont(shared_ptr<FontIntrinsic> intrinsic)
    {
        this->intrinsic = intrinsic;
    }

    void Display(int size, string color)
    {
        cout << "Font: " << intrinsic->fontName << ", Size: " << size << ", Color: " << color << endl;
    }
};

class FontFactory
{
private:
    map<string, shared_ptr<Font>> fontMap;

public:
    shared_ptr<Font> GetFont(shared_ptr<FontIntrinsic> intrinsic)
    {
        string key = intrinsic->ToKey();
        if (fontMap.find(key) == fontMap.end())
        {
            fontMap[key] = make_shared<ConcreteFont>(intrinsic);
        }
        return fontMap[key];
    }   
};

int main()
{
    FontFactory factory;
    shared_ptr<FontIntrinsic> intrinsic1 = make_shared<FontIntrinsic>();
    intrinsic1->fontName = "Arial";
    intrinsic1->width = 12;
    intrinsic1->style = "Bold";
    shared_ptr<Font> font1 = factory.GetFont(intrinsic1);

    shared_ptr<Font> font2 = factory.GetFont(intrinsic1);

    shared_ptr<FontIntrinsic> intrinsic3 = make_shared<FontIntrinsic>();
    intrinsic3->fontName = "Arial";
    intrinsic3->width = 12;
    intrinsic3->style = "Bold";
    shared_ptr<Font> font3 = factory.GetFont(intrinsic3);
    font3->Display(16, "Blue");

    font1->Display(6, "Red");
    font2->Display(16, "Green");
    if (font1 == font2)
    {
        cout << "font1 and font2 are the same instance" << endl;
    }
    else
    {
        cout << "font1 and font2 are different instances" << endl;
    }

    getchar();
    return 0;
}
