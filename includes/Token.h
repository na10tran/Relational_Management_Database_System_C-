#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
using namespace std;
enum Tokens { TOKEN, LPAREN, RPAREN, SYMBOL, LOPERATOR, COPERATOR, RECORDNUMBERS};
class Token
{
public:
	Token() {}; //CTR
	virtual int typeOf() { return TOKEN; } //Returns the type
	virtual void print(ostream&){}	//Prints nothing 
									//(Token never stands alone).

private:
};

#endif // !TOKEN_H

