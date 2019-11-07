/****************************************************************************
** Meta object code from reading C++ file 'asiUI_ControlsAnalysis.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_ControlsAnalysis.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_ControlsAnalysis.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_ControlsAnalysis_t {
    QByteArrayData data[20];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_ControlsAnalysis_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_ControlsAnalysis_t qt_meta_stringdata_asiUI_ControlsAnalysis = {
    {
QT_MOC_LITERAL(0, 0, 22), // "asiUI_ControlsAnalysis"
QT_MOC_LITERAL(1, 23, 10), // "onDiagnose"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 12), // "onCheckToler"
QT_MOC_LITERAL(4, 48, 12), // "onCheckEuler"
QT_MOC_LITERAL(5, 61, 15), // "onCheckContours"
QT_MOC_LITERAL(6, 77, 15), // "onFindOpenEdges"
QT_MOC_LITERAL(7, 93, 22), // "onFindNonManifoldEdges"
QT_MOC_LITERAL(8, 116, 15), // "onShowTopoGraph"
QT_MOC_LITERAL(9, 132, 9), // "onShowAAG"
QT_MOC_LITERAL(10, 142, 14), // "onShowAAGWoSel"
QT_MOC_LITERAL(11, 157, 16), // "onCheckDihAngles"
QT_MOC_LITERAL(12, 174, 17), // "onFindSmoothEdges"
QT_MOC_LITERAL(13, 192, 16), // "onFindConvexOnly"
QT_MOC_LITERAL(14, 209, 15), // "onEdgeCurvature"
QT_MOC_LITERAL(15, 225, 12), // "onEdgeLength"
QT_MOC_LITERAL(16, 238, 12), // "onEdgeStrain"
QT_MOC_LITERAL(17, 251, 10), // "onFaceArea"
QT_MOC_LITERAL(18, 262, 12), // "onFaceEnergy"
QT_MOC_LITERAL(19, 275, 6) // "onAABB"

    },
    "asiUI_ControlsAnalysis\0onDiagnose\0\0"
    "onCheckToler\0onCheckEuler\0onCheckContours\0"
    "onFindOpenEdges\0onFindNonManifoldEdges\0"
    "onShowTopoGraph\0onShowAAG\0onShowAAGWoSel\0"
    "onCheckDihAngles\0onFindSmoothEdges\0"
    "onFindConvexOnly\0onEdgeCurvature\0"
    "onEdgeLength\0onEdgeStrain\0onFaceArea\0"
    "onFaceEnergy\0onAABB"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_ControlsAnalysis[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a /* Public */,
       3,    0,  105,    2, 0x0a /* Public */,
       4,    0,  106,    2, 0x0a /* Public */,
       5,    0,  107,    2, 0x0a /* Public */,
       6,    0,  108,    2, 0x0a /* Public */,
       7,    0,  109,    2, 0x0a /* Public */,
       8,    0,  110,    2, 0x0a /* Public */,
       9,    0,  111,    2, 0x0a /* Public */,
      10,    0,  112,    2, 0x0a /* Public */,
      11,    0,  113,    2, 0x0a /* Public */,
      12,    0,  114,    2, 0x0a /* Public */,
      13,    0,  115,    2, 0x0a /* Public */,
      14,    0,  116,    2, 0x0a /* Public */,
      15,    0,  117,    2, 0x0a /* Public */,
      16,    0,  118,    2, 0x0a /* Public */,
      17,    0,  119,    2, 0x0a /* Public */,
      18,    0,  120,    2, 0x0a /* Public */,
      19,    0,  121,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

void asiUI_ControlsAnalysis::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_ControlsAnalysis *_t = static_cast<asiUI_ControlsAnalysis *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onDiagnose(); break;
        case 1: _t->onCheckToler(); break;
        case 2: _t->onCheckEuler(); break;
        case 3: _t->onCheckContours(); break;
        case 4: _t->onFindOpenEdges(); break;
        case 5: _t->onFindNonManifoldEdges(); break;
        case 6: _t->onShowTopoGraph(); break;
        case 7: _t->onShowAAG(); break;
        case 8: _t->onShowAAGWoSel(); break;
        case 9: _t->onCheckDihAngles(); break;
        case 10: _t->onFindSmoothEdges(); break;
        case 11: _t->onFindConvexOnly(); break;
        case 12: _t->onEdgeCurvature(); break;
        case 13: _t->onEdgeLength(); break;
        case 14: _t->onEdgeStrain(); break;
        case 15: _t->onFaceArea(); break;
        case 16: _t->onFaceEnergy(); break;
        case 17: _t->onAABB(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject asiUI_ControlsAnalysis::staticMetaObject = {
    { &QScrollArea::staticMetaObject, qt_meta_stringdata_asiUI_ControlsAnalysis.data,
      qt_meta_data_asiUI_ControlsAnalysis,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_ControlsAnalysis::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_ControlsAnalysis::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_ControlsAnalysis.stringdata0))
        return static_cast<void*>(const_cast< asiUI_ControlsAnalysis*>(this));
    return QScrollArea::qt_metacast(_clname);
}

int asiUI_ControlsAnalysis::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
