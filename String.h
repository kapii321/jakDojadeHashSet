//
// Created by Kacper on 01.05.2023.
//

#ifndef JAKDOJADEHASHSET_STRING_H
#define JAKDOJADEHASHSET_STRING_H


#include <cstring>
#include <iostream>
#define BUFFORLENADD 15


class String {
public:

    String();
    String(const char* name);


    String(const String& other);

    ~String();

    int length() const;

    bool empty() const;


    char* getString() const;

    char* addCharacter(char c );

    void findCityName(char** array, int x, int y, int height, int width, String& city);
    int stringToIntConv();

    String& operator=(const String& other);

    String operator+(const String& other) const;


private:
    char* str;
    int size =0;
    int bufforSize =0;
};



#endif //JAKDOJADEHASHSET_STRING_H
