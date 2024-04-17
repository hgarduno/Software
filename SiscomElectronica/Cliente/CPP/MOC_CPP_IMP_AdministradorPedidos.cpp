/****************************************************************************
** QAdministradorPedidos meta object code from reading C++ file 'IMP_AdministradorPedidos.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_AdministradorPedidos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QAdministradorPedidos::className() const
{
    return "QAdministradorPedidos";
}

QMetaObject *QAdministradorPedidos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QAdministradorPedidos( "QAdministradorPedidos", &QAdministradorPedidos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QAdministradorPedidos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAdministradorPedidos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QAdministradorPedidos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAdministradorPedidos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QAdministradorPedidos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtAdministradorPedidos::staticMetaObject();
    static const QUMethod slot_0 = {"SlotConsultar", 0, 0 };
    static const QUMethod slot_1 = {"SlotActualizaEstado", 0, 0 };
    static const QUMethod slot_2 = {"SlotImprimir", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotConsultar()", &slot_0, QMetaData::Private },
	{ "SlotActualizaEstado()", &slot_1, QMetaData::Private },
	{ "SlotImprimir()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QAdministradorPedidos", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QAdministradorPedidos.setMetaObject( metaObj );
    return metaObj;
}

void* QAdministradorPedidos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QAdministradorPedidos" ) )
	return this;
    return QtAdministradorPedidos::qt_cast( clname );
}

bool QAdministradorPedidos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotConsultar(); break;
    case 1: SlotActualizaEstado(); break;
    case 2: SlotImprimir(); break;
    default:
	return QtAdministradorPedidos::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QAdministradorPedidos::qt_emit( int _id, QUObject* _o )
{
    return QtAdministradorPedidos::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QAdministradorPedidos::qt_property( int id, int f, QVariant* v)
{
    return QtAdministradorPedidos::qt_property( id, f, v);
}

bool QAdministradorPedidos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
