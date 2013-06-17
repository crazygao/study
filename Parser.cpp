#include <iostream>
#include <stdio.h>

using namespace std;

class Parser {
public:
    void expr();
    void term();
    void match(int);
    Parser() ;
    static int lookahead;
};

int Parser::lookahead = 0;  //static need init

Parser::Parser() { Parser::lookahead = getchar(); }

void Parser::expr()
{
    term();
    while(true) {
        if(Parser::lookahead == '+') {
            match('+');
            term();
            cout << '+';
        } else if(Parser::lookahead == '-') {
            match('-');
            term();
            cout << '-';
        }
        else return;
    }
}

void Parser::term()
{
    if( '0' <= (char)Parser::lookahead && (char)Parser::lookahead <= '9') {
        cout << (char)Parser::lookahead;
        match(Parser::lookahead);
    }
    // else syntax error
}

void Parser::match(int t)
{
    if( Parser::lookahead == t ) Parser::lookahead = getchar();
    // else syntax error
}

int main()
{
    Parser* parse = new Parser();
    try {
        parse->expr();
    } catch (char* e) {
        cout << endl;
        cout << e << endl;
    }
    cout << '\n' << endl;
}

