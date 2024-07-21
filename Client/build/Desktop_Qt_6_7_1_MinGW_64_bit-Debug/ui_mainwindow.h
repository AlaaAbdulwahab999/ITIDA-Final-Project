/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *Bank_System;
    QTabWidget *Bank_System_widget;
    QWidget *tab;
    QLabel *label_2;
    QLabel *Label_picture;
    QLabel *label;
    QLabel *label_3;
    QPushButton *pbStart;
    QWidget *tab_4;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *pdConnect;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QLineEdit *leIP_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_11;
    QLineEdit *LePort_2;
    QPushButton *pdDisconnect;
    QWidget *page_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *usernameLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLineEdit *passwordLineEdit;
    QPushButton *pdLogin;
    QWidget *tab_2;
    QStackedWidget *stackedWidgetAdmin;
    QWidget *page_3;
    QPushButton *pBGetUserAccuntNumberAdmin;
    QPushButton *Pd_GetUserBalanceAdmin;
    QPushButton *Pd_GetUserTransctionHistoryAdmin;
    QPushButton *Pd_AddNewUserAdmin;
    QPushButton *Pd_UpdateUserDataAdmin;
    QPushButton *Pd_DeleteUserAdmin;
    QPushButton *pbGet_ViewBankDatabase;
    QWidget *page_5;
    QGroupBox *groupBox_7;
    QPushButton *pbGetAccNumAdmin;
    QLineEdit *lineEditUserNameAdmin;
    QLabel *label_20;
    QWidget *page_6;
    QGroupBox *groupBox_8;
    QPushButton *pbGet_BalanceAdmin;
    QLabel *label_9;
    QLineEdit *acc_numberLineEditBalanceAdmin;
    QWidget *page_7;
    QGroupBox *groupBox_9;
    QPushButton *pbGet_TransactionHistoryAdmin;
    QLineEdit *acc_numberLineEditHistoryAdmin;
    QLabel *label_19;
    QLineEdit *Pd_countTransactionHistoryAdmin;
    QLabel *label_33;
    QWidget *page_8;
    QGroupBox *groupBox_12;
    QPushButton *pbGet_AddUser;
    QLineEdit *lineEditUserUserNameADD;
    QLabel *label_26;
    QLineEdit *lineEditUserAccNumAdd;
    QLabel *label_27;
    QLineEdit *lineEditUserPasswordAdd;
    QLabel *label_28;
    QLineEdit *lineEditUseFullNameAdd;
    QLabel *label_29;
    QLineEdit *lineEditUserAgeAdd;
    QLabel *label_30;
    QLabel *label_35;
    QLineEdit *lineEditUserEmailAdd;
    QWidget *page_4;
    QGroupBox *groupBox_11;
    QPushButton *pbGetUpdateUserData;
    QLineEdit *lineEditUserUserNameUpdate;
    QLabel *label_21;
    QLineEdit *lineEditUserAccNumUpdate;
    QLabel *label_22;
    QLineEdit *lineEditUserPasswordUpdate;
    QLabel *label_23;
    QLineEdit *lineEditUseFullNameUpdate;
    QLabel *label_24;
    QLineEdit *lineEditUserAgeUpdate;
    QLabel *label_25;
    QLineEdit *lineEditUserEmailUpdate;
    QLabel *label_34;
    QWidget *page_9;
    QGroupBox *groupBox_13;
    QPushButton *pbGet_DeleteUser;
    QLabel *label_31;
    QLineEdit *acc_numberLineEditDeleteUser;
    QPushButton *Pd_BackToAdminPage;
    QWidget *tab_3;
    QStackedWidget *stackedWidgetUser;
    QWidget *page_10;
    QPushButton *pbGetAccNum;
    QPushButton *pbGetBalnceUser;
    QPushButton *Pb_GetTranctionHistoryuser;
    QPushButton *Pb_widthdrawUser;
    QPushButton *Pb_DepositUser;
    QPushButton *Pb_TransferMony;
    QWidget *page_12;
    QGroupBox *groupBox;
    QPushButton *pbGet_Balance;
    QLabel *label_5;
    QLineEdit *acc_numberLineEditBalance;
    QWidget *page_13;
    QGroupBox *groupBox_3;
    QPushButton *pbGet_TransactionHistory;
    QLineEdit *acc_numberLineEditHistory;
    QLabel *label_8;
    QLabel *label_32;
    QLineEdit *Pd_countTransactionHistoryUser;
    QWidget *page_14;
    QGroupBox *groupBox_4;
    QLineEdit *acc_numberLineEditWithdraw;
    QLabel *label_12;
    QLineEdit *Amount_numberLineEditWithdraw;
    QLabel *label_13;
    QPushButton *pbWithdraw;
    QWidget *page_15;
    QGroupBox *groupBox_5;
    QLineEdit *acc_numberLineEditDeposit;
    QLabel *label_14;
    QLineEdit *Amount_numberLineEditDeposit;
    QLabel *label_15;
    QPushButton *pbDeposit;
    QWidget *page_16;
    QGroupBox *groupBox_6;
    QLineEdit *acc_numberLineEditTransfer;
    QLabel *label_16;
    QLineEdit *Amount_numberLineEditTransfer;
    QLabel *label_17;
    QPushButton *pbTransfer;
    QLineEdit *acc_numberLineEditHost;
    QLabel *label_18;
    QPushButton *Pd_BackToUserPage;
    QPushButton *pbLogout;
    QPushButton *pbHelp;
    QPushButton *pbExitFromSystem;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(690, 674);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Bank_System = new QGroupBox(centralwidget);
        Bank_System->setObjectName("Bank_System");
        Bank_System->setGeometry(QRect(0, 0, 691, 631));
        Bank_System->setStyleSheet(QString::fromUtf8("\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 49, 83, 255), stop:1 rgba(50, 100, 150, 255));\n"
""));
        Bank_System_widget = new QTabWidget(Bank_System);
        Bank_System_widget->setObjectName("Bank_System_widget");
        Bank_System_widget->setGeometry(QRect(10, 20, 651, 551));
        Bank_System_widget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 49, 83, 255), stop:1 rgba(50, 100, 150, 255));\n"
