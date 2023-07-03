#ifndef LEFTPARENTHESIS
#define LEFTPARENTHESIS

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

#endif // !LEFTPARENTHESIS