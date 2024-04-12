/****************************************************************************
** QFirmate meta object code from reading C++ file 'IMP_Firmate.h'
**
** Created: Thu Apr 11 21:37:04 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Firmate.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QFirmate::className() const
{
    return "QFirmate";
}

QMetaObject *QFirmate::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QFirmate( "QFirmate", &QFirmate::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QFirmate::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFirmate", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QFirmate::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFirmate", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QFirmate::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Firmate::staticMetaObject();
    static const QUMethod slot_0 = {"SlotValidaFirma", 0, 0 };
    static const QUMethod slot_1 = {"SlotPasaFocoAceptar", 0, 0 };
    static const QUMethod slot_2 = {"SlotCancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotValidaFirma()", &slot_0, QMetaData::Private },
	{ "SlotPasaFocoAceptar()", &slot_1, QMetaData::Private },
	{ "SlotCancelar()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QFirmate", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QFirmate.setMetaObject( metaObj );
    return metaObj;
}

void* QFirmate::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QFirmate" ) )
	return this;
    return Firmate::qt_cast( clname );
}

bool QFirmate::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotValidaFirma(); break;
    case 1: SlotPasaFocoAceptar(); break;
    case 2: SlotCancelar(); break;
    default:
	return Firmate::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QFirmate::qt_emit( int _id, QUObject* _o )
{
    return Firmate::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QFirmate::qt_property( int id, int f, QVariant* v)
{
    return Firmate::qt_property( id, f, v);
}

bool QFirmate::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
