/****************************************************************************
** QOrdenesAFacturar meta object code from reading C++ file 'IMP_OrdenesAFacturar.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_OrdenesAFacturar.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QOrdenesAFacturar::className() const
{
    return "QOrdenesAFacturar";
}

QMetaObject *QOrdenesAFacturar::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QOrdenesAFacturar( "QOrdenesAFacturar", &QOrdenesAFacturar::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QOrdenesAFacturar::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenesAFacturar", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QOrdenesAFacturar::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenesAFacturar", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QOrdenesAFacturar::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = OrdenesAFacturar::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAnexaOrden", 0, 0 };
    static const QUMethod slot_1 = {"SlotPasaFocoAnexarOrden", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "pintFila", &static_QUType_int, 0, QUParameter::In },
	{ "pintColumna", &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotProductosOrden", 4, param_slot_2 };
    static const QUMethod slot_3 = {"SlotAceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAnexaOrden()", &slot_0, QMetaData::Private },
	{ "SlotPasaFocoAnexarOrden()", &slot_1, QMetaData::Private },
	{ "SlotProductosOrden(int,int,int,const QPoint&)", &slot_2, QMetaData::Private },
	{ "SlotAceptar()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QOrdenesAFacturar", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QOrdenesAFacturar.setMetaObject( metaObj );
    return metaObj;
}

void* QOrdenesAFacturar::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QOrdenesAFacturar" ) )
	return this;
    return OrdenesAFacturar::qt_cast( clname );
}

bool QOrdenesAFacturar::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAnexaOrden(); break;
    case 1: SlotPasaFocoAnexarOrden(); break;
    case 2: SlotProductosOrden((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 3: SlotAceptar(); break;
    default:
	return OrdenesAFacturar::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QOrdenesAFacturar::qt_emit( int _id, QUObject* _o )
{
    return OrdenesAFacturar::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QOrdenesAFacturar::qt_property( int id, int f, QVariant* v)
{
    return OrdenesAFacturar::qt_property( id, f, v);
}

bool QOrdenesAFacturar::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
