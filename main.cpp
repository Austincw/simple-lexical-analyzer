/**
 * main.cpp file
 *
 * Created by Austin Washington, Eli Lewis, Zachary Solomon
 *
 * Our program works by parsing through the text file first holding the code,
 * then populating a token array with token identifiers that match the BNF grammar
 * given to us.  After the token array is filled with tokens we then use the methods
 * in Parser.h to verify what was put into the array matches the correct BNF grammar.
 * If anything were to not match the grammar it would print an error message.
 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Parser.h"

using namespace std;

//defined tokens
#define IDENT 1
#define OPEN_PARA 10
#define CLOSE_PARA 11
#define OPEN_BRAC 12
#define CLOSE_BRAC 13
#define ADD_OP 20
#define SUB_OP 21
#define ASSIGN 22
#define SEMI_COLON 30
#define COMMA 31
#define LETTER 50
#define DIGIT 51
#define SYMBOL 52


//variables
char nextChar;
int counter = 0;
int currTkn = 0;
int charType;
int nextTokenType;
int tokens[100];
string lex = "";
FILE *myFile;


void getChar();
void lexeme();
void populateTokenArray();


int main() {
    Parser parse;
    if ((myFile = fopen("test1.txt", "r")) == NULL)
        cout << "Cant open file";
    else {
        cout<<"STARTING TEST FILE 1";
        cout<<"*********************************";
        cout<<"\n";
        getChar();
        lexeme();
        while(!feof(myFile)){
            lex = "";
            getChar();
            lexeme();
        }
        parse.program();
        cout<<"Program matches the given BNF grammar"<<endl<<endl<<endl;
    }
    lex = "";
    counter = 0;
    currTkn = 0;
    for(int i = 0; i < sizeof(tokens); i++)
        tokens[i] = 0;
    if ((myFile = fopen("test2.txt", "r")) == NULL)
        cout << "Cant open file";
    else {
        cout<<"\n";
        cout<<"STARTING TEST FILE 2";
        cout<<"***********************************";
        cout<<"\n";
        getChar();
        lexeme();
        while(!feof(myFile)){
            lex = "";
            getChar();
            lexeme();
        }
        parse.program();
        cout<<"Program matches the given BNF grammar";
    }

    return 0;
}



void getChar() {
    if (!feof(myFile)) {
        nextChar = fgetc(myFile);
        if (isalpha(nextChar))
            charType = LETTER;
        else if (isdigit(nextChar))
            charType = DIGIT;
        else
            charType = SYMBOL;
        //lex += nextChar;
        //cout << nextChar;
    }
    //cout<<lex;
}

void lexeme() { // checks the the vhar type and then
    while (isspace(nextChar))
        getChar();
    switch (charType) {
        case LETTER:
            lex += nextChar;
            getChar();
            while (charType == LETTER || charType == DIGIT) {
                if (isspace(nextChar)) {
                    break;
                }
                lex += nextChar;
                getChar();
            }
            nextTokenType = IDENT;
            break;

        case DIGIT:
            lex += nextChar;
            getChar();
            while (charType == DIGIT) {
                if (isspace(nextChar)) {
                    break;
                }
                lex += nextChar;
                getChar();
            }
            nextTokenType = DIGIT;
            break;
        case SYMBOL:
            switch (nextChar) {
                case '(':
                    lex += nextChar;
                    nextTokenType = OPEN_PARA;
                    break;
                case ')':
                    lex += nextChar;
                    nextTokenType = CLOSE_PARA;
                    break;
                case '{':
                    lex += nextChar;
                    nextTokenType = OPEN_BRAC;
                    break;
                case '}':
                    lex += nextChar;
                    nextTokenType = CLOSE_BRAC;
                    break;
                case '=':
                    lex += nextChar;
                    nextTokenType = ASSIGN;
                    break;
                case ',':
                    lex += nextChar;
                    nextTokenType = COMMA;
                    break;
                case ';':
                    lex += nextChar;
                    nextTokenType = SEMI_COLON;
                    break;
                case '+':
                    lex += nextChar;
                    nextTokenType = ADD_OP;
                    break;
                case '-':
                    lex += nextChar;
                    nextTokenType = SUB_OP;
                    break;
                default:
                    lex += nextChar;
                    nextTokenType = EOF;
                    break;
            }
            break;
    }

    populateTokenArray();
    if(nextChar == '('){
        printf("Next token is %d, Next lexeme is %s\n",nextTokenType,lex.c_str());
        lex = "";
        lex += nextChar;
        populateTokenArray();
        nextTokenType = OPEN_PARA;
    }
    else if(nextChar == ','){
        printf("Next token is %d, Next lexeme is %s\n",nextTokenType,lex.c_str());
        lex = "";
        lex += nextChar;
        populateTokenArray();
        nextTokenType = COMMA;
    }else if(nextChar == ';'){
        printf("Next token is %d, Next lexeme is %s\n",nextTokenType,lex.c_str());
        lex = "";
        lex += nextChar;
        populateTokenArray();
        nextTokenType = SEMI_COLON;
    }
    printf("Next token is %d, Next lexeme is %s\n",nextTokenType,lex.c_str());
}

void populateTokenArray() {
    if (lex == "float"){
        tokens[counter] = IDENT;
        counter++;
        return;
    }
    else{
        if (lex == "(") {
            tokens[counter] = OPEN_PARA;
            counter++;
            tokens[counter] = CLOSE_PARA;
            counter++;
            tokens[counter] = OPEN_BRAC;
            counter++;

        }else {        //handling beginning line
///////////////////////////////////
            if (lex == "}") {
                tokens[counter] = CLOSE_BRAC;
                counter++;
                return;
            }                            //take care of the braces
//////////////////////////////////////////////////////
            if (lex == ",") {
                tokens[counter] = COMMA;
                counter++;
                return;
            }
            if (lex == ";") {
                tokens[counter] = SEMI_COLON;
                counter++;
                return;
            }                            //take care of the braces
/////////////////////////////////////////
            if (lex == "+") {
                tokens[counter] = ADD_OP;
                counter++;
                return;
            }
            if (lex == "-") {
                tokens[counter] = SUB_OP;
                counter++;
                return;
            }                        //take care of the assignments
            if (lex == "=") {
                tokens[counter] = ASSIGN;
                counter++;
                return;
            }
            if(nextTokenType == IDENT){
                tokens[counter] = IDENT;
                counter++;
                return;
            }// other option is ident
        }
/////////////////////////////////////////

    }
}

/*
void Parser::program() { // use this method to call the others




}

void Parser::keyword() {

}

void Parser::declare() {

}

void Parser::declarident() {

}

void Parser::stmts() {

}

void Parser::assign() {

}

void Parser::expr() {

}

void Parser::funcname() {

}

void Parser::ident() {

}
*/

