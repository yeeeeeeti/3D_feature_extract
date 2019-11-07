/****************************************************************************
** Meta object code from reading C++ file 'QDS_LineEdit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QDS_LineEdit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QDS_LineEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QDS_LineEdit_t {
    QByteArrayData data[6];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QDS_LineEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QDS_LineEdit_t qt_meta_stringdata_QDS_LineEdit = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QDS_LineEdit"
QT_MOC_LITERAL(1, 13, 13), // "returnPressed"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "onParamChanged"
QT_MOC_LITERAL(4, 43, 13), // "onTextChanged"
QT_MOC_LITERAL(5, 57, 9) // "Selection"

    },
    "QDS_LineEdit\0returnPressed\0\0onParamChanged\0"
    "onTextChanged\0Selection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QDS_LineEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   34, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   30,    2, 0x09 /* Protected */,
       4,    1,   31,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // properties: name, type, flags
       5, QMetaType::Bool, 0x00095103,

       0        // eod
};

void QDS_LineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QDS_LineEdit *_t = static_cast<QDS_LineEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnPressed(); break;
        case 1: _t->onParamChanged(); break;
        case 2: _t->onTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QDS_LineEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QDS_LineEdit::returnPressed)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QDS_LineEdit *_t = static_cast<QDS_LineEdit *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->hasSelection(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QDS_LineEdit *_t = static_cast<QDS_LineEdit *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSelection(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QDS_LineEdit::staticMetaObject = {
    { &QDS_Datum::staticMetaObject, qt_meta_stringdata_QDS_LineEdit.data,
      qt_meta_data_QDS_LineEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QDS_LineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDS_LineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QDS_LineEdit.stringdata0))
        return static_cast<void*>(const_cast< QDS_LineEdit*>(this));
    return QDS_Datum::qt_metacast(_clname);
}

int QDS_LineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QDS_LineEdit::returnPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
