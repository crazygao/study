#include <tr1/unordered_map>
#include <Word.h>
#include <Tag.h>
#include <stdio.h>

typedef boost::unordered_map<std::string, Word*> map;

class Lexer {
public:
    int line = 1;
    void reserve(Word* t) { words[t->lexeme] = t; }
    Lexer() {
        reserve(new Word(TRUE, "true"));
        reserve(new Word(False, "false"));
    }
    Token scan() {
        // Delete all empty characters, and add lines when scanning \n
        for( ; ; peek = (char)getchar() ) {
            if( peek == ' ' || peek == '\t' ) continue;
            else if( peek == '\n' ) line = line + 1;
            else break;
        }
        // Check Integers
        if( peek >= '0' && peek <= '9' ) {// Digits
            int v = 0;
            do {
                v = 10*v + (peek - '0');
                peek = (char)getchar();
            } while( peek >= '0' && peek <= '9' );
        }
        //Not Complete, too hard to translate the code into c++, I need to go through c and c++ quickly before going on

    }
private:
    char peek = ' ';
    map words;
}