void Parser::program() {
    printf("Verifying BNF Grammar.....");
    keyword();
    funcname();
    if (tokens[currTkn] != OPEN_PARA) {
        std::cout << "Misplaced OPEN_PARA after IDENT" << std::endl;
        exit(-1);
    }
    currTkn++;
    if (tokens[currTkn] != CLOSE_PARA) {
        std::cout << "Misplaced CLOSE_PARENTHESIS after OPEN_PARENTHESIS at beginning of program" << std::endl;
        exit(-1);
    }
    currTkn++;
    if (tokens[currTkn] != OPEN_BRAC) {
        std::cout << "Misplaced OPEN_BRACKETS after CLOSE_PARENTHESIS at beginning of program" << std::endl;
        exit(-1);
    }
    currTkn++;
    declare();
    stmts();
    if (tokens[currTkn] != CLOSE_BRAC) {
        std::cout << "Missing CLOSE_BRAC at end of program" << std::endl;
        exit(-1);
    }
}

void Parser::keyword() {
    if (tokens[currTkn] != IDENT) {
        std::cout << "Missing KEYWORD at beginning of program" << std::endl;
        exit(-1);
    }
    currTkn++;
}

void Parser::declarident() {
    if (tokens[currTkn] != COMMA) //not exactly the same as my code
    {
        std::cout << "Missing COMMA within the DECLARIDENT sequence" << std::endl;
        exit(-1);
    }
    currTkn++;
    if (tokens[currTkn] != IDENT) //not exactly the same as my code
    {
        std::cout << "Missing IDENT within the DECLARIDENT sequence" << std::endl;
        exit(-1);
    }
    currTkn++;
}

void Parser::declare() {
    if (tokens[currTkn] != IDENT) {
        std::cout << "Missing FLOAT at beginning of declare statement" << std::endl;
        exit(-1);
    }
    currTkn++;
    if (tokens[currTkn] != IDENT) {
        std::cout << "Missing IDENT at beginning of declare statement" << std::endl;
        exit(-1);
    }
    currTkn++;
    while (tokens[currTkn] == COMMA)
        declarident();
    if (tokens[currTkn] != SEMI_COLON) {
        std::cout << "Missing SEMI_COLON at end of DECLARIDENT sequence" << std::endl;
        exit(-1);
    }
    currTkn++;
}

void Parser::stmts() {
    while (tokens[currTkn] == IDENT) {
        assign();
    }
}

void Parser::assign() {
    if (tokens[currTkn] != IDENT) {
        std::cout << "Missing IDENT at beginning of a statement" << std::endl;
        exit(-1);
    }
    currTkn++;
    if (tokens[currTkn] != ASSIGN) {
        std::cout << "Missing ASSIGNMENT_OPERATOR after IDENT in a statement" << std::endl;
        exit(-1);
    }
    currTkn++;
    if (tokens[currTkn] != IDENT) {
        std::cout << "Missing IDENT after ASSIGNMENT_OPERATOR in a statement" << std::endl;
        exit(-1);
    }
    currTkn++;
    while (tokens[currTkn] == ADD_OP || tokens[currTkn] == SUB_OP)
        expr();

    if (tokens[currTkn] != SEMI_COLON) {
        std::cout << "Missing SEMI_COLON at end of DECLARIDENT sequence" << std::endl;
        exit(-1);
    }
    currTkn++;
}

void Parser::expr() {
    if (tokens[currTkn] == ADD_OP || tokens[currTkn] == SUB_OP) //not exactly the same as my code
    {
        currTkn++;
    }else {
        std::cout << "Missing ADD_OPERATOR or SUB_OPERATOR within sequence of expressions in a statement" << std::endl;
        exit(-1);
    }
    if (tokens[currTkn] != IDENT) //not exactly the same as my code
    {
        std::cout << "Missing IDENT within sequence of expressions in a statement" << std::endl;
        exit(-1);
    }
    currTkn++;
}

void Parser::funcname() {
    if (tokens[currTkn] != IDENT) {
        std::cout << "Misplaced IDENT after keyword" << std::endl;
        exit(-1);
    }
    currTkn++;
}

void Parser::ident() {
    if (tokens[currTkn] == IDENT){
        lexeme();
    }
    tokens[currTkn++] = IDENT;
}



