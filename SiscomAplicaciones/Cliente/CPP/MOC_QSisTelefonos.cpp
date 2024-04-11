/****************************************************************************
** QSisTelefonos meta object code from reading C++ file 'QSisTelefonos.h'
**
** Created: Sat Jan 27 17:40:44 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QSisTelefonos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QSisTelefonos::className() const
{
    return "QSisTelefonos";
}

QMetaObject *QSisTelefonos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSisTelefonos( "QSisTelefonos", &QSisTelefonos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSisTelefonos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSisTelefonos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSisTelefonos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSisTelefonos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSisTelefonos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPasaFocoDescripcion", 0, 0 };
    static const QUMethod slot_1 = {"SlotPasaFocoAnexar", 0, 0 };
    static const QUMethod slot_2 = {"SlotAnexar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPasaFocoDescripcion()", &slot_0, QMetaData::Private },
	{ "SlotPasaFocoAnexar()", &slot_1, QMetaData::Private },
	{ "SlotAnexar()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSisTelefonos", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSisTelefonos.setMetaObject( metaObj );
    return metaObj;
}

void* QSisTelefonos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSisTelefonos" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool QSisTelefonos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPasaFocoDescripcion(); break;
    case 1: SlotPasaFocoAnexar(); break;
    case 2: SlotAnexar(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSisTelefonos::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSisTelefonos::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QSisTelefonos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
