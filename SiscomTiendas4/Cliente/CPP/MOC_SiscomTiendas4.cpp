/****************************************************************************
** SiscomTiendas4 meta object code from reading C++ file 'SiscomTiendas4.h'
**
** Created: Thu Apr 11 20:32:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/SiscomTiendas4.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *SiscomTiendas4::className() const
{
    return "SiscomTiendas4";
}

QMetaObject *SiscomTiendas4::metaObj = 0;
static QMetaObjectCleanUp cleanUp_SiscomTiendas4( "SiscomTiendas4", &SiscomTiendas4::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString SiscomTiendas4::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SiscomTiendas4", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString SiscomTiendas4::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SiscomTiendas4", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* SiscomTiendas4::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SISCOMVentanaPrincipal::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"SiscomTiendas4", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_SiscomTiendas4.setMetaObject( metaObj );
    return metaObj;
}

void* SiscomTiendas4::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "SiscomTiendas4" ) )
	return this;
    return SISCOMVentanaPrincipal::qt_cast( clname );
}

bool SiscomTiendas4::qt_invoke( int _id, QUObject* _o )
{
    return SISCOMVentanaPrincipal::qt_invoke(_id,_o);
}

bool SiscomTiendas4::qt_emit( int _id, QUObject* _o )
{
    return SISCOMVentanaPrincipal::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool SiscomTiendas4::qt_property( int id, int f, QVariant* v)
{
    return SISCOMVentanaPrincipal::qt_property( id, f, v);
}

bool SiscomTiendas4::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
