#ifndef LEFTPARANTHESIS_H
#define LEFTPARANTHESIS_H
#include <iostream>
#include "LogicalOperator.h"
using namespace std;

class LeftParenthesis : public LogicalOperator
{
public:
    //CTR

    LeftParenthesis();

    //Virtual Type OF

    int typeOf();

    //Virtual Print

    void print(ostream& outs);

    //Precedence Function

    int precedence();
};
#endif // LEFTPARANTHESIS_H
