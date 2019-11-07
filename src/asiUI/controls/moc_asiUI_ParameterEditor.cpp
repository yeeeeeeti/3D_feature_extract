/****************************************************************************
** Meta object code from reading C++ file 'asiUI_ParameterEditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_ParameterEditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_ParameterEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_ParameterEditor_t {
    QByteArrayData data[12];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_ParameterEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_ParameterEditor_t qt_meta_stringdata_asiUI_ParameterEditor = {
    {
QT_MOC_LITERAL(0, 0, 21), // "asiUI_ParameterEditor"
QT_MOC_LITERAL(1, 22, 20), // "ParamEditorActivated"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 10), // "theParamID"
QT_MOC_LITERAL(4, 55, 17), // "ParamEditorClosed"
QT_MOC_LITERAL(5, 73, 13), // "theIsCommited"
QT_MOC_LITERAL(6, 87, 13), // "ParamModified"
QT_MOC_LITERAL(7, 101, 8), // "theValue"
QT_MOC_LITERAL(8, 110, 20), // "ParamComputedChanged"
QT_MOC_LITERAL(9, 131, 13), // "theIsComputed"
QT_MOC_LITERAL(10, 145, 23), // "CustomSelectorTriggered"
QT_MOC_LITERAL(11, 169, 15) // "onParamModified"

    },
    "asiUI_ParameterEditor\0ParamEditorActivated\0"
    "\0theParamID\0ParamEditorClosed\0"
    "theIsCommited\0ParamModified\0theValue\0"
    "ParamComputedChanged\0theIsComputed\0"
    "CustomSelectorTriggered\0onParamModified"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_ParameterEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    2,   47,    2, 0x06 /* Public */,
       6,    2,   52,    2, 0x06 /* Public */,
       8,    2,   57,    2, 0x06 /* Public */,
      10,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    2,   65,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QVariant,    3,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    9,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QVariant,    3,    7,

       0        // eod
};

void asiUI_ParameterEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_ParameterEditor *_t = static_cast<asiUI_ParameterEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ParamEditorActivated((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->ParamEditorClosed((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 2: _t->ParamModified((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 3: _t->ParamComputedChanged((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 4: _t->CustomSelectorTriggered((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 5: _t->onParamModified((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (asiUI_ParameterEditor::*_t)(const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_ParameterEditor::ParamEditorActivated)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (asiUI_ParameterEditor::*_t)(const int , const bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_ParameterEditor::ParamEditorClosed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (asiUI_ParameterEditor::*_t)(const int , const QVariant & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_ParameterEditor::ParamModified)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (asiUI_ParameterEditor::*_t)(const int , const bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_ParameterEditor::ParamComputedChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (asiUI_ParameterEditor::*_t)(const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_ParameterEditor::CustomSelectorTriggered)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject asiUI_ParameterEditor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_asiUI_ParameterEditor.data,
      qt_meta_data_asiUI_ParameterEditor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_ParameterEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_ParameterEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_ParameterEditor.stringdata0))
        return static_cast<void*>(const_cast< asiUI_ParameterEditor*>(this));
    if (!strcmp(_clname, "SUIT_PopupClient"))
        return static_cast< SUIT_PopupClient*>(const_cast< asiUI_ParameterEditor*>(this));
    return QWidget::qt_metacast(_clname);
}

int asiUI_ParameterEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void asiUI_ParameterEditor::ParamEditorActivated(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void asiUI_ParameterEditor::ParamEditorClosed(const int _t1, const bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void asiUI_ParameterEditor::ParamModified(const int _t1, const QVariant & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void asiUI_ParameterEditor::ParamComputedChanged(const int _t1, const bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void asiUI_ParameterEditor::CustomSelectorTriggered(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
