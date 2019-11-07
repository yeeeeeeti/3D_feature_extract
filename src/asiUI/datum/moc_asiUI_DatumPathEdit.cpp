/****************************************************************************
** Meta object code from reading C++ file 'asiUI_DatumPathEdit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_DatumPathEdit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_DatumPathEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_DatumPathEdit_t {
    QByteArrayData data[8];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumPathEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumPathEdit_t qt_meta_stringdata_asiUI_DatumPathEdit = {
    {
QT_MOC_LITERAL(0, 0, 19), // "asiUI_DatumPathEdit"
QT_MOC_LITERAL(1, 20, 12), // "PathSelected"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 13), // "ReturnPressed"
QT_MOC_LITERAL(4, 48, 15), // "EditingFinished"
QT_MOC_LITERAL(5, 64, 12), // "SetDirectory"
QT_MOC_LITERAL(6, 77, 7), // "thePath"
QT_MOC_LITERAL(7, 85, 14) // "onUnitsUpdated"

    },
    "asiUI_DatumPathEdit\0PathSelected\0\0"
    "ReturnPressed\0EditingFinished\0"
    "SetDirectory\0thePath\0onUnitsUpdated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumPathEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   42,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

       0        // eod
};

void asiUI_DatumPathEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_DatumPathEdit *_t = static_cast<asiUI_DatumPathEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->PathSelected(); break;
        case 1: _t->ReturnPressed(); break;
        case 2: _t->EditingFinished(); break;
        case 3: _t->SetDirectory((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onUnitsUpdated(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (asiUI_DatumPathEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_DatumPathEdit::PathSelected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (asiUI_DatumPathEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_DatumPathEdit::ReturnPressed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (asiUI_DatumPathEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_DatumPathEdit::EditingFinished)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject asiUI_DatumPathEdit::staticMetaObject = {
    { &asiUI_Datum::staticMetaObject, qt_meta_stringdata_asiUI_DatumPathEdit.data,
      qt_meta_data_asiUI_DatumPathEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumPathEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumPathEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumPathEdit.stringdata0))
        return static_cast<void*>(const_cast< asiUI_DatumPathEdit*>(this));
    return asiUI_Datum::qt_metacast(_clname);
}

int asiUI_DatumPathEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = asiUI_Datum::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void asiUI_DatumPathEdit::PathSelected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void asiUI_DatumPathEdit::ReturnPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void asiUI_DatumPathEdit::EditingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
struct qt_meta_stringdata_asiUI_DatumPathEdit__Editor_t {
    QByteArrayData data[8];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumPathEdit__Editor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumPathEdit__Editor_t qt_meta_stringdata_asiUI_DatumPathEdit__Editor = {
    {
QT_MOC_LITERAL(0, 0, 27), // "asiUI_DatumPathEdit::Editor"
QT_MOC_LITERAL(1, 28, 12), // "PathSelected"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 13), // "ReturnPressed"
QT_MOC_LITERAL(4, 56, 15), // "EditingFinished"
QT_MOC_LITERAL(5, 72, 12), // "onOpenDialog"
QT_MOC_LITERAL(6, 85, 13), // "onTextChanged"
QT_MOC_LITERAL(7, 99, 6) // "theStr"

    },
    "asiUI_DatumPathEdit::Editor\0PathSelected\0"
    "\0ReturnPressed\0EditingFinished\0"
    "onOpenDialog\0onTextChanged\0theStr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumPathEdit__Editor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   42,    2, 0x08 /* Private */,
       6,    1,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void asiUI_DatumPathEdit::Editor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Editor *_t = static_cast<Editor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->PathSelected(); break;
        case 1: _t->ReturnPressed(); break;
        case 2: _t->EditingFinished(); break;
        case 3: _t->onOpenDialog(); break;
        case 4: _t->onTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Editor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Editor::PathSelected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Editor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Editor::ReturnPressed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Editor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Editor::EditingFinished)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject asiUI_DatumPathEdit::Editor::staticMetaObject = {
    { &QDS_Datum::staticMetaObject, qt_meta_stringdata_asiUI_DatumPathEdit__Editor.data,
      qt_meta_data_asiUI_DatumPathEdit__Editor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumPathEdit::Editor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumPathEdit::Editor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumPathEdit__Editor.stringdata0))
        return static_cast<void*>(const_cast< Editor*>(this));
    return QDS_Datum::qt_metacast(_clname);
}

int asiUI_DatumPathEdit::Editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDS_Datum::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void asiUI_DatumPathEdit::Editor::PathSelected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void asiUI_DatumPathEdit::Editor::ReturnPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void asiUI_DatumPathEdit::Editor::EditingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
