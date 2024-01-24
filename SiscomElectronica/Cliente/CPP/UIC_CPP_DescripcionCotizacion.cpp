/****************************************************************************
** Form implementation generated from reading ui file 'UI/DescripcionCotizacion.ui'
**
** Created: Thu Dec 21 12:53:44 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_DescripcionCotizacion.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a DescripcionCotizacion as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
DescripcionCotizacion::DescripcionCotizacion( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "DescripcionCotizacion" );
    DescripcionCotizacionLayout = new QGridLayout( this, 1, 1, 11, 6, "DescripcionCotizacionLayout"); 

    layout11 = new QHBoxLayout( 0, 0, 6, "layout11"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    layout11->addWidget( QPBAceptar );

    DescripcionCotizacionLayout->addLayout( layout11, 1, 0 );

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout10->addWidget( textLabel2 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    layout10->addWidget( QTEDescripcion );

    DescripcionCotizacionLayout->addLayout( layout10, 0, 0 );
    languageChange();
    resize( QSize(404, 169).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
DescripcionCotizacion::~DescripcionCotizacion()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void DescripcionCotizacion::languageChange()
{
    setCaption( tr( "Form2" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    textLabel2->setText( tr( "Descripcion Cotizacion" ) );
}

