#include "sql.h"

SQL::SQL() : _queryNumber(0) {

            //Default constructor will load the tables of disk.

    fstream f;

    cout << "LOADING TABLE INFO..." << endl;

    open_fileRW(f, "tbldata.txt");
            //Text file table files is loaded / created.

    string tempTableName;

    while (!f.eof()) {
                //While goes through entire file.

        getline(f, tempTableName);

                //Each name is stored on a seperate line. The name is
                //removed...

        if (tempTableName.size() != 0)
            _table_names.push_back(tempTableName);
                //...and added to the _table_names

    }

    for (int i = 0; i < _table_names.size(); i++) {

        if (static_cast<int>(_table_names[i][_table_names[i].size() - 1]) == 13) {
            _table_names[i] = _table_names[i].substr(0, _table_names[i].size() - 1);
        }
                //Checks for rogue deliminating character and removes it.

        _tableMap[_table_names[i]] = Table(_table_names[i]);
                //Every table in _table_names is accessed and stored into the
                //_tableMap

    }

    cout << "COMPLETE." << endl;
}

SQL::~SQL()
{
    cout << "table names: " << _table_names << endl;
    fstream f;

    f.open("tbldata.txt", std::ofstream::out | std::ofstream::trunc);
    f.close();
            //All values in the file are removed.

    f.open("tbldata.txt");
            //The file is opened.

    if (!_table_names.empty()) {
                //While there are no table names left.
        int i;

        for (i = 0; i < _table_names.size() - 1; i++) {
            f << _table_names[i] << endl;
        }
                //each table name is put into the file.

        f << _table_names[i];
                //The final table is not followed with a new line symbol.
    }

    cout << "DATA SAVED." << endl;
    f.close();
}

void SQL::run()
{
    string command;

    cout << "> "; getline(cin, command);
            //Recieves user input.

    while (command != "exit") {
        runCommand(command);
                //Calls corresponding command.

        cout << "> "; getline(cin, command);
    }

}

void SQL::runCommand(const string& command)
{
    _p.set_string(command.c_str());
            //Parser is reset to new command.

    MMap<string, string> ptree = _p.parseTree();
            //A new MMap of ptree is stored.

    if (_p.fail()) {
                //If the ptree fails...
        cout << "ERROR: INVALID COMMAND; PLEASE ENTER VALID COMMAND." << endl;
    }
    else if (ptree["command"][0] == "batch") {
                //If the command is "batch"

        runBatch(ptree["values"][0]);
                //Run the batch command function (will call this function
                //again in one layer of recursion)
    }
    else if (ptree["command"][0] == "select") {
                //If the command is select...

        if (_tableMap.contains(Pair<string, Table>(ptree["table"][0]))) {
                    //Check if the table is listed in the table names.

            Table t = _tableMap[ptree["table"][0]];

            if (ptree["field"][0] == "*") {

                if (ptree["where"][0] == "yes") {
                    cout << t.select_conditional(ptree["condition"]);

                }

                else {

                    cout << t.select_all();

                }

            }

            else if (ptree["where"][0] == "yes"){

                cout << t.selectFields(ptree["field"]).select_conditional(ptree["condition"]);

            }
            else {

                cout << t.selectFields(ptree["field"]);

            }
            cout << "SQL: DONE." << endl;
        }
        else {

            cout << "ERROR: TABLE DOES NOT EXIST." << endl;

        }

    }
    else if (ptree["command"][0] == "make" || ptree["command"][0] == "create") {

        cout << ptree["command"][0] << " table " << ptree["table"][0] << ", cols: " << ptree["condition"] << endl;

        if (!_tableMap.contains(ptree["table"][0]))
            _table_names.push_back(ptree["table"][0]);

        _tableMap[_table_names[_table_names.size() - 1]] = Table(_table_names[_table_names.size() - 1], ptree["condition"]);

        cout << "SQL: DONE." << endl;
    }
    else if (ptree["command"][0] == "insert") {
        cout << command << endl;
        if (_tableMap.contains(ptree["table"][0])) {

            _tableMap[ptree["table"][0]].insert_into(ptree["values"]);

            cout << "SQL: DONE." << endl;
        }
        else {
            cout << "ERROR: CANNOT INSERT INTO NON-EXISTENT TABLE." << endl;
        }
    }
    else if (ptree["command"][0] == "drop") {
        int i;

        for (i = 0; i < _table_names.size() && _table_names[i] != ptree["table"][0]; i++);

        if (i == _table_names.size()) {
            cout << "ERROR: TABLE DOES NOT EXIST." << endl;
        }
        else {
            _table_names.erase(_table_names.begin() + i);
            _tableMap.erase(ptree["table"][0]);
            cout << "Table " << ptree["table"][0] << " dropped." << endl;
        }
    }
    cout << endl;
}

void SQL::runBatch(string filename)
{
    string line;
    fstream f;
    f.open(filename.c_str());
    if (f.fail()) {
        cout << "ERROR: FILE DOES NOT EXIST." << endl;
    }
    else {
        while (!f.eof()) {
            getline(f, line);

            if (line.size() != 0 && line[0] != '/' && line[0] != '\n' && line[0] != '\0') {
                cout << "[" << _queryNumber++ << "] " << line << endl;
                runCommand(line);
            }
            else {
                cout << line << endl;
            }
        }

        f.close();
    }
    cout << endl << endl << "------- END OF BATCH PROCESS -------" << endl;
}
