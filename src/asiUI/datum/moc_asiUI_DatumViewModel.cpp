/****************************************************************************
** Meta object code from reading C++ file 'asiUI_DatumViewModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asiUI_DatumViewModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QSet>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asiUI_DatumViewModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_asiUI_DatumViewModel_t {
    QByteArrayData data[9];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumViewModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumViewModel_t qt_meta_stringdata_asiUI_DatumViewModel = {
    {
QT_MOC_LITERAL(0, 0, 20), // "asiUI_DatumViewModel"
QT_MOC_LITERAL(1, 21, 14), // "OnRowsInserted"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 9), // "theParent"
QT_MOC_LITERAL(4, 47, 8), // "theFirst"
QT_MOC_LITERAL(5, 56, 7), // "theLast"
QT_MOC_LITERAL(6, 64, 13), // "OnRowsRemoved"
QT_MOC_LITERAL(7, 78, 17), // "OnColumnsInserted"
QT_MOC_LITERAL(8, 96, 16) // "OnColumnsRemoved"

    },
    "asiUI_DatumViewModel\0OnRowsInserted\0"
    "\0theParent\0theFirst\0theLast\0OnRowsRemoved\0"
    "OnColumnsInserted\0OnColumnsRemoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumViewModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x09 /* Protected */,
       6,    3,   41,    2, 0x09 /* Protected */,
       7,    3,   48,    2, 0x09 /* Protected */,
       8,    3,   55,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    3,    4,    5,

       0        // eod
};

