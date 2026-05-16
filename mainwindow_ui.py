# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'mainwindow.ui'
##
## Created by: Qt User Interface Compiler version 6.9.1
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QHeaderView, QLabel, QMainWindow,
    QMenuBar, QPlainTextEdit, QPushButton, QSizePolicy,
    QStatusBar, QTableWidget, QTableWidgetItem, QTreeWidget,
    QTreeWidgetItem, QWidget)

class Ui_TheCoolestTruthTable(object):
    def setupUi(self, TheCoolestTruthTable):
        if not TheCoolestTruthTable.objectName():
            TheCoolestTruthTable.setObjectName(u"TheCoolestTruthTable")
        TheCoolestTruthTable.resize(908, 603)
        self.centralwidget = QWidget(TheCoolestTruthTable)
        self.centralwidget.setObjectName(u"centralwidget")
        self.plainTextEdit = QPlainTextEdit(self.centralwidget)
        self.plainTextEdit.setObjectName(u"plainTextEdit")
        self.plainTextEdit.setGeometry(QRect(50, 40, 311, 31))
        self.pushButton = QPushButton(self.centralwidget)
        self.pushButton.setObjectName(u"pushButton")
        self.pushButton.setGeometry(QRect(390, 40, 100, 32))
        self.errorLabel = QLabel(self.centralwidget)
        self.errorLabel.setObjectName(u"errorLabel")
        self.errorLabel.setGeometry(QRect(50, 90, 440, 25))
        self.treeWidget = QTreeWidget(self.centralwidget)
        self.treeWidget.setObjectName(u"treeWidget")
        self.treeWidget.setGeometry(QRect(460, 140, 400, 301))
        self.tableWidget = QTableWidget(self.centralwidget)
        self.tableWidget.setObjectName(u"tableWidget")
        self.tableWidget.setGeometry(QRect(50, 140, 351, 301))
        TheCoolestTruthTable.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(TheCoolestTruthTable)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 908, 30))
        TheCoolestTruthTable.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(TheCoolestTruthTable)
        self.statusbar.setObjectName(u"statusbar")
        TheCoolestTruthTable.setStatusBar(self.statusbar)

        self.retranslateUi(TheCoolestTruthTable)

        QMetaObject.connectSlotsByName(TheCoolestTruthTable)
    # setupUi

    def retranslateUi(self, TheCoolestTruthTable):
        TheCoolestTruthTable.setWindowTitle(QCoreApplication.translate("TheCoolestTruthTable", u"The Coolest Truth Table", None))
        self.pushButton.setText(QCoreApplication.translate("TheCoolestTruthTable", u"Evaluate", None))
        self.errorLabel.setStyleSheet(QCoreApplication.translate("TheCoolestTruthTable", u"color: red;", None))
        self.errorLabel.setText("")
        ___qtreewidgetitem = self.treeWidget.headerItem()
        ___qtreewidgetitem.setText(0, QCoreApplication.translate("TheCoolestTruthTable", u"Expression Tree", None));
    # retranslateUi

