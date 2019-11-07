/****************************************************************************
** Meta object code from reading C++ file 'asiUI_DatumViewBase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_DatumViewBase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_DatumViewBase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_DatumViewEventHandler_t {
    QByteArrayData data[6];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumViewEventHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumViewEventHandler_t qt_meta_stringdata_asiUI_DatumViewEventHandler = {
    {
QT_MOC_LITERAL(0, 0, 27), // "asiUI_DatumViewEventHandler"
QT_MOC_LITERAL(1, 28, 14), // "onUnitsChanged"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 13), // "onItemPressed"
QT_MOC_LITERAL(4, 58, 8), // "theIndex"
QT_MOC_LITERAL(5, 67, 15) // "onItemActivated"

    },
    "asiUI_DatumViewEventHandler\0onUnitsChanged\0"
    "\0onItemPressed\0theIndex\0onItemActivated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumViewEventHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x09 /* Protected */,
       3,    1,   30,    2, 0x09 /* Protected */,
       5,    1,   33,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void, QMetaType::QModelIndex,    4,

       0        // eod
};

void asiUI_DatumViewEventHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_DatumViewEventHandler *_t = static_cast<asiUI_DatumViewEventHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onUnitsChanged(); break;
        case 1: _t->onItemPressed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->onItemActivated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject asiUI_DatumViewEventHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_asiUI_DatumViewEventHandler.data,
      qt_meta_data_asiUI_DatumViewEventHandler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumViewEventHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumViewEventHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumViewEventHandler.stringdata0))
        return static_cast<void*>(const_cast< asiUI_DatumViewEventHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int asiUI_DatumViewEventHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
