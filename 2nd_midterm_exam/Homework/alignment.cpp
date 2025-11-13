#include <iostream>
#include <vector>

class test {
private:
    std::vector<int> sizes;      // member-ների չափերը 
    std::vector<int> addresses;  // member-ների հասցեները 
    int classSize;               // հաշվված class-ի ամբողջ չափը

public:
    test(const std::vector<int>& s) { //const որ չփոխվի, & որ պատճեն չլինի
        sizes = s;
        classSize = 0;
        calculate(); // օբյեկտը հենց ստեղծվի կարենանք հաշվենք
    }

    void calculate() {
        addresses.clear(); // 2 տեղ օգտագործելուց չկրկնվելու համար 
        int address = 0;//հասցեն 0-ից ենք դնում

        for (int i = 0; i < sizes.size(); i++) {
            int Maxsize = sizes[i];

            if (address % Maxsize != 0) {
                int place = Maxsize - (address % Maxsize);
                address += place;
            }

            addresses.push_back(address);

            address += Maxsize;
        }

        int maxSize = 0;
        for (int i = 0; i < sizes.size(); i++) {
            if (sizes[i] > maxSize)
                maxSize = sizes[i];
        }

        int need = address % maxSize;
        if (need != 0)
            address += (maxSize - need);

        classSize = address;   // class size
    }

    const std::vector<int>& getaddress() const {
        return addresses;
    }

    int ClassSize() const {
        return classSize;
    }
};

int main() {
    int n;
    std::cout << "Enter count of members: ";
    std::cin >> n;

    std::vector<int> sizes(n);

    std::cout << "Enter size each member : ";
    for (int i = 0; i < n; i++) {
        std::cin >> sizes[i];
    }

    test o_test(sizes);   

    std::cout << "Class size = " << o_test.ClassSize() << " bytes" << std::endl;

    std::vector<int> adr = o_test.getaddress();

    for (int i = 0; i < adr.size(); i++) {
        std::cout << "Member " << i << " starts from " << adr[i] << " bytes" << std::endl;
    }

    return 0;

}
