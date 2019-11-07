/****************************************************************************
** Meta object code from reading C++ file 'QDS_Datum.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QDS_Datum.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QDS_Datum.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QDS_Datum_t {
    QByteArrayData data[8];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QDS_Datum_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QDS_Datum_t qt_meta_stringdata_QDS_Datum = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QDS_Datum"
QT_MOC_LITERAL(1, 10, 12), // "paramChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "QString&"
QT_MOC_LITERAL(4, 33, 10), // "setEnabled"
QT_MOC_LITERAL(5, 44, 14), // "onParamChanged"
QT_MOC_LITERAL(6, 59, 11), // "onInitDatum"
QT_MOC_LITERAL(7, 71, 11) // "onDestroyed"

    },
    "QDS_Datum\0paramChanged\0\0QString&\0"
    "setEnabled\0onParamChanged\0onInitDatum\0"
    "onDestroyed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QDS_Datum[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       1,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   48,    2, 0x0a /* Public */,
       5,    0,   51,    2, 0x09 /* Protected */,
       6,    0,   52,    2, 0x08 /* Private */,
       7,    1,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QObjectStar,    2,

       0        // eod
};

void QDS_Datum::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QDS_Datum *_t = static_cast<QDS_Datum *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->paramChanged(); break;
        case 1: _t->paramChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onParamChanged(); break;
        case 4: _t->onInitDatum(); break;
        case 5: _t->onDestroyed((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QDS_Datum::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QDS_Datum::paramChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QDS_Datum::*_t)(QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QDS_Datum::paramChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject QDS_Datum::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QDS_Datum.data,
      qt_meta_data_QDS_Datum,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QDS_Datum::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDS_Datum::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QDS_Datum.stringdata0))
        return static_cast<void*>(const_cast< QDS_Datum*>(this));
    if (!strcmp(_clname, "QDS"))
        return static_cast< QDS*>(const_cast< QDS_Datum*>(this));
    return QObject::qt_metacast(_clname);
}

int QDS_Datum::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QDS_Datum::paramChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QDS_Datum::paramChanged(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
