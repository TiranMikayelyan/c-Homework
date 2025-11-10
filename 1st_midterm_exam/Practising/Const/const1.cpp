#include <iostream>
int main(){
int a = 10;
int* p = &a;       

std::cout << *p << std::endl;   


int c = 10, d= 20;
const int* t = &d;

std::cout << *t << std::endl;   
t = &c;



char text[] = "Barev";
const char* k = text;

std::cout << *k << std::endl;  
k++;                           
std::cout << *k << std::endl;  


}
