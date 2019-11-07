/****************************************************************************
** Meta object code from reading C++ file 'asiUI_DatumColorItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_DatumColorItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_DatumColorItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_DatumColorItem_t {
    QByteArrayData data[5];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumColorItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumColorItem_t qt_meta_stringdata_asiUI_DatumColorItem = {
    {
QT_MOC_LITERAL(0, 0, 20), // "asiUI_DatumColorItem"
QT_MOC_LITERAL(1, 21, 12), // "ColorChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 8), // "theValue"
QT_MOC_LITERAL(4, 44, 14) // "onUnitsUpdated"

    },
    "asiUI_DatumColorItem\0ColorChanged\0\0"
    "theValue\0onUnitsUpdated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumColorItem[] = {

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
       4,    0,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void asiUI_DatumColorItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_DatumColorItem *_t = static_cast<asiUI_DatumColorItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ColorChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->onUnitsUpdated(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (asiUI_DatumColorItem::*_t)(const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_DatumColorItem::ColorChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject asiUI_DatumColorItem::staticMetaObject = {
    { &asiUI_Datum::staticMetaObject, qt_meta_stringdata_asiUI_DatumColorItem.data,
      qt_meta_data_asiUI_DatumColorItem,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumColorItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumColorItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumColorItem.stringdata0))
        return static_cast<void*>(const_cast< asiUI_DatumColorItem*>(this));
    return asiUI_Datum::qt_metacast(_clname);
}

int asiUI_DatumColorItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = asiUI_Datum::qt_metacall(_c, _id, _a);
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
void asiUI_DatumColorItem::ColorChanged(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_asiUI_DatumColorItem__Editor_t {
    QByteArrayData data[6];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumColorItem__Editor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumColorItem__Editor_t qt_meta_stringdata_asiUI_DatumColorItem__Editor = {
    {
QT_MOC_LITERAL(0, 0, 28), // "asiUI_DatumColorItem::Editor"
QT_MOC_LITERAL(1, 29, 12), // "ColorChanged"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 13), // "theColorValue"
QT_MOC_LITERAL(4, 57, 14), // "onColorChanged"
QT_MOC_LITERAL(5, 72, 8) // "theColor"

    },
    "asiUI_DatumColorItem::Editor\0ColorChanged\0"
    "\0theColorValue\0onColorChanged\0theColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumColorItem__Editor[] = {

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
       4,    1,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QColor,    5,

       0        // eod
};

void asiUI_DatumColorItem::Editor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Editor *_t = static_cast<Editor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ColorChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->onColorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Editor::*_t)(const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Editor::ColorChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject asiUI_DatumColorItem::Editor::staticMetaObject = {
    { &QDS_Datum::staticMetaObject, qt_meta_stringdata_asiUI_DatumColorItem__Editor.data,
      qt_meta_data_asiUI_DatumColorItem__Editor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumColorItem::Editor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumColorItem::Editor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumColorItem__Editor.stringdata0))
        return static_cast<void*>(const_cast< Editor*>(this));
    return QDS_Datum::qt_metacast(_clname);
}

int asiUI_DatumColorItem::Editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDS_Datum::qt_metacall(_c, _id, _a);
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
void asiUI_DatumColorItem::Editor::ColorChanged(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_asiUI_DatumColorItem__ColorItemDialog_t {
    QByteArrayData data[5];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumColorItem__ColorItemDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumColorItem__ColorItemDialog_t qt_meta_stringdata_asiUI_DatumColorItem__ColorItemDialog = {
    {
QT_MOC_LITERAL(0, 0, 37), // "asiUI_DatumColorItem::ColorIt..."
QT_MOC_LITERAL(1, 38, 12), // "ColorChanged"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 8), // "theColor"
QT_MOC_LITERAL(4, 61, 5) // "color"

    },
    "asiUI_DatumColorItem::ColorItemDialog\0"
    "ColorChanged\0\0theColor\0color"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumColorItem__ColorItemDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    3,

 // properties: name, type, flags
       4, QMetaType::QColor, 0x00195003,

       0        // eod
};

void asiUI_DatumColorItem::ColorItemDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ColorItemDialog *_t = static_cast<ColorItemDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ColorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ColorItemDialog::*_t)(const QColor & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ColorItemDialog::ColorChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ColorItemDialog *_t = static_cast<ColorItemDialog *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = _t->currentColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ColorItemDialog *_t = static_cast<ColorItemDialog *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentColor(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject asiUI_DatumColorItem::ColorItemDialog::staticMetaObject = {
    { &QColorDialog::staticMetaObject, qt_meta_stringdata_asiUI_DatumColorItem__ColorItemDialog.data,
      qt_meta_data_asiUI_DatumColorItem__ColorItemDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumColorItem::ColorItemDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumColorItem::ColorItemDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumColorItem__ColorItemDialog.stringdata0))
        return static_cast<void*>(const_cast< ColorItemDialog*>(this));
    return QColorDialog::qt_metacast(_clname);
}

int asiUI_DatumColorItem::ColorItemDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QColorDialog::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void asiUI_DatumColorItem::ColorItemDialog::ColorChanged(const QColor & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
