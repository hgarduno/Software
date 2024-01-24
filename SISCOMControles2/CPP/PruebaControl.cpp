#include <PruebaControl.h> 
#include <qlayout.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qfiledialog.h>

FILE *gPtrFleArchivoLog;
PruebaControl::PruebaControl( QWidget *parent, const char *name )
    : QWidget( parent, name ), md( File )
{
    QHBoxLayout *layout = new QHBoxLayout( this );
    layout->setMargin( 0 );

    lineEdit = new QLineEdit( this, "filechooser_lineedit" );
    layout->addWidget( lineEdit );

    connect( lineEdit, SIGNAL( textChanged( const QString & ) ),
	     this, SIGNAL( fileNameChanged( const QString & ) ) );

    button = new QPushButton( "...", this, "filechooser_button" );
    button->setFixedWidth( button->fontMetrics().width( " ... " ) );
    layout->addWidget( button );

    QPOtro= new QPushButton( "...", this, "filechooser_button" );
    QPOtro->setFixedWidth( QPOtro->fontMetrics().width( " ... " ) );
    layout->addWidget( QPOtro);

    QPOtro1= new QPushButton( "...", this, "filechooser_button" );
    QPOtro->setFixedWidth( QPOtro1->fontMetrics().width( " ... " ) );
    layout->addWidget( QPOtro1);
    connect( button, SIGNAL( clicked() ),
	     this, SLOT( chooseFile() ) );

    setFocusProxy( lineEdit );
}

void PruebaControl::setMode( Mode m )
{
    md = m;
}

PruebaControl::Mode PruebaControl::mode() const
{
    return md;
}

void PruebaControl::setFileName( const QString &fn )
{
    lineEdit->setText( fn );
}

QString PruebaControl::fileName() const
{
    return lineEdit->text();
}

void PruebaControl::chooseFile()
{
    QString fn;
    if ( mode() == File )
	fn = QFileDialog::getOpenFileName( lineEdit->text(), QString::null, this );
    else
	fn = QFileDialog::getExistingDirectory( lineEdit->text(),this );

    if ( !fn.isEmpty() ) {
	lineEdit->setText( fn );
	emit fileNameChanged( fn );
    }
}

