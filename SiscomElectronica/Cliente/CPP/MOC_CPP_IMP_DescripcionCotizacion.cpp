/****************************************************************************
** QDescripcionCotizacion meta object code from reading C++ file 'IMP_DescripcionCotizacion.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_DescripcionCotizacion.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QDescripcionCotizacion::className() const
{
    return "QDescripcionCotizacion";
}

QMetaObject *QDescripcionCotizacion::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDescripcionCotizacion( "QDescripcionCotizacion", &QDescripcionCotizacion::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDescripcionCotizacion::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDescripcionCotizacion", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDescripcionCotizacion::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDescripcionCotizacion", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDescripcionCotizacion::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = DescripcionCotizacion::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_1 = {"Descripcion", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAceptar()", &slot_0, QMetaData::Private },
	{ "Descripcion()", &slot_1, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "zCotizacion", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalCotizacion", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalCotizacion(zCotizacion*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QDescripcionCotizacion", parentObject,
	slot_tbl, 2,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDescripcionCotizacion.setMetaObject( metaObj );
    return metaObj;
}

void* QDescripcionCotizacion::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDescripcionCotizacion" ) )
	return this;
    return DescripcionCotizacion::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalCotizacion
void QDescripcionCotizacion::SignalCotizacion( zCotizacion* t0 )
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

bool QDescripcionCotizacion::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAceptar(); break;
    case 1: Descripcion(); break;
    default:
	return DescripcionCotizacion::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QDescripcionCotizacion::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalCotizacion((zCotizacion*)static_QUType_ptr.get(_o+1)); break;
    default:
	return DescripcionCotizacion::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QDescripcionCotizacion::qt_property( int id, int f, QVariant* v)
{
    return DescripcionCotizacion::qt_property( id, f, v);
}

bool QDescripcionCotizacion::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
