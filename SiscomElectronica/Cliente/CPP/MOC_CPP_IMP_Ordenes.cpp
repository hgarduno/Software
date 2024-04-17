/****************************************************************************
** QOrdenes meta object code from reading C++ file 'IMP_Ordenes.h'
**
** Created: Fri Apr 12 21:26:08 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Ordenes.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QOrdenes::className() const
{
    return "QOrdenes";
}

QMetaObject *QOrdenes::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QOrdenes( "QOrdenes", &QOrdenes::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QOrdenes::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenes", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QOrdenes::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenes", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QOrdenes::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Ordenes::staticMetaObject();
    static const QUMethod slot_0 = {"SlotRangoFechas", 0, 0 };
    static const QUMethod slot_1 = {"SlotAnexarContabilidad", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotSeleccionaOrden", 4, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotSeleccionaOrden", 2, param_slot_3 };
    static const QMetaData slot_tbl[] = {
	{ "SlotRangoFechas()", &slot_0, QMetaData::Private },
	{ "SlotAnexarContabilidad()", &slot_1, QMetaData::Private },
	{ "SlotSeleccionaOrden(int,int,int,const QPoint&)", &slot_2, QMetaData::Private },
	{ "SlotSeleccionaOrden(int,int)", &slot_3, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QOrdenes", parentObject,
	slot_tbl, 4,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QOrdenes.setMetaObject( metaObj );
    return metaObj;
}

void* QOrdenes::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QOrdenes" ) )
	return this;
    return Ordenes::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QOrdenes::SignalTerminar( QWidget* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool QOrdenes::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotRangoFechas(); break;
    case 1: SlotAnexarContabilidad(); break;
    case 2: SlotSeleccionaOrden((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 3: SlotSeleccionaOrden((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return Ordenes::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QOrdenes::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return Ordenes::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QOrdenes::qt_property( int id, int f, QVariant* v)
{
    return Ordenes::qt_property( id, f, v);
}

bool QOrdenes::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
