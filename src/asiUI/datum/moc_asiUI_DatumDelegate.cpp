/****************************************************************************
** Meta object code from reading C++ file 'asiUI_DatumDelegate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_DatumDelegate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_DatumDelegate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_DatumDelegate_t {
    QByteArrayData data[9];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumDelegate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumDelegate_t qt_meta_stringdata_asiUI_DatumDelegate = {
    {
QT_MOC_LITERAL(0, 0, 19), // "asiUI_DatumDelegate"
QT_MOC_LITERAL(1, 20, 13), // "EditorCreated"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 8), // "QWidget*"
QT_MOC_LITERAL(4, 44, 9), // "theEditor"
QT_MOC_LITERAL(5, 54, 8), // "theIndex"
QT_MOC_LITERAL(6, 63, 23), // "CustomSelectorTriggered"
QT_MOC_LITERAL(7, 87, 13), // "onCommitValue"
QT_MOC_LITERAL(8, 101, 13) // "onCloseEditor"

    },
    "asiUI_DatumDelegate\0EditorCreated\0\0"
    "QWidget*\0theEditor\0theIndex\0"
    "CustomSelectorTriggered\0onCommitValue\0"
    "onCloseEditor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumDelegate[] = {

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
       1,    2,   34,    2, 0x06 /* Public */,
       6,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   42,    2, 0x09 /* Protected */,
       8,    0,   43,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QModelIndex,    4,    5,
    QMetaType::Void, QMetaType::QModelIndex,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void asiUI_DatumDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_DatumDelegate *_t = static_cast<asiUI_DatumDelegate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->EditorCreated((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 1: _t->CustomSelectorTriggered((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->onCommitValue(); break;
        case 3: _t->onCloseEditor(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (asiUI_DatumDelegate::*_t)(QWidget * , const QModelIndex & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_DatumDelegate::EditorCreated)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (asiUI_DatumDelegate::*_t)(const QModelIndex & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_DatumDelegate::CustomSelectorTriggered)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject asiUI_DatumDelegate::staticMetaObject = {
    { &QStyledItemDelegate::staticMetaObject, qt_meta_stringdata_asiUI_DatumDelegate.data,
      qt_meta_data_asiUI_DatumDelegate,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumDelegate.stringdata0))
        return static_cast<void*>(const_cast< asiUI_DatumDelegate*>(this));
    return QStyledItemDelegate::qt_metacast(_clname);
}

int asiUI_DatumDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
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
void asiUI_DatumDelegate::EditorCreated(QWidget * _t1, const QModelIndex & _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< asiUI_DatumDelegate *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void asiUI_DatumDelegate::CustomSelectorTriggered(const QModelIndex & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
