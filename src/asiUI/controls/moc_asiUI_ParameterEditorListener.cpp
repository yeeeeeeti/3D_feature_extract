/****************************************************************************
** Meta object code from reading C++ file 'asiUI_ParameterEditorListener.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_ParameterEditorListener.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_ParameterEditorListener.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_ParameterEditorListener_t {
    QByteArrayData data[6];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_ParameterEditorListener_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_ParameterEditorListener_t qt_meta_stringdata_asiUI_ParameterEditorListener = {
    {
QT_MOC_LITERAL(0, 0, 29), // "asiUI_ParameterEditorListener"
QT_MOC_LITERAL(1, 30, 15), // "parameterStored"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 18), // "onParameterChanged"
QT_MOC_LITERAL(4, 66, 3), // "pid"
QT_MOC_LITERAL(5, 70, 5) // "value"

    },
    "asiUI_ParameterEditorListener\0"
    "parameterStored\0\0onParameterChanged\0"
    "pid\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_ParameterEditorListener[] = {

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
       3,    2,   25,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QVariant,    4,    5,

       0        // eod
};

void asiUI_ParameterEditorListener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_ParameterEditorListener *_t = static_cast<asiUI_ParameterEditorListener *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->parameterStored(); break;
        case 1: _t->onParameterChanged((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (asiUI_ParameterEditorListener::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_ParameterEditorListener::parameterStored)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject asiUI_ParameterEditorListener::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_asiUI_ParameterEditorListener.data,
      qt_meta_data_asiUI_ParameterEditorListener,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_ParameterEditorListener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_ParameterEditorListener::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_ParameterEditorListener.stringdata0))
        return static_cast<void*>(const_cast< asiUI_ParameterEditorListener*>(this));
    return QObject::qt_metacast(_clname);
}

int asiUI_ParameterEditorListener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void asiUI_ParameterEditorListener::parameterStored()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
