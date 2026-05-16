#include <iostream>
#include <set>
#include "tokenizer.h"
#include "parser.h"
#include "truthtable.h"
void printTruthTable(const std::string &input)
{

    Tokenizer tokenizer(input);
    Truthtable table(tokenizer.tokenize());
    table.generate();
}

int main()
{
    printTruthTable("a AND b OR c");             // spaces
    printTruthTable("aANDbORc");                 // no spaces
    printTruthTable("(aANDbORc)OR((NOTd)ANDb)"); // no spaces with parens
    return 0;
}
