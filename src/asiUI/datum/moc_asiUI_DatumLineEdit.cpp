/****************************************************************************
** Meta object code from reading C++ file 'asiUI_DatumLineEdit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_DatumLineEdit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_DatumLineEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_DatumLineEdit_t {
    QByteArrayData data[4];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumLineEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumLineEdit_t qt_meta_stringdata_asiUI_DatumLineEdit = {
    {
QT_MOC_LITERAL(0, 0, 19), // "asiUI_DatumLineEdit"
QT_MOC_LITERAL(1, 20, 13), // "ReturnPressed"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 15) // "EditingFinished"

    },
    "asiUI_DatumLineEdit\0ReturnPressed\0\0"
    "EditingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumLineEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    0,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void asiUI_DatumLineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_DatumLineEdit *_t = static_cast<asiUI_DatumLineEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReturnPressed(); break;
        case 1: _t->EditingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (asiUI_DatumLineEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_DatumLineEdit::ReturnPressed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (asiUI_DatumLineEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_DatumLineEdit::EditingFinished)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject asiUI_DatumLineEdit::staticMetaObject = {
    { &asiUI_Datum::staticMetaObject, qt_meta_stringdata_asiUI_DatumLineEdit.data,
      qt_meta_data_asiUI_DatumLineEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumLineEdit.stringdata0))
        return static_cast<void*>(const_cast< asiUI_DatumLineEdit*>(this));
    return asiUI_Datum::qt_metacast(_clname);
}

int asiUI_DatumLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = asiUI_Datum::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void asiUI_DatumLineEdit::ReturnPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void asiUI_DatumLineEdit::EditingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_asiUI_DatumLineEdit__LineEditImpl_t {
    QByteArrayData data[4];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumLineEdit__LineEditImpl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumLineEdit__LineEditImpl_t qt_meta_stringdata_asiUI_DatumLineEdit__LineEditImpl = {
    {
QT_MOC_LITERAL(0, 0, 33), // "asiUI_DatumLineEdit::LineEdit..."
QT_MOC_LITERAL(1, 34, 15), // "EditingFinished"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 14) // "onParamChanged"

    },
    "asiUI_DatumLineEdit::LineEditImpl\0"
    "EditingFinished\0\0onParamChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumLineEdit__LineEditImpl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void asiUI_DatumLineEdit::LineEditImpl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LineEditImpl *_t = static_cast<LineEditImpl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->EditingFinished(); break;
        case 1: _t->onParamChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LineEditImpl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LineEditImpl::EditingFinished)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject asiUI_DatumLineEdit::LineEditImpl::staticMetaObject = {
    { &asiUI_Datum::DatumImpl<QDS_LineEdit>::staticMetaObject, qt_meta_stringdata_asiUI_DatumLineEdit__LineEditImpl.data,
      qt_meta_data_asiUI_DatumLineEdit__LineEditImpl,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumLineEdit::LineEditImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumLineEdit::LineEditImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumLineEdit__LineEditImpl.stringdata0))
        return static_cast<void*>(const_cast< LineEditImpl*>(this));
    return asiUI_Datum::DatumImpl<QDS_LineEdit>::qt_metacast(_clname);
}

int asiUI_DatumLineEdit::LineEditImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = asiUI_Datum::DatumImpl<QDS_LineEdit>::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void asiUI_DatumLineEdit::LineEditImpl::EditingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
