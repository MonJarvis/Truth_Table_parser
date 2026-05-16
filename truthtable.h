#pragma once
#include <vector>
#include <set>
#include <map>
#include "tokenizer.h"
#include "parser.h"

// Holds the full truth table data — returned to the UI
struct TruthTableResult
{
    std::vector<std::string> variables;  // column headers in order
    std::vector<std::vector<bool>> rows; // variable values per row
    std::vector<bool> results;           // expression result per row
};

class Truthtable
{
public:
    Truthtable(const std::vector<Token> &tokens);
    void generate();             // prints to console (kept for testing)
    TruthTableResult evaluate(); // returns data for the UI

private:
    void extractVariables();
    std::vector<Token> tokens;
    std::set<std::string> variables;
    std::vector<std::string> varlist;
};