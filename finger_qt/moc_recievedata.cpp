/****************************************************************************
** Meta object code from reading C++ file 'recievedata.h'
**
** Created: Fri Apr 26 18:59:14 2013
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "recievedata.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recievedata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_recievedata[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      23,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_recievedata[] = {
    "recievedata\0\0ReadCom()\0back()\0"
};

const QMetaObject recievedata::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_recievedata,
      qt_meta_data_recievedata, 0 }
};

const QMetaObject *recievedata::metaObject() const
{
    return &staticMetaObject;
}

void *recievedata::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_recievedata))
        return static_cast<void*>(const_cast< recievedata*>(this));
    return QWidget::qt_metacast(_clname);
}

int recievedata::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
