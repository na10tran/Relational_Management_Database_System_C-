#include "rpn.h"

RPN::RPN(Queue<Token*> postFix) : _postfix(postFix) {}

RPN::~RPN()
{
}

vector<long> RPN::operator ()(Map<string, int>& fields, vector<MMap<string, long>>& indices)
{
    vector<long> temp;

    Queue<Token*> postfix = _postfix;

    Queue<Token*>::Iterator i;

    Stack<Token*> buffer;

    while (!postfix.Empty()) {
            //While there are more tokens to process.

        if (postfix.Front()->typeOf() == SYMBOL) {
            buffer.Push(postfix.Pop());
                    //If the next token is a symbol, then it immediately goes
                    //to the stack.

        }

        else if (postfix.Front()->typeOf() == LOPERATOR) {
                    //If an operator is fiund...

            vector<long> v = vector<long>();
                    //resulting vector

            Symbol* condition = static_cast<Symbol*>(buffer.Pop());
                    //The condition to be met.

            Symbol* field = static_cast<Symbol*>(buffer.Pop());
                    //The field it must be met in.

            MMap<string, long>::Iterator start;
            MMap<string, long>::Iterator end;
                    //Iterator represent the boundaries for the record
                    //numbers to be collected.

            string oper = static_cast<LogicalOperator*>(postfix.Pop())->value();
                    //The operator is removed.

            if (oper == "=") {
                        //If "="...

                if (indices[fields[field->string()]].contains(condition->string())) {
                    v = indices[fields[field->string()]][condition->string()];
                            //If the condition exists, then it's recnos
                            //are added to the result.
                }
            }
            else if (oper == "<") {
                        //If "<"...

                end = indices[fields[field->string()]].lower_bound(condition->string());
                start = indices[fields[field->string()]].begin();

                        //Boundaries are set from the begining to the conditon
                        //(not inclusive)


                while (start != end) {
                    v = getUnion(v, (*start).value_list);
                    start++;
                            //All records between the boundaries are sent to
                            //the vector.
                }
            }
            else if (oper == ">"){
                end = indices[fields[field->string()]].end();
                start = indices[fields[field->string()]].upper_bound(condition->string());

                        //Boundaries are set from the condition
                        //(not inclusive) to the end.

                while (start != end) {
                    v = getUnion(v, (*start).value_list);
                    start++;
                            //All records between the boundaries are sent to
                            //the vector.
                }
            }
            else if (oper == "<=") {
                end = indices[fields[field->string()]].upper_bound(condition->string());
                start = indices[fields[field->string()]].begin();

                        //Boundaries are set from the begining to the conditon
                        //(inclusive)

                while (start != end) {
                    v = getUnion(v, (*start).value_list);
                    start++;
                            //All records between the boundaries are sent to
                            //the vector.
                }
            }
            else if (oper == ">=") {
                end = indices[fields[field->string()]].end();
                start = indices[fields[field->string()]].lower_bound(condition->string());

                        //Boundaries are set from the condition
                        //(inclusive) to the end.

                while (start != end) {
                    v = getUnion(v, (*start).value_list);
                    start++;
                            //All records between the boundaries are sent to
                            //the vector.
                }
            }

            buffer.Push(new RecordNums(v));
                    //The new result is pushed to the stack.

            v.clear();
        }
        else if (postfix.Front()->typeOf() == COPERATOR) {
                //If a conditional operator is found...

            RecordNums* r1 = static_cast<RecordNums*>(buffer.Pop());
            RecordNums* r2 = static_cast<RecordNums*>(buffer.Pop());
                    //Two vectors are popped from the stack.

            string oper = static_cast<LogicalOperator*>(postfix.Pop())->value();

            if (oper == "and") {
                        //If the operator is and...

                buffer.Push(new RecordNums(getIntersection(r1->records(), r2->records())));
                        //The intersection is pushed to the buffer.
            }
            else if (oper == "or") {
                        //If the operator is or...
                buffer.Push(new RecordNums(getUnion(r1->records(), r2->records())));
                        //The intersection is pushed to the buffer.
            }

            /*delete r1;
            delete r2;*/
        }
    }

    vector<long> ans = static_cast<RecordNums*>(buffer.Pop())->records();
            //There should only be one vector left in the stack. We pop
            //and store it.

    assert(buffer.Empty());

    return ans;
            //Returns the remaining vector.

}
