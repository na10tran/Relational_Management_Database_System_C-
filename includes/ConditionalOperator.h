#ifndef CONDITIONALOPERATOR_H
#define CONDITIONALOPERATOR_H

#include "LogicalOperator.h"
#include <string>
using namespace std;

//Conditional Operator: <, >, <=, >=, =

class ConditionalOperator : public LogicalOperator
{
public:

	//CTR

	ConditionalOperator(string oper);

	//TYPE OF

	int typeOf(); //Returns the type of this operator
				  //NOTE: This operator is a subclass of the Logic operator; 
				  //this allows us to easily place objects of this class into 
				  //the Stack in ShuntingYard for easy operator changes.
};

#endif // !CONDITIONALOPERATOR_H

