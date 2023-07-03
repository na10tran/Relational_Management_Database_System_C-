#ifndef RPN_H
#define RPN_H
#include <cmath>
#include <iostream>
#include <algorithm>
#include "MultiMap.h"
#include "Map.h"
#include "Token.h"
#include "LogicalOperator.h"
#include "ConditionalOperator.h"
#include "LeftParenthesis.h"
#include "RightParenthesis.h"
#include "Symbol.h"
#include "RecordNums.h"
#include "Queue.h"
#include "Stack.h"
using namespace std;

template<typename T>
vector<T> getUnion(vector<T> v1, vector<T> v2);
template<typename T>
vector<T> getIntersection(vector<T> v1, vector<T> v2);

class RPN
{
public:
	RPN(Queue<Token*> postFix);

	~RPN();

	vector<long> operator ()(Map<string, int>& fields, vector<MMap<string, long>>& indices);
            //Returns a vector of record numbers that correspond 
            //to the condition given in the given matrix.

private:
	Queue<Token*> _postfix; //Queue of postfix values to be returned.
};

#endif // !RPN

template <typename T>
vector<T> getIntersection(vector<T> v1, vector<T> v2)
{

    vector<T> v3;

    //    sort(v1.begin(), v1.end());
    //    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));

    return v3;
}

template <typename T>
vector<T> getUnion(vector<T> v1, vector<T> v2)
{

    vector<T> v3;

    //    sort(v1.begin(), v1.end());
    //    sort(v2.begin(), v2.end());

    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));

    return v3;
}
