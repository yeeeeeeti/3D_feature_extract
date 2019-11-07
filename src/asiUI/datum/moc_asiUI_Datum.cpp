/****************************************************************************
** Meta object code from reading C++ file 'asiUI_Datum.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_Datum.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_Datum.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_Datum_t {
    QByteArrayData data[10];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_Datum_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_Datum_t qt_meta_stringdata_asiUI_Datum = {
    {
QT_MOC_LITERAL(0, 0, 11), // "asiUI_Datum"
QT_MOC_LITERAL(1, 12, 12), // "ValueChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "theValue"
QT_MOC_LITERAL(4, 35, 19), // "OnUnitSystemChanged"
QT_MOC_LITERAL(5, 55, 28), // "asiAlgo_DictionaryUnitSystem"
QT_MOC_LITERAL(6, 84, 11), // "thePrevious"
QT_MOC_LITERAL(7, 96, 6), // "theNew"
QT_MOC_LITERAL(8, 103, 14), // "onValueChanged"
QT_MOC_LITERAL(9, 118, 8) // "QString&"

    },
    "asiUI_Datum\0ValueChanged\0\0theValue\0"
    "OnUnitSystemChanged\0asiAlgo_DictionaryUnitSystem\0"
    "thePrevious\0theNew\0onValueChanged\0"
    "QString&"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_Datum[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       1,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   43,    2, 0x0a /* Public */,
       8,    0,   48,    2, 0x08 /* Private */,
       8,    1,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    6,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    3,

       0        // eod
};

void asiUI_Datum::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_Datum *_t = static_cast<asiUI_Datum *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ValueChanged(); break;
        case 1: _t->ValueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->OnUnitSystemChanged((*reinterpret_cast< const asiAlgo_DictionaryUnitSystem(*)>(_a[1])),(*reinterpret_cast< const asiAlgo_DictionaryUnitSystem(*)>(_a[2]))); break;
        case 3: _t->onValueChanged(); break;
        case 4: _t->onValueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (asiUI_Datum::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_Datum::ValueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (asiUI_Datum::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_Datum::ValueChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject asiUI_Datum::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_asiUI_Datum.data,
      qt_meta_data_asiUI_Datum,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_Datum::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_Datum::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_Datum.stringdata0))
        return static_cast<void*>(const_cast< asiUI_Datum*>(this));
    return QObject::qt_metacast(_clname);
}

int asiUI_Datum::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void asiUI_Datum::ValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void asiUI_Datum::ValueChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_asiUI_Datum__DoubleValidator_t {
    QByteArrayData data[1];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_Datum__DoubleValidator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_Datum__DoubleValidator_t qt_meta_stringdata_asiUI_Datum__DoubleValidator = {
    {
QT_MOC_LITERAL(0, 0, 28) // "asiUI_Datum::DoubleValidator"

    },
    "asiUI_Datum::DoubleValidator"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_Datum__DoubleValidator[] = {

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

void asiUI_Datum::DoubleValidator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject asiUI_Datum::DoubleValidator::staticMetaObject = {
    { &QDS_DoubleValidator::staticMetaObject, qt_meta_stringdata_asiUI_Datum__DoubleValidator.data,
      qt_meta_data_asiUI_Datum__DoubleValidator,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_Datum::DoubleValidator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_Datum::DoubleValidator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_Datum__DoubleValidator.stringdata0))
        return static_cast<void*>(const_cast< DoubleValidator*>(this));
    return QDS_DoubleValidator::qt_metacast(_clname);
}

int asiUI_Datum::DoubleValidator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDS_DoubleValidator::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_asiUI_Datum__ExactRegExpValidator_t {
    QByteArrayData data[1];
    char stringdata0[34];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_Datum__ExactRegExpValidator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_Datum__ExactRegExpValidator_t qt_meta_stringdata_asiUI_Datum__ExactRegExpValidator = {
    {
QT_MOC_LITERAL(0, 0, 33) // "asiUI_Datum::ExactRegExpValid..."

    },
    "asiUI_Datum::ExactRegExpValidator"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_Datum__ExactRegExpValidator[] = {

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

void asiUI_Datum::ExactRegExpValidator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject asiUI_Datum::ExactRegExpValidator::staticMetaObject = {
    { &QRegExpValidator::staticMetaObject, qt_meta_stringdata_asiUI_Datum__ExactRegExpValidator.data,
      qt_meta_data_asiUI_Datum__ExactRegExpValidator,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_Datum::ExactRegExpValidator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_Datum::ExactRegExpValidator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_Datum__ExactRegExpValidator.stringdata0))
        return static_cast<void*>(const_cast< ExactRegExpValidator*>(this));
    return QRegExpValidator::qt_metacast(_clname);
}

int asiUI_Datum::ExactRegExpValidator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QRegExpValidator::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_asiUI_Datum__FormattedLineEdit_t {
    QByteArrayData data[1];
    char stringdata0[31];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_Datum__FormattedLineEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_Datum__FormattedLineEdit_t qt_meta_stringdata_asiUI_Datum__FormattedLineEdit = {
    {
QT_MOC_LITERAL(0, 0, 30) // "asiUI_Datum::FormattedLineEdit"

    },
    "asiUI_Datum::FormattedLineEdit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_Datum__FormattedLineEdit[] = {

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

void asiUI_Datum::FormattedLineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject asiUI_Datum::FormattedLineEdit::staticMetaObject = {
    { &QDS_LineEdit::Editor::staticMetaObject, qt_meta_stringdata_asiUI_Datum__FormattedLineEdit.data,
      qt_meta_data_asiUI_Datum__FormattedLineEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_Datum::FormattedLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_Datum::FormattedLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_Datum__FormattedLineEdit.stringdata0))
        return static_cast<void*>(const_cast< FormattedLineEdit*>(this));
    return QDS_LineEdit::Editor::qt_metacast(_clname);
}

int asiUI_Datum::FormattedLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDS_LineEdit::Editor::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
