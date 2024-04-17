/****************************************************************************
** QClientesRegistrados4 meta object code from reading C++ file 'IMP_ClientesRegistrados4.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ClientesRegistrados4.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QClientesRegistrados4::className() const
{
    return "QClientesRegistrados4";
}

QMetaObject *QClientesRegistrados4::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QClientesRegistrados4( "QClientesRegistrados4", &QClientesRegistrados4::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QClientesRegistrados4::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QClientesRegistrados4", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QClientesRegistrados4::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QClientesRegistrados4", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QClientesRegistrados4::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ClientesRegistrados4::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAceptar", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotCliente", 4, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotSeleccionoCliente", 4, param_slot_2 };
    static const QUMethod slot_3 = {"SlotCancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAceptar()", &slot_0, QMetaData::Private },
	{ "SlotCliente(int,int,int,const QPoint&)", &slot_1, QMetaData::Private },
	{ "SlotSeleccionoCliente(int,int,int,const QPoint&)", &slot_2, QMetaData::Private },
	{ "SlotCancelar()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QClientesRegistrados4", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QClientesRegistrados4.setMetaObject( metaObj );
    return metaObj;
}

void* QClientesRegistrados4::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QClientesRegistrados4" ) )
	return this;
    return ClientesRegistrados4::qt_cast( clname );
}

bool QClientesRegistrados4::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAceptar(); break;
    case 1: SlotCliente((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 2: SlotSeleccionoCliente((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 3: SlotCancelar(); break;
    default:
	return ClientesRegistrados4::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QClientesRegistrados4::qt_emit( int _id, QUObject* _o )
{
    return ClientesRegistrados4::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QClientesRegistrados4::qt_property( int id, int f, QVariant* v)
{
    return ClientesRegistrados4::qt_property( id, f, v);
}

bool QClientesRegistrados4::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
