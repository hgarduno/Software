/****************************************************************************
** Form implementation generated from reading ui file 'UI/CtrExpendios.ui'
**
** Created: Fri Apr 12 21:35:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CtrExpendios.h"

#include <qvariant.h>
#include <qiconview.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CtrExpendios as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CtrExpendios::CtrExpendios( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CtrExpendios" );
    CtrExpendiosLayout = new QGridLayout( this, 1, 1, 11, 6, "CtrExpendiosLayout"); 

    QIVExpendios = new QIconView( this, "QIVExpendios" );

    CtrExpendiosLayout->addWidget( QIVExpendios, 0, 0 );

    QPBCEEActual = new QPushButton( this, "QPBCEEActual" );
    QPBCEEActual->setMinimumSize( QSize( 0, 70 ) );
    QPBCEEActual->setMaximumSize( QSize( 32767, 70 ) );

    CtrExpendiosLayout->addWidget( QPBCEEActual, 1, 0 );
    languageChange();
    resize( QSize(600, 438).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CtrExpendios::~CtrExpendios()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CtrExpendios::languageChange()
{
    setCaption( tr( "Controlador De Expendios" ) );
    QPBCEEActual->setText( tr( "Crea Espacio  Para El Expendio\n"
"Actual" ) );
}

