/****************************************************************************
** Meta object code from reading C++ file 'asiUI_DatumComboBox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_DatumComboBox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_DatumComboBox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_DatumComboBox_t {
    QByteArrayData data[6];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumComboBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumComboBox_t qt_meta_stringdata_asiUI_DatumComboBox = {
    {
QT_MOC_LITERAL(0, 0, 19), // "asiUI_DatumComboBox"
QT_MOC_LITERAL(1, 20, 9), // "Activated"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "theValue"
QT_MOC_LITERAL(4, 40, 13), // "theStringName"
QT_MOC_LITERAL(5, 54, 14) // "onUnitsUpdated"

    },
    "asiUI_DatumComboBox\0Activated\0\0theValue\0"
    "theStringName\0onUnitsUpdated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumComboBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       1,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void asiUI_DatumComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_DatumComboBox *_t = static_cast<asiUI_DatumComboBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->Activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onUnitsUpdated(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (asiUI_DatumComboBox::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_DatumComboBox::Activated)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (asiUI_DatumComboBox::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_DatumComboBox::Activated)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject asiUI_DatumComboBox::staticMetaObject = {
    { &asiUI_Datum::staticMetaObject, qt_meta_stringdata_asiUI_DatumComboBox.data,
      qt_meta_data_asiUI_DatumComboBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumComboBox.stringdata0))
        return static_cast<void*>(const_cast< asiUI_DatumComboBox*>(this));
    return asiUI_Datum::qt_metacast(_clname);
}

int asiUI_DatumComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void asiUI_DatumComboBox::Activated(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void asiUI_DatumComboBox::Activated(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_asiUI_DatumComboBox__Editor_t {
    QByteArrayData data[1];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumComboBox__Editor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumComboBox__Editor_t qt_meta_stringdata_asiUI_DatumComboBox__Editor = {
    {
QT_MOC_LITERAL(0, 0, 27) // "asiUI_DatumComboBox::Editor"

    },
    "asiUI_DatumComboBox::Editor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumComboBox__Editor[] = {

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

void asiUI_DatumComboBox::Editor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject asiUI_DatumComboBox::Editor::staticMetaObject = {
    { &QDS_ComboBox::staticMetaObject, qt_meta_stringdata_asiUI_DatumComboBox__Editor.data,
      qt_meta_data_asiUI_DatumComboBox__Editor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumComboBox::Editor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumComboBox::Editor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumComboBox__Editor.stringdata0))
        return static_cast<void*>(const_cast< Editor*>(this));
    return QDS_ComboBox::qt_metacast(_clname);
}

int asiUI_DatumComboBox::Editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDS_ComboBox::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
