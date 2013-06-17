#include <Token.h>
#include <Tag.h>

class Num : public Token {
public:
    const int value;
    Num(int v)
        : Token(NUM)
    {
        value = v;
    }
}
