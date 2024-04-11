/****************************************************************************
** QCtrlSaldosMovimientosMes meta object code from reading C++ file 'QCtrlSaldosMovimientosMes.h'
**
** Created: Thu Apr 11 21:09:15 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlSaldosMovimientosMes.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlSaldosMovimientosMes::className() const
{
    return "QCtrlSaldosMovimientosMes";
}

QMetaObject *QCtrlSaldosMovimientosMes::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlSaldosMovimientosMes( "QCtrlSaldosMovimientosMes", &QCtrlSaldosMovimientosMes::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlSaldosMovimientosMes::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlSaldosMovimientosMes", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlSaldosMovimientosMes::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlSaldosMovimientosMes", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlSaldosMovimientosMes::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QTable::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pintMes", &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotMes", 4, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotMes(int,int,int,const QPoint&)", &slot_0, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "pintMes", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalMes", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalMes(int)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlSaldosMovimientosMes", parentObject,
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlSaldosMovimientosMes.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlSaldosMovimientosMes::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlSaldosMovimientosMes" ) )
	return this;
    return QTable::qt_cast( clname );
}

// SIGNAL SignalMes
void QCtrlSaldosMovimientosMes::SignalMes( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

bool QCtrlSaldosMovimientosMes::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotMes((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    default:
	return QTable::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlSaldosMovimientosMes::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalMes((int)static_QUType_int.get(_o+1)); break;
    default:
	return QTable::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlSaldosMovimientosMes::qt_property( int id, int f, QVariant* v)
{
    return QTable::qt_property( id, f, v);
}

bool QCtrlSaldosMovimientosMes::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
