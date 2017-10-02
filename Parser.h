//
// Created by Austin Washington on 9/18/17.\
// Parse.cpp file
//

#ifndef COMP322_PROJECT_1_PARSE_H
#define COMP322_PROJECT_1_PARSE_H


#include <stdio.h>
using namespace std;

class Parser{

public:

    void program();
    void keyword();
    void declare();
    void declarident();
    void stmts();
    void assign();
    void expr();
    void funcname();
    void ident();

};

#endif //COMP322_PROJECT_1_PARSE_H



