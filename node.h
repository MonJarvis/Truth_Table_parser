#pragma once
#include <map>
#include <memory>
#include <string>
#include <QTreeWidgetItem>

// Base class for expression tree nodes
class Node
{
public:
    virtual bool evaluate(const std::map<std::string, bool> &variables) = 0;
    virtual QTreeWidgetItem* toTreeItem() const = 0;
    virtual ~Node() = default;
};

// Node for variables (leaf nodes)
class VariableNode : public Node
{
public:
    std::string name;
    VariableNode(const std::string &name) : name(name) {}
    bool evaluate(const std::map<std::string, bool> &variables) override
    {
        return variables.at(name);
    }
    QTreeWidgetItem* toTreeItem() const override
    {
        return new QTreeWidgetItem(QStringList(QString::fromStdString(name)));
    }
};

// Node for NOT operator
class Notnode : public Node
{
public:
    std::unique_ptr<Node> child;
    Notnode(std::unique_ptr<Node> child) : child(std::move(child)) {}
    bool evaluate(const std::map<std::string, bool> &variables) override
    {
        return !child->evaluate(variables);
    }
    QTreeWidgetItem* toTreeItem() const override
    {
        auto *item = new QTreeWidgetItem(QStringList("NOT"));
        item->addChild(child->toTreeItem());
        return item;
    }
};

// And Node
class AndNode : public Node
{
public:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    AndNode(std::unique_ptr<Node> left, std::unique_ptr<Node> right) : left(std::move(left)), right(std::move(right)) {}
    bool evaluate(const std::map<std::string, bool> &variables) override
    {
        return left->evaluate(variables) && right->evaluate(variables);
    }
    QTreeWidgetItem* toTreeItem() const override
    {
        auto *item = new QTreeWidgetItem(QStringList("AND"));
        item->addChild(left->toTreeItem());
        item->addChild(right->toTreeItem());
        return item;
    }
};

// Or Node
class OrNode : public Node
{
public:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    OrNode(std::unique_ptr<Node> left, std::unique_ptr<Node> right) : left(std::move(left)), right(std::move(right)) {}
    bool evaluate(const std::map<std::string, bool> &variables) override
    {
        return left->evaluate(variables) || right->evaluate(variables);
    }
    QTreeWidgetItem* toTreeItem() const override
    {
        auto *item = new QTreeWidgetItem(QStringList("OR"));
        item->addChild(left->toTreeItem());
        item->addChild(right->toTreeItem());
        return item;
    }
};