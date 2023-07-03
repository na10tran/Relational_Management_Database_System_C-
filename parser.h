#ifndef PARSER_H
#define PARSER_H
#include "../Final_Project_Submission/includes_folder/stokenizer.h"
#include "MMap.h"
#include "../Final_Project_Submission/includes_folder/Map.h"
#include "../Final_Project_Submission/includes_folder/Queue.h"
#include <string>
#include <iostream>
using namespace std;

class Parser {
public:
    Parser();
    Parser(const char input[]);
    void set_string(const char c[]);
    MMap<string, string> parseTree();
    bool fail();
private:

            //Enums of the Key words that are used in the project. If a value
            //is arbitrary, it gets stored as SYMBOL. Otherwise, it is
            //assigned a Keyword

    enum {
        ZERO,
        SELECT,
        FROM,
        WHERE,
        LAST,
        FIRST,
        CREATE,
        STAR,
        SYMBOL,
        MAKE,
        COMMA,
        TABLE,
        FIELD,
        QUOTE,
        INSERT,
        INTO,
        VALUES,
        FIELDS,
        BATCH,
        GREATERTHAN,
        LESSTHAN,
        DROP,

        MAX_ROWS_P = 30,    //Max rows in the Adj. table
        MAX_COLS_P = 50,    //Mac cols in the Adj. table

        SUCCESS = MAX_COLS_P - 1    //Column signifying the success of
                                    //the operation done.


    };

    Queue<SToken> _inputq;      //Queue of input Tokens. Used for checking
                                //steps in Adj. table.

    MMap<string, string> _ptree;//Ptree to be returned.
    Map<string, int> _keywords;//Maps of strings and their corresponding
                               //keywords (see above)
    int _table[MAX_ROWS_P][MAX_COLS_P]; //Adj. table
    STokenizer _stok;   //String tokenizer for tokenizing input.
    bool _failed;   //Bool dictating whether the operation failed.

    //Helper functions

    void mark_cell(int table[MAX_ROWS][MAX_COLS_P], int row, int word, int newState);

    void mark_cell_for_all(int table[MAX_ROWS][MAX_COLS_P], int row, int newState);

    void mark_success(int table[MAX_ROWS][MAX_COLS_P], int row);

    //create table for all the tokens we will recognize
    //                      (e.g. doubles, words, etc.)

    void make_table(int _table[][MAX_COLS_P]);

    int getColumn(SToken t);

    bool setParseTree();

    void buildKeywordList();

    string toLower(const string& str);
};
#endif // PARSER_H
