/****************************************************************************
** Meta object code from reading C++ file 'message.h'
**
** Created: Fri Apr 26 18:59:08 2013
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "message.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'message.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Message[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      22,    8,    8,    8, 0x08,
      39,    8,    8,    8, 0x08,
      46,    8,    8,    8, 0x08,
      53,    8,    8,    8, 0x08,
      64,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Message[] = {
    "Message\0\0EditTelnum()\0EditMescontent()\0"
    "send()\0exit()\0zimuback()\0shuziback()\0"
};

const QMetaObject Message::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Message,
      qt_meta_data_Message, 0 }
};

const QMetaObject *Message::metaObject() const
{
    return &staticMetaObject;
}

void *Message::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Message))
        return static_cast<void*>(const_cast< Message*>(this));
    return QWidget::qt_metacast(_clname);
}

int Message::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: EditTelnum(); break;
        case 1: EditMescontent(); break;
        case 2: send(); break;
        case 3: exit(); break;
        case 4: zimuback(); break;
        case 5: shuziback(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
