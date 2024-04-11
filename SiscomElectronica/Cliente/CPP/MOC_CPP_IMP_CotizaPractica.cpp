/****************************************************************************
** QCotizaPractica meta object code from reading C++ file 'IMP_CotizaPractica.h'
**
** Created: Wed Apr 10 21:11:08 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CotizaPractica.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCotizaPractica::className() const
{
    return "QCotizaPractica";
}

QMetaObject *QCotizaPractica::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCotizaPractica( "QCotizaPractica", &QCotizaPractica::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCotizaPractica::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCotizaPractica", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCotizaPractica::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCotizaPractica", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCotizaPractica::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CotizaPractica::staticMetaObject();
    static const QUMethod slot_0 = {"S_SeleccionoEscuela", 0, 0 };
    static const QUMethod slot_1 = {"S_SeleccionoMateria", 0, 0 };
    static const QUMethod slot_2 = {"S_SeleccionoPractica", 0, 0 };
    static const QUMethod slot_3 = {"S_AnexarALaOrden", 0, 0 };
    static const QUMethod slot_4 = {"S_VendeLoQueHay", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SeleccionoEscuela()", &slot_0, QMetaData::Private },
	{ "S_SeleccionoMateria()", &slot_1, QMetaData::Private },
	{ "S_SeleccionoPractica()", &slot_2, QMetaData::Private },
	{ "S_AnexarALaOrden()", &slot_3, QMetaData::Private },
	{ "S_VendeLoQueHay()", &slot_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCotizaPractica", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCotizaPractica.setMetaObject( metaObj );
    return metaObj;
}

void* QCotizaPractica::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCotizaPractica" ) )
	return this;
    return CotizaPractica::qt_cast( clname );
}

bool QCotizaPractica::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SeleccionoEscuela(); break;
    case 1: S_SeleccionoMateria(); break;
    case 2: S_SeleccionoPractica(); break;
    case 3: S_AnexarALaOrden(); break;
    case 4: S_VendeLoQueHay(); break;
    default:
	return CotizaPractica::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCotizaPractica::qt_emit( int _id, QUObject* _o )
{
    return CotizaPractica::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCotizaPractica::qt_property( int id, int f, QVariant* v)
{
    return CotizaPractica::qt_property( id, f, v);
}

bool QCotizaPractica::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
