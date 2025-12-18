#include <iostream>

// vtable struct
struct VTable {
    int id;                       // info
};

// Base class
struct Base {
    VTable* vptr;                   // pointer դեպի vtable
};

// Derived class
struct Derived {
    VTable* vptr;                   // նույն տեղում vptr , որ Base-ը կարդա ճիշտ տեղից
    int x;                          // Քաստից հետո տվյալը ցույց տալու համար
};

// Base-ի vtable-ը
VTable base_vtable = { 1 };         // id = 1 (Base)

// Derived-ի vtable-ը
VTable derived_vtable = { 2 };      // id = 2 (Derived)

// dynamic_cast-ը
Derived* my_dynamic_cast(Base* b) {

    // Եթե Base pointer-ը դատարկ է
    if (b == nullptr)
        return nullptr;             // վերադարձնում ենք nullptr

    // Ստուգում ենք՝ արդյոք սա Derived է
    if (b->vptr == &derived_vtable) // vtable-ների համեմատում
        return (Derived*)b;         // CAST → Base* → Derived*

    // Եթե id-ին չի համապատասխանում
    return nullptr;                 // cast չեղավ
}

int main() {

    Derived d;

    d.vptr = &derived_vtable;
    d.x = 10;

    // Derived օբյեկտը դիտում ենք որպես Base-ի օբյեկտ
    Base* b = (Base*)&d;            // CAST → Derived* → Base*

    Derived* result = my_dynamic_cast(b);

    if (result)
        std::cout << result->x;     // կտպի 10
    else
        std::cout << "nullptr";     // հակառակ դեպքում
}
