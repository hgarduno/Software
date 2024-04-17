/****************************************************************************
** QMaterialPractica meta object code from reading C++ file 'IMP_MaterialPractica.h'
**
** Created: Fri Apr 12 21:35:17 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_MaterialPractica.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QMaterialPractica::className() const
{
    return "QMaterialPractica";
}

QMetaObject *QMaterialPractica::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QMaterialPractica( "QMaterialPractica", &QMaterialPractica::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QMaterialPractica::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMaterialPractica", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QMaterialPractica::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMaterialPractica", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QMaterialPractica::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = MaterialPractica::staticMetaObject();
    static const QUMethod slot_0 = {"S_Anexar", 0, 0 };
    static const QUMethod slot_1 = {"S_MaterialPractica", 0, 0 };
    static const QUMethod slot_2 = {"S_EliminarProductos", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_Anexar()", &slot_0, QMetaData::Private },
	{ "S_MaterialPractica()", &slot_1, QMetaData::Private },
	{ "S_EliminarProductos()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QMaterialPractica", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QMaterialPractica.setMetaObject( metaObj );
    return metaObj;
}

void* QMaterialPractica::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QMaterialPractica" ) )
	return this;
    return MaterialPractica::qt_cast( clname );
}

bool QMaterialPractica::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_Anexar(); break;
    case 1: S_MaterialPractica(); break;
    case 2: S_EliminarProductos(); break;
    default:
	return MaterialPractica::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QMaterialPractica::qt_emit( int _id, QUObject* _o )
{
    return MaterialPractica::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QMaterialPractica::qt_property( int id, int f, QVariant* v)
{
    return MaterialPractica::qt_property( id, f, v);
}

bool QMaterialPractica::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
