/****************************************************************************
** Meta object code from reading C++ file 'asiUI_PartGraphItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_PartGraphItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_PartGraphItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_PartGraphItem_t {
    QByteArrayData data[8];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_PartGraphItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_PartGraphItem_t qt_meta_stringdata_asiUI_PartGraphItem = {
    {
QT_MOC_LITERAL(0, 0, 19), // "asiUI_PartGraphItem"
QT_MOC_LITERAL(1, 20, 12), // "vertexPicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 10), // "subShapeId"
QT_MOC_LITERAL(4, 45, 16), // "TopAbs_ShapeEnum"
QT_MOC_LITERAL(5, 62, 12), // "subShapeType"
QT_MOC_LITERAL(6, 75, 9), // "vtkIdType"
QT_MOC_LITERAL(7, 85, 8) // "vertexId"

    },
    "asiUI_PartGraphItem\0vertexPicked\0\0"
    "subShapeId\0TopAbs_ShapeEnum\0subShapeType\0"
    "vtkIdType\0vertexId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_PartGraphItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, 0x80000000 | 6,    3,    5,    7,

       0        // eod
};

void asiUI_PartGraphItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_PartGraphItem *_t = static_cast<asiUI_PartGraphItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->vertexPicked((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const TopAbs_ShapeEnum(*)>(_a[2])),(*reinterpret_cast< const vtkIdType(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (asiUI_PartGraphItem::*_t)(const int , const TopAbs_ShapeEnum , const vtkIdType );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_PartGraphItem::vertexPicked)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject asiUI_PartGraphItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_asiUI_PartGraphItem.data,
      qt_meta_data_asiUI_PartGraphItem,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_PartGraphItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_PartGraphItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_PartGraphItem.stringdata0))
        return static_cast<void*>(const_cast< asiUI_PartGraphItem*>(this));
    if (!strcmp(_clname, "vtkGraphItem"))
        return static_cast< vtkGraphItem*>(const_cast< asiUI_PartGraphItem*>(this));
    return QObject::qt_metacast(_clname);
}

int asiUI_PartGraphItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void asiUI_PartGraphItem::vertexPicked(const int _t1, const TopAbs_ShapeEnum _t2, const vtkIdType _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
