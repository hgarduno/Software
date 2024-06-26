/****************************************************************************
** QtImprimeBeneficiosIntegrales meta object code from reading C++ file 'QtImprimeBeneficiosIntegrales.h'
**
** Created: Thu Apr 11 21:08:21 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImprimeBeneficiosIntegrales.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImprimeBeneficiosIntegrales::className() const
{
    return "QtImprimeBeneficiosIntegrales";
}

QMetaObject *QtImprimeBeneficiosIntegrales::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImprimeBeneficiosIntegrales( "QtImprimeBeneficiosIntegrales", &QtImprimeBeneficiosIntegrales::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImprimeBeneficiosIntegrales::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimeBeneficiosIntegrales", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImprimeBeneficiosIntegrales::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimeBeneficiosIntegrales", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImprimeBeneficiosIntegrales::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "zContratoBeneficios", QUParameter::In }
    };
    static const QUMethod slot_0 = {"imprimir", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pzConBeneficios", &static_QUType_ptr, "zContratoBeneficios", QUParameter::In }
    };
    static const QUMethod slot_1 = {"ImprimeFrente", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "pzConBeneficios", &static_QUType_ptr, "zContratoBeneficios", QUParameter::In }
    };
    static const QUMethod slot_2 = {"ImprimeAtras", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "pchrPtrArchivo", &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "zContratoBeneficios", QUParameter::In }
    };
    static const QUMethod slot_3 = {"ImprimeAArchivo", 2, param_slot_3 };
    static const QMetaData slot_tbl[] = {
	{ "imprimir(zContratoBeneficios*)", &slot_0, QMetaData::Public },
	{ "ImprimeFrente(zContratoBeneficios*)", &slot_1, QMetaData::Public },
	{ "ImprimeAtras(zContratoBeneficios*)", &slot_2, QMetaData::Public },
	{ "ImprimeAArchivo(const char*,zContratoBeneficios*)", &slot_3, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImprimeBeneficiosIntegrales", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImprimeBeneficiosIntegrales.setMetaObject( metaObj );
    return metaObj;
}

void* QtImprimeBeneficiosIntegrales::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImprimeBeneficiosIntegrales" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool QtImprimeBeneficiosIntegrales::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: imprimir((zContratoBeneficios*)static_QUType_ptr.get(_o+1)); break;
    case 1: ImprimeFrente((zContratoBeneficios*)static_QUType_ptr.get(_o+1)); break;
    case 2: ImprimeAtras((zContratoBeneficios*)static_QUType_ptr.get(_o+1)); break;
    case 3: ImprimeAArchivo((const char*)static_QUType_charstar.get(_o+1),(zContratoBeneficios*)static_QUType_ptr.get(_o+2)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImprimeBeneficiosIntegrales::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImprimeBeneficiosIntegrales::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QtImprimeBeneficiosIntegrales::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
