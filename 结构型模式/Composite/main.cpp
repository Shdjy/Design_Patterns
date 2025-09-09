#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Component {
public:
    virtual void operation() = 0;
    virtual void add(shared_ptr<Component> c) = 0;
    virtual void remove(shared_ptr<Component> c) = 0;
    virtual shared_ptr<Component> getChild(int i) = 0;
    virtual int getChildCount() = 0;
};

class Leaf : public Component {
public:
    void operation() override {
        cout << "Leaf operation" << endl;
    }
    void add(shared_ptr<Component> c) override {
        cout << "Cannot add to a leaf" << endl;
    }
    void remove(shared_ptr<Component> c) override {
        cout << "Cannot remove from a leaf" << endl;
    }
    shared_ptr<Component> getChild(int i) override {
        return nullptr;
    }
    int getChildCount() override {
        return 0;
    }
};

class Composite : public Component {
public:
    void operation() override {
        cout << "Composite operation" << endl;
        for (int i = 0; i < getChildCount(); i++) {
            getChild(i)->operation();
        }
    }
    void add(shared_ptr<Component> c) override {
        children.push_back(c);
    }
    void remove(shared_ptr<Component> c) override {
        for (int i = 0; i < getChildCount(); i++) {
            if (getChild(i) == c) {
                children.erase(children.begin() + i);
                return;
            }
        }
    }
    shared_ptr<Component> getChild(int i) override {
        return children[i];
    }
    int getChildCount() override {
        return children.size();
    }
private:
    vector<shared_ptr<Component>> children;
};

int main() {
    shared_ptr<Component> root = make_shared<Composite>();
    shared_ptr<Component> composite1 = make_shared<Composite>();
    shared_ptr<Component> composite2 = make_shared<Composite>();
    shared_ptr<Component> leaf1 = make_shared<Leaf>();
    shared_ptr<Component> leaf2 = make_shared<Leaf>();
    shared_ptr<Component> leaf3 = make_shared<Leaf>();

    root->add(composite1);
    root->add(composite2);
    composite1->add(leaf1);
    composite1->add(leaf2);
    composite2->add(leaf3);
    cout << "Root has " << root->getChildCount() << " children" << endl;
    root->operation();
    root->remove(composite1);
    cout << "Root has " << root->getChildCount() << " children" << endl;    
    root->operation();

    getchar();
    return 0;
}