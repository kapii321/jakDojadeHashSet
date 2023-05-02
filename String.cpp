//
// Created by Kacper on 25.04.2023.
//
#include "String.h"
String::String() {
    str = new char[1];
    str[0] = '\0';
}
String::String(const char *name) {
    if(name==nullptr) {
        str = new char[1];
        str[0] = '\0';
    }
    else {
        size = strlen(name);
        str = new char[size + 1];
        strcpy(str, name);
        str[size] = '\0';
    }
}

char *String::addCharacter(char c) {
    if (!str) {
        bufforSize += BUFFORLENADD;
        str = new char[bufforSize]();
        if (!str) {
            return nullptr;
        }
        size = 0;
    }

    if (size+ 2 >= bufforSize) {
        bufforSize += BUFFORLENADD;
        char *newString = new char[bufforSize]();
        if (!newString) {
            return nullptr;
        }
        strcpy(newString, str);
        delete[] str;
        str = newString;
    }

    str[size] = c;
    str[size + 1] = '\0';
    size++;

    return str;
}

String::String(const String &other) {
    size = other.size;
    str = new char[size + 1];
    strcpy(str, other.str);
}

String::~String() {
    delete[] str;
}

int String::length() const {
    return size;
}

bool String::empty() const {
    return size ==0;
}



char* String::getString() const {
    return str;
}

void String::findCityName(char** array, int x, int y, int height, int width, String& city) {
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(i ==0 && j==0){
                continue;
            }
            int nx= x+i;
            int ny = y+j;
            if (nx >= 0 && nx < height && ny >= 0 && ny < width) {
                if(array[nx][ny]!= '.' && array[nx][ny] !='#' && array[nx][ny]!= '*'){
                    while(array[nx][ny]!= '.' && array[nx][ny] !='#' && array[nx][ny]!= '*'){
                        ny--;
                        if(ny<0) break;
                    }
                    ny++;
                    while(array[nx][ny]!= '.' && array[nx][ny] !='#' && array[nx][ny]!= '*') {
                        city.addCharacter(array[nx][ny]);
                        ny++;
                        if(ny>=width) break;
                    }
                    return;
                }
            }
        }
    }
}

int String::stringToIntConv() {
    const char* string = this->getString();
    char * pEnd;
    int output=strtol(string,&pEnd,10);
    return output;

}


String &String::operator=(const String &other) {
    if (this != &other) {
        size = other.size;
        str = new char[size + 2];
        strcpy(str, other.str);
    }
    return *this;
}

String String::operator+(const String &other) const {
    char* new_str = new char[size + other.size + 1];
    strcpy(new_str, str);
    strcat(new_str, other.str);
    String result(new_str);
    delete[] new_str;
    return result;
}

