#include <QEspacioExpendios.h>
#include <EmpresasN.h>
#include <qvbox.h>
#include <qworkspace.h>


QEspacioExpendios::QEspacioExpendios(EmpresaN *pExpendio,
				     QWidget *pQWParent,
				     const char *pchrPtrName,
				     WFlags pWFlags):
	QMainWindow(pQWParent,pchrPtrName,pWFlags),
	Expendio(pExpendio)

{
	ColocaEncabezado();
	CreaWS();
	show();

}
void QEspacioExpendios::ColocaEncabezado()
{
	setCaption(QString("SISCOM Tiendas ")			+
		   "Expendio:"				+
		   Expendio->SRegistrosPro2["RazonSocial"]);

}
void QEspacioExpendios::CreaWS()
{
QVBox* vb = new QVBox( this );
vb->setFrameStyle( QFrame::StyledPanel | QFrame::Sunken );
ws = new QWorkspace( vb );
ws->setScrollBarsEnabled( TRUE );
setCentralWidget( vb );
}
QWorkspace *QEspacioExpendios::ObtenEspacioTrabajo()
{
	return ws;
}
