/****************************************************************************
** Meta object code from reading C++ file 'uart.h'
**
** Created: Fri Apr 26 18:59:18 2013
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "uart.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uart.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_uart[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x08,
      16,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_uart[] = {
    "uart\0\0ReadCom()\0back()\0"
};

const QMetaObject uart::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_uart,
      qt_meta_data_uart, 0 }
};

const QMetaObject *uart::metaObject() const
{
    return &staticMetaObject;
}

void *uart::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_uart))
        return static_cast<void*>(const_cast< uart*>(this));
    return QWidget::qt_metacast(_clname);
}

int uart::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: ReadCom(); break;
        case 1: back(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
