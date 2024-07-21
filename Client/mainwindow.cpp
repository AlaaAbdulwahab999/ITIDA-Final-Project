#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),client(),
    Admin(client),
    User(client)
{
    ui->setupUi(this);
    this->setWindowTitle("Bank System"); // Set the new window title here

    connect(&client, &MyClient::Connection, this, &MainWindow::onConnectionDevice);
    connect(&client, &MyClient::Disconnected, this, &MainWindow::onDisconnectedDevice);
    connect(&client, &MyClient::ErrorOccurred, this, &MainWindow::onErrorOccurredDevice);
    connect(&client, &MyClient::StateChanged, this, &MainWindow::onStateChangedDevice);
    connect(&client, &MyClient::ReadyRead, this, &MainWindow::onReadyReadDevice);

    QPixmap pix("..\\..\\BankLogo.png");
    ui->Label_picture->setPixmap(pix.scaled(ui->Label_picture->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    ui->Bank_System_widget->setTabEnabled(1, false);
    ui->Bank_System_widget->setTabEnabled(2, false);
    ui->Bank_System_widget->setTabEnabled(3, false);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onConnectionDevice()
{
    //  QMessageBox::warning(this, "Connect", "Client has connected to the server....");

    ui->Bank_System_widget->setCurrentIndex(1); // Ensure the first tab is selected
    ui->stackedWidget->setCurrentIndex(1); // Switch to the login page
}

void MainWindow::onDisconnectedDevice()
{
    // QMessageBox::warning(this, "Disconnect", "Client has disconnected from the server....");

}

void MainWindow::onErrorOccurredDevice(QAbstractSocket::SocketError socketError)
{
    QMetaEnum meta = QMetaEnum::fromType<QAbstractSocket::SocketError>();
    //ui->Connection_widget->addItem(meta.valueToKey(socketError));

}

void MainWindow::onStateChangedDevice(QAbstractSocket::SocketState socketState)
{
    QMetaEnum meta = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    //ui->Connection_widget->addItem(meta.valueToKey(socketState));

}
void MainWindow::onReadyReadDevice(const QString &requestType, const QString &data)
{
    if (requestType == "Login")
    {
        if (data.contains("Invalid username or password"))
        {
            QMessageBox::warning(this, "Login Failed", data);
        }
        else{
            if (client.Role == "user")
            {
                ui->Bank_System_widget->setCurrentIndex(3); // Switch to the user tab
                ui->stackedWidgetUser->setCurrentIndex(0);
                ui->Bank_System_widget->setTabEnabled(3, true);
                ui->Bank_System_widget->setTabEnabled(1, false);
            }
            else
            {
                ui->Bank_System_widget->setCurrentIndex(2);
                ui->stackedWidgetAdmin->setCurrentIndex(0);
                ui->Bank_System_widget->setTabEnabled(2, true);
                ui->Bank_System_widget->setTabEnabled(1, false);
            }
        }
        QMessageBox::information(this, requestType, data);

    }
    else if (requestType == "Exit"){
        clearFields();
        client.Disconnect();
        ui->Bank_System_widget->setCurrentIndex(0); // Switch to the Start tab
        ui->Bank_System_widget->setTabEnabled(0, true);
        ui->Bank_System_widget->setTabEnabled(1, false);
        ui->Bank_System_widget->setTabEnabled(2, false);
        ui->Bank_System_widget->setTabEnabled(3, false);
        QMessageBox::information(this, requestType, data);
    }
    else if (requestType == "ViewBankDataBase")
    {
        displayBankDatabase(data);
    }
    else if(requestType =="GetTransactionHistoryAdmin" || requestType =="GetHistory")
    {
        displayTransactionHistory(data);
    }
    else
    {
        QMessageBox::information(this, requestType, data);
    }

}

void MainWindow::on_pbStart_clicked()
{
    ui->Bank_System_widget->setCurrentIndex(1);
    ui->Bank_System_widget->setTabEnabled(1, true);
    ui->stackedWidget->setCurrentIndex(0); // Show the Connect page
}

void MainWindow::on_pdConnect_clicked()
{
    QString ip = ui->leIP_2->text();
    qint32 port = ui->LePort_2->text().toInt();
    client.ConnectToDevice(ip, port);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pdDisconnect_clicked()
{
    client.Disconnect();
}

void MainWindow::on_pdLogin_clicked()
{
    username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Empty Faild", "Username or Password cannot be empty.");
        return;
    }
    QJsonObject requestObject;
    requestObject["request_type"] = "Login";
    QJsonObject dataObject;
    dataObject["username"] = username;
    dataObject["password"] = password;
    requestObject["data"] = dataObject;

    QJsonDocument requestDoc(requestObject);
    QString requestString = requestDoc.toJson(QJsonDocument::Compact);
    client.sendRequest(requestString);
}

void MainWindow::on_pbLogout_clicked()
{
    clearFields();
    ui->Bank_System_widget->setCurrentIndex(1); // Switch to the login tab
    ui->stackedWidget->setCurrentIndex(1);
    ui->Bank_System_widget->setTabEnabled(1, true);
    ui->Bank_System_widget->setTabEnabled(2, false);
    ui->Bank_System_widget->setTabEnabled(3, false);
}

void MainWindow::on_pbHelp_clicked()
{
    QJsonObject requestObject;
    requestObject["request_type"] = "Help";
    QJsonDocument requestDoc(requestObject);
    QString requestString = requestDoc.toJson(QJsonDocument::Compact);
    client.sendRequest(requestString);
}
//clear all line edit
void MainWindow::clearFields()
{
    for (QWidget *widget : findChildren<QWidget *>()) {
        if (QLineEdit *lineEdit = qobject_cast<QLineEdit *>(widget)) {
            lineEdit->clear();
        }
    }
}

void MainWindow::on_pbExitFromSystem_clicked()
{
    QJsonObject requestObject;
    requestObject["request_type"] = "Exit";
    QJsonDocument requestDoc(requestObject);
    QString requestString = requestDoc.toJson(QJsonDocument::Compact);
    client.sendRequest(requestString);
}

/*---------------------------------------------Admin Widget--------------------------------------------*/
void MainWindow::on_pbGetAccNumAdmin_clicked()
{
    QString _UserName = ui->lineEditUserNameAdmin->text();

    if (_UserName.isEmpty() )
    {
        QMessageBox::warning(this, "UserName", "UserName cannot be empty.");
        return;
    }
    Admin.getAccountNumberAdmin(_UserName);
}

void MainWindow::on_pbGet_BalanceAdmin_clicked()
{
    QString Acc_Number = ui->acc_numberLineEditBalanceAdmin->text();

    if (Acc_Number.isEmpty() )
    {
        QMessageBox::warning(this, "Account Number", "Account Number cannot be empty.");
        return;
    }
    Admin.getBalanceAdmin(Acc_Number);
}

void MainWindow::on_pbGet_TransactionHistoryAdmin_clicked()
{
    QString Acc_Number = ui->acc_numberLineEditHistoryAdmin->text();
    bool ok;
    int count = ui->Pd_countTransactionHistoryAdmin->text().toInt(&ok);

    if (Acc_Number.isEmpty() || !ok)
    {
        QMessageBox::warning(this, "Input Error", "Account Number and Count cannot be empty");
        return;
    }
    Admin.getTransactionHistoryAdmin(Acc_Number,count);
}

void MainWindow::on_pbGet_ViewBankDatabase_clicked()
{
    Admin.viewBankDatabase();
}

void MainWindow::on_pbGet_DeleteUser_clicked()
{
    QString Acc_Number = ui->acc_numberLineEditDeleteUser->text();

    if (Acc_Number.isEmpty() )
    {
        QMessageBox::warning(this, "Account Number", "Account Number cannot be empty.");
        return;
    }
    Admin.deleteUser(Acc_Number);
}

void MainWindow::on_pbGet_AddUser_clicked()
{
    QString _username = ui->lineEditUserUserNameADD->text();
    QString password = ui->lineEditUserPasswordAdd->text();
    QString FullName=ui->lineEditUseFullNameAdd->text();
    QString Age=ui->lineEditUserAgeAdd->text();
    QString UserEmail=ui->lineEditUserEmailAdd->text();
    if (username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Empty Faild", "Username or Password cannot be empty."); // Show login failed message
        return;
    }
    Admin.addUser(_username,password,FullName,Age,UserEmail);
}

void MainWindow::on_pbGetUpdateUserData_clicked()
{
    QString username = ui->lineEditUserUserNameUpdate->text();
    QString password = ui->lineEditUserPasswordUpdate->text();
    QString fullName = ui->lineEditUseFullNameUpdate->text();
    QString accNumber = ui->lineEditUserAccNumUpdate->text();
    QString age = ui->lineEditUserAgeUpdate->text();
    QString UserEmail=ui->lineEditUserEmailUpdate->text();
    if (username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Empty Field", "Username or Password cannot be empty.");
        return;
    }
    Admin.updateUser(username,password,fullName,accNumber,age,UserEmail);
}

void MainWindow::on_Pd_BackToAdminPage_clicked()
{
    ui->stackedWidgetAdmin->setCurrentIndex(0);
    clearFields();

}

void MainWindow::on_pBGetUserAccuntNumberAdmin_clicked()
{
    ui->stackedWidgetAdmin->setCurrentIndex(1);

}

void MainWindow::on_Pd_GetUserBalanceAdmin_clicked()
{
    ui->stackedWidgetAdmin->setCurrentIndex(2);

}
void MainWindow::on_Pd_GetUserTransctionHistoryAdmin_clicked()
{
    ui->stackedWidgetAdmin->setCurrentIndex(3);

}

void MainWindow::on_Pd_AddNewUserAdmin_clicked()
{
    ui->stackedWidgetAdmin->setCurrentIndex(4);

}

void MainWindow::on_Pd_UpdateUserDataAdmin_clicked()
{
    ui->stackedWidgetAdmin->setCurrentIndex(5);

}

void MainWindow::on_Pd_DeleteUserAdmin_clicked()
{
    ui->stackedWidgetAdmin->setCurrentIndex(6);

}
/*---------------------------------------------User Widget--------------------------------------------*/
void MainWindow::on_pbGetAccNum_clicked()
{
    User.getAccountNumber(username);
}

void MainWindow::on_pbGet_Balance_clicked()
{
    QString Acc_Number = ui->acc_numberLineEditBalance->text();

    if (Acc_Number.isEmpty() )
    {
        QMessageBox::warning(this, "Account Number", "Account Number cannot be empty.");
        return;
    }
    User.getBalance(Acc_Number);
}
void MainWindow::on_pbGet_TransactionHistory_clicked()
{
    QString Acc_Number = ui->acc_numberLineEditHistory->text();
    bool ok;
    int count = ui->Pd_countTransactionHistoryUser->text().toInt(&ok);
    if (Acc_Number.isEmpty() || !ok)
    {
        QMessageBox::warning(this, "Input Error", "Account Number and Count cannot be empty, and Count must be a valid number.");
        return;
    }
    User.getTransactionHistory(Acc_Number,count);
}

void MainWindow::on_pbWithdraw_clicked()
{
    QString Acc_Number = ui->acc_numberLineEditWithdraw->text();
    bool ok;
    double Amount = ui->Amount_numberLineEditWithdraw->text().toDouble(&ok);
    // Check if the account number is empty or the amount is not valid
    if (Acc_Number.isEmpty() || !ok || Amount <= 0)
    {
        QMessageBox::warning(this, "Input Error", "Account Number cannot be empty and Amount must be a positive number.");
        return;
    }
    User.withdraw(Acc_Number, Amount);
}

void MainWindow::on_pbDeposit_clicked()
{
    QString accNumber = ui->acc_numberLineEditDeposit->text();
    bool ok;
    double amount = ui->Amount_numberLineEditDeposit->text().toDouble(&ok);
    // Check if the account number is empty or the amount is not valid
    if (accNumber.isEmpty() || !ok || amount <= 0)
    {
        QMessageBox::warning(this, "Input Error", "Account Number cannot be empty and Amount must be a positive number.");
        return;
    }
    User.deposit(accNumber,amount);
}

void MainWindow::on_pbTransfer_clicked()
{
    QString accNumber = ui->acc_numberLineEditTransfer->text();
    QString accNumberHost = ui->acc_numberLineEditHost->text();
    bool ok;
    double amount = ui->Amount_numberLineEditTransfer->text().toDouble(&ok);
    // Check if any of the fields are empty
    if (accNumber.isEmpty() || accNumberHost.isEmpty() || !ok || amount <= 0)
    {
        QMessageBox::warning(this, "Input Error", "All fields must be filled.");
        return;
    }
    User.transfer(accNumber,accNumberHost,amount);
}

void MainWindow::on_pbGetBalnceUser_clicked()
{
    ui->stackedWidgetUser->setCurrentIndex(1);
}

void MainWindow::on_Pb_GetTranctionHistoryuser_clicked()
{
    ui->stackedWidgetUser->setCurrentIndex(2);

}
void MainWindow::on_Pb_TransferMony_clicked()
{
    ui->stackedWidgetUser->setCurrentIndex(5);

}
void MainWindow::on_Pb_widthdrawUser_clicked()
{
    ui->stackedWidgetUser->setCurrentIndex(3);

}
void MainWindow::on_Pb_DepositUser_clicked()
{
    ui->stackedWidgetUser->setCurrentIndex(4);

}
void MainWindow::on_Pd_BackToUserPage_clicked()
{
    ui->stackedWidgetUser->setCurrentIndex(0);
    clearFields();
}


/*****************************************************Functions to displays*********************************/
//function to display Bank DataBase
void MainWindow::displayBankDatabase(const QString &data)
{
    // Create a new dialog to display the bank database
    QDialog *bankDatabaseDialog = new QDialog(this);
    bankDatabaseDialog->setWindowTitle("Bank Database");

    bankDatabaseDialog->setFixedSize(1000, 300);

    // Create a layout for the dialog
    QVBoxLayout *layout = new QVBoxLayout(bankDatabaseDialog);

    // Create a table widget
    QTableWidget *bankDatabaseTable = new QTableWidget(bankDatabaseDialog);
    bankDatabaseTable->setColumnCount(8); // number of columns

    QStringList headers;
    headers << "Username" << "Password" << "Email" << "Fullname" << "Age" << "Account Number" << "Balance" << "Role";
    bankDatabaseTable->setHorizontalHeaderLabels(headers);

    // Set the width of Email columns
    bankDatabaseTable->setColumnWidth(2, 220);
    // Set the width of Fullname columns
    bankDatabaseTable->setColumnWidth(3, 150);

    // Add the table widget to the layout
    layout->addWidget(bankDatabaseTable);

    // Create a close button
    QPushButton *closeButton = new QPushButton("Close", bankDatabaseDialog);
    connect(closeButton, &QPushButton::clicked, bankDatabaseDialog, &QDialog::accept);
    layout->addWidget(closeButton);

    // Set the layout for the dialog
    bankDatabaseDialog->setLayout(layout);

    // Handle the bank database data
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
    if (doc.isArray())
    {
        QJsonArray jsonArray = doc.array();
        bankDatabaseTable->setRowCount(jsonArray.size());
        for (int i = 0; i < jsonArray.size(); ++i)
        {
            QJsonObject jsonObject = jsonArray.at(i).toObject();
            bankDatabaseTable->setItem(i, 0, new QTableWidgetItem(jsonObject["username"].toString()));
            bankDatabaseTable->setItem(i, 1, new QTableWidgetItem(jsonObject["password"].toString()));
            bankDatabaseTable->setItem(i, 2, new QTableWidgetItem(jsonObject["email"].toString()));
            bankDatabaseTable->setItem(i, 3, new QTableWidgetItem(jsonObject["fullname"].toString()));
            bankDatabaseTable->setItem(i, 4, new QTableWidgetItem(jsonObject["age"].toString()));
            bankDatabaseTable->setItem(i, 5, new QTableWidgetItem(jsonObject["accountNumber"].toString()));
            bankDatabaseTable->setItem(i, 6, new QTableWidgetItem(QString::number(jsonObject["balance"].toDouble())));
            bankDatabaseTable->setItem(i, 7, new QTableWidgetItem(jsonObject["role"].toString()));
        }
    }
    else
    {
        QMessageBox::warning(this, "Error", "Invalid data received");
    }

    // Show the dialog
    bankDatabaseDialog->exec();
}
//function to display trancation history
void MainWindow::displayTransactionHistory(const QString &data)
{
    // Create a new dialog to display the transaction history
    QDialog *transactionHistoryDialog = new QDialog(this);
    transactionHistoryDialog->setWindowTitle("Transaction History");

    transactionHistoryDialog->setFixedSize(450, 300);

    // Create a layout for the dialog
    QVBoxLayout *layout = new QVBoxLayout(transactionHistoryDialog);

    // Create a table widget
    QTableWidget *transactionTable = new QTableWidget(transactionHistoryDialog);
    transactionTable->setColumnCount(3); // Amount, Date, Type
    QStringList headers;
    headers << "Date" << "Amount" << "Type";
    transactionTable->setHorizontalHeaderLabels(headers);

    // Set the width of (type,amount,data) columns
    transactionTable->setColumnWidth(0, 200);
    transactionTable->setColumnWidth(1, 100);
    transactionTable->setColumnWidth(2, 100);

    // Add the table widget to the layout
    layout->addWidget(transactionTable);

    // Create a close button
    QPushButton *closeButton = new QPushButton("Close", transactionHistoryDialog);
    connect(closeButton, &QPushButton::clicked, transactionHistoryDialog, &QDialog::accept);
    layout->addWidget(closeButton);

    // Set the layout for the dialog
    transactionHistoryDialog->setLayout(layout);

    // Handle the transaction data
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
    if (doc.isObject())
    {
        QJsonObject jsonObject = doc.object();
        QJsonArray transactionsArray = jsonObject["transactions"].toArray();
        transactionTable->setRowCount(transactionsArray.size());
        for (int i = 0; i < transactionsArray.size(); ++i)
        {
            QJsonObject transactionObject = transactionsArray.at(i).toObject();
            transactionTable->setItem(i, 0, new QTableWidgetItem(transactionObject["date"].toString()));
            transactionTable->setItem(i, 1, new QTableWidgetItem(QString::number(transactionObject["amount"].toDouble())));
            transactionTable->setItem(i, 2, new QTableWidgetItem(transactionObject["type"].toString()));
        }
        // Show the dialog
        transactionHistoryDialog->exec();
    }
    else
    {
        QMessageBox::warning(this, "Error", data);
    }

}


