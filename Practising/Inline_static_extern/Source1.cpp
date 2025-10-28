#include "Header1.h"
static int idk = 15;
//int a = 11; // փորձել եմ 2 ֆայլում a ունենալ , error multiple ........
//inline int b = 22; 
int main1() {
	
	std::cout << "idk=" << idk << std::endl;
	//std::cout << "a then ="<<a << std::endl;
	//std::cout << "b then ="<<b << std::endl;
	greeting();
	sayHi();
	barev();
	return 0;
}

static void sayHi() {    // միայն այս ֆայլում հասանելի
	std::cout << "Hi from Source1!" << std::endl;
}
