/****************************************************************************
** Meta object code from reading C++ file 'asiUI_DatumSpinBoxDbl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_DatumSpinBoxDbl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_DatumSpinBoxDbl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_DatumSpinBoxDbl_t {
    QByteArrayData data[3];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumSpinBoxDbl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumSpinBoxDbl_t qt_meta_stringdata_asiUI_DatumSpinBoxDbl = {
    {
QT_MOC_LITERAL(0, 0, 21), // "asiUI_DatumSpinBoxDbl"
QT_MOC_LITERAL(1, 22, 15), // "EditingFinished"
QT_MOC_LITERAL(2, 38, 0) // ""

    },
    "asiUI_DatumSpinBoxDbl\0EditingFinished\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumSpinBoxDbl[] = {

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
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void asiUI_DatumSpinBoxDbl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_DatumSpinBoxDbl *_t = static_cast<asiUI_DatumSpinBoxDbl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->EditingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (asiUI_DatumSpinBoxDbl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_DatumSpinBoxDbl::EditingFinished)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject asiUI_DatumSpinBoxDbl::staticMetaObject = {
    { &asiUI_Datum::staticMetaObject, qt_meta_stringdata_asiUI_DatumSpinBoxDbl.data,
      qt_meta_data_asiUI_DatumSpinBoxDbl,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumSpinBoxDbl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumSpinBoxDbl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumSpinBoxDbl.stringdata0))
        return static_cast<void*>(const_cast< asiUI_DatumSpinBoxDbl*>(this));
    return asiUI_Datum::qt_metacast(_clname);
}

int asiUI_DatumSpinBoxDbl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = asiUI_Datum::qt_metacall(_c, _id, _a);
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
void asiUI_DatumSpinBoxDbl::EditingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_asiUI_DatumSpinBoxDbl__SpinBoxImpl_t {
    QByteArrayData data[4];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumSpinBoxDbl__SpinBoxImpl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumSpinBoxDbl__SpinBoxImpl_t qt_meta_stringdata_asiUI_DatumSpinBoxDbl__SpinBoxImpl = {
    {
QT_MOC_LITERAL(0, 0, 34), // "asiUI_DatumSpinBoxDbl::SpinBo..."
QT_MOC_LITERAL(1, 35, 15), // "EditingFinished"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 9) // "onChanged"

    },
    "asiUI_DatumSpinBoxDbl::SpinBoxImpl\0"
    "EditingFinished\0\0onChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumSpinBoxDbl__SpinBoxImpl[] = {

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
       3,    0,   25,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void asiUI_DatumSpinBoxDbl::SpinBoxImpl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SpinBoxImpl *_t = static_cast<SpinBoxImpl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->EditingFinished(); break;
        case 1: _t->onChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SpinBoxImpl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SpinBoxImpl::EditingFinished)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject asiUI_DatumSpinBoxDbl::SpinBoxImpl::staticMetaObject = {
    { &asiUI_Datum::DatumImpl<QDS_SpinBoxDbl>::staticMetaObject, qt_meta_stringdata_asiUI_DatumSpinBoxDbl__SpinBoxImpl.data,
      qt_meta_data_asiUI_DatumSpinBoxDbl__SpinBoxImpl,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumSpinBoxDbl::SpinBoxImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumSpinBoxDbl::SpinBoxImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumSpinBoxDbl__SpinBoxImpl.stringdata0))
        return static_cast<void*>(const_cast< SpinBoxImpl*>(this));
    return asiUI_Datum::DatumImpl<QDS_SpinBoxDbl>::qt_metacast(_clname);
}

int asiUI_DatumSpinBoxDbl::SpinBoxImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = asiUI_Datum::DatumImpl<QDS_SpinBoxDbl>::qt_metacall(_c, _id, _a);
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
void asiUI_DatumSpinBoxDbl::SpinBoxImpl::EditingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_asiUI_DatumSpinBoxDbl__SpinBoxWidget_t {
    QByteArrayData data[1];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumSpinBoxDbl__SpinBoxWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumSpinBoxDbl__SpinBoxWidget_t qt_meta_stringdata_asiUI_DatumSpinBoxDbl__SpinBoxWidget = {
    {
QT_MOC_LITERAL(0, 0, 36) // "asiUI_DatumSpinBoxDbl::SpinBo..."

    },
    "asiUI_DatumSpinBoxDbl::SpinBoxWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumSpinBoxDbl__SpinBoxWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void asiUI_DatumSpinBoxDbl::SpinBoxWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject asiUI_DatumSpinBoxDbl::SpinBoxWidget::staticMetaObject = {
    { &QtxDoubleSpinBox::staticMetaObject, qt_meta_stringdata_asiUI_DatumSpinBoxDbl__SpinBoxWidget.data,
      qt_meta_data_asiUI_DatumSpinBoxDbl__SpinBoxWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumSpinBoxDbl::SpinBoxWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumSpinBoxDbl::SpinBoxWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumSpinBoxDbl__SpinBoxWidget.stringdata0))
        return static_cast<void*>(const_cast< SpinBoxWidget*>(this));
    return QtxDoubleSpinBox::qt_metacast(_clname);
}

int asiUI_DatumSpinBoxDbl::SpinBoxWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QtxDoubleSpinBox::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
