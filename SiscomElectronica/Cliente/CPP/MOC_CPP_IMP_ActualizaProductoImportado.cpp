/****************************************************************************
** QActualizaProductoImportado meta object code from reading C++ file 'IMP_ActualizaProductoImportado.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ActualizaProductoImportado.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QActualizaProductoImportado::className() const
{
    return "QActualizaProductoImportado";
}

QMetaObject *QActualizaProductoImportado::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QActualizaProductoImportado( "QActualizaProductoImportado", &QActualizaProductoImportado::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QActualizaProductoImportado::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QActualizaProductoImportado", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QActualizaProductoImportado::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QActualizaProductoImportado", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QActualizaProductoImportado::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ActualizaProductoImportado::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_1 = {"SlotFocoACostoUnitario", 0, 0 };
    static const QUMethod slot_2 = {"SlotFocoAPeso", 0, 0 };
    static const QUMethod slot_3 = {"SlotFocoAAceptar", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotCambiandoPeso", 1, param_slot_4 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAceptar()", &slot_0, QMetaData::Private },
	{ "SlotFocoACostoUnitario()", &slot_1, QMetaData::Private },
	{ "SlotFocoAPeso()", &slot_2, QMetaData::Private },
	{ "SlotFocoAAceptar()", &slot_3, QMetaData::Private },
	{ "SlotCambiandoPeso(const QString&)", &slot_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QActualizaProductoImportado", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QActualizaProductoImportado.setMetaObject( metaObj );
    return metaObj;
}

void* QActualizaProductoImportado::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QActualizaProductoImportado" ) )
	return this;
    return ActualizaProductoImportado::qt_cast( clname );
}

bool QActualizaProductoImportado::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAceptar(); break;
    case 1: SlotFocoACostoUnitario(); break;
    case 2: SlotFocoAPeso(); break;
    case 3: SlotFocoAAceptar(); break;
    case 4: SlotCambiandoPeso((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return ActualizaProductoImportado::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QActualizaProductoImportado::qt_emit( int _id, QUObject* _o )
{
    return ActualizaProductoImportado::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QActualizaProductoImportado::qt_property( int id, int f, QVariant* v)
{
    return ActualizaProductoImportado::qt_property( id, f, v);
}

bool QActualizaProductoImportado::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
