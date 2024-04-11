/****************************************************************************
** QConExpendiosVenta meta object code from reading C++ file 'IMP_ConExpendiosVenta.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ConExpendiosVenta.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QConExpendiosVenta::className() const
{
    return "QConExpendiosVenta";
}

QMetaObject *QConExpendiosVenta::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QConExpendiosVenta( "QConExpendiosVenta", &QConExpendiosVenta::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QConExpendiosVenta::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QConExpendiosVenta", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QConExpendiosVenta::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QConExpendiosVenta", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QConExpendiosVenta::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ConExpendiosVenta::staticMetaObject();
    static const QUMethod slot_0 = {"SlotOExpendio", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotExpendio", 4, param_slot_1 };
    static const QUMethod slot_2 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_3 = {"SlotDejaPrecios", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotOExpendio()", &slot_0, QMetaData::Private },
	{ "SlotExpendio(int,int,int,const QPoint&)", &slot_1, QMetaData::Private },
	{ "SlotAceptar()", &slot_2, QMetaData::Private },
	{ "SlotDejaPrecios()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QConExpendiosVenta", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QConExpendiosVenta.setMetaObject( metaObj );
    return metaObj;
}

void* QConExpendiosVenta::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QConExpendiosVenta" ) )
	return this;
    return ConExpendiosVenta::qt_cast( clname );
}

bool QConExpendiosVenta::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotOExpendio(); break;
    case 1: SlotExpendio((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 2: SlotAceptar(); break;
    case 3: SlotDejaPrecios(); break;
    default:
	return ConExpendiosVenta::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QConExpendiosVenta::qt_emit( int _id, QUObject* _o )
{
    return ConExpendiosVenta::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QConExpendiosVenta::qt_property( int id, int f, QVariant* v)
{
    return ConExpendiosVenta::qt_property( id, f, v);
}

bool QConExpendiosVenta::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
