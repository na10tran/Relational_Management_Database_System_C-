TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        includes_folder/conditionaloperator.cpp \
        includes_folder/ftokenizer.cpp \
        includes_folder/leftparanthesis.cpp \
        includes_folder/logicaloperator.cpp \
        includes_folder/record.cpp \
        includes_folder/recordnums.cpp \
        includes_folder/rightparenthesis.cpp \
        includes_folder/rpn.cpp \
        includes_folder/shuntingyard.cpp \
        includes_folder/stoken.cpp \
        includes_folder/stokenizer.cpp \
        includes_folder/symbol.cpp \
        includes_folder/tokenizer.cpp \
        main.cpp \
        parser.cpp \
        sql.cpp \
        table.cpp

HEADERS += \
    MMap.h \
    includes_folder/BTree_Util_Functions.h \
    includes_folder/Constants.h \
    includes_folder/Linked_List_Functions.h \
    includes_folder/MPair.h \
    includes_folder/Map.h \
    includes_folder/Node.h \
    includes_folder/Queue.h \
    includes_folder/Stack.h \
    includes_folder/Token.h \
    includes_folder/bplustree.h \
    includes_folder/conditionaloperator.h \
    includes_folder/ftokenizer.h \
    includes_folder/leftparanthesis.h \
    includes_folder/logicaloperator.h \
    includes_folder/pair.h \
    includes_folder/record.h \
    includes_folder/recordnums.h \
    includes_folder/rightparenthesis.h \
    includes_folder/rpn.h \
    includes_folder/shuntingyard.h \
    includes_folder/stoken.h \
    includes_folder/stokenizer.h \
    includes_folder/symbol.h \
    includes_folder/tokenizer.h \
    parser.h \
    sql.h \
    table.h
