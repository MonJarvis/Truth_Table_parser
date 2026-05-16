#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "truthtable.h"
#include "tokenizer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class TheCoolestTruthTable;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void onEvaluateClicked();

private:
    Ui::TheCoolestTruthTable *ui;
};
#endif // MAINWINDOW_H