void asiUI_DatumViewModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_DatumViewModel *_t = static_cast<asiUI_DatumViewModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnRowsInserted((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->OnRowsRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->OnColumnsInserted((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->OnColumnsRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject asiUI_DatumViewModel::staticMetaObject = {
    { &QStandardItemModel::staticMetaObject, qt_meta_stringdata_asiUI_DatumViewModel.data,
      qt_meta_data_asiUI_DatumViewModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumViewModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumViewModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumViewModel.stringdata0))
        return static_cast<void*>(const_cast< asiUI_DatumViewModel*>(this));
    if (!strcmp(_clname, "asiUI_HeaderViewDataApi"))
        return static_cast< asiUI_HeaderViewDataApi*>(const_cast< asiUI_DatumViewModel*>(this));
    return QStandardItemModel::qt_metacast(_clname);
}

int asiUI_DatumViewModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStandardItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
struct qt_meta_stringdata_asiUI_DatumViewSelectionModel_t {
    QByteArrayData data[30];
    char stringdata0[433];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_asiUI_DatumViewSelectionModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_asiUI_DatumViewSelectionModel_t qt_meta_stringdata_asiUI_DatumViewSelectionModel = {
    {
QT_MOC_LITERAL(0, 0, 29), // "asiUI_DatumViewSelectionModel"
QT_MOC_LITERAL(1, 30, 16), // "selectionChanged"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 15), // "Qt::Orientation"
QT_MOC_LITERAL(4, 64, 9), // "theHeader"
QT_MOC_LITERAL(5, 74, 21), // "asiUI_HeaderIndexList"
QT_MOC_LITERAL(6, 96, 11), // "theSelected"
QT_MOC_LITERAL(7, 108, 13), // "theDeselected"
QT_MOC_LITERAL(8, 122, 6), // "select"
QT_MOC_LITERAL(9, 129, 17), // "asiUI_HeaderIndex"
QT_MOC_LITERAL(10, 147, 8), // "theIndex"
QT_MOC_LITERAL(11, 156, 35), // "QItemSelectionModel::Selectio..."
QT_MOC_LITERAL(12, 192, 10), // "theCommand"
QT_MOC_LITERAL(13, 203, 24), // "QList<asiUI_HeaderIndex>"
QT_MOC_LITERAL(14, 228, 10), // "theIndexes"
QT_MOC_LITERAL(15, 239, 14), // "QItemSelection"
QT_MOC_LITERAL(16, 254, 12), // "theSelection"
QT_MOC_LITERAL(17, 267, 5), // "clear"
QT_MOC_LITERAL(18, 273, 5), // "reset"
QT_MOC_LITERAL(19, 279, 18), // "OnSelectionChanged"
QT_MOC_LITERAL(20, 298, 21), // "OnSelectionInSections"
QT_MOC_LITERAL(21, 320, 9), // "QSet<int>"
QT_MOC_LITERAL(22, 330, 11), // "theSections"
QT_MOC_LITERAL(23, 342, 14), // "OnRowsInserted"
QT_MOC_LITERAL(24, 357, 9), // "theParent"
QT_MOC_LITERAL(25, 367, 8), // "theFirst"
QT_MOC_LITERAL(26, 376, 7), // "theLast"
QT_MOC_LITERAL(27, 384, 13), // "OnRowsRemoved"
QT_MOC_LITERAL(28, 398, 17), // "OnColumnsInserted"
QT_MOC_LITERAL(29, 416, 16) // "OnColumnsRemoved"

    },
    "asiUI_DatumViewSelectionModel\0"
    "selectionChanged\0\0Qt::Orientation\0"
    "theHeader\0asiUI_HeaderIndexList\0"
    "theSelected\0theDeselected\0select\0"
    "asiUI_HeaderIndex\0theIndex\0"
    "QItemSelectionModel::SelectionFlags\0"
    "theCommand\0QList<asiUI_HeaderIndex>\0"
    "theIndexes\0QItemSelection\0theSelection\0"
    "clear\0reset\0OnSelectionChanged\0"
    "OnSelectionInSections\0QSet<int>\0"
    "theSections\0OnRowsInserted\0theParent\0"
    "theFirst\0theLast\0OnRowsRemoved\0"
    "OnColumnsInserted\0OnColumnsRemoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_asiUI_DatumViewSelectionModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    3,   86,    2, 0x0a /* Public */,
       8,    3,   93,    2, 0x0a /* Public */,
       8,    2,  100,    2, 0x0a /* Public */,
       8,    2,  105,    2, 0x0a /* Public */,
      17,    0,  110,    2, 0x0a /* Public */,
      18,    0,  111,    2, 0x0a /* Public */,
      19,    2,  112,    2, 0x09 /* Protected */,
      20,    2,  117,    2, 0x09 /* Protected */,
      23,    3,  122,    2, 0x09 /* Protected */,
      27,    3,  129,    2, 0x09 /* Protected */,
      28,    3,  136,    2, 0x09 /* Protected */,
      29,    3,  143,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 9, 0x80000000 | 11,    4,   10,   12,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 13, 0x80000000 | 11,    4,   14,   12,
    QMetaType::Void, QMetaType::QModelIndex, 0x80000000 | 11,   10,   12,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 11,   16,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 15,    6,    7,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 21,    4,   22,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,   24,   25,   26,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,   24,   25,   26,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,   24,   25,   26,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,   24,   25,   26,

       0        // eod
};

void asiUI_DatumViewSelectionModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        asiUI_DatumViewSelectionModel *_t = static_cast<asiUI_DatumViewSelectionModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectionChanged((*reinterpret_cast< const Qt::Orientation(*)>(_a[1])),(*reinterpret_cast< const asiUI_HeaderIndexList(*)>(_a[2])),(*reinterpret_cast< const asiUI_HeaderIndexList(*)>(_a[3]))); break;
        case 1: _t->select((*reinterpret_cast< const Qt::Orientation(*)>(_a[1])),(*reinterpret_cast< const asiUI_HeaderIndex(*)>(_a[2])),(*reinterpret_cast< QItemSelectionModel::SelectionFlags(*)>(_a[3]))); break;
        case 2: _t->select((*reinterpret_cast< const Qt::Orientation(*)>(_a[1])),(*reinterpret_cast< const QList<asiUI_HeaderIndex>(*)>(_a[2])),(*reinterpret_cast< QItemSelectionModel::SelectionFlags(*)>(_a[3]))); break;
        case 3: _t->select((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< QItemSelectionModel::SelectionFlags(*)>(_a[2]))); break;
        case 4: _t->select((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< QItemSelectionModel::SelectionFlags(*)>(_a[2]))); break;
        case 5: _t->clear(); break;
        case 6: _t->reset(); break;
        case 7: _t->OnSelectionChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 8: _t->OnSelectionInSections((*reinterpret_cast< const Qt::Orientation(*)>(_a[1])),(*reinterpret_cast< const QSet<int>(*)>(_a[2]))); break;
        case 9: _t->OnRowsInserted((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 10: _t->OnRowsRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 11: _t->OnColumnsInserted((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 12: _t->OnColumnsRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSet<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (asiUI_DatumViewSelectionModel::*_t)(const Qt::Orientation , const asiUI_HeaderIndexList & , const asiUI_HeaderIndexList & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&asiUI_DatumViewSelectionModel::selectionChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject asiUI_DatumViewSelectionModel::staticMetaObject = {
    { &QItemSelectionModel::staticMetaObject, qt_meta_stringdata_asiUI_DatumViewSelectionModel.data,
      qt_meta_data_asiUI_DatumViewSelectionModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *asiUI_DatumViewSelectionModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *asiUI_DatumViewSelectionModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_asiUI_DatumViewSelectionModel.stringdata0))
        return static_cast<void*>(const_cast< asiUI_DatumViewSelectionModel*>(this));
    if (!strcmp(_clname, "asiUI_HeaderViewSelectionApi"))
        return static_cast< asiUI_HeaderViewSelectionApi*>(const_cast< asiUI_DatumViewSelectionModel*>(this));
    return QItemSelectionModel::qt_metacast(_clname);
}

int asiUI_DatumViewSelectionModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QItemSelectionModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void asiUI_DatumViewSelectionModel::selectionChanged(const Qt::Orientation _t1, const asiUI_HeaderIndexList & _t2, const asiUI_HeaderIndexList & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
