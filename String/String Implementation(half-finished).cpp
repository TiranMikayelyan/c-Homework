#include <iostream>

struct dyn_str {
    size_t m_size;       
    size_t m_capacity;   
    char* m_pointer;    
};

union u {
    dyn_str dynamic;       
    char    static_str[24]; 
};

class mystring {
private:
    u data;       
    size_t len;   

    bool is_small() const { 
        return len <= 23;}                //const-ը նրա համարա , որ կարդա len, բայց չփոխի ոչ մի դաշտ։

public:
    //mystring() {                 //default կոնտրտուկտոր, որ 0-ներով դատարկ սթրինգ սարքենք։ 
    //    len = 0;
    //    data.static_str[0] = '\0';
    //    data.dynamic.m_pointer = nullptr;
    //}


    mystring(const char* text) { //const որ ֆունկցիան տեքստի արժեքը չկարենա փոխի
        len = std::strlen(text);

        if (is_small()) {
            strcpy_s(data.static_str, sizeof(data.static_str), text); 
            data.dynamic.m_pointer = nullptr;
        }
        else {
            data.dynamic.m_size = len;
            data.dynamic.m_capacity = len;
            data.dynamic.m_pointer = new char[len + 1]; //heap-ում  նոր տեղ, մի հատ ավել \0-ի համար;
            strcpy_s(data.dynamic.m_pointer, len + 1, text);//copy ենք անում նոր տեղում
        }
    }

    ~mystring() {
        if (!is_small() && data.dynamic.m_pointer)
            delete[] data.dynamic.m_pointer;
    }

    void print() const {
        if (is_small())
            std::cout << data.static_str << std::endl;
        else
            std::cout << data.dynamic.m_pointer << std::endl;
    }

    void where() const {
        if (is_small())
            std::cout << "Saved in Stack (SSO)" << std::endl;
        else
            std::cout << "Saved in Heap" << std::endl;
    }
};

int main() {
        char text[100];    
        std::cout << "Enter Text: ";
        std::cin.getline(text, sizeof(text));   

        mystring a(text);   
        a.print();         
        a.where();          
    }
