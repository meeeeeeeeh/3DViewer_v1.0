/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../3d_viewer/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[34];
    char stringdata0[270];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 17), // "on_X_valueChanged"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 4), // "arg1"
QT_MOC_LITERAL(35, 17), // "on_Y_valueChanged"
QT_MOC_LITERAL(53, 17), // "on_Z_valueChanged"
QT_MOC_LITERAL(71, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(91, 7), // "checked"
QT_MOC_LITERAL(99, 20), // "on_file_path_clicked"
QT_MOC_LITERAL(120, 15), // "on_move_clicked"
QT_MOC_LITERAL(136, 19), // "on_R_X_valueChanged"
QT_MOC_LITERAL(156, 19), // "on_R_Y_valueChanged"
QT_MOC_LITERAL(176, 18), // "on_R_Z_textChanged"
QT_MOC_LITERAL(195, 17), // "on_rotate_clicked"
QT_MOC_LITERAL(213, 17), // "on_resize_clicked"
QT_MOC_LITERAL(231, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(264, 5) // "value"

    },
    "MainWindow\0on_X_valueChanged\0\0arg1\0"
    "on_Y_valueChanged\0on_Z_valueChanged\0"
    "on_checkBox_clicked\0checked\0"
    "on_file_path_clicked\0on_move_clicked\0"
    "on_R_X_valueChanged\0on_R_Y_valueChanged\0"
    "on_R_Z_textChanged\0on_rotate_clicked\0"
    "on_resize_clicked\0on_horizontalSlider_valueChanged\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x08,    1 /* Private */,
       4,    1,   89,    2, 0x08,    3 /* Private */,
       5,    1,   92,    2, 0x08,    5 /* Private */,
       6,    1,   95,    2, 0x08,    7 /* Private */,
       8,    0,   98,    2, 0x08,    9 /* Private */,
       9,    0,   99,    2, 0x08,   10 /* Private */,
      10,    1,  100,    2, 0x08,   11 /* Private */,
      11,    1,  103,    2, 0x08,   13 /* Private */,
      12,    1,  106,    2, 0x08,   15 /* Private */,
      13,    0,  109,    2, 0x08,   17 /* Private */,
      14,    0,  110,    2, 0x08,   18 /* Private */,
      15,    1,  111,    2, 0x08,   19 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_X_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->on_Y_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->on_Z_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_file_path_clicked(); break;
        case 5: _t->on_move_clicked(); break;
        case 6: _t->on_R_X_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->on_R_Y_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->on_R_Z_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_rotate_clicked(); break;
        case 10: _t->on_resize_clicked(); break;
        case 11: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
