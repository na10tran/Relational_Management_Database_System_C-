#ifndef TABLE_H
#define TABLE_H
#include "../Final_Project_Submission/includes_folder/Record.h"
#include "MMap.h"
#include "../Final_Project_Submission/includes_folder/Map.h"
#include "../Final_Project_Submission/includes_folder/ShuntingYard.h"
#include "../Final_Project_Submission/includes_folder/RPN.h"
#include "../Final_Project_Submission/includes_folder/Tokenizer.h"
#include <iomanip>
#include <string>

class Table {
public:

    //ctors
    Table();
    Table(const string& name, const vector<string> fields);
    Table(const string& name);


    void insert_into(vector<string> v);

    //select
    Table select_all();
    //Table selectRows(vector<string> v);
    Table select_conditional(vector<string> condition);
    Table select(vector<string> fields, vector<long> recordNumbers = vector<long>());
    Table selectFields(vector<string> fields);

    //set and get
    vector<string> getFields();

    bool containsField(string field);

    //ostream operator
    friend ostream& operator <<(ostream& outs, const Table& t) {

        outs << "Table Name: " << t._table_name << ", Records: " << t._last_record_num + 1 << endl;
        outs << left << setw(15) << "Record Num." << "|";
        for (int i = 0; i < t._field_names.size(); i++) {
            outs << left << setw(15) << t._field_names[i] << "|";
        }
        outs << endl;

        fstream file;
        Record r;
        open_fileW(file, (t._table_name + ".bin").c_str());

        int recno = 0;
        r.read(file, recno++, t._field_names.size());

        while (!file.eof()) {
            outs << left << setw(15) << recno - 1 << "|"
                << r << endl;
            r.read(file, recno++, t._field_names.size());
        }

        return outs;
    }
private:
    //private vars
    string _table_name; //Name of the table

    vector<MMap<string, long> > _indices;
                               //indices
                               //each has an index and each index holds a type
                               //holds a type of data(last,first) that has all
                               //of the last names from the table

    vector<string> _field_names;    //Names of the fields in the table.

    Map<string, int> _field_names_map;  //field names and their corresponding
                                        //indices in _field_names

    bool _empty;    //Checks if empty

    int _last_record_num;   //Last recorded rec. number

    static int _serialNumber;   //Current serial number.

    //helper function
    void reindex(); //Creates all index structures for the _indices
    void set_fields(vector<string> fields); //Sets the field_names and map.
};


#endif // TABLE_H
