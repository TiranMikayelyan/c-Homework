
/*base class pointer/reference-ով կանչում ենք ֆունկցիա,
բայց իրականում աշխատում է derived class-ի override արած տարբերակը։*/

#include <iostream>        
using namespace std;       

// Base class
class Animal {               
public:
    virtual void sound() {   // virtual ֆունկցիա → dynamic polymorphism
        cout << "Animal makes a sound" << endl; // base class-ի output
    }
    virtual ~Animal() = default; // virtual destructor, default , որ compiler-ը սարքի դեստրուկտորը, բայց վիրտուալ

};

// Derived classеs
class Dog : public Animal {  
public:
    void sound() override {  // override  փոխարինում ենք base-ի virtual-ը
        cout << "Dog barks" << endl; // Dog classi otput
    }
};


class Cat : public Animal {
public:
    void sound() override {  // override  փոխարինում ենք base-ի virtual-ը
        cout << "Cat Meows" << endl; // Cat class-ի otput
    }

};
int main() {                 
    Animal* a;      
    Dog d;
    Cat  c;

    a = &d;                  // base pointer-ը ցույց է տալիս Dog օբյեկտի վրա
    a->sound();              // runtime-ում որոշվում է կանչվում է Dog::sound()
    
    a= &c;
    a->sound();              // կաշխատի cat-ի sound()-ը
    
    
    Animal b;
    b.sound();               // կաշխատի animal-ի sound()-ը
    return 0;               
}
