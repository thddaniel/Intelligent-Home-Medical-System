/****************************************************************************
** Meta object code from reading C++ file 'musicwidget.h'
**
** Created: Fri Apr 26 18:59:10 2013
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "musicwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MusicWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x0a,
      38,   12,   12,   12, 0x0a,
      52,   12,   12,   12, 0x0a,
      76,   12,   12,   12, 0x0a,
     100,   12,   12,   12, 0x0a,
     128,   12,   12,   12, 0x0a,
     158,   12,   12,   12, 0x0a,
     182,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MusicWidget[] = {
    "MusicWidget\0\0value\0volume_change(int)\0"
    "mute_on_off()\0on_PlayButton_clicked()\0"
    "on_StopButton_clicked()\0"
    "on_NextSongButton_clicked()\0"
    "on_UpdateListButton_clicked()\0"
    "on_PrevButton_clicked()\0on_Debug()\0"
};

const QMetaObject MusicWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MusicWidget,
      qt_meta_data_MusicWidget, 0 }
};

const QMetaObject *MusicWidget::metaObject() const
{
    return &staticMetaObject;
}

void *MusicWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MusicWidget))
        return static_cast<void*>(const_cast< MusicWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MusicWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: volume_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: mute_on_off(); break;
        case 2: on_PlayButton_clicked(); break;
        case 3: on_StopButton_clicked(); break;
        case 4: on_NextSongButton_clicked(); break;
        case 5: on_UpdateListButton_clicked(); break;
        case 6: on_PrevButton_clicked(); break;
        case 7: on_Debug(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
