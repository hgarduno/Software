/****************************************************************************
** QCotizaVdys meta object code from reading C++ file 'IMP_CotizaVdys.h'
**
** Created: Fri Apr 12 21:36:43 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CotizaVdys.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCotizaVdys::className() const
{
    return "QCotizaVdys";
}

QMetaObject *QCotizaVdys::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCotizaVdys( "QCotizaVdys", &QCotizaVdys::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCotizaVdys::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCotizaVdys", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCotizaVdys::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCotizaVdys", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCotizaVdys::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CotizaVdys::staticMetaObject();
    static const QUMethod slot_0 = {"SlotSCliente", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSCliente()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCotizaVdys", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCotizaVdys.setMetaObject( metaObj );
    return metaObj;
}

void* QCotizaVdys::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCotizaVdys" ) )
	return this;
    return CotizaVdys::qt_cast( clname );
}

bool QCotizaVdys::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSCliente(); break;
    default:
	return CotizaVdys::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCotizaVdys::qt_emit( int _id, QUObject* _o )
{
    return CotizaVdys::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCotizaVdys::qt_property( int id, int f, QVariant* v)
{
    return CotizaVdys::qt_property( id, f, v);
}

bool QCotizaVdys::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
