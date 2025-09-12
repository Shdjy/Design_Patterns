#include <iostream>
#include <memory.h>

using namespace std;

class Strategy
{
public:
    virtual void algorithm() = 0;
};

class StrategyA : public Strategy
{
public:
    void algorithm()
    {
        cout << "StrategyA" << endl;
    }
};

class StrategyB : public Strategy 
{
public:
    void algorithm() 
    {
        cout << "StrategyB" << endl;
    }
};

class Context
{
private:
    unique_ptr<Strategy> strategy;
public:
    Context(unique_ptr<Strategy> s)
    {
        strategy = move(s);
    }
    void contextInterface()
    {
        strategy->algorithm();
    }
};

int main()
{
    unique_ptr<Strategy> s1(new StrategyA);
    unique_ptr<Strategy> s2(new StrategyB);
    Context c1(move(s1));
    Context c2(move(s2));
    c1.contextInterface();
    c2.contextInterface();

    getchar();
    return 0;
}