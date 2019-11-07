/****************************************************************************
** Meta object code from reading C++ file 'asiUI_ViewerDomain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_ViewerDomain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_ViewerDomain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_ViewerDomain_t {
    QByteArrayData data[11];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_ViewerDomain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_ViewerDomain_t qt_meta_stringdata_asiUI_ViewerDomain = {
    {
QT_MOC_LITERAL(0, 0, 18), // "asiUI_ViewerDomain"
QT_MOC_LITERAL(1, 19, 11), // "pointPicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 1), // "x"
QT_MOC_LITERAL(4, 34, 1), // "y"
QT_MOC_LITERAL(5, 36, 12), // "partModified"
QT_MOC_LITERAL(6, 49, 11), // "onResetView"
QT_MOC_LITERAL(7, 61, 14), // "onDomainPicked"
QT_MOC_LITERAL(8, 76, 11), // "onKillEdges"
QT_MOC_LITERAL(9, 88, 11), // "onJoinEdges"
QT_MOC_LITERAL(10, 100, 13) // "onContextMenu"

    },
    "asiUI_ViewerDomain\0pointPicked\0\0x\0y\0"
    "partModified\0onResetView\0onDomainPicked\0"
    "onKillEdges\0onJoinEdges\0onContextMenu"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_ViewerDomain[] = {

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
       1,    2,   49,    2, 0x06 /* Public */,
       5,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   55,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x0a /* Public */,
       8,    0,   57,    2, 0x0a /* Public */,
       9,    0,   58,    2, 0x0a /* Public */,
      10,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,

       0        // eod
};

void asiUI_ViewerDomain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_ViewerDomain *_t = static_cast<asiUI_ViewerDomain *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pointPicked((*reinterpret_cast< const double(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2]))); break;
        case 1: _t->partModified(); break;
        case 2: _t->onResetView(); break;
        case 3: _t->onDomainPicked(); break;
        case 4: _t->onKillEdges(); break;
        case 5: _t->onJoinEdges(); break;
        case 6: _t->onContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (asiUI_ViewerDomain::*_t)(const double , const double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_ViewerDomain::pointPicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (asiUI_ViewerDomain::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_ViewerDomain::partModified)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject asiUI_ViewerDomain::staticMetaObject = {
    { &asiUI_Viewer::staticMetaObject, qt_meta_stringdata_asiUI_ViewerDomain.data,
      qt_meta_data_asiUI_ViewerDomain,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_ViewerDomain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_ViewerDomain::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_ViewerDomain.stringdata0))
        return static_cast<void*>(const_cast< asiUI_ViewerDomain*>(this));
    return asiUI_Viewer::qt_metacast(_clname);
}

int asiUI_ViewerDomain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = asiUI_Viewer::qt_metacall(_c, _id, _a);
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
void asiUI_ViewerDomain::pointPicked(const double _t1, const double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void asiUI_ViewerDomain::partModified()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
