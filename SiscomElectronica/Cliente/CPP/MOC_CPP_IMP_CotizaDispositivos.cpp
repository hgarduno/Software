/****************************************************************************
** QCotizaDispositivos meta object code from reading C++ file 'IMP_CotizaDispositivos.h'
**
** Created: Thu Apr 11 21:52:08 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CotizaDispositivos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCotizaDispositivos::className() const
{
    return "QCotizaDispositivos";
}

QMetaObject *QCotizaDispositivos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCotizaDispositivos( "QCotizaDispositivos", &QCotizaDispositivos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCotizaDispositivos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCotizaDispositivos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCotizaDispositivos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCotizaDispositivos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCotizaDispositivos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CotizaDispositivos::staticMetaObject();
    static const QUMethod slot_0 = {"S_PasaFocoDispositivo", 0, 0 };
    static const QUMethod slot_1 = {"S_PasaFocoAnexarOrden", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"S_MuestraDescripcion", 1, param_slot_2 };
    static const QUMethod slot_3 = {"S_AnexarALaOrden", 0, 0 };
    static const QUMethod slot_4 = {"S_ProductosPorDescripcion", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_PasaFocoDispositivo()", &slot_0, QMetaData::Private },
	{ "S_PasaFocoAnexarOrden()", &slot_1, QMetaData::Private },
	{ "S_MuestraDescripcion(int)", &slot_2, QMetaData::Private },
	{ "S_AnexarALaOrden()", &slot_3, QMetaData::Private },
	{ "S_ProductosPorDescripcion()", &slot_4, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "ProductoE", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalAnexarALaOrden", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalAnexarALaOrden(ProductoE*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCotizaDispositivos", parentObject,
	slot_tbl, 5,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCotizaDispositivos.setMetaObject( metaObj );
    return metaObj;
}

void* QCotizaDispositivos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCotizaDispositivos" ) )
	return this;
    if ( !qstrcmp( clname, "Seguridad3Protocolo2" ) )
	return (Seguridad3Protocolo2*)this;
    return CotizaDispositivos::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalAnexarALaOrden
void QCotizaDispositivos::SignalAnexarALaOrden( ProductoE* t0 )
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

bool QCotizaDispositivos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_PasaFocoDispositivo(); break;
    case 1: S_PasaFocoAnexarOrden(); break;
    case 2: S_MuestraDescripcion((int)static_QUType_int.get(_o+1)); break;
    case 3: S_AnexarALaOrden(); break;
    case 4: S_ProductosPorDescripcion(); break;
    default:
	return CotizaDispositivos::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCotizaDispositivos::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalAnexarALaOrden((ProductoE*)static_QUType_ptr.get(_o+1)); break;
    default:
	return CotizaDispositivos::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCotizaDispositivos::qt_property( int id, int f, QVariant* v)
{
    return CotizaDispositivos::qt_property( id, f, v);
}

bool QCotizaDispositivos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
