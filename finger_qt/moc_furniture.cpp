/****************************************************************************
** Meta object code from reading C++ file 'furniture.h'
**
** Created: Fri Apr 26 18:59:02 2013
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "furniture.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'furniture.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_furniture[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      22,   10,   10,   10, 0x08,
      33,   10,   10,   10, 0x08,
      44,   10,   10,   10, 0x08,
      55,   10,   10,   10, 0x08,
      66,   10,   10,   10, 0x08,
      77,   10,   10,   10, 0x08,
      88,   10,   10,   10, 0x08,
      99,   10,   10,   10, 0x08,
     114,   10,   10,   10, 0x08,
     129,   10,   10,   10, 0x08,
     144,   10,   10,   10, 0x08,
     159,   10,   10,   10, 0x08,
     166,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_furniture[] = {
    "furniture\0\0led1show()\0led2show()\0"
    "led3show()\0led4show()\0air1show()\0"
    "air2show()\0air3show()\0air4show()\0"
    "curtain1show()\0curtain2show()\0"
    "curtain3show()\0curtain4show()\0back()\0"
    "go()\0"
};

const QMetaObject furniture::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_furniture,
      qt_meta_data_furniture, 0 }
};

const QMetaObject *furniture::metaObject() const
{
    return &staticMetaObject;
}

void *furniture::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_furniture))
        return static_cast<void*>(const_cast< furniture*>(this));
    return QWidget::qt_metacast(_clname);
}

int furniture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 4: air1show(); break;
        case 5: air2show(); break;
        case 6: air3show(); break;
        case 7: air4show(); break;
        case 8: curtain1show(); break;
        case 9: curtain2show(); break;
        case 10: curtain3show(); break;
        case 11: curtain4show(); break;
        case 12: back(); break;
        case 13: go(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
