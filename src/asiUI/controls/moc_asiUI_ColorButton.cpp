/****************************************************************************
** Meta object code from reading C++ file 'asiUI_ColorButton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_ColorButton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_ColorButton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_ColorButton_t {
    QByteArrayData data[8];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_ColorButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_ColorButton_t qt_meta_stringdata_asiUI_ColorButton = {
    {
QT_MOC_LITERAL(0, 0, 17), // "asiUI_ColorButton"
QT_MOC_LITERAL(1, 18, 7), // "clicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "changed"
QT_MOC_LITERAL(4, 35, 13), // "onAboutToShow"
QT_MOC_LITERAL(5, 49, 9), // "onClicked"
QT_MOC_LITERAL(6, 59, 9), // "onToggled"
QT_MOC_LITERAL(7, 69, 15) // "onDialogClicked"

    },
    "asiUI_ColorButton\0clicked\0\0changed\0"
    "onAboutToShow\0onClicked\0onToggled\0"
    "onDialogClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_ColorButton[] = {

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
       1,    1,   44,    2, 0x06 /* Public */,
       3,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   50,    2, 0x08 /* Private */,
       5,    1,   51,    2, 0x08 /* Private */,
       6,    1,   54,    2, 0x08 /* Private */,
       7,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void asiUI_ColorButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_ColorButton *_t = static_cast<asiUI_ColorButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: _t->changed((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 2: _t->onAboutToShow(); break;
        case 3: _t->onClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->onDialogClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (asiUI_ColorButton::*_t)(QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_ColorButton::clicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (asiUI_ColorButton::*_t)(QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_ColorButton::changed)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject asiUI_ColorButton::staticMetaObject = {
    { &QToolButton::staticMetaObject, qt_meta_stringdata_asiUI_ColorButton.data,
      qt_meta_data_asiUI_ColorButton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_ColorButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_ColorButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_ColorButton.stringdata0))
        return static_cast<void*>(const_cast< asiUI_ColorButton*>(this));
    return QToolButton::qt_metacast(_clname);
}

int asiUI_ColorButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolButton::qt_metacall(_c, _id, _a);
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
void asiUI_ColorButton::clicked(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void asiUI_ColorButton::changed(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
