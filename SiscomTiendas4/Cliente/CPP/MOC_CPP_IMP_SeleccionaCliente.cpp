/****************************************************************************
** QSeleccionaCliente meta object code from reading C++ file 'IMP_SeleccionaCliente.h'
**
** Created: Thu Apr 11 20:30:21 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_SeleccionaCliente.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QSeleccionaCliente::className() const
{
    return "QSeleccionaCliente";
}

QMetaObject *QSeleccionaCliente::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSeleccionaCliente( "QSeleccionaCliente", &QSeleccionaCliente::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSeleccionaCliente::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSeleccionaCliente", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSeleccionaCliente::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSeleccionaCliente", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSeleccionaCliente::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SeleccionaCliente::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotMoral", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotFisica", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "SlotMoral(SiscomRegistro3*)", &slot_0, QMetaData::Private },
	{ "SlotFisica(SiscomRegistro3*)", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSeleccionaCliente", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSeleccionaCliente.setMetaObject( metaObj );
    return metaObj;
}

void* QSeleccionaCliente::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSeleccionaCliente" ) )
	return this;
    return SeleccionaCliente::qt_cast( clname );
}

bool QSeleccionaCliente::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotMoral((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotFisica((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    default:
	return SeleccionaCliente::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSeleccionaCliente::qt_emit( int _id, QUObject* _o )
{
    return SeleccionaCliente::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSeleccionaCliente::qt_property( int id, int f, QVariant* v)
{
    return SeleccionaCliente::qt_property( id, f, v);
}

bool QSeleccionaCliente::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
