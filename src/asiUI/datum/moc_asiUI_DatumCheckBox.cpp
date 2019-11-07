/****************************************************************************
** Meta object code from reading C++ file 'asiUI_DatumCheckBox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_DatumCheckBox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_DatumCheckBox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_DatumCheckBox_t {
    QByteArrayData data[4];
    char stringdata0[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumCheckBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumCheckBox_t qt_meta_stringdata_asiUI_DatumCheckBox = {
    {
QT_MOC_LITERAL(0, 0, 19), // "asiUI_DatumCheckBox"
QT_MOC_LITERAL(1, 20, 7), // "Toggled"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12) // "theIsChecked"

    },
    "asiUI_DatumCheckBox\0Toggled\0\0theIsChecked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumCheckBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void asiUI_DatumCheckBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_DatumCheckBox *_t = static_cast<asiUI_DatumCheckBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (asiUI_DatumCheckBox::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_DatumCheckBox::Toggled)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject asiUI_DatumCheckBox::staticMetaObject = {
    { &asiUI_Datum::staticMetaObject, qt_meta_stringdata_asiUI_DatumCheckBox.data,
      qt_meta_data_asiUI_DatumCheckBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumCheckBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumCheckBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumCheckBox.stringdata0))
        return static_cast<void*>(const_cast< asiUI_DatumCheckBox*>(this));
    return asiUI_Datum::qt_metacast(_clname);
}

int asiUI_DatumCheckBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = asiUI_Datum::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void asiUI_DatumCheckBox::Toggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_asiUI_DatumCheckBox__CheckBoxImpl_t {
    QByteArrayData data[1];
    char stringdata0[34];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumCheckBox__CheckBoxImpl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumCheckBox__CheckBoxImpl_t qt_meta_stringdata_asiUI_DatumCheckBox__CheckBoxImpl = {
    {
QT_MOC_LITERAL(0, 0, 33) // "asiUI_DatumCheckBox::CheckBox..."

    },
    "asiUI_DatumCheckBox::CheckBoxImpl"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumCheckBox__CheckBoxImpl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void asiUI_DatumCheckBox::CheckBoxImpl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject asiUI_DatumCheckBox::CheckBoxImpl::staticMetaObject = {
    { &asiUI_Datum::DatumImpl<QDS_CheckBox>::staticMetaObject, qt_meta_stringdata_asiUI_DatumCheckBox__CheckBoxImpl.data,
      qt_meta_data_asiUI_DatumCheckBox__CheckBoxImpl,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumCheckBox::CheckBoxImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumCheckBox::CheckBoxImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumCheckBox__CheckBoxImpl.stringdata0))
        return static_cast<void*>(const_cast< CheckBoxImpl*>(this));
    return asiUI_Datum::DatumImpl<QDS_CheckBox>::qt_metacast(_clname);
}

int asiUI_DatumCheckBox::CheckBoxImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = asiUI_Datum::DatumImpl<QDS_CheckBox>::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
