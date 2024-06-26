/****************************************************************************
** QtImprimeTransferencia meta object code from reading C++ file 'QtImprimeTransferencia.h'
**
** Created: Thu Apr 11 21:08:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImprimeTransferencia.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImprimeTransferencia::className() const
{
    return "QtImprimeTransferencia";
}

QMetaObject *QtImprimeTransferencia::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImprimeTransferencia( "QtImprimeTransferencia", &QtImprimeTransferencia::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImprimeTransferencia::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimeTransferencia", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImprimeTransferencia::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImprimeTransferencia", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImprimeTransferencia::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "zTransferencia", QUParameter::InOut }
    };
    static const QUMethod slot_0 = {"imprimir", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "imprimir(zTransferencia&)", &slot_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImprimeTransferencia", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImprimeTransferencia.setMetaObject( metaObj );
    return metaObj;
}

void* QtImprimeTransferencia::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImprimeTransferencia" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool QtImprimeTransferencia::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: imprimir((zTransferencia&)*((zTransferencia*)static_QUType_ptr.get(_o+1))); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImprimeTransferencia::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImprimeTransferencia::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QtImprimeTransferencia::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
