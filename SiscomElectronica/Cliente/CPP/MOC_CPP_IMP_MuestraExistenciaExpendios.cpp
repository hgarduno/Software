/****************************************************************************
** QMuestraExistenciaExpendios meta object code from reading C++ file 'IMP_MuestraExistenciaExpendios.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_MuestraExistenciaExpendios.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QMuestraExistenciaExpendios::className() const
{
    return "QMuestraExistenciaExpendios";
}

QMetaObject *QMuestraExistenciaExpendios::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QMuestraExistenciaExpendios( "QMuestraExistenciaExpendios", &QMuestraExistenciaExpendios::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QMuestraExistenciaExpendios::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMuestraExistenciaExpendios", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QMuestraExistenciaExpendios::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMuestraExistenciaExpendios", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QMuestraExistenciaExpendios::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = MuestraExistenciaExpendios::staticMetaObject();
    static const QUMethod slot_0 = {"SlotCancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotCancelar()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QMuestraExistenciaExpendios", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QMuestraExistenciaExpendios.setMetaObject( metaObj );
    return metaObj;
}

void* QMuestraExistenciaExpendios::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QMuestraExistenciaExpendios" ) )
	return this;
    return MuestraExistenciaExpendios::qt_cast( clname );
}

bool QMuestraExistenciaExpendios::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotCancelar(); break;
    default:
	return MuestraExistenciaExpendios::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QMuestraExistenciaExpendios::qt_emit( int _id, QUObject* _o )
{
    return MuestraExistenciaExpendios::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QMuestraExistenciaExpendios::qt_property( int id, int f, QVariant* v)
{
    return MuestraExistenciaExpendios::qt_property( id, f, v);
}

bool QMuestraExistenciaExpendios::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
