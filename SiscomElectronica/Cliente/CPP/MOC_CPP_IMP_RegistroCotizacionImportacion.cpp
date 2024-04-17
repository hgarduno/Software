/****************************************************************************
** QRegistroCotizacionImportacion meta object code from reading C++ file 'IMP_RegistroCotizacionImportacion.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistroCotizacionImportacion.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistroCotizacionImportacion::className() const
{
    return "QRegistroCotizacionImportacion";
}

QMetaObject *QRegistroCotizacionImportacion::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistroCotizacionImportacion( "QRegistroCotizacionImportacion", &QRegistroCotizacionImportacion::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistroCotizacionImportacion::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroCotizacionImportacion", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistroCotizacionImportacion::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroCotizacionImportacion", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistroCotizacionImportacion::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistroCotizacionImportacion::staticMetaObject();
    static const QUMethod slot_0 = {"SlotCapturandoCotizacion", 0, 0 };
    static const QUMethod slot_1 = {"SlotRegistrar", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotSeleccionaCotizacion", 4, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "SlotCapturandoCotizacion()", &slot_0, QMetaData::Private },
	{ "SlotRegistrar()", &slot_1, QMetaData::Private },
	{ "SlotSeleccionaCotizacion(int,int,int,const QPoint&)", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistroCotizacionImportacion", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistroCotizacionImportacion.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistroCotizacionImportacion::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistroCotizacionImportacion" ) )
	return this;
    return RegistroCotizacionImportacion::qt_cast( clname );
}

bool QRegistroCotizacionImportacion::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotCapturandoCotizacion(); break;
    case 1: SlotRegistrar(); break;
    case 2: SlotSeleccionaCotizacion((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    default:
	return RegistroCotizacionImportacion::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistroCotizacionImportacion::qt_emit( int _id, QUObject* _o )
{
    return RegistroCotizacionImportacion::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRegistroCotizacionImportacion::qt_property( int id, int f, QVariant* v)
{
    return RegistroCotizacionImportacion::qt_property( id, f, v);
}

bool QRegistroCotizacionImportacion::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
