#include <iostream>
#include <memory.h>

using namespace std;

class Handler
{
protected:
    shared_ptr<Handler> nextHandler;
public:
    virtual void handle(int level, const char* message) = 0;
    void setNextHandler(shared_ptr<Handler> handler) 
    {
        nextHandler = handler;
    }
};

class HandlerA : public Handler 
{
public:
    void handle(int level, const char* message) 
    {
        if (level == 1) 
        {
            cout << "HandlerA: " << message << endl;
        } else
        {
            if (nextHandler) 
            {
                nextHandler->handle(level, message);
            }
        }
    }
};

class HandlerB : public Handler 
{
public:
    void handle(int level, const char* message)
    {
        if (level >= 2) 
        {
            cout << "HandlerB: " << message << endl;
        } else 
        {
            if (nextHandler) 
            {
                nextHandler->handle(level, message);
            }
        }
    }
};

int main()
{
    shared_ptr<Handler> handlerA(new HandlerA);
    shared_ptr<Handler> handlerB(new HandlerB);
    handlerA->setNextHandler(handlerB);

    handlerA->handle(1, "Level 1 message");
    handlerA->handle(2, "Level 2 message");
    handlerA->handle(3, "Level 3 message");

    getchar();
    return 0;
}
