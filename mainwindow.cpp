#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <QTreeWidgetItem>
#include <stdexcept>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TheCoolestTruthTable)
{
    ui->setupUi(this);
    // connect the button click to our slot
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onEvaluateClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onEvaluateClicked()
{
    // clear previous results and errors
    ui->errorLabel->clear();
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);
    ui->treeWidget->clear();

    try {
        // get the expression from the input box, trimmed of whitespace
        std::string input = ui->plainTextEdit->toPlainText().trimmed().toStdString();

        if (input.empty()) {
            ui->errorLabel->setText("Please enter an expression.");
            return;
        }

        // tokenize once, reuse for both truth table and tree
        Tokenizer tokenizer(input);
        std::vector<Token> tokens = tokenizer.tokenize();

        // truth table
        Truthtable table(tokens);
        TruthTableResult result = table.evaluate();

        int varCount = result.variables.size();
        int rowCount = result.rows.size();

        // set up columns: one per variable + Result
        ui->tableWidget->setColumnCount(varCount + 1);
        ui->tableWidget->setRowCount(rowCount);

        // set column headers
        QStringList headers;
        for (const std::string &v : result.variables)
            headers << QString::fromStdString(v);
        headers << "Result";
        ui->tableWidget->setHorizontalHeaderLabels(headers);

        // fill in each row
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < varCount; j++) {
                auto *item = new QTableWidgetItem(result.rows[i][j] ? "T" : "F");
                item->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget->setItem(i, j, item);
            }
            auto *resultItem = new QTableWidgetItem(result.results[i] ? "TRUE" : "FALSE");
            resultItem->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(i, varCount, resultItem);
        }

        ui->tableWidget->resizeColumnsToContents();

        // build and display the expression tree
        Parser treeParser(tokens);
        auto tree = treeParser.parse();
        QTreeWidgetItem *root = tree->toTreeItem();
        ui->treeWidget->addTopLevelItem(root);
        ui->treeWidget->expandAll();
    }
    catch (const std::exception &e) {
        ui->errorLabel->setText(QString::fromStdString(e.what()));
    }
}
