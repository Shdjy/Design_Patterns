#include <iostream>
#include <memory.h>

using namespace std;

class Component {
public:
    virtual void operation() = 0;
};

class ConcreteComponent : public Component {
public:
    void operation() {
        cout << "ConcreteComponent operation" << endl;
    }
};

class Decorator : public Component {
public:
    Decorator(Component* component) {
        this->component = component;
    }

    void operation() {
        component->operation();
    }

private:
    Component* component;
};

class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {
    }

    void operation() {
        Decorator::operation();
        cout << "ConcreteDecoratorA operation" << endl;
    }
};

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {
    }

    void operation() {
        Decorator::operation();
        cout << "ConcreteDecoratorB operation" << endl;
    }
};

int main() {
    Component* component = new ConcreteComponent();
    ConcreteDecoratorA* decoratorA = new ConcreteDecoratorA(component);
    ConcreteDecoratorB* decoratorB = new ConcreteDecoratorB(decoratorA);

    decoratorB->operation();

    delete component;
    delete decoratorA;
    delete decoratorB;

    getchar();
    return 0;
}
