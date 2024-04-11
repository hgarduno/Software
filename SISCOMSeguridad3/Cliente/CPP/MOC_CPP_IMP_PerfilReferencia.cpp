/****************************************************************************
** CQSisPerfilReferencia meta object code from reading C++ file 'IMP_PerfilReferencia.h'
**
** Created: Sat Jan 27 16:42:29 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_PerfilReferencia.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CQSisPerfilReferencia::className() const
{
    return "CQSisPerfilReferencia";
}

QMetaObject *CQSisPerfilReferencia::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CQSisPerfilReferencia( "CQSisPerfilReferencia", &CQSisPerfilReferencia::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CQSisPerfilReferencia::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisPerfilReferencia", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CQSisPerfilReferencia::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisPerfilReferencia", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CQSisPerfilReferencia::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = PerfilReferencia::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionaPerfil", 4, param_slot_0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionaPerfil(int,int,int,const QPoint&)", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"CQSisPerfilReferencia", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CQSisPerfilReferencia.setMetaObject( metaObj );
    return metaObj;
}

void* CQSisPerfilReferencia::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CQSisPerfilReferencia" ) )
	return this;
    return PerfilReferencia::qt_cast( clname );
}

bool CQSisPerfilReferencia::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionaPerfil((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 1: SlotAceptar(); break;
    default:
	return PerfilReferencia::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CQSisPerfilReferencia::qt_emit( int _id, QUObject* _o )
{
    return PerfilReferencia::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool CQSisPerfilReferencia::qt_property( int id, int f, QVariant* v)
{
    return PerfilReferencia::qt_property( id, f, v);
}

bool CQSisPerfilReferencia::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
