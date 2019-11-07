/****************************************************************************
** Meta object code from reading C++ file 'asiUI_Plot2d.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_Plot2d.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_Plot2d.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_Plot2d_t {
    QByteArrayData data[4];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_Plot2d_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_Plot2d_t qt_meta_stringdata_asiUI_Plot2d = {
    {
QT_MOC_LITERAL(0, 0, 12), // "asiUI_Plot2d"
QT_MOC_LITERAL(1, 13, 12), // "onMouseEvent"
QT_MOC_LITERAL(2, 26, 12), // "asiUI_EXPORT"
QT_MOC_LITERAL(3, 39, 14) // "onDumpGraphics"

    },
    "asiUI_Plot2d\0onMouseEvent\0asiUI_EXPORT\0"
    "onDumpGraphics"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_Plot2d[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    0,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void asiUI_Plot2d::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_Plot2d *_t = static_cast<asiUI_Plot2d *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onMouseEvent(); break;
        case 1: _t->onDumpGraphics(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject asiUI_Plot2d::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_asiUI_Plot2d.data,
      qt_meta_data_asiUI_Plot2d,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_Plot2d::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_Plot2d::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_Plot2d.stringdata0))
        return static_cast<void*>(const_cast< asiUI_Plot2d*>(this));
    return QWidget::qt_metacast(_clname);
}

int asiUI_Plot2d::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
