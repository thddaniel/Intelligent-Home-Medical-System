/****************************************************************************
** Meta object code from reading C++ file 'telwidget.h'
**
** Created: Fri Apr 26 18:59:16 2013
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "telwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'telwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TelWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      21,   10,   10,   10, 0x0a,
      31,   10,   10,   10, 0x0a,
      41,   10,   10,   10, 0x0a,
      51,   10,   10,   10, 0x0a,
      61,   10,   10,   10, 0x0a,
      71,   10,   10,   10, 0x0a,
      81,   10,   10,   10, 0x0a,
      91,   10,   10,   10, 0x0a,
     101,   10,   10,   10, 0x0a,
     111,   10,   10,   10, 0x0a,
     118,   10,   10,   10, 0x0a,
     125,   10,   10,   10, 0x0a,
     132,   10,   10,   10, 0x0a,
     141,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TelWidget[] = {
    "TelWidget\0\0press_0()\0press_1()\0press_2()\0"
    "press_3()\0press_4()\0press_5()\0press_6()\0"
    "press_7()\0press_8()\0press_9()\0back()\0"
    "call()\0stop()\0listen()\0exit()\0"
};

const QMetaObject TelWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TelWidget,
      qt_meta_data_TelWidget, 0 }
};

const QMetaObject *TelWidget::metaObject() const
{
    return &staticMetaObject;
}

void *TelWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TelWidget))
        return static_cast<void*>(const_cast< TelWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int TelWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: press_0(); break;
        case 1: press_1(); break;
        case 2: press_2(); break;
        case 3: press_3(); break;
        case 4: press_4(); break;
        case 5: press_5(); break;
        case 6: press_6(); break;
        case 7: press_7(); break;
        case 8: press_8(); break;
        case 9: press_9(); break;
        case 10: back(); break;
        case 11: call(); break;
        case 12: stop(); break;
        case 13: listen(); break;
        case 14: exit(); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
