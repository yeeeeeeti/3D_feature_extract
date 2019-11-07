/****************************************************************************
** Meta object code from reading C++ file 'asiUI_ControlsPart.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_ControlsPart.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_ControlsPart.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_ControlsPart_t {
    QByteArrayData data[17];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_ControlsPart_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_ControlsPart_t qt_meta_stringdata_asiUI_ControlsPart = {
    {
QT_MOC_LITERAL(0, 0, 18), // "asiUI_ControlsPart"
QT_MOC_LITERAL(1, 19, 10), // "partLoaded"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 9), // "partAdded"
QT_MOC_LITERAL(4, 41, 9), // "partSaved"
QT_MOC_LITERAL(5, 51, 12), // "partModified"
QT_MOC_LITERAL(6, 64, 16), // "selectionFacesOn"
QT_MOC_LITERAL(7, 81, 16), // "selectionEdgesOn"
QT_MOC_LITERAL(8, 98, 19), // "selectionVerticesOn"
QT_MOC_LITERAL(9, 118, 14), // "onLoadFromSTEP"
QT_MOC_LITERAL(10, 133, 14), // "onLoadFromBRep"
QT_MOC_LITERAL(11, 148, 20), // "onLoadFromBRepAppend"
QT_MOC_LITERAL(12, 169, 12), // "onSaveToSTEP"
QT_MOC_LITERAL(13, 182, 12), // "onSaveToBRep"
QT_MOC_LITERAL(14, 195, 13), // "onSelectFaces"
QT_MOC_LITERAL(15, 209, 13), // "onSelectEdges"
QT_MOC_LITERAL(16, 223, 16) // "onSelectVertices"

    },
    "asiUI_ControlsPart\0partLoaded\0\0partAdded\0"
    "partSaved\0partModified\0selectionFacesOn\0"
    "selectionEdgesOn\0selectionVerticesOn\0"
    "onLoadFromSTEP\0onLoadFromBRep\0"
    "onLoadFromBRepAppend\0onSaveToSTEP\0"
    "onSaveToBRep\0onSelectFaces\0onSelectEdges\0"
    "onSelectVertices"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_ControlsPart[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       3,    1,   92,    2, 0x06 /* Public */,
       4,    0,   95,    2, 0x06 /* Public */,
       5,    0,   96,    2, 0x06 /* Public */,
       6,    0,   97,    2, 0x06 /* Public */,
       7,    0,   98,    2, 0x06 /* Public */,
       8,    0,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  100,    2, 0x0a /* Public */,
      10,    0,  101,    2, 0x0a /* Public */,
      11,    0,  102,    2, 0x0a /* Public */,
      12,    0,  103,    2, 0x0a /* Public */,
      13,    0,  104,    2, 0x0a /* Public */,
      14,    0,  105,    2, 0x0a /* Public */,
      15,    0,  106,    2, 0x0a /* Public */,
      16,    0,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void asiUI_ControlsPart::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_ControlsPart *_t = static_cast<asiUI_ControlsPart *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->partLoaded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->partAdded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->partSaved(); break;
        case 3: _t->partModified(); break;
        case 4: _t->selectionFacesOn(); break;
        case 5: _t->selectionEdgesOn(); break;
        case 6: _t->selectionVerticesOn(); break;
        case 7: _t->onLoadFromSTEP(); break;
        case 8: _t->onLoadFromBRep(); break;
        case 9: _t->onLoadFromBRepAppend(); break;
        case 10: _t->onSaveToSTEP(); break;
        case 11: _t->onSaveToBRep(); break;
        case 12: _t->onSelectFaces(); break;
        case 13: _t->onSelectEdges(); break;
        case 14: _t->onSelectVertices(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (asiUI_ControlsPart::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_ControlsPart::partLoaded)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (asiUI_ControlsPart::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_ControlsPart::partAdded)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (asiUI_ControlsPart::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_ControlsPart::partSaved)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (asiUI_ControlsPart::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_ControlsPart::partModified)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (asiUI_ControlsPart::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_ControlsPart::selectionFacesOn)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (asiUI_ControlsPart::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_ControlsPart::selectionEdgesOn)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (asiUI_ControlsPart::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_ControlsPart::selectionVerticesOn)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject asiUI_ControlsPart::staticMetaObject = {
    { &QScrollArea::staticMetaObject, qt_meta_stringdata_asiUI_ControlsPart.data,
      qt_meta_data_asiUI_ControlsPart,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_ControlsPart::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_ControlsPart::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_ControlsPart.stringdata0))
        return static_cast<void*>(const_cast< asiUI_ControlsPart*>(this));
    return QScrollArea::qt_metacast(_clname);
}

int asiUI_ControlsPart::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void asiUI_ControlsPart::partLoaded(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void asiUI_ControlsPart::partAdded(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void asiUI_ControlsPart::partSaved()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void asiUI_ControlsPart::partModified()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void asiUI_ControlsPart::selectionFacesOn()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void asiUI_ControlsPart::selectionEdgesOn()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void asiUI_ControlsPart::selectionVerticesOn()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
