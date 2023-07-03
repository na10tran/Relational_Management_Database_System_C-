#ifndef LOGICALOPERATOR_H
#define LOGICALOPERATOR_H

#include "Token.h"
#include <string>
using namespace std;

class LogicalOperator : public Token
{
public:

	//CTR

	LogicalOperator(string oper);

	//Virutal Type Of

	int typeOf();

	//Virtual Value function
			//Needed for checking the operator's effect in RPN.

	virtual string value();

	//Virtual Print Function

	virtual void print(ostream& outs);

	//Virtual Precedence Function

	virtual int precedence();

private:
	string _operator;	//Operator Symbol
};

#endif // !LOGICALOPERATOR_H

