/****************************************************************************
** Meta object code from reading C++ file 'asiUI_DatumLabel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_DatumLabel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_DatumLabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_DatumLabel_t {
    QByteArrayData data[1];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumLabel_t qt_meta_stringdata_asiUI_DatumLabel = {
    {
QT_MOC_LITERAL(0, 0, 16) // "asiUI_DatumLabel"

    },
    "asiUI_DatumLabel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumLabel[] = {

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

void asiUI_DatumLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject asiUI_DatumLabel::staticMetaObject = {
    { &asiUI_Datum::staticMetaObject, qt_meta_stringdata_asiUI_DatumLabel.data,
      qt_meta_data_asiUI_DatumLabel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumLabel.stringdata0))
        return static_cast<void*>(const_cast< asiUI_DatumLabel*>(this));
    return asiUI_Datum::qt_metacast(_clname);
}

int asiUI_DatumLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = asiUI_Datum::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_asiUI_DatumLabel__Editor_t {
    QByteArrayData data[1];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumLabel__Editor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumLabel__Editor_t qt_meta_stringdata_asiUI_DatumLabel__Editor = {
    {
QT_MOC_LITERAL(0, 0, 24) // "asiUI_DatumLabel::Editor"

    },
    "asiUI_DatumLabel::Editor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumLabel__Editor[] = {

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

void asiUI_DatumLabel::Editor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject asiUI_DatumLabel::Editor::staticMetaObject = {
    { &asiUI_Datum::DatumImpl<QDS_Datum>::staticMetaObject, qt_meta_stringdata_asiUI_DatumLabel__Editor.data,
      qt_meta_data_asiUI_DatumLabel__Editor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumLabel::Editor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumLabel::Editor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumLabel__Editor.stringdata0))
        return static_cast<void*>(const_cast< Editor*>(this));
    return asiUI_Datum::DatumImpl<QDS_Datum>::qt_metacast(_clname);
}

int asiUI_DatumLabel::Editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = asiUI_Datum::DatumImpl<QDS_Datum>::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
