#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>
#include "Token.h"
#include "LogicalOperator.h"
#include "ConditionalOperator.h"
#include "leftparanthesis.h"
#include "RightParenthesis.h"
#include "Symbol.h"
#include "Queue.h"
using namespace std;

class Tokenizer
{
public:
    //CTR

    Tokenizer(vector<string> tokens);

    //Accessor function

    Queue<Token*> getTokens(); //Returns a Queue of tokenized commands.

private:
    Queue<Token*> _tokens;	//Queue of tokenized commands
};

#endif // TOKENIZER_H
