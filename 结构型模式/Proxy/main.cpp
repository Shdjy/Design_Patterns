#include <iostream>
#include <memory>

class Subject 
{
public:
    virtual void request() = 0;
};

class RealSubject : public Subject
{
public:
    void request() override 
    {
        std::cout << "RealSubject::request()" << std::endl;
    }
};

class Proxy : public Subject 
{
public:
    Proxy(){}

    void request() override
    {
        if (!_realSubject) 
        {
            std::cout << "Proxy::request(): create RealSubject" << std::endl;
            _realSubject = std::make_shared<RealSubject>();
        }
        std::cout << "Proxy::request()" << std::endl;
		_realSubject->request();

    }

private:
    std::shared_ptr<Subject> _realSubject;
};

int main() 
{
    //std::shared_ptr<Subject> realSubject = std::make_shared<RealSubject>();
    std::shared_ptr<Subject> proxy = std::make_shared<Proxy>();

    proxy->request();
    proxy->request();

    getchar();
    return 0;
}