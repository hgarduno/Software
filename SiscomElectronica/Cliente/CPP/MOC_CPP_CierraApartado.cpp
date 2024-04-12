/****************************************************************************
** CierraApartado meta object code from reading C++ file 'UIC_H_CierraApartado.h'
**
** Created: Thu Apr 11 21:40:00 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/UIC_H_CierraApartado.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CierraApartado::className() const
{
    return "CierraApartado";
}

QMetaObject *CierraApartado::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CierraApartado( "CierraApartado", &CierraApartado::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CierraApartado::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CierraApartado", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CierraApartado::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CierraApartado", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CierraApartado::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "languageChange()", &slot_0, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"CierraApartado", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CierraApartado.setMetaObject( metaObj );
    return metaObj;
}

void* CierraApartado::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CierraApartado" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool CierraApartado::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CierraApartado::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool CierraApartado::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool CierraApartado::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
