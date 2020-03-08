/****************************************************************************
** Meta object code from reading C++ file 'menu.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "menu.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_menu_t {
    QByteArrayData data[12];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_menu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_menu_t qt_meta_stringdata_menu = {
    {
QT_MOC_LITERAL(0, 0, 4), // "menu"
QT_MOC_LITERAL(1, 5, 10), // "changeMode"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 4), // "mode"
QT_MOC_LITERAL(4, 22, 1), // "m"
QT_MOC_LITERAL(5, 24, 14), // "goToCliqueGame"
QT_MOC_LITERAL(6, 39, 20), // "goToCliqueTargetGame"
QT_MOC_LITERAL(7, 60, 13), // "goToDactyGame"
QT_MOC_LITERAL(8, 74, 14), // "changePbClique"
QT_MOC_LITERAL(9, 89, 5), // "newpb"
QT_MOC_LITERAL(10, 95, 14), // "changePbTarget"
QT_MOC_LITERAL(11, 110, 16) // "changPbDactyGame"

    },
    "menu\0changeMode\0\0mode\0m\0goToCliqueGame\0"
    "goToCliqueTargetGame\0goToDactyGame\0"
    "changePbClique\0newpb\0changePbTarget\0"
    "changPbDactyGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_menu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    1,   55,    2, 0x0a /* Public */,
      10,    1,   58,    2, 0x0a /* Public */,
      11,    1,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        menu *_t = static_cast<menu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeMode((*reinterpret_cast< mode(*)>(_a[1]))); break;
        case 1: _t->goToCliqueGame(); break;
        case 2: _t->goToCliqueTargetGame(); break;
        case 3: _t->goToDactyGame(); break;
        case 4: _t->changePbClique((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->changePbTarget((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->changPbDactyGame((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (menu::*_t)(mode );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&menu::changeMode)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject menu::staticMetaObject = {
    { &mainwindow::staticMetaObject, qt_meta_stringdata_menu.data,
      qt_meta_data_menu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *menu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_menu.stringdata0))
        return static_cast<void*>(this);
    return mainwindow::qt_metacast(_clname);
}

int menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = mainwindow::qt_metacall(_c, _id, _a);
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
void menu::changeMode(mode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
