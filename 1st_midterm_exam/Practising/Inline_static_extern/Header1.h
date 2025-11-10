#include <iostream>
#pragma once

extern int a;
void greeting(); // եթե extern-ը չենք գրում  default extern է;
extern void sayHi();
int main1();
inline int b = 999;//եթե հիդեռում գրել ենք, մյուս տեղերը հայտարարենք էռռոռ ,կտա , որովհետև կրկնակի է լինում։

inline void barev() {
	std::cout << "Barev" << std::endl;  //inline կարանք օգտագործենք հիդեռում , որովհետև մյուս ֆայլերում Include-ի դեպքում , ինքը գիտի որ նույն աբնն են։
}
static inline int c=5;
extern void counter();


static int t = 888;

inline int& get_a() // c++ 17-ից ցածր վերսիաների համար inline փոփոխական ստանալ;
{
	return t;

}
