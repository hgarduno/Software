#include <QSisEstsMedico.h>
#include <QSisImporteServicios.h>
#include <QSisResultadosGen.h>
#include <qtabwidget.h>

QSisEstsMedico::QSisEstsMedico(QWidget *pQWParent,
			       const char *pchrPtrName,
			       WFlags pWFlags):
			   QWidget(pQWParent,pchrPtrName,pWFlags)
{

IniciaInterfaz();

}

void QSisEstsMedico::IniciaInterfaz()
{
QVBoxLayout *lQVBLControl=new QVBoxLayout(this);

QTWDatos=new QTabWidget(this,"QTWDatos");

QSIServicios=new QSisImporteServicios(this,"QSIServicios");
QSRGenerales=new QSisResultadosGen(this,"QSRGenerales");
QPBActualiza=new QPushButton("Actualiza",this,"QPBActualiza");
QTWDatos->addTab(QSRGenerales,"General");
QTWDatos->addTab(QSIServicios,"Importe Por Servicio");
lQVBLControl->addWidget(QTWDatos);
lQVBLControl->addWidget(QPBActualiza);
}
void QSisEstsMedico::IdMedico(const char *pchrPtrIdMedico)
{
	QSIServicios->IdMedico(pchrPtrIdMedico);
}
void QSisEstsMedico::Servidor(SiscomDatCom *pSisDatCom)
{
	QSIServicios->Servidor(pSisDatCom);
}
void QSisEstsMedico::RangoFechas(const char *pchrPtrFechaIni,
				 const char *pchrPtrFechaFin)
{
	QSIServicios->RangoFechas(pchrPtrFechaIni,pchrPtrFechaFin);
}
void QSisEstsMedico::IniciaControl()
{
	QSIServicios->IniciaControl();
}
