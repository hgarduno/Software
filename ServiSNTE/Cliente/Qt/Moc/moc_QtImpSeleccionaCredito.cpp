/****************************************************************************
** QtImpSeleccionaCredito meta object code from reading C++ file 'QtImpSeleccionaCredito.h'
**
** Created: Sat Jan 27 16:39:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpSeleccionaCredito.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpSeleccionaCredito::className() const
{
    return "QtImpSeleccionaCredito";
}

QMetaObject *QtImpSeleccionaCredito::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpSeleccionaCredito( "QtImpSeleccionaCredito", &QtImpSeleccionaCredito::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpSeleccionaCredito::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpSeleccionaCredito", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpSeleccionaCredito::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpSeleccionaCredito", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpSeleccionaCredito::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SeleccionaCredito::staticMetaObject();
    static const QUMethod slot_0 = {"SlotRFC", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSeleccionaApartado", 4, param_slot_1 };
    static const QUMethod slot_2 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_3 = {"SlotCancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotRFC()", &slot_0, QMetaData::Private },
	{ "SlotSeleccionaApartado(int,int,int,const QPoint&)", &slot_1, QMetaData::Private },
	{ "SlotAceptar()", &slot_2, QMetaData::Private },
	{ "SlotCancelar()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpSeleccionaCredito", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpSeleccionaCredito.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpSeleccionaCredito::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpSeleccionaCredito" ) )
	return this;
    return SeleccionaCredito::qt_cast( clname );
}

bool QtImpSeleccionaCredito::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotRFC(); break;
    case 1: SlotSeleccionaApartado((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 2: SlotAceptar(); break;
    case 3: SlotCancelar(); break;
    default:
	return SeleccionaCredito::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpSeleccionaCredito::qt_emit( int _id, QUObject* _o )
{
    return SeleccionaCredito::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpSeleccionaCredito::qt_property( int id, int f, QVariant* v)
{
    return SeleccionaCredito::qt_property( id, f, v);
}

bool QtImpSeleccionaCredito::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
