#include <IMP_SeleccionaOrden.h>
#include <IMP_QControlFecha.h>

#include <zSiscomQt3.h>
#include <zSiscomDesarrollo4.h>
#include <qradiobutton.h>
QSeleccionaOrden::QSeleccionaOrden(zSiscomConexion *pzSiscomConexion,
			           QWidget *pQWParent,
				   const char *pchrPtrName,
				   bool pbModal,
				   WFlags pWFlags):
			QCotizaciones(pzSiscomConexion,
				      pQWParent,
				      pchrPtrName,
				      pbModal,
				      pWFlags)
{
TipoOrden(1);
IniciaVariables();
}
QSeleccionaOrden::~QSeleccionaOrden()
{

}

void QSeleccionaOrden::IniciaVariables()
{
 PonConsultaPorRangoFechas(1);
 HabilitaBotones(false);
 QRBCotizaciones->setDown(true);
 QCtrFechaInicio->setEnabled(true);
 zSiscomQt3::Foco(QCtrFechaInicio);
 QCtrFechaFin->setEnabled(true);
 SlotConsulta();
}
