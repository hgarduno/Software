/****************************************************************************
** SiscomTiendas41 meta object code from reading C++ file 'SiscomTiendas41.h'
**
** Created: Thu Apr 11 22:09:38 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/SiscomTiendas41.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *SiscomTiendas41::className() const
{
    return "SiscomTiendas41";
}

QMetaObject *SiscomTiendas41::metaObj = 0;
static QMetaObjectCleanUp cleanUp_SiscomTiendas41( "SiscomTiendas41", &SiscomTiendas41::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString SiscomTiendas41::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SiscomTiendas41", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString SiscomTiendas41::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SiscomTiendas41", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* SiscomTiendas41::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SiscomVentanaPrincipal::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"SiscomTiendas41", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_SiscomTiendas41.setMetaObject( metaObj );
    return metaObj;
}

void* SiscomTiendas41::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "SiscomTiendas41" ) )
	return this;
    return SiscomVentanaPrincipal::qt_cast( clname );
}

bool SiscomTiendas41::qt_invoke( int _id, QUObject* _o )
{
    return SiscomVentanaPrincipal::qt_invoke(_id,_o);
}

bool SiscomTiendas41::qt_emit( int _id, QUObject* _o )
{
    return SiscomVentanaPrincipal::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool SiscomTiendas41::qt_property( int id, int f, QVariant* v)
{
    return SiscomVentanaPrincipal::qt_property( id, f, v);
}

bool SiscomTiendas41::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
