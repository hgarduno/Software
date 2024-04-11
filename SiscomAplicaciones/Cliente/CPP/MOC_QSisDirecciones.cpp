/****************************************************************************
** QSisDirecciones meta object code from reading C++ file 'QSisDirecciones.h'
**
** Created: Sat Jan 27 17:40:44 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QSisDirecciones.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QSisDirecciones::className() const
{
    return "QSisDirecciones";
}

QMetaObject *QSisDirecciones::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSisDirecciones( "QSisDirecciones", &QSisDirecciones::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSisDirecciones::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSisDirecciones", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSisDirecciones::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSisDirecciones", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSisDirecciones::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAnexar", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotDireccion", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAnexar()", &slot_0, QMetaData::Private },
	{ "SlotDireccion(SiscomRegistro3*)", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSisDirecciones", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSisDirecciones.setMetaObject( metaObj );
    return metaObj;
}

void* QSisDirecciones::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSisDirecciones" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool QSisDirecciones::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAnexar(); break;
    case 1: SlotDireccion((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSisDirecciones::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSisDirecciones::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QSisDirecciones::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
