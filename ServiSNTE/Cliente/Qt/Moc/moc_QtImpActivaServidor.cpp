/****************************************************************************
** QtImpActivaServidor meta object code from reading C++ file 'QtImpActivaServidor.h'
**
** Created: Tue Jun 24 08:59:49 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpActivaServidor.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpActivaServidor::className() const
{
    return "QtImpActivaServidor";
}

QMetaObject *QtImpActivaServidor::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpActivaServidor( "QtImpActivaServidor", &QtImpActivaServidor::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpActivaServidor::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpActivaServidor", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpActivaServidor::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpActivaServidor", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpActivaServidor::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ActivaServidor::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSisRegTienda", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotTienda", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pintMaquina", &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSeleccionaMaquina", 4, param_slot_1 };
    static const QUMethod slot_2 = {"SlotCambiarConexionA", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotTienda(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotSeleccionaMaquina(int,int,int,const QPoint&)", &slot_1, QMetaData::Private },
	{ "SlotCambiarConexionA()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpActivaServidor", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpActivaServidor.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpActivaServidor::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpActivaServidor" ) )
	return this;
    return ActivaServidor::qt_cast( clname );
}

bool QtImpActivaServidor::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotTienda((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotSeleccionaMaquina((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 2: SlotCambiarConexionA(); break;
    default:
	return ActivaServidor::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpActivaServidor::qt_emit( int _id, QUObject* _o )
{
    return ActivaServidor::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpActivaServidor::qt_property( int id, int f, QVariant* v)
{
    return ActivaServidor::qt_property( id, f, v);
}

bool QtImpActivaServidor::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
