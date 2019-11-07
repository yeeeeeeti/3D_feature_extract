/****************************************************************************
** Meta object code from reading C++ file 'QtxColorButton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QtxColorButton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtxColorButton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtxColorButton_t {
    QByteArrayData data[9];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtxColorButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtxColorButton_t qt_meta_stringdata_QtxColorButton = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QtxColorButton"
QT_MOC_LITERAL(1, 15, 7), // "clicked"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "changed"
QT_MOC_LITERAL(4, 32, 9), // "onClicked"
QT_MOC_LITERAL(5, 42, 9), // "onToggled"
QT_MOC_LITERAL(6, 52, 13), // "onAboutToShow"
QT_MOC_LITERAL(7, 66, 13), // "onAutoClicked"
QT_MOC_LITERAL(8, 80, 15) // "onDialogClicked"

    },
    "QtxColorButton\0clicked\0\0changed\0"
    "onClicked\0onToggled\0onAboutToShow\0"
    "onAutoClicked\0onDialogClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtxColorButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   55,    2, 0x08 /* Private */,
       5,    1,   58,    2, 0x08 /* Private */,
       6,    0,   61,    2, 0x08 /* Private */,
       7,    1,   62,    2, 0x08 /* Private */,
       8,    1,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void QtxColorButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtxColorButton *_t = static_cast<QtxColorButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: _t->changed((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 2: _t->onClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onAboutToShow(); break;
        case 5: _t->onAutoClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->onDialogClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QtxColorButton::*_t)(QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtxColorButton::clicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QtxColorButton::*_t)(QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtxColorButton::changed)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject QtxColorButton::staticMetaObject = {
    { &QToolButton::staticMetaObject, qt_meta_stringdata_QtxColorButton.data,
      qt_meta_data_QtxColorButton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtxColorButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtxColorButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtxColorButton.stringdata0))
        return static_cast<void*>(const_cast< QtxColorButton*>(this));
    return QToolButton::qt_metacast(_clname);
}

int QtxColorButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QtxColorButton::clicked(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtxColorButton::changed(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
