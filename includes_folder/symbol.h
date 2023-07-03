#ifndef SYMBOL_H
#define SYMBOL_H
#include <iostream>
#include <string>
#include "Token.h"
using namespace std;


class Symbol : public Token
{
public:

    Symbol(string str); //CTR

    Symbol& operator =(string value); //Checks the equivalence of two symbols.

    int typeOf();	//Returns the type

    int precedence();	//Returns it's precedence.

    string string();	//Returns the stored value.

    void print(ostream& outs);	//Prints the symbol

private:
    std::string _str;	//A symbol is stored as a string.
};
#endif // SYMBOL_H
