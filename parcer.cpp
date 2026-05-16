#include "parser.h"

Token Parser::peek(){
    if (position >= tokens.size())
    {
        throw std::out_of_range("Parser::peek out of range");
    }
    return tokens[position];
}
Token Parser::moveForward(){
    if (position >= tokens.size())
    {
        throw std::out_of_range("Parser::moveForward out of range");
    }
    return tokens[position++];
}

std::unique_ptr<Node> Parser::parseOR(){

    auto node = parseAND();
    while (position < tokens.size() && peek().type == TokenType::OR)
    {
        moveForward(); // consume OR
        node = std::make_unique<OrNode>(std::move(node), parseAND());
    }
    return node;
}

std::unique_ptr<Node> Parser::parseAND(){
    auto node = parseNOT();
    while (position < tokens.size() && peek().type == TokenType::AND)
    {
        moveForward(); // consume AND
        node = std::make_unique<AndNode>(std::move(node), parseNOT());
    }
    return node;
}

std::unique_ptr<Node> Parser::parseNOT(){
    if (position < tokens.size() && peek().type == TokenType::NOT)
    {
        moveForward(); // consume NOT
        return std::make_unique<Notnode>(parseNOT());
    }
    return parsePrimary();
}

std::unique_ptr<Node> Parser::parsePrimary(){
    if (position >= tokens.size())
    {
        throw std::out_of_range("Parser::parsePrimary out of range");
    }
    Token token = peek();
    if (token.type == TokenType::VARIABLE)
    {
        moveForward(); // consume variable
        return std::make_unique<VariableNode>(token.value);
    }
    else if (token.type == TokenType::LPAREN)
    {
        moveForward(); // consume '('
        auto node = parseOR();
        if (position >= tokens.size() || peek().type != TokenType::RPAREN)
        {
            throw std::runtime_error("Parser::parsePrimary expected ')'");
        }
        moveForward(); // consume ')'
        return node;
    }
    else
    {
        throw std::runtime_error("Parser::parsePrimary unexpected token: " + token.value);
    }
}

std::unique_ptr<Node> Parser::parse(){
    auto node = parseOR();
    if (position != tokens.size())
    {
        throw std::runtime_error("Parser::parse unexpected extra tokens");
    }
    return node;
}
