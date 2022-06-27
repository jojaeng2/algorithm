//
// Created by edward on 21. 5. 7..
//

#ifndef MY_STRING_MYSTRING_H
#define MY_STRING_MYSTRING_H

#include <cstring>
#include <iostream>
#include <algorithm>

class MyString {

public:
    MyString() ;
    MyString(const char* s) ;
    ~MyString() ;
    MyString(MyString&& s)  ;
    MyString& operator=(MyString&& s) {
        //std::cout << "move assignment operator" << std::endl;
        MyString tmp(std::move(s));
        swap(tmp);
        return *this;
    }
    MyString(const MyString& s) ;
    MyString& operator=(const MyString& s) {
        MyString tmp(s);
        swap(tmp);
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
        return i >= 0 && i < length;
    }

    void swap(MyString& other) {
        using std::swap;
        swap(this->length, other.length);
        swap(this->str, other.str);
    };
};

#endif //MY_STRING_MYSTRING_H

MyString::MyString() {
    this->length = 0;
    this->str = new char[0];
    this->str[0] = '\0';
}

MyString::MyString(const char* s) {
    this->length = (int)strlen(s);
    this->str = new char[length+1];
    for(int i=0; i<length+1; i++) this->str[i] = s[i];
}
MyString::~MyString() {
    this->length = 0;
    delete [] str;
}
MyString::MyString(MyString &&s) {
    this->length = s.length;
    this->str = new char[length];
    for(int i=0; i<length; i++) this->str[i] = s.str[i];
    s.str = nullptr;
    s.length = 0;
}
MyString::MyString(const MyString& s) {
    this->length = s.length;
    this->str = new char[length+1];
    for(int i=0; i<length+1; i++) str[i] = s.str[i];
}

char& MyString::at(size_t pos) {
    return this->str[pos];
}

const char* MyString::data() const {
    if( this->str != nullptr) return this->str;
    else return '\0';
}

bool MyString::empty() const {
    return this->length == 0;
}

size_t MyString::size() const {
    return this->length;
}
void MyString::clear() {
    if(this->str != nullptr) {
        this->length = 0;
        delete [] this->str;
        this->str = new char[0];
        this->str[0] = '\0';
    }
    else {
        this->str = new char[0];
        this->str[0] = '\0';
    }
}

MyString& MyString::append(const MyString& str) {
    int len = this->length;
    char* arr = new char[len+1];
    for(int i=0; i<len+1; i++) arr[i] = this->str[i];
    this->length += len + str.length;
    if(this->str != nullptr) {
        delete [] this->str;
        this->str = nullptr;
    }
    this->str = new char[len+1];
    for(int i=0; i<len+1; i++) this->str[i] = arr[i];
    for(int i=0; i<str.length+1; i++) this->str[i+len] = str.str[i];
    delete [] arr;
    this->str[length+1] = '\0';
    return *this;
}
MyString& MyString::append(const char* str) {
    int len = this->length;
    char* arr = new char[len+1];
    for(int i=0; i<len+1; i++) arr[i] = this->str[i];
    this->length += len + strlen(str);
    if(this->str != nullptr) {
        delete [] this->str;
        this->str = nullptr;
    }
    this->str = new char[len+1];
    for(int i=0; i<len+1; i++) this->str[i] = arr[i];
    for(int i=0; i<strlen(str)+1; i++) this->str[i+len] = str[i];
    delete [] arr;
    this->str[length+1] = '\0';
    return *this;
}

MyString& MyString::replace(size_t pos, size_t count, const MyString& s) {
    char* first_str = new char[pos+1];
    int i=0;
    while(i<pos) {
        first_str[i] = this->str[i];
        i++;
    }
    first_str[pos] = '\0';

    char* end_str
};
MyString& MyString::replace(size_t pos, size_t count, const char* s) {

};