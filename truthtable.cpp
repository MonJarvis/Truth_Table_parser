#include "truthtable.h"
#include <iostream>
using namespace std;
// Constructor that initializes the tokens vector and extracts variables
Truthtable::Truthtable(const vector<Token> &tokens) : tokens(tokens)
{
    extractVariables();
}

void Truthtable::extractVariables()
{
    for (const Token &token : tokens)
    {
        if (token.type == TokenType::VARIABLE)
        {
            Truthtable::variables.insert(token.value);
        }
    }
}

TruthTableResult Truthtable::evaluate()
{
    Parser parser(tokens);
    auto tree = parser.parse();
    vector<string> varlist(variables.begin(), variables.end());
    int n = varlist.size();
    int rows = 1 << n;

    TruthTableResult result;
    result.variables = varlist;

    for (int i = 0; i < rows; i++)
    {
        map<string, bool> values;
        for (int j = 0; j < n; j++)
            values[varlist[j]] = (i >> j) & 1;

        vector<bool> row;
        for (int j = 0; j < n; j++)
            row.push_back(values[varlist[j]]);
        result.rows.push_back(row);
        result.results.push_back(tree->evaluate(values));
    }
    return result;
}

void Truthtable::generate()
{
    Parser parser(tokens);
    auto tree = parser.parse();
    vector<string> varlist(variables.begin(), variables.end());
    int n = varlist.size();
    int rows = 1 << n; // 2^n
    // Print header
    for (const string &v : varlist)
        cout << v << "\t";
    cout << "| Result\n";
    for (int i = 0; i < (int)varlist.size(); i++)
        cout << "--------";
    cout << "---------\n";
    // Generate rows
    for (int i = 0; i < rows; i++)
    {
        map<string, bool> values;
        for (int j = 0; j < n; j++)
            values[varlist[j]] = (i >> j) & 1;
        for (const string &v : varlist)
            cout << (values[v] ? "T" : "F") << "\t";
        bool result = tree->evaluate(values);
        cout << "| " << (result ? "TRUE" : "FALSE") << "\n";
    }
}
