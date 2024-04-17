/****************************************************************************
** CQSisFirmas meta object code from reading C++ file 'IMP_Firmas.h'
**
** Created: Fri Apr 12 21:24:00 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Firmas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CQSisFirmas::className() const
{
    return "CQSisFirmas";
}

QMetaObject *CQSisFirmas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CQSisFirmas( "CQSisFirmas", &CQSisFirmas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CQSisFirmas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisFirmas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CQSisFirmas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisFirmas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CQSisFirmas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Firmas::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionaUsuario", 4, param_slot_0 };
    static const QUMethod slot_1 = {"SlotRegistraFirma", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionaUsuario(int,int,int,const QPoint&)", &slot_0, QMetaData::Private },
	{ "SlotRegistraFirma()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"CQSisFirmas", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CQSisFirmas.setMetaObject( metaObj );
    return metaObj;
}

void* CQSisFirmas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CQSisFirmas" ) )
	return this;
    return Firmas::qt_cast( clname );
}

bool CQSisFirmas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionaUsuario((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 1: SlotRegistraFirma(); break;
    default:
	return Firmas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CQSisFirmas::qt_emit( int _id, QUObject* _o )
{
    return Firmas::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool CQSisFirmas::qt_property( int id, int f, QVariant* v)
{
    return Firmas::qt_property( id, f, v);
}

bool CQSisFirmas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
