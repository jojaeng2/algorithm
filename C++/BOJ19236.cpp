//
// Created by edward on 21. 5. 7..
//

#ifndef MY_STRING_MYSTRING_H
#define MY_STRING_MYSTRING_H

#include <cstring>
#include <iostream>
#include <algorithm>
#include <iostream>
class MyString {

public:
    MyString() ;
    MyString(const char* s) ;
    ~MyString() ;
    MyString(MyString&& s) ;
    MyString& operator=(MyString&& s) {
        //std::cout << "move assignment operator" << std::endl;
        MyString tmp(s);
        swap(tmp);
        return *this;
    }
    MyString(const MyString& s) ;
    MyString& operator=(const MyString& s) {
        //std::cout << "copy assignment operator" << std::endl;
        if (this != &s) {
            delete[] this->str;
            this->str = nullptr;
            this->length = 0;
            //constructor initializes class MyString with length:0 and str:'\0'
            //strlen(nullptr) raises an error
            this->length = strlen(s.str);
            //deep copy
            //new char[0] raises an error
            this->str = new char[this->length + 1];
            strcpy(str, s.str);
        }
        return *this;
    }

public:
    char& at(size_t pos);
    const char* data() const;
    bool empty() const;
    size_t size() const;
    void clear();
    MyString& append(const MyString& str);
    MyString& append(const char* str);
    MyString& replace(size_t pos, size_t count, const MyString& s);
    MyString& replace(size_t pos, size_t count, const char* s);
    int compare(const MyString& s) const;
    int compare(const char* s) const;
    size_t find(const MyString& s) const;
    size_t find(const char* s) const;

private:
    size_t length = 0 ;
    char* str = nullptr ;

    bool bounded(int i) const {
        return i >= 0 && i <= length;
    }

    void swap(MyString& other) {
        using std::swap;
        swap(this->length, other.length);
        swap(this->str, other.str);
    };
};

#endif //MY_STRING_MYSTRING_H



MyString::MyString() {
	length = 0;
	str = nullptr;
}	

MyString::MyString(const char* s) {
	length = strlen(s);
	str = new char[length];
	for(int i=0; i != length; i++) str[i] = s[i];
	str[length] = '\0';
}	

MyString::MyString(MyString&& s) {
	
}	

MyString::MyString(const MyString& s) {
	length = s.length;
	str = new char[length];
	for(int i=0; i!=length; i++) str[i] = s.str[i];
	str[length] = '\0';
}	

MyString::~MyString() {
	length = 0;
	delete [] str;
}


char& MyString::at(size_t pos) {
	return this->str[pos];
}

const char* MyString::data() const {
	if(str != nullptr) {
		char* now = new char[length];
		strcpy(now, str);
		return now;
	}
	else return 0;
}

bool MyString::empty() const{
	if(this->str == nullptr) return true;
	return false;
}

size_t MyString::size() const {
	return this->length;
}

void MyString::clear() {
	if(this->str != nullptr) {
		length = 0;
		str = nullptr;
	}
}



int main() {
	MyString m("abcd");
	std::cout << m.empty() << '\n';
	std::cout << m.size() << '\n';
	std::cout << m.data() << '\n';
	std::cout << m.empty() << '\n';
}