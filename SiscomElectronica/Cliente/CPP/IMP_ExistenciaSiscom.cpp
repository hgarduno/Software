#include <IMP_ExistenciaSiscom.h>
#include <QCtrlProductosSE.h>
#include <IMP_QControlFecha.h>

#include <zSiscomDesarrollo4.h> 
#include <zSiscomElectronica.h>

#include <zExistenciaVenta.h>
#include <zProductos.h>
#include <zProducto.h>
QExistenciaSiscom *InstanciaExistenciaSiscom(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QExistenciaSiscom((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QExistenciaSiscom::QExistenciaSiscom(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				QtExistenciaSiscom(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
  QtExistenciaSiscom::IniciaVariables(); 
  IniciaVariables();
}

QExistenciaSiscom::~QExistenciaSiscom()
{

}
void QExistenciaSiscom::IniciaVariables()
{
IniciaExistenciaVenta();

}

void QExistenciaSiscom::ProductosSiscom()
{
QCtrProductos->Servidor(zSiscomDesarrollo4::Conexion());
QCtrProductos->IniciaControl();
}

void QExistenciaSiscom::ConsultaProductos()
{
  ConsultandoProductos();
  QtExistenciaSiscom::MuestraProductos(ExistenciaVenta()->Productos());
}
void QExistenciaSiscom::ConsultandoProductos()
{
zSiscomElectronica lzSisElectronica(zSiscomDesarrollo4::Conexion(),
				    "ExistenciaSiscom");
ExistenciaVenta()->FechaIni((const char *)QCtrFechaIni->ObtenFecha());
ExistenciaVenta()->FechaFin((const char *)QCtrFechaFin->ObtenFecha());
ExistenciaVenta()->IdExpendio(*(chrPtrArgumentos+0));
ExistenciaVenta()->Productos(QtExistenciaSiscom::Productos());
lzSisElectronica.ExistenciaExpendios(ExistenciaVenta());
}
void QExistenciaSiscom::IniciaExistenciaVenta()
{
 zExistenciaV=new zExistenciaVenta();
}
zExistenciaVenta *QExistenciaSiscom::ExistenciaVenta()
{
   return zExistenciaV;
}
void QExistenciaSiscom::ConsultaTodo()
{
zSiscomElectronica lzSisElectronica(zSiscomDesarrollo4::Conexion(),"ExistenciaSiscomT");
ExistenciaVenta()->FechaIni((const char *)QCtrFechaIni->ObtenFecha());
ExistenciaVenta()->FechaFin((const char *)QCtrFechaFin->ObtenFecha());
ExistenciaVenta()->IdExpendio(*(chrPtrArgumentos+0));
lzSisElectronica.ExistenciaSiscom(ExistenciaVenta());
}

void QExistenciaSiscom::GuardaArchivo()
{
zSiscomRegistro *lzSisRegProducto;
AbreArchivo();
for(lzSisRegProducto=ExistenciaVenta()->Productos()->Primer();
    lzSisRegProducto;
    lzSisRegProducto=ExistenciaVenta()->Productos()->Siguiente())
 fprintf(Archivo(),
 	 "%s|%s|%s\n",
	 (*lzSisRegProducto)["CveProducto"],
	 (*lzSisRegProducto)["Ventas"],
	 (*lzSisRegProducto)["Existencia"]);



CierraArchivo();	
/*SiscomRegistrosLog(ExistenciaVenta()->Productos());  */
}
