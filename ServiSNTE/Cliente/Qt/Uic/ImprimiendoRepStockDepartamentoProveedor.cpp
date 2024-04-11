/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/ImprimiendoRepStockDepartamentoProveedor.ui'
**
** Created: Sat Jan 27 16:38:22 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "ImprimiendoRepStockDepartamentoProveedor.h"

#include <qvariant.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ImprimiendoRepStockDepartamentoProveedor as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ImprimiendoRepStockDepartamentoProveedor::ImprimiendoRepStockDepartamentoProveedor( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ImprimiendoRepStockDepartamentoProveedor" );
    setMinimumSize( QSize( 800, 600 ) );
    languageChange();
    resize( QSize(800, 600).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ImprimiendoRepStockDepartamentoProveedor::~ImprimiendoRepStockDepartamentoProveedor()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ImprimiendoRepStockDepartamentoProveedor::languageChange()
{
    setCaption( tr( "Stock Deparamento Provedor" ) );
}

