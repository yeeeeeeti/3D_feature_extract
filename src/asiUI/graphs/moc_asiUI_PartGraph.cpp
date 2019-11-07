/****************************************************************************
** Meta object code from reading C++ file 'asiUI_PartGraph.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_PartGraph.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_PartGraph.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_PartGraph_t {
    QByteArrayData data[6];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_PartGraph_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_PartGraph_t qt_meta_stringdata_asiUI_PartGraph = {
    {
QT_MOC_LITERAL(0, 0, 15), // "asiUI_PartGraph"
QT_MOC_LITERAL(1, 16, 14), // "onViewerClosed"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 14), // "onVertexPicked"
QT_MOC_LITERAL(4, 47, 16), // "TopAbs_ShapeEnum"
QT_MOC_LITERAL(5, 64, 9) // "vtkIdType"

    },
    "asiUI_PartGraph\0onViewerClosed\0\0"
    "onVertexPicked\0TopAbs_ShapeEnum\0"
    "vtkIdType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_PartGraph[] = {

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
       1,    0,   24,    2, 0x09 /* Protected */,
       3,    3,   25,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, 0x80000000 | 5,    2,    2,    2,

       0        // eod
};

void asiUI_PartGraph::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_PartGraph *_t = static_cast<asiUI_PartGraph *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onViewerClosed(); break;
        case 1: _t->onVertexPicked((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const TopAbs_ShapeEnum(*)>(_a[2])),(*reinterpret_cast< const vtkIdType(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject asiUI_PartGraph::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_asiUI_PartGraph.data,
      qt_meta_data_asiUI_PartGraph,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_PartGraph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_PartGraph::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_PartGraph.stringdata0))
        return static_cast<void*>(const_cast< asiUI_PartGraph*>(this));
    return QObject::qt_metacast(_clname);
}

int asiUI_PartGraph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
