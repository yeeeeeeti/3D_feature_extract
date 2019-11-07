/****************************************************************************
** Meta object code from reading C++ file 'asiUI_DatumRadioBox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_DatumRadioBox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_DatumRadioBox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_DatumRadioBox_t {
    QByteArrayData data[6];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumRadioBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumRadioBox_t qt_meta_stringdata_asiUI_DatumRadioBox = {
    {
QT_MOC_LITERAL(0, 0, 19), // "asiUI_DatumRadioBox"
QT_MOC_LITERAL(1, 20, 9), // "Activated"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "theID"
QT_MOC_LITERAL(4, 37, 14), // "onUnitsUpdated"
QT_MOC_LITERAL(5, 52, 11) // "onActivated"

    },
    "asiUI_DatumRadioBox\0Activated\0\0theID\0"
    "onUnitsUpdated\0onActivated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumRadioBox[] = {

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
       4,    0,   32,    2, 0x0a /* Public */,
       5,    1,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void asiUI_DatumRadioBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_DatumRadioBox *_t = static_cast<asiUI_DatumRadioBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onUnitsUpdated(); break;
        case 2: _t->onActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (asiUI_DatumRadioBox::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_DatumRadioBox::Activated)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject asiUI_DatumRadioBox::staticMetaObject = {
    { &asiUI_Datum::staticMetaObject, qt_meta_stringdata_asiUI_DatumRadioBox.data,
      qt_meta_data_asiUI_DatumRadioBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumRadioBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumRadioBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumRadioBox.stringdata0))
        return static_cast<void*>(const_cast< asiUI_DatumRadioBox*>(this));
    return asiUI_Datum::qt_metacast(_clname);
}

int asiUI_DatumRadioBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = asiUI_Datum::qt_metacall(_c, _id, _a);
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
void asiUI_DatumRadioBox::Activated(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_asiUI_DatumRadioBox__Editor_t {
    QByteArrayData data[1];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumRadioBox__Editor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumRadioBox__Editor_t qt_meta_stringdata_asiUI_DatumRadioBox__Editor = {
    {
QT_MOC_LITERAL(0, 0, 27) // "asiUI_DatumRadioBox::Editor"

    },
    "asiUI_DatumRadioBox::Editor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumRadioBox__Editor[] = {

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

void asiUI_DatumRadioBox::Editor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject asiUI_DatumRadioBox::Editor::staticMetaObject = {
    { &QDS_RadioBox::staticMetaObject, qt_meta_stringdata_asiUI_DatumRadioBox__Editor.data,
      qt_meta_data_asiUI_DatumRadioBox__Editor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumRadioBox::Editor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumRadioBox::Editor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumRadioBox__Editor.stringdata0))
        return static_cast<void*>(const_cast< Editor*>(this));
    return QDS_RadioBox::qt_metacast(_clname);
}

int asiUI_DatumRadioBox::Editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDS_RadioBox::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
