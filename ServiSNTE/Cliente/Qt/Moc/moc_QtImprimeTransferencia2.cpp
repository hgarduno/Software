/****************************************************************************
** QtImprimeTransferencia2 meta object code from reading C++ file 'QtImprimeTransferencia2.h'
**
** Created: Thu Apr 11 21:08:29 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImprimeTransferencia2.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImprimeTransferencia2::className() const
{
    return "QtImprimeTransferencia2";
}

QMetaObject *QtImprimeTransferencia2::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImprimeTransferencia2( "QtImprimeTransferencia2", &QtImprimeTransferencia2::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImprimeTransferencia2::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimeTransferencia2", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImprimeTransferencia2::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimeTransferencia2", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImprimeTransferencia2::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QtImprimeTransferencia2", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImprimeTransferencia2.setMetaObject( metaObj );
    return metaObj;
}

void* QtImprimeTransferencia2::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImprimeTransferencia2" ) )
	return this;
    if ( !qstrcmp( clname, "QtBaseMedidas" ) )
	return (QtBaseMedidas*)this;
    return QWidget::qt_cast( clname );
}

bool QtImprimeTransferencia2::qt_invoke( int _id, QUObject* _o )
{
    return QWidget::qt_invoke(_id,_o);
}

bool QtImprimeTransferencia2::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImprimeTransferencia2::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QtImprimeTransferencia2::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
