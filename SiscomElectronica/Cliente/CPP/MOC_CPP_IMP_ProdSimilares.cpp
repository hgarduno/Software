/****************************************************************************
** QProdSimilares meta object code from reading C++ file 'IMP_ProdSimilares.h'
**
** Created: Thu Apr 11 21:51:27 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ProdSimilares.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QProdSimilares::className() const
{
    return "QProdSimilares";
}

QMetaObject *QProdSimilares::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QProdSimilares( "QProdSimilares", &QProdSimilares::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QProdSimilares::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProdSimilares", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QProdSimilares::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProdSimilares", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QProdSimilares::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ProdSimilares::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_SeleccionoProducto", 4, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SeleccionoProducto(int,int,int,const QPoint&)", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QProdSimilares", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QProdSimilares.setMetaObject( metaObj );
    return metaObj;
}

void* QProdSimilares::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QProdSimilares" ) )
	return this;
    return ProdSimilares::qt_cast( clname );
}

bool QProdSimilares::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SeleccionoProducto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    default:
	return ProdSimilares::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QProdSimilares::qt_emit( int _id, QUObject* _o )
{
    return ProdSimilares::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QProdSimilares::qt_property( int id, int f, QVariant* v)
{
    return ProdSimilares::qt_property( id, f, v);
}

bool QProdSimilares::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
