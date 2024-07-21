#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHostAddress>
#include <QMetaEnum>
#include <QPixmap>
#include "MyClient.h"
#include <QMessageBox>
#include <QTableWidget>
#include <QVBoxLayout>
#include <Admin.h>
#include <User.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onConnectionDevice();
    void onDisconnectedDevice();
    void onErrorOccurredDevice(QAbstractSocket::SocketError socketError);
    void onStateChangedDevice(QAbstractSocket::SocketState socketState);
    //Function to recive the data from server
    void onReadyReadDevice(const QString &requestType,const QString &data);
    //function to display Bank DataBase
    void displayBankDatabase(const QString &data);
    //Function To display Tranction history
    void displayTransactionHistory(const QString &data);
    /******************************************Push Buttons**************************************************/
    void on_pbStart_clicked();
    void on_pdConnect_clicked();
    void on_pdDisconnect_clicked();
    void on_pdLogin_clicked();

    void on_pbGetAccNum_clicked();

    void on_pbGet_Balance_clicked();

    void on_pbHelp_clicked();

    void on_pbLogout_clicked();

    void on_pbGet_TransactionHistory_clicked();

    void on_pbWithdraw_clicked();

    void on_pbDeposit_clicked();

    void on_pbTransfer_clicked();

    void on_pbGetAccNumAdmin_clicked();

    void on_pbGet_BalanceAdmin_clicked();

    void on_pbGet_TransactionHistoryAdmin_clicked();

    void on_pbGet_DeleteUser_clicked();

    void on_pbGet_AddUser_clicked();

    void on_pbGetUpdateUserData_clicked();

    void on_pbGet_ViewBankDatabase_clicked();



    void on_pBGetUserAccuntNumberAdmin_clicked();

    void on_Pd_GetUserBalanceAdmin_clicked();

    void on_Pd_GetUserTransctionHistoryAdmin_clicked();

    void on_Pd_AddNewUserAdmin_clicked();

    void on_Pd_UpdateUserDataAdmin_clicked();

    void on_Pd_DeleteUserAdmin_clicked();

    void on_Pd_BackToAdminPage_clicked();

    void on_pbGetBalnceUser_clicked();

    void on_Pb_GetTranctionHistoryuser_clicked();

    void on_Pb_TransferMony_clicked();

    void on_Pb_widthdrawUser_clicked();

    void on_Pb_DepositUser_clicked();

    void on_Pd_BackToUserPage_clicked();

    void on_pbExitFromSystem_clicked();
    void clearFields();

private:
    Ui::MainWindow *ui;
    MyClient client;
    QString username="";
    Admin Admin;
    User User;

};

#endif // MAINWINDOW_H
