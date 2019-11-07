/****************************************************************************
** Meta object code from reading C++ file 'asiUI_DatumColorEdit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_DatumColorEdit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_DatumColorEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_DatumColorEdit_t {
    QByteArrayData data[5];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumColorEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumColorEdit_t qt_meta_stringdata_asiUI_DatumColorEdit = {
    {
QT_MOC_LITERAL(0, 0, 20), // "asiUI_DatumColorEdit"
QT_MOC_LITERAL(1, 21, 12), // "ColorChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 8), // "theValue"
QT_MOC_LITERAL(4, 44, 14) // "onUnitsUpdated"

    },
    "asiUI_DatumColorEdit\0ColorChanged\0\0"
    "theValue\0onUnitsUpdated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumColorEdit[] = {

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
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void asiUI_DatumColorEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_DatumColorEdit *_t = static_cast<asiUI_DatumColorEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ColorChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->onUnitsUpdated(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (asiUI_DatumColorEdit::*_t)(const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_DatumColorEdit::ColorChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject asiUI_DatumColorEdit::staticMetaObject = {
    { &asiUI_Datum::staticMetaObject, qt_meta_stringdata_asiUI_DatumColorEdit.data,
      qt_meta_data_asiUI_DatumColorEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumColorEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumColorEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumColorEdit.stringdata0))
        return static_cast<void*>(const_cast< asiUI_DatumColorEdit*>(this));
    return asiUI_Datum::qt_metacast(_clname);
}

int asiUI_DatumColorEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void asiUI_DatumColorEdit::ColorChanged(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_asiUI_DatumColorEdit__Editor_t {
    QByteArrayData data[6];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumColorEdit__Editor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumColorEdit__Editor_t qt_meta_stringdata_asiUI_DatumColorEdit__Editor = {
    {
QT_MOC_LITERAL(0, 0, 28), // "asiUI_DatumColorEdit::Editor"
QT_MOC_LITERAL(1, 29, 12), // "ColorChanged"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 13), // "theColorValue"
QT_MOC_LITERAL(4, 57, 14), // "onColorChanged"
QT_MOC_LITERAL(5, 72, 8) // "theColor"

    },
    "asiUI_DatumColorEdit::Editor\0ColorChanged\0"
    "\0theColorValue\0onColorChanged\0theColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumColorEdit__Editor[] = {

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
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QColor,    5,

       0        // eod
};

void asiUI_DatumColorEdit::Editor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Editor *_t = static_cast<Editor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ColorChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->onColorChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Editor::*_t)(const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Editor::ColorChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject asiUI_DatumColorEdit::Editor::staticMetaObject = {
    { &QDS_Datum::staticMetaObject, qt_meta_stringdata_asiUI_DatumColorEdit__Editor.data,
      qt_meta_data_asiUI_DatumColorEdit__Editor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumColorEdit::Editor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumColorEdit::Editor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumColorEdit__Editor.stringdata0))
        return static_cast<void*>(const_cast< Editor*>(this));
    return QDS_Datum::qt_metacast(_clname);
}

int asiUI_DatumColorEdit::Editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDS_Datum::qt_metacall(_c, _id, _a);
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
void asiUI_DatumColorEdit::Editor::ColorChanged(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
