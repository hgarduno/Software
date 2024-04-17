/****************************************************************************
** QCNSClientes meta object code from reading C++ file 'IMP_CNSClientes.h'
**
** Created: Fri Apr 12 21:34:52 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CNSClientes.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCNSClientes::className() const
{
    return "QCNSClientes";
}

QMetaObject *QCNSClientes::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCNSClientes( "QCNSClientes", &QCNSClientes::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCNSClientes::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCNSClientes", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCNSClientes::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCNSClientes", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCNSClientes::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CNSClientes::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_Cliente", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"S_SelCliente", 1, param_slot_1 };
    static const QUMethod slot_2 = {"S_SelCliente", 0, 0 };
    static const QUMethod slot_3 = {"S_Aceptar", 0, 0 };
    static const QUMethod slot_4 = {"S_Cancelar", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_5 = {"SlotEscuela", 1, param_slot_5 };
    static const QMetaData slot_tbl[] = {
	{ "S_Cliente(int)", &slot_0, QMetaData::Private },
	{ "S_SelCliente(int)", &slot_1, QMetaData::Private },
	{ "S_SelCliente()", &slot_2, QMetaData::Private },
	{ "S_Aceptar()", &slot_3, QMetaData::Private },
	{ "S_Cancelar()", &slot_4, QMetaData::Private },
	{ "SlotEscuela(SiscomRegistro3*)", &slot_5, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCNSClientes", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCNSClientes.setMetaObject( metaObj );
    return metaObj;
}

void* QCNSClientes::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCNSClientes" ) )
	return this;
    return CNSClientes::qt_cast( clname );
}

bool QCNSClientes::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_Cliente((int)static_QUType_int.get(_o+1)); break;
    case 1: S_SelCliente((int)static_QUType_int.get(_o+1)); break;
    case 2: S_SelCliente(); break;
    case 3: S_Aceptar(); break;
    case 4: S_Cancelar(); break;
    case 5: SlotEscuela((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    default:
	return CNSClientes::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCNSClientes::qt_emit( int _id, QUObject* _o )
{
    return CNSClientes::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCNSClientes::qt_property( int id, int f, QVariant* v)
{
    return CNSClientes::qt_property( id, f, v);
}

bool QCNSClientes::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
