/****************************************************************************
** QCierreDia meta object code from reading C++ file 'IMP_CierreDia.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CierreDia.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCierreDia::className() const
{
    return "QCierreDia";
}

QMetaObject *QCierreDia::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCierreDia( "QCierreDia", &QCierreDia::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCierreDia::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCierreDia", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCierreDia::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCierreDia", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCierreDia::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CierreDia::staticMetaObject();
    static const QUMethod slot_0 = {"SlotFocoAFechaFin", 0, 0 };
    static const QUMethod slot_1 = {"SlotFocoAExpendio", 0, 0 };
    static const QUMethod slot_2 = {"SlotSeleccionaExpendio", 0, 0 };
    static const QUMethod slot_3 = {"SlotConsulta", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFocoAFechaFin()", &slot_0, QMetaData::Private },
	{ "SlotFocoAExpendio()", &slot_1, QMetaData::Private },
	{ "SlotSeleccionaExpendio()", &slot_2, QMetaData::Private },
	{ "SlotConsulta()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCierreDia", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCierreDia.setMetaObject( metaObj );
    return metaObj;
}

void* QCierreDia::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCierreDia" ) )
	return this;
    return CierreDia::qt_cast( clname );
}

bool QCierreDia::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFocoAFechaFin(); break;
    case 1: SlotFocoAExpendio(); break;
    case 2: SlotSeleccionaExpendio(); break;
    case 3: SlotConsulta(); break;
    default:
	return CierreDia::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCierreDia::qt_emit( int _id, QUObject* _o )
{
    return CierreDia::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCierreDia::qt_property( int id, int f, QVariant* v)
{
    return CierreDia::qt_property( id, f, v);
}

bool QCierreDia::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
