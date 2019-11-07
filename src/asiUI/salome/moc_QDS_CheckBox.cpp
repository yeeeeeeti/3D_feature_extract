/****************************************************************************
** Meta object code from reading C++ file 'QDS_CheckBox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QDS_CheckBox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QDS_CheckBox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QDS_CheckBox_t {
    QByteArrayData data[5];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QDS_CheckBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QDS_CheckBox_t qt_meta_stringdata_QDS_CheckBox = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QDS_CheckBox"
QT_MOC_LITERAL(1, 13, 7), // "toggled"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "onParamChanged"
QT_MOC_LITERAL(4, 37, 14) // "onStateChanged"

    },
    "QDS_CheckBox\0toggled\0\0onParamChanged\0"
    "onStateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QDS_CheckBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   32,    2, 0x08 /* Private */,
       4,    1,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void QDS_CheckBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QDS_CheckBox *_t = static_cast<QDS_CheckBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onParamChanged(); break;
        case 2: _t->onStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QDS_CheckBox::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QDS_CheckBox::toggled)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject QDS_CheckBox::staticMetaObject = {
    { &QDS_Datum::staticMetaObject, qt_meta_stringdata_QDS_CheckBox.data,
      qt_meta_data_QDS_CheckBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QDS_CheckBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDS_CheckBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QDS_CheckBox.stringdata0))
        return static_cast<void*>(const_cast< QDS_CheckBox*>(this));
    return QDS_Datum::qt_metacast(_clname);
}

int QDS_CheckBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDS_Datum::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void QDS_CheckBox::toggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
