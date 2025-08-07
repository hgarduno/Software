/****************************************************************************
** QtImpMultiApoyos meta object code from reading C++ file 'QtImpMultiApoyos.h'
**
** Created: Tue Jun 24 08:59:58 2025
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpMultiApoyos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpMultiApoyos::className() const
{
    return "QtImpMultiApoyos";
}

QMetaObject *QtImpMultiApoyos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpMultiApoyos( "QtImpMultiApoyos", &QtImpMultiApoyos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpMultiApoyos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpMultiApoyos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpMultiApoyos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpMultiApoyos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpMultiApoyos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = MultiApoyos::staticMetaObject();
    static const QUMethod slot_0 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotSeleccionaCredito", 4, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "SlotCancelar()", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private },
	{ "SlotSeleccionaCredito(int,int,int,const QPoint&)", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpMultiApoyos", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpMultiApoyos.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpMultiApoyos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpMultiApoyos" ) )
	return this;
    return MultiApoyos::qt_cast( clname );
}

bool QtImpMultiApoyos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotCancelar(); break;
    case 1: SlotAceptar(); break;
    case 2: SlotSeleccionaCredito((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    default:
	return MultiApoyos::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpMultiApoyos::qt_emit( int _id, QUObject* _o )
{
    return MultiApoyos::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpMultiApoyos::qt_property( int id, int f, QVariant* v)
{
    return MultiApoyos::qt_property( id, f, v);
}

bool QtImpMultiApoyos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
