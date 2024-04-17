/****************************************************************************
** CQSisSelIconos meta object code from reading C++ file 'IMP_SelIconos.h'
**
** Created: Fri Apr 12 21:23:37 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_SelIconos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CQSisSelIconos::className() const
{
    return "CQSisSelIconos";
}

QMetaObject *CQSisSelIconos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CQSisSelIconos( "CQSisSelIconos", &CQSisSelIconos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CQSisSelIconos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisSelIconos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CQSisSelIconos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisSelIconos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CQSisSelIconos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SelIconos::staticMetaObject();
    static const QUMethod slot_0 = {"SlotSeleccionaDirectorio", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSeleccionaIcono", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotAceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionaDirectorio()", &slot_0, QMetaData::Private },
	{ "SlotSeleccionaIcono(QIconViewItem*)", &slot_1, QMetaData::Private },
	{ "SlotAceptar()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"CQSisSelIconos", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CQSisSelIconos.setMetaObject( metaObj );
    return metaObj;
}

void* CQSisSelIconos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CQSisSelIconos" ) )
	return this;
    return SelIconos::qt_cast( clname );
}

bool CQSisSelIconos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionaDirectorio(); break;
    case 1: SlotSeleccionaIcono((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotAceptar(); break;
    default:
	return SelIconos::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CQSisSelIconos::qt_emit( int _id, QUObject* _o )
{
    return SelIconos::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool CQSisSelIconos::qt_property( int id, int f, QVariant* v)
{
    return SelIconos::qt_property( id, f, v);
}

bool CQSisSelIconos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
