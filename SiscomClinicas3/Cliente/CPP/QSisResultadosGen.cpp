#include <QSisResultadosGen.h>

QSisResultadosGen::QSisResultadosGen(QWidget *pQWParent,
				     const char *pchrPtrName,
				     WFlags pWFlags):
				 QWidget(pQWParent,pchrPtrName,pWFlags)
{
IniciaInterfaz();

}


void QSisResultadosGen::IniciaInterfaz()
{
QGLRegilla=new QGridLayout(this,2,1,2,2,"QGLRegilla");
QSisHEspacio *lQSHECnsTotalesVTotales;
QSisHEspacio *lQSHETPromTTotalConsulta;


lQSHECnsTotalesVTotales=new QSisHEspacio(0,5,5,"lQSHECnsTotalesVTotales");
lQSHETPromTTotalConsulta=new QSisHEspacio(0,5,5,"lQSHETPromTTotalConsulta");

(*lQSHECnsTotalesVTotales)+=SiscomCreaDisplayEtiqueta(this,
					      "QLCnsTotales",
					      "Consultas Totales",
					      "QLCDCnsTotales",
					      4,
					      &QLCDCnsTotales,
					      &QLCnsTotales);
(*lQSHECnsTotalesVTotales)+=SiscomCreaDisplayEtiqueta(this,
					      "QLVTotales",
					      "Ventas Totales",
					      "QLCDVenTotales",
					      6,
					      &QLCDVenTotales,
					      &QLVTotales);
(*lQSHETPromTTotalConsulta)+=SiscomCreaDisplayEtiqueta(this,
					      "QLTPromConsulta",
					      "Tiempo Promedio Por Consulta",
					      "QLCDTPromConsulta",
					      4,
					      &QLCDTPromConsulta,
					      &QLTPromConsulta);
(*lQSHETPromTTotalConsulta)+=SiscomCreaDisplayEtiqueta(this,
					      "QLTTotalConsulta",
					      "Tiempo Total En Consulta",
					      "QLCDTotalConsulta",
					      8,
					      &QLCDTotalConsulta,
					      &QLTTotalConsulta);
QGLRegilla->addItem(lQSHECnsTotalesVTotales,0,0);
QGLRegilla->addItem(lQSHETPromTTotalConsulta,1,0);
}
