/****************************************************************************
** QTransferenciasExpendioExpendio meta object code from reading C++ file 'IMP_TransferenciasExpendioExpendio.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_TransferenciasExpendioExpendio.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QTransferenciasExpendioExpendio::className() const
{
    return "QTransferenciasExpendioExpendio";
}

QMetaObject *QTransferenciasExpendioExpendio::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QTransferenciasExpendioExpendio( "QTransferenciasExpendioExpendio", &QTransferenciasExpendioExpendio::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QTransferenciasExpendioExpendio::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTransferenciasExpendioExpendio", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QTransferenciasExpendioExpendio::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTransferenciasExpendioExpendio", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QTransferenciasExpendioExpendio::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = TransferenciasExpendioExpendio::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QTransferenciasExpendioExpendio", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QTransferenciasExpendioExpendio.setMetaObject( metaObj );
    return metaObj;
}

void* QTransferenciasExpendioExpendio::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QTransferenciasExpendioExpendio" ) )
	return this;
    return TransferenciasExpendioExpendio::qt_cast( clname );
}

bool QTransferenciasExpendioExpendio::qt_invoke( int _id, QUObject* _o )
{
    return TransferenciasExpendioExpendio::qt_invoke(_id,_o);
}

bool QTransferenciasExpendioExpendio::qt_emit( int _id, QUObject* _o )
{
    return TransferenciasExpendioExpendio::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QTransferenciasExpendioExpendio::qt_property( int id, int f, QVariant* v)
{
    return TransferenciasExpendioExpendio::qt_property( id, f, v);
}

bool QTransferenciasExpendioExpendio::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
