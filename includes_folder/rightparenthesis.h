#ifndef RIGHTPARENTHESIS_H
#define RIGHTPARENTHESIS_H

#include <iostream>
#include "LogicalOperator.h"
using namespace std;

class RightParenthesis : public LogicalOperator
{
public:

    //CTR

    RightParenthesis();

    //Type of function

    int typeOf();

    //PRint function

    void print(ostream& outs);

    //Precedence operator

    int precedence();
};

#endif // RIGHTPARENTHESIS_H
