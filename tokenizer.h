#pragma once
#include <string>
#include <vector>

enum class TokenType {
    VARIABLE,
    AND,
    OR,
    NOT,
    LPAREN,
    RPAREN
};
struct Token {
    TokenType type;
    std::string value;
};
class Tokenizer
{
public:
    Tokenizer(const std::string &input);
    std::vector<Token> tokenize();

private:
    std::string input;
    std::vector<Token> tokens;
    void split();
};