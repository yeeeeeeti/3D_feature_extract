/****************************************************************************
** Meta object code from reading C++ file 'asiUI_ControlsMesh.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_ControlsMesh.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_ControlsMesh.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_ControlsMesh_t {
    QByteArrayData data[9];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_ControlsMesh_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_ControlsMesh_t qt_meta_stringdata_asiUI_ControlsMesh = {
    {
QT_MOC_LITERAL(0, 0, 18), // "asiUI_ControlsMesh"
QT_MOC_LITERAL(1, 19, 13), // "onLoadFromStl"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 13), // "onLoadFromPly"
QT_MOC_LITERAL(4, 48, 11), // "onSaveToStl"
QT_MOC_LITERAL(5, 60, 17), // "onSaveFacetsToPly"
QT_MOC_LITERAL(6, 78, 13), // "onSelectFaces"
QT_MOC_LITERAL(7, 92, 13), // "onSelectEdges"
QT_MOC_LITERAL(8, 106, 16) // "onSelectVertices"

    },
    "asiUI_ControlsMesh\0onLoadFromStl\0\0"
    "onLoadFromPly\0onSaveToStl\0onSaveFacetsToPly\0"
    "onSelectFaces\0onSelectEdges\0"
    "onSelectVertices"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_ControlsMesh[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void asiUI_ControlsMesh::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_ControlsMesh *_t = static_cast<asiUI_ControlsMesh *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onLoadFromStl(); break;
        case 1: _t->onLoadFromPly(); break;
        case 2: _t->onSaveToStl(); break;
        case 3: _t->onSaveFacetsToPly(); break;
        case 4: _t->onSelectFaces(); break;
        case 5: _t->onSelectEdges(); break;
        case 6: _t->onSelectVertices(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject asiUI_ControlsMesh::staticMetaObject = {
    { &QScrollArea::staticMetaObject, qt_meta_stringdata_asiUI_ControlsMesh.data,
      qt_meta_data_asiUI_ControlsMesh,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_ControlsMesh::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_ControlsMesh::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_ControlsMesh.stringdata0))
        return static_cast<void*>(const_cast< asiUI_ControlsMesh*>(this));
    return QScrollArea::qt_metacast(_clname);
}

int asiUI_ControlsMesh::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
