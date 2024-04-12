/****************************************************************************
** QResultadosBusqueda meta object code from reading C++ file 'IMP_ResultadosBusqueda.h'
**
** Created: Thu Apr 11 22:09:38 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ResultadosBusqueda.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QResultadosBusqueda::className() const
{
    return "QResultadosBusqueda";
}

QMetaObject *QResultadosBusqueda::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QResultadosBusqueda( "QResultadosBusqueda", &QResultadosBusqueda::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QResultadosBusqueda::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QResultadosBusqueda", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QResultadosBusqueda::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QResultadosBusqueda", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QResultadosBusqueda::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ResultadosBusqueda::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSelecciono", 4, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSelecciono(int,int,int,const QPoint&)", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QResultadosBusqueda", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QResultadosBusqueda.setMetaObject( metaObj );
    return metaObj;
}

void* QResultadosBusqueda::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QResultadosBusqueda" ) )
	return this;
    return ResultadosBusqueda::qt_cast( clname );
}

bool QResultadosBusqueda::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSelecciono((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    default:
	return ResultadosBusqueda::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QResultadosBusqueda::qt_emit( int _id, QUObject* _o )
{
    return ResultadosBusqueda::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QResultadosBusqueda::qt_property( int id, int f, QVariant* v)
{
    return ResultadosBusqueda::qt_property( id, f, v);
}

bool QResultadosBusqueda::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
