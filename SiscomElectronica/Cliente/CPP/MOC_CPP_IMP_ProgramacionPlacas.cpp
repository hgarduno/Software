/****************************************************************************
** QProgramacionPlacas meta object code from reading C++ file 'IMP_ProgramacionPlacas.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ProgramacionPlacas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QProgramacionPlacas::className() const
{
    return "QProgramacionPlacas";
}

QMetaObject *QProgramacionPlacas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QProgramacionPlacas( "QProgramacionPlacas", &QProgramacionPlacas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QProgramacionPlacas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProgramacionPlacas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QProgramacionPlacas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProgramacionPlacas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QProgramacionPlacas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ProgramacionPlacas::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPlacasPendientes", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSeleccionaPlaca", 4, param_slot_1 };
    static const QUMethod slot_2 = {"SlotEntrega", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPlacasPendientes()", &slot_0, QMetaData::Private },
	{ "SlotSeleccionaPlaca(int,int,int,const QPoint&)", &slot_1, QMetaData::Private },
	{ "SlotEntrega()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QProgramacionPlacas", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QProgramacionPlacas.setMetaObject( metaObj );
    return metaObj;
}

void* QProgramacionPlacas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QProgramacionPlacas" ) )
	return this;
    return ProgramacionPlacas::qt_cast( clname );
}

bool QProgramacionPlacas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPlacasPendientes(); break;
    case 1: SlotSeleccionaPlaca((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 2: SlotEntrega(); break;
    default:
	return ProgramacionPlacas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QProgramacionPlacas::qt_emit( int _id, QUObject* _o )
{
    return ProgramacionPlacas::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QProgramacionPlacas::qt_property( int id, int f, QVariant* v)
{
    return ProgramacionPlacas::qt_property( id, f, v);
}

bool QProgramacionPlacas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
