/****************************************************************************
** Meta object code from reading C++ file 'furniture2.h'
**
** Created: Fri Apr 26 18:59:03 2013
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "furniture2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'furniture2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_furniture2[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      23,   11,   11,   11, 0x08,
      34,   11,   11,   11, 0x08,
      45,   11,   11,   11, 0x08,
      56,   11,   11,   11, 0x08,
      69,   11,   11,   11, 0x08,
      82,   11,   11,   11, 0x08,
      95,   11,   11,   11, 0x08,
     108,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_furniture2[] = {
    "furniture2\0\0led1show()\0led2show()\0"
    "led3show()\0led4show()\0other1show()\0"
    "other2show()\0other3show()\0other4show()\0"
    "back()\0"
};

const QMetaObject furniture2::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_furniture2,
      qt_meta_data_furniture2, 0 }
};

const QMetaObject *furniture2::metaObject() const
{
    return &staticMetaObject;
}

void *furniture2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_furniture2))
        return static_cast<void*>(const_cast< furniture2*>(this));
    return QWidget::qt_metacast(_clname);
}

int furniture2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: led1show(); break;
        case 1: led2show(); break;
        case 2: led3show(); break;
        case 3: led4show(); break;
        case 4: other1show(); break;
        case 5: other2show(); break;
        case 6: other3show(); break;
        case 7: other4show(); break;
        case 8: back(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