"color: rgb(0, 0, 0);"));
        tab = new QWidget();
        tab->setObjectName("tab");
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(370, 0, 271, 551));
        label_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 49, 83, 255), stop:1 rgba(50, 100, 150, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 700 20pt \"Segoe UI\";"));
        Label_picture = new QLabel(tab);
        Label_picture->setObjectName("Label_picture");
        Label_picture->setGeometry(QRect(0, 90, 381, 461));
        Label_picture->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(440, 420, 161, 51));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Segoe UI\";"));
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(-10, 0, 391, 91));
        label_3->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        pbStart = new QPushButton(tab);
        pbStart->setObjectName("pbStart");
        pbStart->setGeometry(QRect(450, 240, 111, 51));
        pbStart->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 20pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(255, 255, 255);  /* Text color */"));
        Bank_System_widget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        stackedWidget = new QStackedWidget(tab_4);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(40, 10, 581, 511));
        page = new QWidget();
        page->setObjectName("page");
        pdConnect = new QPushButton(page);
        pdConnect->setObjectName("pdConnect");
        pdConnect->setGeometry(QRect(140, 260, 151, 41));
        pdConnect->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */\n"
""));
        layoutWidget_2 = new QWidget(page);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(120, 110, 371, 131));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName("label_10");
        label_10->setStyleSheet(QString::fromUtf8("font: 900 italic 14pt \"Segoe UI\";\n"
""));

        horizontalLayout_5->addWidget(label_10);

        leIP_2 = new QLineEdit(layoutWidget_2);
        leIP_2->setObjectName("leIP_2");
        leIP_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Segoe UI\";"));

        horizontalLayout_5->addWidget(leIP_2);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_11 = new QLabel(layoutWidget_2);
        label_11->setObjectName("label_11");
        label_11->setStyleSheet(QString::fromUtf8("font: 900 italic 14pt \"Segoe UI\";\n"
"\n"
"color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_6->addWidget(label_11);

        LePort_2 = new QLineEdit(layoutWidget_2);
        LePort_2->setObjectName("LePort_2");
        LePort_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Segoe UI\";"));

        horizontalLayout_6->addWidget(LePort_2);


        verticalLayout_3->addLayout(horizontalLayout_6);

        pdDisconnect = new QPushButton(page);
        pdDisconnect->setObjectName("pdDisconnect");
        pdDisconnect->setGeometry(QRect(310, 260, 161, 41));
        pdDisconnect->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        layoutWidget = new QWidget(page_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(80, 100, 432, 181));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("font: 900 italic 14pt \"Segoe UI\";\n"
""));

        horizontalLayout_3->addWidget(label_6);

        usernameLineEdit = new QLineEdit(layoutWidget);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 13pt \"Segoe UI\";"));

        horizontalLayout_3->addWidget(usernameLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("font: 900 italic 14pt \"Segoe UI\";"));

        horizontalLayout_4->addWidget(label_7);

        passwordLineEdit = new QLineEdit(layoutWidget);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 13pt \"Segoe UI\";"));

        horizontalLayout_4->addWidget(passwordLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_4);

        pdLogin = new QPushButton(page_2);
        pdLogin->setObjectName("pdLogin");
        pdLogin->setGeometry(QRect(200, 300, 171, 41));
        pdLogin->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        stackedWidget->addWidget(page_2);
        Bank_System_widget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        stackedWidgetAdmin = new QStackedWidget(tab_2);
        stackedWidgetAdmin->setObjectName("stackedWidgetAdmin");
        stackedWidgetAdmin->setGeometry(QRect(10, 50, 631, 441));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        pBGetUserAccuntNumberAdmin = new QPushButton(page_3);
        pBGetUserAccuntNumberAdmin->setObjectName("pBGetUserAccuntNumberAdmin");
        pBGetUserAccuntNumberAdmin->setGeometry(QRect(40, 50, 211, 51));
        pBGetUserAccuntNumberAdmin->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        Pd_GetUserBalanceAdmin = new QPushButton(page_3);
        Pd_GetUserBalanceAdmin->setObjectName("Pd_GetUserBalanceAdmin");
        Pd_GetUserBalanceAdmin->setGeometry(QRect(40, 180, 211, 51));
        Pd_GetUserBalanceAdmin->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        Pd_GetUserTransctionHistoryAdmin = new QPushButton(page_3);
        Pd_GetUserTransctionHistoryAdmin->setObjectName("Pd_GetUserTransctionHistoryAdmin");
        Pd_GetUserTransctionHistoryAdmin->setGeometry(QRect(40, 300, 211, 51));
        Pd_GetUserTransctionHistoryAdmin->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        Pd_AddNewUserAdmin = new QPushButton(page_3);
        Pd_AddNewUserAdmin->setObjectName("Pd_AddNewUserAdmin");
        Pd_AddNewUserAdmin->setGeometry(QRect(360, 50, 211, 51));
        Pd_AddNewUserAdmin->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        Pd_UpdateUserDataAdmin = new QPushButton(page_3);
        Pd_UpdateUserDataAdmin->setObjectName("Pd_UpdateUserDataAdmin");
        Pd_UpdateUserDataAdmin->setGeometry(QRect(360, 180, 211, 51));
        Pd_UpdateUserDataAdmin->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        Pd_DeleteUserAdmin = new QPushButton(page_3);
        Pd_DeleteUserAdmin->setObjectName("Pd_DeleteUserAdmin");
        Pd_DeleteUserAdmin->setGeometry(QRect(360, 300, 211, 51));
        Pd_DeleteUserAdmin->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        pbGet_ViewBankDatabase = new QPushButton(page_3);
        pbGet_ViewBankDatabase->setObjectName("pbGet_ViewBankDatabase");
        pbGet_ViewBankDatabase->setGeometry(QRect(190, 390, 211, 51));
        pbGet_ViewBankDatabase->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        stackedWidgetAdmin->addWidget(page_3);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        groupBox_7 = new QGroupBox(page_5);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setGeometry(QRect(140, 120, 301, 141));
        groupBox_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pbGetAccNumAdmin = new QPushButton(groupBox_7);
        pbGetAccNumAdmin->setObjectName("pbGetAccNumAdmin");
        pbGetAccNumAdmin->setGeometry(QRect(50, 70, 171, 31));
        pbGetAccNumAdmin->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        lineEditUserNameAdmin = new QLineEdit(groupBox_7);
        lineEditUserNameAdmin->setObjectName("lineEditUserNameAdmin");
        lineEditUserNameAdmin->setGeometry(QRect(110, 30, 131, 31));
        lineEditUserNameAdmin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_20 = new QLabel(groupBox_7);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(20, 30, 81, 31));
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        stackedWidgetAdmin->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        groupBox_8 = new QGroupBox(page_6);
        groupBox_8->setObjectName("groupBox_8");
        groupBox_8->setGeometry(QRect(170, 150, 281, 141));
        groupBox_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pbGet_BalanceAdmin = new QPushButton(groupBox_8);
        pbGet_BalanceAdmin->setObjectName("pbGet_BalanceAdmin");
        pbGet_BalanceAdmin->setGeometry(QRect(70, 90, 141, 41));
        pbGet_BalanceAdmin->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        label_9 = new QLabel(groupBox_8);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 30, 131, 31));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        acc_numberLineEditBalanceAdmin = new QLineEdit(groupBox_8);
        acc_numberLineEditBalanceAdmin->setObjectName("acc_numberLineEditBalanceAdmin");
        acc_numberLineEditBalanceAdmin->setGeometry(QRect(140, 30, 121, 31));
        acc_numberLineEditBalanceAdmin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        stackedWidgetAdmin->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        groupBox_9 = new QGroupBox(page_7);
        groupBox_9->setObjectName("groupBox_9");
        groupBox_9->setGeometry(QRect(160, 130, 271, 181));
        groupBox_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pbGet_TransactionHistoryAdmin = new QPushButton(groupBox_9);
        pbGet_TransactionHistoryAdmin->setObjectName("pbGet_TransactionHistoryAdmin");
        pbGet_TransactionHistoryAdmin->setGeometry(QRect(10, 120, 241, 41));
        pbGet_TransactionHistoryAdmin->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        acc_numberLineEditHistoryAdmin = new QLineEdit(groupBox_9);
        acc_numberLineEditHistoryAdmin->setObjectName("acc_numberLineEditHistoryAdmin");
        acc_numberLineEditHistoryAdmin->setGeometry(QRect(140, 40, 111, 31));
        acc_numberLineEditHistoryAdmin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_19 = new QLabel(groupBox_9);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(10, 40, 131, 31));
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        Pd_countTransactionHistoryAdmin = new QLineEdit(groupBox_9);
        Pd_countTransactionHistoryAdmin->setObjectName("Pd_countTransactionHistoryAdmin");
        Pd_countTransactionHistoryAdmin->setGeometry(QRect(110, 80, 131, 22));
        Pd_countTransactionHistoryAdmin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_33 = new QLabel(groupBox_9);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(40, 80, 51, 21));
        label_33->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        stackedWidgetAdmin->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        groupBox_12 = new QGroupBox(page_8);
        groupBox_12->setObjectName("groupBox_12");
        groupBox_12->setGeometry(QRect(160, 100, 271, 281));
        groupBox_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pbGet_AddUser = new QPushButton(groupBox_12);
        pbGet_AddUser->setObjectName("pbGet_AddUser");
        pbGet_AddUser->setGeometry(QRect(50, 230, 171, 31));
        pbGet_AddUser->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        lineEditUserUserNameADD = new QLineEdit(groupBox_12);
        lineEditUserUserNameADD->setObjectName("lineEditUserUserNameADD");
        lineEditUserUserNameADD->setGeometry(QRect(110, 60, 131, 21));
        lineEditUserUserNameADD->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 10pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_26 = new QLabel(groupBox_12);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(20, 60, 81, 21));
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        lineEditUserAccNumAdd = new QLineEdit(groupBox_12);
        lineEditUserAccNumAdd->setObjectName("lineEditUserAccNumAdd");
        lineEditUserAccNumAdd->setGeometry(QRect(110, 30, 131, 21));
        lineEditUserAccNumAdd->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 10pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_27 = new QLabel(groupBox_12);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(20, 30, 81, 21));
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        lineEditUserPasswordAdd = new QLineEdit(groupBox_12);
        lineEditUserPasswordAdd->setObjectName("lineEditUserPasswordAdd");
        lineEditUserPasswordAdd->setGeometry(QRect(110, 90, 131, 21));
        lineEditUserPasswordAdd->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 10pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_28 = new QLabel(groupBox_12);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(20, 90, 81, 21));
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        lineEditUseFullNameAdd = new QLineEdit(groupBox_12);
        lineEditUseFullNameAdd->setObjectName("lineEditUseFullNameAdd");
        lineEditUseFullNameAdd->setGeometry(QRect(110, 120, 131, 21));
        lineEditUseFullNameAdd->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 10pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_29 = new QLabel(groupBox_12);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(20, 120, 81, 21));
        label_29->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        lineEditUserAgeAdd = new QLineEdit(groupBox_12);
        lineEditUserAgeAdd->setObjectName("lineEditUserAgeAdd");
        lineEditUserAgeAdd->setGeometry(QRect(110, 150, 131, 21));
        lineEditUserAgeAdd->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 10pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_30 = new QLabel(groupBox_12);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(20, 150, 81, 21));
        label_30->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        label_35 = new QLabel(groupBox_12);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(20, 180, 81, 21));
        label_35->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        lineEditUserEmailAdd = new QLineEdit(groupBox_12);
        lineEditUserEmailAdd->setObjectName("lineEditUserEmailAdd");
        lineEditUserEmailAdd->setGeometry(QRect(110, 180, 131, 21));
        lineEditUserEmailAdd->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 10pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        stackedWidgetAdmin->addWidget(page_8);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        groupBox_11 = new QGroupBox(page_4);
        groupBox_11->setObjectName("groupBox_11");
        groupBox_11->setGeometry(QRect(170, 50, 291, 301));
        groupBox_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pbGetUpdateUserData = new QPushButton(groupBox_11);
        pbGetUpdateUserData->setObjectName("pbGetUpdateUserData");
        pbGetUpdateUserData->setGeometry(QRect(50, 240, 171, 31));
        pbGetUpdateUserData->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        lineEditUserUserNameUpdate = new QLineEdit(groupBox_11);
        lineEditUserUserNameUpdate->setObjectName("lineEditUserUserNameUpdate");
        lineEditUserUserNameUpdate->setGeometry(QRect(110, 60, 131, 21));
        lineEditUserUserNameUpdate->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 10pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_21 = new QLabel(groupBox_11);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(20, 60, 81, 21));
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        lineEditUserAccNumUpdate = new QLineEdit(groupBox_11);
        lineEditUserAccNumUpdate->setObjectName("lineEditUserAccNumUpdate");
        lineEditUserAccNumUpdate->setGeometry(QRect(110, 30, 131, 21));
        lineEditUserAccNumUpdate->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 10pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_22 = new QLabel(groupBox_11);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(20, 30, 81, 21));
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        lineEditUserPasswordUpdate = new QLineEdit(groupBox_11);
        lineEditUserPasswordUpdate->setObjectName("lineEditUserPasswordUpdate");
        lineEditUserPasswordUpdate->setGeometry(QRect(110, 90, 131, 21));
        lineEditUserPasswordUpdate->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 10pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_23 = new QLabel(groupBox_11);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(20, 90, 81, 21));
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        lineEditUseFullNameUpdate = new QLineEdit(groupBox_11);
        lineEditUseFullNameUpdate->setObjectName("lineEditUseFullNameUpdate");
        lineEditUseFullNameUpdate->setGeometry(QRect(110, 120, 131, 21));
        lineEditUseFullNameUpdate->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 10pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_24 = new QLabel(groupBox_11);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(20, 120, 81, 21));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        lineEditUserAgeUpdate = new QLineEdit(groupBox_11);
        lineEditUserAgeUpdate->setObjectName("lineEditUserAgeUpdate");
        lineEditUserAgeUpdate->setGeometry(QRect(110, 150, 131, 21));
        lineEditUserAgeUpdate->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 10pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_25 = new QLabel(groupBox_11);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(20, 150, 81, 21));
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        lineEditUserEmailUpdate = new QLineEdit(groupBox_11);
        lineEditUserEmailUpdate->setObjectName("lineEditUserEmailUpdate");
        lineEditUserEmailUpdate->setGeometry(QRect(110, 180, 131, 21));
        lineEditUserEmailUpdate->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 10pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_34 = new QLabel(groupBox_11);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(20, 180, 81, 21));
        label_34->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        stackedWidgetAdmin->addWidget(page_4);
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        groupBox_13 = new QGroupBox(page_9);
        groupBox_13->setObjectName("groupBox_13");
        groupBox_13->setGeometry(QRect(130, 160, 331, 131));
        groupBox_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pbGet_DeleteUser = new QPushButton(groupBox_13);
        pbGet_DeleteUser->setObjectName("pbGet_DeleteUser");
        pbGet_DeleteUser->setGeometry(QRect(80, 80, 191, 31));
        pbGet_DeleteUser->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        label_31 = new QLabel(groupBox_13);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(30, 40, 131, 21));
        label_31->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        acc_numberLineEditDeleteUser = new QLineEdit(groupBox_13);
        acc_numberLineEditDeleteUser->setObjectName("acc_numberLineEditDeleteUser");
        acc_numberLineEditDeleteUser->setGeometry(QRect(170, 40, 111, 22));
        acc_numberLineEditDeleteUser->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 10pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        stackedWidgetAdmin->addWidget(page_9);
        Pd_BackToAdminPage = new QPushButton(tab_2);
        Pd_BackToAdminPage->setObjectName("Pd_BackToAdminPage");
        Pd_BackToAdminPage->setGeometry(QRect(30, 20, 171, 41));
        Pd_BackToAdminPage->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"background-color: rgb(255, 255, 255);\n"
