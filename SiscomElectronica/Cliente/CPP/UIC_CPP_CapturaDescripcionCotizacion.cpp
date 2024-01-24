/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaDescripcionCotizacion.ui'
**
** Created: Thu Dec 21 12:53:46 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaDescripcionCotizacion.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <qbuttongroup.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaDescripcionCotizacion as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaDescripcionCotizacion::CapturaDescripcionCotizacion( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaDescripcionCotizacion" );
    CapturaDescripcionCotizacionLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaDescripcionCotizacionLayout"); 

    layout14 = new QHBoxLayout( 0, 0, 6, "layout14"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout14->addWidget( QPBAceptar );

    pushButton1_2 = new QPushButton( this, "pushButton1_2" );
    layout14->addWidget( pushButton1_2 );

    CapturaDescripcionCotizacionLayout->addMultiCellLayout( layout14, 2, 2, 0, 1 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout3->addWidget( textLabel2 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setReadOnly( TRUE );
    layout3->addWidget( QTEDescripcion );

    CapturaDescripcionCotizacionLayout->addMultiCellLayout( layout3, 0, 1, 1, 1 );

    layout28 = new QVBoxLayout( 0, 0, 6, "layout28"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout28->addWidget( textLabel1_3 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    QLENombre->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLENombre->sizePolicy().hasHeightForWidth() ) );
    layout28->addWidget( QLENombre );

    CapturaDescripcionCotizacionLayout->addLayout( layout28, 0, 0 );

    layout32 = new QHBoxLayout( 0, 0, 6, "layout32"); 

    layout31 = new QVBoxLayout( 0, 0, 6, "layout31"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QLETelefono = new QLineEdit( this, "QLETelefono" );
    QLETelefono->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLETelefono->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QLETelefono );
    layout31->addLayout( layout1 );

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout1_2->addWidget( textLabel1_2 );

    QLEPagaCon = new QLineEdit( this, "QLEPagaCon" );
    QLEPagaCon->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEPagaCon->sizePolicy().hasHeightForWidth() ) );
    layout1_2->addWidget( QLEPagaCon );
    layout31->addLayout( layout1_2 );

    layout1_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    layout1_2_2->addWidget( textLabel1_2_2 );

    QLEHora = new QLineEdit( this, "QLEHora" );
    QLEHora->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEHora->sizePolicy().hasHeightForWidth() ) );
    layout1_2_2->addWidget( QLEHora );
    layout31->addLayout( layout1_2_2 );
    spacer1 = new QSpacerItem( 20, 86, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layout31->addItem( spacer1 );
    layout32->addLayout( layout31 );

    QBGEscuelas = new QButtonGroup( this, "QBGEscuelas" );
    QBGEscuelas->setColumnLayout(0, Qt::Vertical );
    QBGEscuelas->layout()->setSpacing( 6 );
    QBGEscuelas->layout()->setMargin( 11 );
    QBGEscuelasLayout = new QGridLayout( QBGEscuelas->layout() );
    QBGEscuelasLayout->setAlignment( Qt::AlignTop );
    layout32->addWidget( QBGEscuelas );

    CapturaDescripcionCotizacionLayout->addLayout( layout32, 1, 0 );
    languageChange();
    resize( QSize(668, 305).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaDescripcionCotizacion::~CapturaDescripcionCotizacion()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaDescripcionCotizacion::languageChange()
{
    setCaption( tr( "Form1" ) );
    QPBAceptar->setText( tr( "&Aceptar" ) );
    QPBAceptar->setAccel( QKeySequence( tr( "Alt+A" ) ) );
    pushButton1_2->setText( tr( "Cancelar" ) );
    textLabel2->setText( tr( "Descripcion" ) );
    textLabel1_3->setText( tr( "Nombre" ) );
    textLabel1->setText( tr( "Telefono" ) );
    QLETelefono->setInputMask( tr( "##-####-####; " ) );
    textLabel1_2->setText( tr( "Paga Con" ) );
    QLEPagaCon->setInputMask( tr( "###.## ; " ) );
    textLabel1_2_2->setText( tr( "Hora de entrega" ) );
    QLEHora->setInputMask( tr( "##:##; " ) );
    QBGEscuelas->setTitle( tr( "Escuelas" ) );
}

