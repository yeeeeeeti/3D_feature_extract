/****************************************************************************
** Meta object code from reading C++ file 'asiUI_PrimDataView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_PrimDataView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_PrimDataView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_PrimDataView_t {
    QByteArrayData data[5];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_PrimDataView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_PrimDataView_t qt_meta_stringdata_asiUI_PrimDataView = {
    {
QT_MOC_LITERAL(0, 0, 18), // "asiUI_PrimDataView"
QT_MOC_LITERAL(1, 19, 12), // "valueChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 8), // "QWidget*"
QT_MOC_LITERAL(4, 42, 14) // "onEditFinished"

    },
    "asiUI_PrimDataView\0valueChanged\0\0"
    "QWidget*\0onEditFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_PrimDataView[] = {

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
       4,    0,   27,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void asiUI_PrimDataView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_PrimDataView *_t = static_cast<asiUI_PrimDataView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 1: _t->onEditFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (asiUI_PrimDataView::*_t)(QWidget * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_PrimDataView::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject asiUI_PrimDataView::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_asiUI_PrimDataView.data,
      qt_meta_data_asiUI_PrimDataView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_PrimDataView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_PrimDataView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_PrimDataView.stringdata0))
        return static_cast<void*>(const_cast< asiUI_PrimDataView*>(this));
    return QObject::qt_metacast(_clname);
}

int asiUI_PrimDataView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void asiUI_PrimDataView::valueChanged(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
