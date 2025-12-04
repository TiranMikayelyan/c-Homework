#include <iostream>
#include <string>
#include <new>  //placement new-ի համար
using string_alias = std::string;   // aliase եմ անում, որ անունն օգտագործեմ դեստրուկտորում(անունը սովորական փոփոխականի պես պետք է լինի)

int main() {
    alignas(string_alias) char buf[sizeof(string_alias)];     // buf-ը հիշողության կառավարման համար , թե ինչին բազմապատիկ լինի


    string_alias* s = new (buf) string_alias("Hello");  // (placement new) Վերցնում է buf–ի վրա գտնվող հիշողությունը, էդ տեղում constructor–ով կառուցում է string_alias("Hello") օբյեկտ»։
    std::cout << *s << "\n";   // Hello

    s->~string_alias();        // օբյեկտը քանդում ենք, բայց հիշողության  տարածքը մնում է

    s = new (buf) string_alias("barev");  // նույն հիշողության վրա նոր string օբյեկտ
    std::cout << *s << "\n";   // barev

    s->~string_alias();        // նորից destructor

    return 0;
}
