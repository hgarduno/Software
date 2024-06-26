/****************************************************************************
** QtImpFoliosCancelados meta object code from reading C++ file 'QtImpFoliosCancelados.h'
**
<<<<<<< HEAD
** Created: Mon Apr 1 17:30:34 2024
=======
** Created: Thu Apr 11 21:08:40 2024
>>>>>>> d8559e8a5b2006215346761b79004c9434166dbc
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpFoliosCancelados.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpFoliosCancelados::className() const
{
    return "QtImpFoliosCancelados";
}

QMetaObject *QtImpFoliosCancelados::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpFoliosCancelados( "QtImpFoliosCancelados", &QtImpFoliosCancelados::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpFoliosCancelados::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpFoliosCancelados", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpFoliosCancelados::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpFoliosCancelados", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpFoliosCancelados::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = FoliosCancelados::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pzSisRegTienda", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotTienda", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotMostrar", 0, 0 };
    static const QUMethod slot_2 = {"SlotFechaInicio", 0, 0 };
    static const QUMethod slot_3 = {"SlotFechaFinal", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotTienda(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotMostrar()", &slot_1, QMetaData::Private },
	{ "SlotFechaInicio()", &slot_2, QMetaData::Private },
	{ "SlotFechaFinal()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpFoliosCancelados", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpFoliosCancelados.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpFoliosCancelados::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpFoliosCancelados" ) )
	return this;
    return FoliosCancelados::qt_cast( clname );
}

bool QtImpFoliosCancelados::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotTienda((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotMostrar(); break;
    case 2: SlotFechaInicio(); break;
    case 3: SlotFechaFinal(); break;
    default:
	return FoliosCancelados::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpFoliosCancelados::qt_emit( int _id, QUObject* _o )
{
    return FoliosCancelados::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpFoliosCancelados::qt_property( int id, int f, QVariant* v)
{
    return FoliosCancelados::qt_property( id, f, v);
}

bool QtImpFoliosCancelados::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
