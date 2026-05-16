#pragma once
#include "tokenizer.h"
#include "node.h"
#include <stdexcept>
class Parser
{
public:
    Parser(const std::vector<Token> &Tokens) : tokens(Tokens) {}
    std::unique_ptr<Node> parse();

private:
    std::vector<Token> tokens;
    size_t position = 0;

    Token peek();
    Token moveForward();

    std::unique_ptr<Node> parseOR();
    std::unique_ptr<Node> parseAND();
    std::unique_ptr<Node> parseNOT();
    std::unique_ptr<Node> parsePrimary();
};
