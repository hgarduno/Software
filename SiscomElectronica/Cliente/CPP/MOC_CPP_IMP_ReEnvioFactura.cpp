/****************************************************************************
** QReEnvioFactura meta object code from reading C++ file 'IMP_ReEnvioFactura.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ReEnvioFactura.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QReEnvioFactura::className() const
{
    return "QReEnvioFactura";
}

QMetaObject *QReEnvioFactura::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QReEnvioFactura( "QReEnvioFactura", &QReEnvioFactura::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QReEnvioFactura::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QReEnvioFactura", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QReEnvioFactura::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QReEnvioFactura", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QReEnvioFactura::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ReEnvioFactura::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotCorreo", 4, param_slot_0 };
    static const QUMethod slot_1 = {"SlotReEnviaFactura", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotCapturandoOtroCorreo", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "SlotCorreo(int,int,int,const QPoint&)", &slot_0, QMetaData::Private },
	{ "SlotReEnviaFactura()", &slot_1, QMetaData::Private },
	{ "SlotCapturandoOtroCorreo(const QString&)", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QReEnvioFactura", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QReEnvioFactura.setMetaObject( metaObj );
    return metaObj;
}

void* QReEnvioFactura::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QReEnvioFactura" ) )
	return this;
    return ReEnvioFactura::qt_cast( clname );
}

bool QReEnvioFactura::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotCorreo((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 1: SlotReEnviaFactura(); break;
    case 2: SlotCapturandoOtroCorreo((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return ReEnvioFactura::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QReEnvioFactura::qt_emit( int _id, QUObject* _o )
{
    return ReEnvioFactura::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QReEnvioFactura::qt_property( int id, int f, QVariant* v)
{
    return ReEnvioFactura::qt_property( id, f, v);
}

bool QReEnvioFactura::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
