/****************************************************************************
** PagaConTransferencia meta object code from reading C++ file 'UIC_H_PagaConTransferencia.h'
**
** Created: Wed Apr 10 20:52:39 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/UIC_H_PagaConTransferencia.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *PagaConTransferencia::className() const
{
    return "PagaConTransferencia";
}

QMetaObject *PagaConTransferencia::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PagaConTransferencia( "PagaConTransferencia", &PagaConTransferencia::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString PagaConTransferencia::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PagaConTransferencia", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PagaConTransferencia::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PagaConTransferencia", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PagaConTransferencia::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "languageChange()", &slot_0, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"PagaConTransferencia", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PagaConTransferencia.setMetaObject( metaObj );
    return metaObj;
}

void* PagaConTransferencia::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PagaConTransferencia" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool PagaConTransferencia::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PagaConTransferencia::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool PagaConTransferencia::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool PagaConTransferencia::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
