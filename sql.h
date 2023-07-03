#ifndef SQL_H
#define SQL_H
#include <iostream>
#include <vector>
#include "../Final_Project_Submission/parser.h"
#include "../Final_Project_Submission/table.h"
using namespace std;
class SQL {
public:
    SQL();	//CTR
    ~SQL();	//Deallocation operator (Saves the tables to the directory).

    void run();	//Runs the SQL Program
private:
    vector<string> _table_names;	//List of table names
    Map<string, Table> _tableMap;	//Map of table names and their
                                    //corresponding tables.
    Parser _p;	//Parser helper variable
    int _queryNumber;	//Current Query Number

    void runCommand(const string& command);	//Runs a given command.
    void runBatch(string filename);	//Runs all commands on a batch file.
};

#endif // SQL_H
