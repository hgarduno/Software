/****************************************************************************
** ProductosConDesajuste meta object code from reading C++ file 'UIC_H_ProductosConDesajuste.h'
**
** Created: Fri Apr 12 21:26:08 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/UIC_H_ProductosConDesajuste.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *ProductosConDesajuste::className() const
{
    return "ProductosConDesajuste";
}

QMetaObject *ProductosConDesajuste::metaObj = 0;
static QMetaObjectCleanUp cleanUp_ProductosConDesajuste( "ProductosConDesajuste", &ProductosConDesajuste::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString ProductosConDesajuste::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ProductosConDesajuste", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString ProductosConDesajuste::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ProductosConDesajuste", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* ProductosConDesajuste::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "languageChange()", &slot_0, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"ProductosConDesajuste", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_ProductosConDesajuste.setMetaObject( metaObj );
    return metaObj;
}

void* ProductosConDesajuste::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "ProductosConDesajuste" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool ProductosConDesajuste::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool ProductosConDesajuste::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool ProductosConDesajuste::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool ProductosConDesajuste::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
