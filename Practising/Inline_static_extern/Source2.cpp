#include "Header1.h"
static int idk = 150; 
int a = 18;
//inline int b = 80; // սա խախտում է , ու ամեն անգամ կվերցվի ինչ-որ մեկը օրինակ 22  ու կտպի։ 2-ն էլ տպելու համար, ստատիկից ճիշտը չկա։
int main() {
	//int a = 10; //local եթե հայտարարեմ , մյուս ֆայլի a-ն էլ կտպի , լոկալն էլ;
	std::cout << "a="<<a<< std::endl;
	std::cout <<"idk this ="<< idk << std::endl; //այս ֆայլի համար կտպի 150, source1-ի համար 15;
	std::cout << "b ="<<b << std::endl;
	sayHi();
	barev();
	counter();
	main1();
}

void greeting() {
	std::cout << "hello" << std::endl;

}

static void sayHi() {    // միայն այս ֆայլում հասանելի
	std::cout << "Hi from Source2!" << std::endl;
}

static void counter() {
	c--;
	std::cout << "c this = " << c << std::endl;
}
