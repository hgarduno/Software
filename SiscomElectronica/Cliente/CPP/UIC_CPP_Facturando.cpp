/****************************************************************************
** Form implementation generated from reading ui file 'UI/Facturando.ui'
**
** Created: Wed Jan 31 10:56:48 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Facturando.h"

#include <qvariant.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Facturando as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Facturando::Facturando( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Facturando" );
    FacturandoLayout = new QGridLayout( this, 1, 1, 11, 6, "FacturandoLayout"); 
    spacer8 = new QSpacerItem( 20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding );
    FacturandoLayout->addItem( spacer8, 1, 0 );

    table12 = new QTable( this, "table12" );
    table12->setNumRows( 3 );
    table12->setNumCols( 3 );

    FacturandoLayout->addWidget( table12, 0, 0 );
    languageChange();
    resize( QSize(532, 360).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Facturando::~Facturando()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Facturando::languageChange()
{
    setCaption( tr( "Form2" ) );
}

