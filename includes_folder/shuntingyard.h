#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include "Stack.h"
#include "Queue.h"
#include "Token.h"
#include "LogicalOperator.h"
#include "ConditionalOperator.h"
#include "leftparanthesis.h"
#include "RightParenthesis.h"
#include "Symbol.h"

void printTokens(Queue<Token*> toPrint);
class ShuntingYard
{
public:
    ShuntingYard(Queue<Token*> infix);	//CTR
    Queue<Token*>& postfix();	//gets the postfix value
private:
    Queue<Token*> _infix;	//The inital infix Queue
    Queue<Token*> _postfix;	//The evaluated Postfix Queue.
};


#endif // SHUNTINGYARD_H
