#ifndef RECORDNUMS_H
#define RECORDNUMS_H
#include <iostream>
#include <string>
#include <vector>
#include "Token.h"
using namespace std;

        //Stores a vector of record numbers to be used in the RPN.

class RecordNums : public Token
{
public:

    //CTR

    RecordNums(vector<long> rNums);

    //Type Of Function

    int typeOf();

    //Precedence Function

    int precedence();

    //The store list of record numbers.

    vector<long> records();

    //Print function

    void print(ostream& outs);

private:
    vector<long> _recordNumbers;	//The stored list of record numbers.
};


#endif // RECORDNUMS_H
