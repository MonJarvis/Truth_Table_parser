# The Coolest Truth Table 🧠

A desktop application that evaluates boolean logic expressions and displays a full truth table — built with **C++** and **Qt 6**.

---

## Features

- Accepts expressions with `AND`, `OR`, `NOT` operators and parentheses
- Works with or without spaces — `aANDbORc` is the same as `a AND b OR c`
- Case-insensitive keywords — `AND`, `and`, `And` all work
- Variable names can be anything — single letters, words, numbers (`temperature`, `x1`, `1`, `a`)
- Correct operator priority: `NOT` > `AND` > `OR`
- Displays the full truth table ($2^n$ rows for $n$ variables)
- Displays the expression tree visually so you can see how the expression was parsed
- Shows clear error messages for invalid expressions

---

## Example Inputs

```
a AND b OR c
NOT a AND b
(a OR b) AND (NOT c)
aANDbORc
(aANDbORc)OR((NOTd)ANDb)
temperature AND humidity
```

---

## Architecture

The project is split into clean, separated classes — the logic has zero Qt dependency:

```
tokenizer.h / tokenizer.cpp   → splits raw string into typed tokens
parser.h / parcer.cpp         → builds an expression tree from tokens (recursive descent)
node.h                        → expression tree nodes (VariableNode, AndNode, OrNode, NotNode)
truthtable.h / truthtable.cpp → extracts variables, generates 2ⁿ rows, evaluates each row
mainwindow.h / mainwindow.cpp → Qt UI — wires everything together
```

### Pipeline

```
User input (string)
  → Tokenizer    → vector<Token>
  → TruthTable   → extracts variables, generates rows
  → Parser       → expression tree (Node*)
  → evaluate()   → bool result per row
  → Qt UI        → QTableWidget + QTreeWidget
```

---

## How the Parser Works

The parser uses **recursive descent** to enforce operator priority. Each priority level has its own function that calls the next higher level first:

```
parseOr()          ← lowest priority, called first
  └── parseAnd()
        └── parseNot()
              └── parsePrimary()   ← variables and ( )
```

This means `AND` always binds its operands before `OR` gets a chance — no ambiguity.

---

## Building

### Requirements
- Qt 6.5+
- CMake 3.19+
- C++17 compiler

### Build steps

```bash
git clone <your-repo-url>
cd Truth_Table
mkdir build && cd build
cmake ..
cmake --build .
```

Or open the project in **Qt Creator** and press ▶ Run.

---

## What I Learned Building This

This project was built milestone by milestone as a learning exercise in **OOP and C++**:

| Milestone | Concept learned |
|---|---|
| Tokenizer | `class`, `struct`, `enum class`, `vector`, string manipulation |
| Variable extraction | `set`, iterators, `find()`, range-based for loops |
| Expression tree | Inheritance, polymorphism, `virtual`, abstract classes, `unique_ptr` |
| Parser | Recursive descent, operator priority, `move` semantics |
| No-spaces tokenizer | Character-by-character scanning, greedy matching |
| Qt UI | Signals & slots, `QTableWidget`, `QTreeWidget`, separation of concerns |
# Truth_Table_parser
