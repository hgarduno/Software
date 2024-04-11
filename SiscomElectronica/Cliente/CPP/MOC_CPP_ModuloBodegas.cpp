/****************************************************************************
** ModuloBodegas meta object code from reading C++ file 'UIC_H_ModuloBodegas.h'
**
** Created: Wed Apr 10 20:52:39 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/UIC_H_ModuloBodegas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *ModuloBodegas::className() const
{
    return "ModuloBodegas";
}

QMetaObject *ModuloBodegas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_ModuloBodegas( "ModuloBodegas", &ModuloBodegas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString ModuloBodegas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ModuloBodegas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString ModuloBodegas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ModuloBodegas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* ModuloBodegas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "languageChange()", &slot_0, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"ModuloBodegas", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_ModuloBodegas.setMetaObject( metaObj );
    return metaObj;
}

void* ModuloBodegas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "ModuloBodegas" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool ModuloBodegas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: languageChange(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool ModuloBodegas::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool ModuloBodegas::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool ModuloBodegas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
