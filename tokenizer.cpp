#include "tokenizer.h"
#include <sstream>
#include <cctype>

using namespace std;
// Constructor that initializes the input string
Tokenizer::Tokenizer(const string &input) : input(input) {};

// returns true if input at position pos starts with keyword (case-insensitive)
// AND checks that the character after the keyword is NOT a letter (so "anderson" won't match "and")
bool isKeywordAt(const string &input, int pos, const string &keyword)
{
    // does the keyword even fit from this position?
    if (pos + (int)keyword.size() > (int)input.size())
        return false;

    // check each character matches (case-insensitive)
    for (int i = 0; i < (int)keyword.size(); i++)
        if (tolower(input[pos + i]) != keyword[i])
            return false;

    return true;
}

// implement the split function to tokenize the input string
void Tokenizer::split()
{
    printf("Input string: %s\n", input.c_str());

    int pos = 0;
    while (pos < (int)input.size())
    {
        // skip whitespace
        if (isspace(input[pos]))
        {
            pos++;
            continue;
        }

        Token token;

        // check for parentheses first — they are always single character tokens
        if (input[pos] == '(')
        {
            token.type = TokenType::LPAREN;
            token.value = "(";
            pos++;
        }
        else if (input[pos] == ')')
        {
            token.type = TokenType::RPAREN;
            token.value = ")";
            pos++;
        }
        // check for keywords — order matters: check longer ones first
        else if (isKeywordAt(input, pos, "and"))
        {
            token.type = TokenType::AND;
            token.value = "and";
            pos += 3;
        }
        else if (isKeywordAt(input, pos, "or"))
        {
            token.type = TokenType::OR;
            token.value = "or";
            pos += 2;
        }
        else if (isKeywordAt(input, pos, "not"))
        {
            token.type = TokenType::NOT;
            token.value = "not";
            pos += 3;
        }
        // otherwise it's a variable — accumulate characters until we hit
        // a keyword, parenthesis, or whitespace
        else
        {
            token.type = TokenType::VARIABLE;
            token.value = "";
            while (pos < (int)input.size() && !isspace(input[pos]) && input[pos] != '(' && input[pos] != ')' && !isKeywordAt(input, pos, "and") && !isKeywordAt(input, pos, "or") && !isKeywordAt(input, pos, "not"))
            {
                token.value += input[pos]; // append this character to the variable name
                pos++;
            }
        }

        tokens.push_back(token);
        printf("Token: %s  Type: %d\n", token.value.c_str(), static_cast<int>(token.type));
    }
}

// tokenize() calls split() to fill the tokens vector, then returns it
std::vector<Token> Tokenizer::tokenize()
{
    split();
    return tokens;
}
