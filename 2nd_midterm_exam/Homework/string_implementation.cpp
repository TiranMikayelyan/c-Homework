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

    char* raw_ptr() {                  // վերադարձնում է pointer դեպի իրական սթրինգը (փոփոխվող տարբերակ)
        // եթե սթրինգը փոքր է (SSO),
        // վերադարձնում ենք static_str-ը (stack-ում)
        // հակառակ դեպքում՝ heap-ում պահված pointer-ը
        return is_small() ? data.static_str : data.dynamic.m_pointer;
    }

    // նույնը, բայց const տարբերակ,որ սթրինգը չկարողանանք փոփոխել
    const char* raw_ptr() const {
        return is_small() ? data.static_str : data.dynamic.m_pointer;
    }
    void ensure_capacity(size_t needed_len) { // ստուգում է  կա բավարար հիշողություն
                                              // needed_len ինչքան երկարություն ենք ուզում ունենալ
                                              // եթե նոր երկարությունը տեղավորվում է SSO-ի մեջ (≤23),
        if (needed_len <= 23) return;          // ոչինչ չենք անում
               
        if (is_small()) { // եթե հիմա դեռ SSO-ի մեջ ենք,
                            // պետք է անցնենք heap
            data.dynamic.m_size = len;            // պահում ենք ընթացիկ երկարությունը
            data.dynamic.m_capacity = needed_len;   // capacity-ը դնում ենք պետք եղած չափը
            data.dynamic.m_pointer = new char[needed_len + 1];    // heap-ում վերցնում ենք նոր memory
            std::memcpy(data.dynamic.m_pointer, data.static_str, len);  // SSO-ից copy ենք անում heap
            data.dynamic.m_pointer[len] = '\0'; //դնում ենք null
            return;
        }

        if (needed_len <= data.dynamic.m_capacity) return;  // եթե արդեն heap-ում ենք և տեղը հերիքում է, ոչինչ չենք անում

        char* new_ptr = new char[needed_len + 1];       // եթե heap-ում տեղը չի հերիքում, բացում ենք ավելի մեծ memory

        std::memcpy(new_ptr, data.dynamic.m_pointer, len);   // հին  տվյալները copy ենք անում նոր 
        new_ptr[len] = '\0';
        delete[] data.dynamic.m_pointer;
        data.dynamic.m_pointer = new_ptr;

        // update capacity
        data.dynamic.m_capacity = needed_len;

        // update size
        data.dynamic.m_size = len;
    }

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
// size
size_t size() const {
    return len;
}

// capacity
size_t capacity() const {
    return is_small() ? 23 : data.dynamic.m_capacity;
}

// c_str
const char* c_str() const {
    return raw_ptr();
}

// clear 
void clear() {
    if (is_small()) {
        data.static_str[0] = '\0';
    }
    else {
        data.dynamic.m_pointer[0] = '\0';
        data.dynamic.m_size = 0;
    }
    len = 0;
}

//operator 
char& operator[](size_t i) {
    return raw_ptr()[i];
}
const char& operator[](size_t i) const {
    return raw_ptr()[i];
}

// reserve
void reserve(size_t new_cap) {
    if (new_cap <= capacity()) return;
    ensure_capacity(new_cap);
}

// push_back
void push_back(char ch) {
    ensure_capacity(len + 1);

    if (is_small()) {
        data.static_str[len] = ch;
        len++;
        data.static_str[len] = '\0';
    }
    else {
        data.dynamic.m_pointer[len] = ch;
        len++;
        data.dynamic.m_pointer[len] = '\0';
        data.dynamic.m_size = len;
    }
}

// append
void append(const char* text) {
    if (!text) return;

    size_t add = std::strlen(text);
    if (add == 0) return;

    size_t new_len = len + add;
    ensure_capacity(new_len);

    if (is_small()) {
        std::memcpy(data.static_str + len, text, add);
        len = new_len;
        data.static_str[len] = '\0';
    }
    else {
        std::memcpy(data.dynamic.m_pointer + len, text, add);
        len = new_len;
        data.dynamic.m_pointer[len] = '\0';
        data.dynamic.m_size = len;
    }
}

// append
void append(const mystring& other) {
    append(other.c_str());
}
};


int main() {
    char text[100];
    std::cout << "Enter Text: ";
    std::cin.getline(text, sizeof(text));

    mystring a(text);
    a.print();
    a.where();

    a.push_back('!');
    a.append(" HELLO");
    a.print();
    a.where();

    std::cout << "Size: " << a.size() << "\n";
    std::cout << "Capacity: " << a.capacity() << "\n";
    std::cout << "First char: " << a[0] << "\n";

    return 0;
}
