/****************************************************************************
** Meta object code from reading C++ file 'asiUI_ControlsPartListener.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_ControlsPartListener.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_ControlsPartListener.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_ControlsPartListener_t {
    QByteArrayData data[8];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_ControlsPartListener_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_ControlsPartListener_t qt_meta_stringdata_asiUI_ControlsPartListener = {
    {
QT_MOC_LITERAL(0, 0, 26), // "asiUI_ControlsPartListener"
QT_MOC_LITERAL(1, 27, 12), // "onPartLoaded"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 11), // "onPartAdded"
QT_MOC_LITERAL(4, 53, 14), // "onPartModified"
QT_MOC_LITERAL(5, 68, 18), // "onSelectionFacesOn"
QT_MOC_LITERAL(6, 87, 18), // "onSelectionEdgesOn"
QT_MOC_LITERAL(7, 106, 21) // "onSelectionVerticesOn"

    },
    "asiUI_ControlsPartListener\0onPartLoaded\0"
    "\0onPartAdded\0onPartModified\0"
    "onSelectionFacesOn\0onSelectionEdgesOn\0"
    "onSelectionVerticesOn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_ControlsPartListener[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x09 /* Protected */,
       3,    1,   47,    2, 0x09 /* Protected */,
       4,    0,   50,    2, 0x09 /* Protected */,
       5,    0,   51,    2, 0x09 /* Protected */,
       6,    0,   52,    2, 0x09 /* Protected */,
       7,    0,   53,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void asiUI_ControlsPartListener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_ControlsPartListener *_t = static_cast<asiUI_ControlsPartListener *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onPartLoaded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onPartAdded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onPartModified(); break;
        case 3: _t->onSelectionFacesOn(); break;
        case 4: _t->onSelectionEdgesOn(); break;
        case 5: _t->onSelectionVerticesOn(); break;
        default: ;
        }
    }
}

const QMetaObject asiUI_ControlsPartListener::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_asiUI_ControlsPartListener.data,
      qt_meta_data_asiUI_ControlsPartListener,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_ControlsPartListener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_ControlsPartListener::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_ControlsPartListener.stringdata0))
        return static_cast<void*>(const_cast< asiUI_ControlsPartListener*>(this));
    return QObject::qt_metacast(_clname);
}

int asiUI_ControlsPartListener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
