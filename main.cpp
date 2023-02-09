#include <iostream>
#include <memory>

class Parent {
public:
    virtual int getAge() const {
        return _age;
    }
    virtual const std::string& getName() const {
        return _name;
    }
    virtual ~Parent() {}

private:
    int _age;
    std::string _name = "Parent";
};

class Child : public Parent {
public:
    Child(int age) : _age(age) {}
    int getAge() const override {
        return _age;
    }
    const std::string& getName() const override {
        return _name;
    }
private:
    int _age;
    std::string _name = "Child";
};


void report(std::shared_ptr<Parent> ptr)
{
    if (ptr) {
        std::cout << "*ptr=" << ptr << "\n";
    }
    else {
        std::cout << "ptr is not a valid pointer.\n";
    }
}


void funcChild(std::shared_ptr<Child> childPtr) {

    std::cout << "Inside funcChild" << std::endl;
    std::cout << childPtr->getAge() << std::endl;
    std::cout << childPtr->getName() << std::endl;
}

int main() {

    std::shared_ptr<Parent> p = std::make_shared<Child>(4);
    std::cout << p->getAge() << std::endl;
    std::cout << p->getName() << std::endl;
    std::cout << "==================" << std::endl;

    std::shared_ptr<Child> ch = std::make_shared<Child>(5);
    std::shared_ptr<Parent> p1 = std::dynamic_pointer_cast<Parent>(ch);
    std::cout << p1->getAge() << std::endl;
    std::cout << p1->getName() << std::endl;
    std::cout << "==================" << std::endl;

    funcChild(ch);
    std::cout << "==================" << std::endl;
    report(p1);
    std::cout << "==================" << std::endl;
    std::shared_ptr<Parent> p2;
    report(p2);
    std::cout << "==================" << std::endl;   
    report(ch);


    /* if (p1 == nullptr) {
        std::cout << "Shared_ptr<Parent> p1 is nullptr" << std::endl;
    }

    try {
        std::shared_ptr<Parent> p1 = std::dynamic_pointer_cast<Parent>(ch);
    }
    catch (std::bad_cast& e) {
        std::cout <<
            "dynamic_pointer_cast<Parent>(ch) results in bad_cast" << std::endl;
        std::cout << e.what() << std::endl;
    }*/
     

    return 0;
}