"    font: 600 italic 10pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        Bank_System_widget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        stackedWidgetUser = new QStackedWidget(tab_3);
        stackedWidgetUser->setObjectName("stackedWidgetUser");
        stackedWidgetUser->setGeometry(QRect(20, 50, 601, 451));
        page_10 = new QWidget();
        page_10->setObjectName("page_10");
        pbGetAccNum = new QPushButton(page_10);
        pbGetAccNum->setObjectName("pbGetAccNum");
        pbGetAccNum->setGeometry(QRect(20, 80, 211, 51));
        pbGetAccNum->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        pbGetBalnceUser = new QPushButton(page_10);
        pbGetBalnceUser->setObjectName("pbGetBalnceUser");
        pbGetBalnceUser->setGeometry(QRect(20, 200, 211, 51));
        pbGetBalnceUser->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        Pb_GetTranctionHistoryuser = new QPushButton(page_10);
        Pb_GetTranctionHistoryuser->setObjectName("Pb_GetTranctionHistoryuser");
        Pb_GetTranctionHistoryuser->setGeometry(QRect(20, 310, 211, 51));
        Pb_GetTranctionHistoryuser->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        Pb_widthdrawUser = new QPushButton(page_10);
        Pb_widthdrawUser->setObjectName("Pb_widthdrawUser");
        Pb_widthdrawUser->setGeometry(QRect(350, 80, 211, 51));
        Pb_widthdrawUser->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        Pb_DepositUser = new QPushButton(page_10);
        Pb_DepositUser->setObjectName("Pb_DepositUser");
        Pb_DepositUser->setGeometry(QRect(350, 200, 211, 51));
        Pb_DepositUser->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        Pb_TransferMony = new QPushButton(page_10);
        Pb_TransferMony->setObjectName("Pb_TransferMony");
        Pb_TransferMony->setGeometry(QRect(350, 310, 211, 51));
        Pb_TransferMony->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        stackedWidgetUser->addWidget(page_10);
        page_12 = new QWidget();
        page_12->setObjectName("page_12");
        groupBox = new QGroupBox(page_12);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(130, 120, 301, 131));
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pbGet_Balance = new QPushButton(groupBox);
        pbGet_Balance->setObjectName("pbGet_Balance");
        pbGet_Balance->setGeometry(QRect(80, 80, 141, 31));
        pbGet_Balance->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 30, 131, 31));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        acc_numberLineEditBalance = new QLineEdit(groupBox);
        acc_numberLineEditBalance->setObjectName("acc_numberLineEditBalance");
        acc_numberLineEditBalance->setGeometry(QRect(150, 30, 131, 31));
        acc_numberLineEditBalance->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        stackedWidgetUser->addWidget(page_12);
        page_13 = new QWidget();
        page_13->setObjectName("page_13");
        groupBox_3 = new QGroupBox(page_13);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(120, 130, 291, 171));
        groupBox_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pbGet_TransactionHistory = new QPushButton(groupBox_3);
        pbGet_TransactionHistory->setObjectName("pbGet_TransactionHistory");
        pbGet_TransactionHistory->setGeometry(QRect(20, 110, 241, 31));
        pbGet_TransactionHistory->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        acc_numberLineEditHistory = new QLineEdit(groupBox_3);
        acc_numberLineEditHistory->setObjectName("acc_numberLineEditHistory");
        acc_numberLineEditHistory->setGeometry(QRect(150, 31, 131, 31));
        acc_numberLineEditHistory->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 30, 131, 31));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        label_32 = new QLabel(groupBox_3);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(60, 70, 51, 21));
        label_32->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        Pd_countTransactionHistoryUser = new QLineEdit(groupBox_3);
        Pd_countTransactionHistoryUser->setObjectName("Pd_countTransactionHistoryUser");
        Pd_countTransactionHistoryUser->setGeometry(QRect(130, 70, 131, 22));
        Pd_countTransactionHistoryUser->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        stackedWidgetUser->addWidget(page_13);
        page_14 = new QWidget();
        page_14->setObjectName("page_14");
        groupBox_4 = new QGroupBox(page_14);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(170, 140, 291, 161));
        groupBox_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        acc_numberLineEditWithdraw = new QLineEdit(groupBox_4);
        acc_numberLineEditWithdraw->setObjectName("acc_numberLineEditWithdraw");
        acc_numberLineEditWithdraw->setGeometry(QRect(150, 21, 131, 31));
        acc_numberLineEditWithdraw->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 20, 131, 31));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        Amount_numberLineEditWithdraw = new QLineEdit(groupBox_4);
        Amount_numberLineEditWithdraw->setObjectName("Amount_numberLineEditWithdraw");
        Amount_numberLineEditWithdraw->setGeometry(QRect(150, 60, 131, 31));
        Amount_numberLineEditWithdraw->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(60, 60, 61, 31));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        pbWithdraw = new QPushButton(groupBox_4);
        pbWithdraw->setObjectName("pbWithdraw");
        pbWithdraw->setGeometry(QRect(100, 110, 91, 41));
        pbWithdraw->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        stackedWidgetUser->addWidget(page_14);
        page_15 = new QWidget();
        page_15->setObjectName("page_15");
        groupBox_5 = new QGroupBox(page_15);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(160, 130, 291, 161));
        groupBox_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        acc_numberLineEditDeposit = new QLineEdit(groupBox_5);
        acc_numberLineEditDeposit->setObjectName("acc_numberLineEditDeposit");
        acc_numberLineEditDeposit->setGeometry(QRect(150, 21, 131, 31));
        acc_numberLineEditDeposit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 20, 131, 31));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        Amount_numberLineEditDeposit = new QLineEdit(groupBox_5);
        Amount_numberLineEditDeposit->setObjectName("Amount_numberLineEditDeposit");
        Amount_numberLineEditDeposit->setGeometry(QRect(150, 60, 131, 31));
        Amount_numberLineEditDeposit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(50, 60, 61, 31));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        pbDeposit = new QPushButton(groupBox_5);
        pbDeposit->setObjectName("pbDeposit");
        pbDeposit->setGeometry(QRect(100, 110, 91, 41));
        pbDeposit->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        stackedWidgetUser->addWidget(page_15);
        page_16 = new QWidget();
        page_16->setObjectName("page_16");
        groupBox_6 = new QGroupBox(page_16);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(160, 100, 291, 201));
        groupBox_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        acc_numberLineEditTransfer = new QLineEdit(groupBox_6);
        acc_numberLineEditTransfer->setObjectName("acc_numberLineEditTransfer");
        acc_numberLineEditTransfer->setGeometry(QRect(150, 20, 131, 31));
        acc_numberLineEditTransfer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_16 = new QLabel(groupBox_6);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 20, 131, 31));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        Amount_numberLineEditTransfer = new QLineEdit(groupBox_6);
        Amount_numberLineEditTransfer->setObjectName("Amount_numberLineEditTransfer");
        Amount_numberLineEditTransfer->setGeometry(QRect(150, 100, 131, 31));
        Amount_numberLineEditTransfer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_17 = new QLabel(groupBox_6);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(50, 100, 61, 31));
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        pbTransfer = new QPushButton(groupBox_6);
        pbTransfer->setObjectName("pbTransfer");
        pbTransfer->setGeometry(QRect(90, 150, 91, 31));
        pbTransfer->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        acc_numberLineEditHost = new QLineEdit(groupBox_6);
        acc_numberLineEditHost->setObjectName("acc_numberLineEditHost");
        acc_numberLineEditHost->setGeometry(QRect(150, 60, 131, 31));
        acc_numberLineEditHost->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_18 = new QLabel(groupBox_6);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(10, 60, 131, 31));
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 600 italic 12pt \"Segoe UI\";"));
        stackedWidgetUser->addWidget(page_16);
        Pd_BackToUserPage = new QPushButton(tab_3);
        Pd_BackToUserPage->setObjectName("Pd_BackToUserPage");
        Pd_BackToUserPage->setGeometry(QRect(10, 10, 171, 41));
        Pd_BackToUserPage->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"background-color: rgb(255, 255, 255);\n"
