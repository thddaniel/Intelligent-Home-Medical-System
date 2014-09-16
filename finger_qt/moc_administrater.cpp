/****************************************************************************
** Meta object code from reading C++ file 'administrater.h'
**
** Created: Fri Apr 26 18:58:59 2013
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "administrater.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'administrater.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_administrater[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      53,   14,   14,   14, 0x08,
      91,   14,   14,   14, 0x08,
     120,   14,   14,   14, 0x08,
     149,   14,   14,   14, 0x08,
     178,   14,   14,   14, 0x08,
     207,   14,   14,   14, 0x08,
     236,   14,   14,   14, 0x08,
     265,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_administrater[] = {
    "administrater\0\0on_increasefingerPushButton_clicked()\0"
    "on_decreasefingerPushButton_clicked()\0"
    "on_name1PushButton_clicked()\0"
    "on_name2PushButton_clicked()\0"
    "on_name3PushButton_clicked()\0"
    "on_name4PushButton_clicked()\0"
    "on_name5PushButton_clicked()\0"
    "on_name6PushButton_clicked()\0back()\0"
};

const QMetaObject administrater::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_administrater,
      qt_meta_data_administrater, 0 }
};

const QMetaObject *administrater::metaObject() const
{
    return &staticMetaObject;
}

void *administrater::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_administrater))
        return static_cast<void*>(const_cast< administrater*>(this));
    return QWidget::qt_metacast(_clname);
}

int administrater::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_increasefingerPushButton_clicked(); break;
        case 1: on_decreasefingerPushButton_clicked(); break;
        case 2: on_name1PushButton_clicked(); break;
        case 3: on_name2PushButton_clicked(); break;
        case 4: on_name3PushButton_clicked(); break;
        case 5: on_name4PushButton_clicked(); break;
        case 6: on_name5PushButton_clicked(); break;
        case 7: on_name6PushButton_clicked(); break;
        case 8: back(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
