#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class String {
protected:
    char* str;
    size_t length;

public:
    String() : str(nullptr), length(0) {}

    String(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy_s(str, length + 1, s);
    }

    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    size_t getLength() const {
        return length;
    }

    void clear() {
        delete[] str;
        str = nullptr;
        length = 0;
    }

    ~String() {
        delete[] str;
    }

    String operator+(const String& other) const {
        char* newStr = new char[length + other.length + 1];
        strcpy(newStr, str);
        strcat(newStr, other.str);
        return String(newStr);
    }

    String& operator+=(const String& other) {
        *this = *this + other;
        return *this;
    }

    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const String& s) {
        os << s.str;
        return os;
    }

    const char* getStr() const {
        return str;
    }
};

class BinaryString : public String {
public:
    BinaryString() : String() {}

    BinaryString(const char* s) : String() {
        for (size_t i = 0; i < strlen(s); ++i) {
            if (s[i] != '0' && s[i] != '1') {
                clear();
                return;
            }
        }
        str = new char[strlen(s) + 1];
        strcpy(str, s);
        length = strlen(s);
    }

    BinaryString(const BinaryString& other) : String(other) {}

    BinaryString& operator=(const BinaryString& other) {
        String::operator=(other);
        return *this;
    }

    void changeSign() {
        for (size_t i = 0; i < length; ++i) {
            if (str[i] == '0')
                str[i] = '1';
            else
                str[i] = '0';
        }
    }

    BinaryString operator+(const BinaryString& other) const {
        return BinaryString((String::operator+(other)).getStr());
    }

    bool operator==(const BinaryString& other) const {
        return String::operator==(other);
    }

    bool operator!=(const BinaryString& other) const {
        return !(*this == other);
    }
};

int main() {
    String s1("Hello");
    String s2("World");

    String s3 = s1 + s2;
    std::cout << "Concatenated string: " << s3 << std::endl;

    if (s1 == s2) {
        std::cout << "s1 is equal to s2" << std::endl;
    }
    else {
        std::cout << "s1 is not equal to s2" << std::endl;
    }

    BinaryString bs1("1010");
    BinaryString bs2("1100");

    BinaryString bs3 = bs1 + bs2;
    std::cout << "Concatenated binary string: " << bs3 << std::endl;

    if (bs1 == bs2) {
        std::cout << "bs1 is equal to bs2" << std::endl;
    }
    else {
        std::cout << "bs1 is not equal to bs2" << std::endl;
    }

    return 0;
}