"    font: 600 italic 10pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        Bank_System_widget->addTab(tab_3, QString());
        pbLogout = new QPushButton(Bank_System);
        pbLogout->setObjectName("pbLogout");
        pbLogout->setGeometry(QRect(250, 580, 161, 41));
        pbLogout->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        pbHelp = new QPushButton(Bank_System);
        pbHelp->setObjectName("pbHelp");
        pbHelp->setGeometry(QRect(450, 580, 171, 41));
        pbHelp->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        pbExitFromSystem = new QPushButton(Bank_System);
        pbExitFromSystem->setObjectName("pbExitFromSystem");
        pbExitFromSystem->setGeometry(QRect(60, 580, 161, 41));
        pbExitFromSystem->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* Adjust this value to control the curvature */\n"
"    border: 2px solid #1E90FF;  /* Border color: Dodger Blue */\n"
"background-color: rgb(255, 255, 255);\n"
"    padding: 5px;  /* Adjust padding as needed */\n"
"    font: 600 italic 12pt \"Segoe UI\";  /* Font settings */\n"
"    color: rgb(0, 0, 0);  /* Text color */"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 690, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        Bank_System_widget->setCurrentIndex(3);
        stackedWidget->setCurrentIndex(0);
        stackedWidgetAdmin->setCurrentIndex(1);
        stackedWidgetUser->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Bank_System->setTitle(QCoreApplication::translate("MainWindow", "Bank System", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p><p align=\"center\"><br/></p><p align=\"center\">Bank System </p><p align=\"center\"><br/></p><p align=\"center\"><br/></p><p align=\"center\"><br/></p><p align=\"center\"><br/></p><p align=\"center\"><br/></p></body></html>", nullptr));
        Label_picture->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Alaa Abdul Wahab", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Welcome to Bank System </p></body></html>", nullptr));
        pbStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        Bank_System_widget->setTabText(Bank_System_widget->indexOf(tab), QCoreApplication::translate("MainWindow", "Welcome", nullptr));
        pdConnect->setText(QCoreApplication::translate("MainWindow", "Connect ", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">Enter IP:</span></p></body></html>", nullptr));
        leIP_2->setInputMask(QCoreApplication::translate("MainWindow", "000.000.000.000", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">Enter Port:</span></p></body></html>", nullptr));
        pdDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Enter Name:</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Enter Password:</span></p></body></html>", nullptr));
        pdLogin->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        Bank_System_widget->setTabText(Bank_System_widget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Login", nullptr));
        pBGetUserAccuntNumberAdmin->setText(QCoreApplication::translate("MainWindow", "Get User Accunt Number", nullptr));
        Pd_GetUserBalanceAdmin->setText(QCoreApplication::translate("MainWindow", "Get User Balance", nullptr));
        Pd_GetUserTransctionHistoryAdmin->setText(QCoreApplication::translate("MainWindow", "Get User Transction History", nullptr));
        Pd_AddNewUserAdmin->setText(QCoreApplication::translate("MainWindow", "Add New User ", nullptr));
        Pd_UpdateUserDataAdmin->setText(QCoreApplication::translate("MainWindow", "Update User Data", nullptr));
        Pd_DeleteUserAdmin->setText(QCoreApplication::translate("MainWindow", "Delete User", nullptr));
        pbGet_ViewBankDatabase->setText(QCoreApplication::translate("MainWindow", "View Bank Database", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "Acc Number", nullptr));
        pbGetAccNumAdmin->setText(QCoreApplication::translate("MainWindow", "Get Account Number", nullptr));
        lineEditUserNameAdmin->setText(QString());
        label_20->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "Balance", nullptr));
        pbGet_BalanceAdmin->setText(QCoreApplication::translate("MainWindow", "Get_Balance", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Account Number:", nullptr));
        acc_numberLineEditBalanceAdmin->setText(QString());
        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "Transaction History", nullptr));
        pbGet_TransactionHistoryAdmin->setText(QCoreApplication::translate("MainWindow", "Get Transaction History", nullptr));
        acc_numberLineEditHistoryAdmin->setText(QString());
        label_19->setText(QCoreApplication::translate("MainWindow", "Account Number:", nullptr));
        Pd_countTransactionHistoryAdmin->setText(QString());
        label_33->setText(QCoreApplication::translate("MainWindow", "Count", nullptr));
        groupBox_12->setTitle(QCoreApplication::translate("MainWindow", "Add User", nullptr));
        pbGet_AddUser->setText(QCoreApplication::translate("MainWindow", "Add User", nullptr));
        lineEditUserUserNameADD->setText(QString());
        label_26->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Acc Num:", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Full Name:", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Age:", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        lineEditUserEmailAdd->setText(QString());
        groupBox_11->setTitle(QCoreApplication::translate("MainWindow", "Update User", nullptr));
        pbGetUpdateUserData->setText(QCoreApplication::translate("MainWindow", "Update User", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Acc Num:", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Full Name:", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Age:", nullptr));
        lineEditUserEmailUpdate->setText(QString());
        label_34->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("MainWindow", "Delete User", nullptr));
        pbGet_DeleteUser->setText(QCoreApplication::translate("MainWindow", "Delete User", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Account Number:", nullptr));
        acc_numberLineEditDeleteUser->setText(QString());
        Pd_BackToAdminPage->setText(QCoreApplication::translate("MainWindow", "< Back to Main Page", nullptr));
        Bank_System_widget->setTabText(Bank_System_widget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Admin", nullptr));
        pbGetAccNum->setText(QCoreApplication::translate("MainWindow", "Get Account Number", nullptr));
        pbGetBalnceUser->setText(QCoreApplication::translate("MainWindow", "Get Balance", nullptr));
        Pb_GetTranctionHistoryuser->setText(QCoreApplication::translate("MainWindow", "Get Transaction History", nullptr));
        Pb_widthdrawUser->setText(QCoreApplication::translate("MainWindow", "Withdraw", nullptr));
        Pb_DepositUser->setText(QCoreApplication::translate("MainWindow", "Deposit", nullptr));
        Pb_TransferMony->setText(QCoreApplication::translate("MainWindow", "Transfer Money", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Balance", nullptr));
        pbGet_Balance->setText(QCoreApplication::translate("MainWindow", "Get_Balance", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Account Number:", nullptr));
        acc_numberLineEditBalance->setText(QString());
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Transaction History", nullptr));
        pbGet_TransactionHistory->setText(QCoreApplication::translate("MainWindow", "Get Transaction History", nullptr));
        acc_numberLineEditHistory->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Account Number:", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "Count", nullptr));
        Pd_countTransactionHistoryUser->setText(QString());
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Withdraw", nullptr));
        acc_numberLineEditWithdraw->setText(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "Account Number:", nullptr));
        Amount_numberLineEditWithdraw->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "Amount:", nullptr));
        pbWithdraw->setText(QCoreApplication::translate("MainWindow", "Withdraw", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Deposit", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Account Number:", nullptr));
        Amount_numberLineEditDeposit->setText(QString());
        label_15->setText(QCoreApplication::translate("MainWindow", "Amount:", nullptr));
        pbDeposit->setText(QCoreApplication::translate("MainWindow", "Deposit", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Transfer", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Account Number:", nullptr));
        Amount_numberLineEditTransfer->setText(QString());
        label_17->setText(QCoreApplication::translate("MainWindow", "Amount:", nullptr));
        pbTransfer->setText(QCoreApplication::translate("MainWindow", "Transfer", nullptr));
        acc_numberLineEditHost->setText(QString());
        label_18->setText(QCoreApplication::translate("MainWindow", " Host Acc Number:", nullptr));
        Pd_BackToUserPage->setText(QCoreApplication::translate("MainWindow", "< Back to Main Page", nullptr));
        Bank_System_widget->setTabText(Bank_System_widget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "User", nullptr));
        pbLogout->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        pbHelp->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        pbExitFromSystem->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
