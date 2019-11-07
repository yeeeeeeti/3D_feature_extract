/****************************************************************************
** Meta object code from reading C++ file 'asiUI_DatumSelector.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_DatumSelector.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_DatumSelector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_DatumSelector_t {
    QByteArrayData data[4];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumSelector_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumSelector_t qt_meta_stringdata_asiUI_DatumSelector = {
    {
QT_MOC_LITERAL(0, 0, 19), // "asiUI_DatumSelector"
QT_MOC_LITERAL(1, 20, 17), // "SelectionFinished"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 14) // "onUnitsUpdated"

    },
    "asiUI_DatumSelector\0SelectionFinished\0"
    "\0onUnitsUpdated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumSelector[] = {

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
       3,    0,   25,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void asiUI_DatumSelector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_DatumSelector *_t = static_cast<asiUI_DatumSelector *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SelectionFinished(); break;
        case 1: _t->onUnitsUpdated(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (asiUI_DatumSelector::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_DatumSelector::SelectionFinished)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject asiUI_DatumSelector::staticMetaObject = {
    { &asiUI_Datum::staticMetaObject, qt_meta_stringdata_asiUI_DatumSelector.data,
      qt_meta_data_asiUI_DatumSelector,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumSelector.stringdata0))
        return static_cast<void*>(const_cast< asiUI_DatumSelector*>(this));
    return asiUI_Datum::qt_metacast(_clname);
}

int asiUI_DatumSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void asiUI_DatumSelector::SelectionFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_asiUI_DatumSelector__Editor_t {
    QByteArrayData data[3];
    char stringdata0[47];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumSelector__Editor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumSelector__Editor_t qt_meta_stringdata_asiUI_DatumSelector__Editor = {
    {
QT_MOC_LITERAL(0, 0, 27), // "asiUI_DatumSelector::Editor"
QT_MOC_LITERAL(1, 28, 17), // "SelectionFinished"
QT_MOC_LITERAL(2, 46, 0) // ""

    },
    "asiUI_DatumSelector::Editor\0"
    "SelectionFinished\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumSelector__Editor[] = {

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
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void asiUI_DatumSelector::Editor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Editor *_t = static_cast<Editor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SelectionFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Editor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Editor::SelectionFinished)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject asiUI_DatumSelector::Editor::staticMetaObject = {
    { &QDS_Datum::staticMetaObject, qt_meta_stringdata_asiUI_DatumSelector__Editor.data,
      qt_meta_data_asiUI_DatumSelector__Editor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumSelector::Editor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumSelector::Editor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumSelector__Editor.stringdata0))
        return static_cast<void*>(const_cast< Editor*>(this));
    return QDS_Datum::qt_metacast(_clname);
}

int asiUI_DatumSelector::Editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDS_Datum::qt_metacall(_c, _id, _a);
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
void asiUI_DatumSelector::Editor::SelectionFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
