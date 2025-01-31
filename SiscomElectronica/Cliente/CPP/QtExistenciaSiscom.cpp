#include <QtExistenciaSiscom.h>
#include <QCtrlProductosSE.h>
#include <IMP_QControlFecha.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>

#include <zProductos.h> 

#include <qpushbutton.h>
QtExistenciaSiscom::QtExistenciaSiscom(QWidget *pQWParent,
				       const char *pchrPtrName,
				       WFlags pWFlags):
				       ExistenciaSiscom(pQWParent,pchrPtrName,pWFlags)
{
 ConectaSlots();
}

void QtExistenciaSiscom::IniciaVariables()
{
 IniciaFechas();
 IniciaProductos();
 ProductosSiscom();
}
void QtExistenciaSiscom::ProductosSiscom()
{
}
void QtExistenciaSiscom::ConectaSlots()
{
connect(QCtrProductos,
        SIGNAL(SignalSelecciono(zSiscomRegistro *)),
        SLOT(SlotSeleccionoProducto(zSiscomRegistro *)));
connect(QCtrFechaIni,
           SIGNAL(Signal_EnterA_o()),
           SLOT(SlotFocoAFechaFin()));
connect(QCtrFechaFin,
           SIGNAL(Signal_EnterA_o()),
           SLOT(SlotFocoAProductos()));
connect(QPBConsultaT,SIGNAL(clicked()),SLOT(SlotConsultaT()));
connect(QPBGArchivo,SIGNAL(clicked()),SLOT(SlotGuardaArchivo()));
}
void QtExistenciaSiscom::SlotGuardaArchivo()
{
 GuardaArchivo();
}
void QtExistenciaSiscom::SlotConsultaT()
{
 ConsultaTodo();
}
void QtExistenciaSiscom::SlotFocoAProductos()
{
zSiscomQt3::Foco(QCtrProductos);
}
void QtExistenciaSiscom::SlotFocoAFechaFin()
{
 QCtrFechaFin->setFocus();
}
void QtExistenciaSiscom::SlotSeleccionoProducto(zSiscomRegistro *pzSisRegProducto)
{
 Producto(pzSisRegProducto);
 ConsultaProductos();
 /*
 MuestraProductos(Productos());

 */
 zSiscomQt3::Foco(QCtrProductos);
}
zProductos *QtExistenciaSiscom::Productos()
{
   return zProds;
}
void QtExistenciaSiscom::MuestraProductos(zProductos *pzProductos)
{
const char *lchrArrCampos[]={"CveProducto",
		      "Existencia",
		      "Ventas",
		      0};

zSiscomQt3::LlenaTabla(lchrArrCampos,
                       pzProductos,
		       QTProductos);
}
void QtExistenciaSiscom::Producto(zSiscomRegistro *pzSisRegProducto)
{
    Productos()->Agrega((zProducto *)pzSisRegProducto);
}
void QtExistenciaSiscom::ConsultaProductos()
{

}
void QtExistenciaSiscom::ConsultaTodo()
{

}
void QtExistenciaSiscom::IniciaProductos()
{
    zProds=new zProductos;
}
void QtExistenciaSiscom::IniciaFechas()
{
QCtrFechaIni->ColocaFechaHoy();
QCtrFechaFin->ColocaFechaHoy();
QCtrFechaIni->setFocus();
}
void QtExistenciaSiscom::GuardaArchivo()
{
}
void QtExistenciaSiscom::AbreArchivo()
{
const char *lchrPtrHome=getenv("HOME");
char lchrArrArchivo[1024];
sprintf(lchrArrArchivo,
	"%s/ExistenciaSiscom.csv",
	lchrPtrHome);
if((FlePtrArchivo=fopen(lchrArrArchivo,"w")))
{
}
else
LogSiscom("No se pudo abrir %s",lchrArrArchivo);
}

FILE *QtExistenciaSiscom::Archivo()
{
  return FlePtrArchivo;
}

void QtExistenciaSiscom::CierraArchivo()
{
   fclose(Archivo());
}
