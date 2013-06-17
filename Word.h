#include <Token.h>
#include <Tag.h>
#include <string.h>

class Word : public Token {
public:
    const char* lexeme;
    Word(int t, char* s)
        : Token(t), lexeme(s)
    {
    }
}
