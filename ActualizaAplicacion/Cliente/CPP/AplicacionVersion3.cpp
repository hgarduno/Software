#include <qapplication.h>
#include <IMP_Cliente.h>

int main( int argc, char ** argv )
{
    QApplication a( argc, argv );
    QCliente *lQCliente=new QCliente;
    lQCliente->show();
    a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
    return a.exec();
}

