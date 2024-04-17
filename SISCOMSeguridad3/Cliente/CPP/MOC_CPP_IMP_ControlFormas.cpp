/****************************************************************************
** CQSisControlFormas meta object code from reading C++ file 'IMP_ControlFormas.h'
**
** Created: Fri Apr 12 21:23:37 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ControlFormas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CQSisControlFormas::className() const
{
    return "CQSisControlFormas";
}

QMetaObject *CQSisControlFormas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CQSisControlFormas( "CQSisControlFormas", &CQSisControlFormas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CQSisControlFormas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisControlFormas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CQSisControlFormas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CQSisControlFormas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CQSisControlFormas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ControlFormas::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionoItem", 3, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotMenuOperaciones", 3, param_slot_1 };
    static const QUMethod slot_2 = {"SlotAnexarObjetos", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionoItem(QListViewItem*,const QPoint&,int)", &slot_0, QMetaData::Public },
	{ "SlotMenuOperaciones(QListViewItem*,const QPoint&,int)", &slot_1, QMetaData::Public },
	{ "SlotAnexarObjetos()", &slot_2, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"CQSisControlFormas", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CQSisControlFormas.setMetaObject( metaObj );
    return metaObj;
}

void* CQSisControlFormas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CQSisControlFormas" ) )
	return this;
    return ControlFormas::qt_cast( clname );
}

bool CQSisControlFormas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionoItem((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 1: SlotMenuOperaciones((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 2: SlotAnexarObjetos(); break;
    default:
	return ControlFormas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CQSisControlFormas::qt_emit( int _id, QUObject* _o )
{
    return ControlFormas::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool CQSisControlFormas::qt_property( int id, int f, QVariant* v)
{
    return ControlFormas::qt_property( id, f, v);
}

bool CQSisControlFormas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
