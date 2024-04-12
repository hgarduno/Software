/****************************************************************************
** CQSisActualizaPantalla meta object code from reading C++ file 'IMP_ActualizaPantalla.h'
**
** Created: Thu Apr 11 21:36:26 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ActualizaPantalla.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CQSisActualizaPantalla::className() const
{
    return "CQSisActualizaPantalla";
}

QMetaObject *CQSisActualizaPantalla::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CQSisActualizaPantalla( "CQSisActualizaPantalla", &CQSisActualizaPantalla::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CQSisActualizaPantalla::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisActualizaPantalla", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CQSisActualizaPantalla::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisActualizaPantalla", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CQSisActualizaPantalla::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ActualizaPantalla::staticMetaObject();
    static const QUMethod slot_0 = {"S_SeleccionaArchivo", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SeleccionaArchivo()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"CQSisActualizaPantalla", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CQSisActualizaPantalla.setMetaObject( metaObj );
    return metaObj;
}

void* CQSisActualizaPantalla::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CQSisActualizaPantalla" ) )
	return this;
    return ActualizaPantalla::qt_cast( clname );
}

bool CQSisActualizaPantalla::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SeleccionaArchivo(); break;
    default:
	return ActualizaPantalla::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CQSisActualizaPantalla::qt_emit( int _id, QUObject* _o )
{
    return ActualizaPantalla::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool CQSisActualizaPantalla::qt_property( int id, int f, QVariant* v)
{
    return ActualizaPantalla::qt_property( id, f, v);
}

bool CQSisActualizaPantalla::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
