/****************************************************************************
** Meta object code from reading C++ file 'QDS_ComboBox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QDS_ComboBox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QDS_ComboBox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QDS_ComboBox_t {
    QByteArrayData data[5];
    char stringdata0[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QDS_ComboBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QDS_ComboBox_t qt_meta_stringdata_QDS_ComboBox = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QDS_ComboBox"
QT_MOC_LITERAL(1, 13, 9), // "activated"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "onActivated"
QT_MOC_LITERAL(4, 36, 13) // "onTextChanged"

    },
    "QDS_ComboBox\0activated\0\0onActivated\0"
    "onTextChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QDS_ComboBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       1,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x09 /* Protected */,
       4,    1,   43,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void QDS_ComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QDS_ComboBox *_t = static_cast<QDS_ComboBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QDS_ComboBox::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QDS_ComboBox::activated)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QDS_ComboBox::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QDS_ComboBox::activated)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject QDS_ComboBox::staticMetaObject = {
    { &QDS_Datum::staticMetaObject, qt_meta_stringdata_QDS_ComboBox.data,
      qt_meta_data_QDS_ComboBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QDS_ComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDS_ComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QDS_ComboBox.stringdata0))
        return static_cast<void*>(const_cast< QDS_ComboBox*>(this));
    return QDS_Datum::qt_metacast(_clname);
}

int QDS_ComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDS_Datum::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QDS_ComboBox::activated(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QDS_ComboBox::activated(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
