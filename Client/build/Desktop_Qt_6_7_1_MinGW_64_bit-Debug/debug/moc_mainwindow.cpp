/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "onConnectionDevice",
    "",
    "onDisconnectedDevice",
    "onErrorOccurredDevice",
    "QAbstractSocket::SocketError",
    "socketError",
    "onStateChangedDevice",
    "QAbstractSocket::SocketState",
    "socketState",
    "onReadyReadDevice",
    "requestType",
    "data",
    "displayBankDatabase",
    "displayTransactionHistory",
    "on_pbStart_clicked",
    "on_pdConnect_clicked",
    "on_pdDisconnect_clicked",
    "on_pdLogin_clicked",
    "on_pbGetAccNum_clicked",
    "on_pbGet_Balance_clicked",
    "on_pbHelp_clicked",
    "on_pbLogout_clicked",
    "on_pbGet_TransactionHistory_clicked",
    "on_pbWithdraw_clicked",
    "on_pbDeposit_clicked",
    "on_pbTransfer_clicked",
    "on_pbGetAccNumAdmin_clicked",
    "on_pbGet_BalanceAdmin_clicked",
    "on_pbGet_TransactionHistoryAdmin_clicked",
    "on_pbGet_DeleteUser_clicked",
    "on_pbGet_AddUser_clicked",
    "on_pbGetUpdateUserData_clicked",
    "on_pbGet_ViewBankDatabase_clicked",
    "on_pBGetUserAccuntNumberAdmin_clicked",
    "on_Pd_GetUserBalanceAdmin_clicked",
    "on_Pd_GetUserTransctionHistoryAdmin_clicked",
    "on_Pd_AddNewUserAdmin_clicked",
    "on_Pd_UpdateUserDataAdmin_clicked",
    "on_Pd_DeleteUserAdmin_clicked",
    "on_Pd_BackToAdminPage_clicked",
    "on_pbGetBalnceUser_clicked",
    "on_Pb_GetTranctionHistoryuser_clicked",
    "on_Pb_TransferMony_clicked",
    "on_Pb_widthdrawUser_clicked",
    "on_Pb_DepositUser_clicked",
    "on_Pd_BackToUserPage_clicked",
    "on_pbExitFromSystem_clicked",
    "clearFields"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  260,    2, 0x08,    1 /* Private */,
       3,    0,  261,    2, 0x08,    2 /* Private */,
       4,    1,  262,    2, 0x08,    3 /* Private */,
       7,    1,  265,    2, 0x08,    5 /* Private */,
      10,    2,  268,    2, 0x08,    7 /* Private */,
      13,    1,  273,    2, 0x08,   10 /* Private */,
      14,    1,  276,    2, 0x08,   12 /* Private */,
      15,    0,  279,    2, 0x08,   14 /* Private */,
      16,    0,  280,    2, 0x08,   15 /* Private */,
      17,    0,  281,    2, 0x08,   16 /* Private */,
      18,    0,  282,    2, 0x08,   17 /* Private */,
      19,    0,  283,    2, 0x08,   18 /* Private */,
      20,    0,  284,    2, 0x08,   19 /* Private */,
      21,    0,  285,    2, 0x08,   20 /* Private */,
      22,    0,  286,    2, 0x08,   21 /* Private */,
      23,    0,  287,    2, 0x08,   22 /* Private */,
      24,    0,  288,    2, 0x08,   23 /* Private */,
      25,    0,  289,    2, 0x08,   24 /* Private */,
      26,    0,  290,    2, 0x08,   25 /* Private */,
      27,    0,  291,    2, 0x08,   26 /* Private */,
      28,    0,  292,    2, 0x08,   27 /* Private */,
      29,    0,  293,    2, 0x08,   28 /* Private */,
      30,    0,  294,    2, 0x08,   29 /* Private */,
      31,    0,  295,    2, 0x08,   30 /* Private */,
      32,    0,  296,    2, 0x08,   31 /* Private */,
      33,    0,  297,    2, 0x08,   32 /* Private */,
      34,    0,  298,    2, 0x08,   33 /* Private */,
      35,    0,  299,    2, 0x08,   34 /* Private */,
      36,    0,  300,    2, 0x08,   35 /* Private */,
      37,    0,  301,    2, 0x08,   36 /* Private */,
      38,    0,  302,    2, 0x08,   37 /* Private */,
      39,    0,  303,    2, 0x08,   38 /* Private */,
      40,    0,  304,    2, 0x08,   39 /* Private */,
      41,    0,  305,    2, 0x08,   40 /* Private */,
      42,    0,  306,    2, 0x08,   41 /* Private */,
      43,    0,  307,    2, 0x08,   42 /* Private */,
      44,    0,  308,    2, 0x08,   43 /* Private */,
      45,    0,  309,    2, 0x08,   44 /* Private */,
      46,    0,  310,    2, 0x08,   45 /* Private */,
      47,    0,  311,    2, 0x08,   46 /* Private */,
      48,    0,  312,    2, 0x08,   47 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'onConnectionDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDisconnectedDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onErrorOccurredDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>,
        // method 'onStateChangedDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketState, std::false_type>,
        // method 'onReadyReadDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'displayBankDatabase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'displayTransactionHistory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pbStart_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pdConnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pdDisconnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pdLogin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbGetAccNum_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbGet_Balance_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbHelp_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbLogout_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbGet_TransactionHistory_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbWithdraw_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbDeposit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbTransfer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbGetAccNumAdmin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbGet_BalanceAdmin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbGet_TransactionHistoryAdmin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbGet_DeleteUser_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbGet_AddUser_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbGetUpdateUserData_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbGet_ViewBankDatabase_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pBGetUserAccuntNumberAdmin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Pd_GetUserBalanceAdmin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Pd_GetUserTransctionHistoryAdmin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Pd_AddNewUserAdmin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Pd_UpdateUserDataAdmin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Pd_DeleteUserAdmin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Pd_BackToAdminPage_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbGetBalnceUser_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Pb_GetTranctionHistoryuser_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Pb_TransferMony_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Pb_widthdrawUser_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Pb_DepositUser_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Pd_BackToUserPage_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbExitFromSystem_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearFields'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onConnectionDevice(); break;
        case 1: _t->onDisconnectedDevice(); break;
        case 2: _t->onErrorOccurredDevice((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 3: _t->onStateChangedDevice((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketState>>(_a[1]))); break;
        case 4: _t->onReadyReadDevice((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 5: _t->displayBankDatabase((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->displayTransactionHistory((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->on_pbStart_clicked(); break;
        case 8: _t->on_pdConnect_clicked(); break;
        case 9: _t->on_pdDisconnect_clicked(); break;
        case 10: _t->on_pdLogin_clicked(); break;
        case 11: _t->on_pbGetAccNum_clicked(); break;
        case 12: _t->on_pbGet_Balance_clicked(); break;
        case 13: _t->on_pbHelp_clicked(); break;
        case 14: _t->on_pbLogout_clicked(); break;
        case 15: _t->on_pbGet_TransactionHistory_clicked(); break;
        case 16: _t->on_pbWithdraw_clicked(); break;
        case 17: _t->on_pbDeposit_clicked(); break;
        case 18: _t->on_pbTransfer_clicked(); break;
        case 19: _t->on_pbGetAccNumAdmin_clicked(); break;
        case 20: _t->on_pbGet_BalanceAdmin_clicked(); break;
        case 21: _t->on_pbGet_TransactionHistoryAdmin_clicked(); break;
        case 22: _t->on_pbGet_DeleteUser_clicked(); break;
        case 23: _t->on_pbGet_AddUser_clicked(); break;
        case 24: _t->on_pbGetUpdateUserData_clicked(); break;
        case 25: _t->on_pbGet_ViewBankDatabase_clicked(); break;
        case 26: _t->on_pBGetUserAccuntNumberAdmin_clicked(); break;
        case 27: _t->on_Pd_GetUserBalanceAdmin_clicked(); break;
        case 28: _t->on_Pd_GetUserTransctionHistoryAdmin_clicked(); break;
        case 29: _t->on_Pd_AddNewUserAdmin_clicked(); break;
        case 30: _t->on_Pd_UpdateUserDataAdmin_clicked(); break;
        case 31: _t->on_Pd_DeleteUserAdmin_clicked(); break;
        case 32: _t->on_Pd_BackToAdminPage_clicked(); break;
        case 33: _t->on_pbGetBalnceUser_clicked(); break;
        case 34: _t->on_Pb_GetTranctionHistoryuser_clicked(); break;
        case 35: _t->on_Pb_TransferMony_clicked(); break;
        case 36: _t->on_Pb_widthdrawUser_clicked(); break;
        case 37: _t->on_Pb_DepositUser_clicked(); break;
        case 38: _t->on_Pd_BackToUserPage_clicked(); break;
        case 39: _t->on_pbExitFromSystem_clicked(); break;
        case 40: _t->clearFields(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    }
    return _id;
}
QT_WARNING_POP
