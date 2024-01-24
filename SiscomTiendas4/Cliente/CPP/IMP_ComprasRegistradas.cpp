#include <IMP_ComprasRegistradas.h>
#include <IMP_QControlFecha.h>
#include<SISCOMComunicaciones++.h>
#include <CQSisEmpresas.h>
#include <CQSisContactos.h>
#include <CQSisProductos.h>
QComprasRegistradas *InstanciaComprasRegistradas(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QComprasRegistradas((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QComprasRegistradas::QComprasRegistradas(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ComprasRegistradas(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QComprasRegistradas::~QComprasRegistradas()
{

}
void QComprasRegistradas::IniciaVariables()
{
	QCtrFechaIni->ColocaFechaHoy();
	QCtrFechaFin->ColocaFechaHoy();
}
void QComprasRegistradas::ConectaSlots()
{
	
	connect(QPBEjecuta,
		SIGNAL(clicked()),
		SLOT(SlotEjecuta()));
	connect(QTCompras,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotDetalleCompra(int,int,int,const QPoint &)));

}
void QComprasRegistradas::SlotDetalleCompra(int pintNCompra,
					    int ,
					    int,
					    const QPoint &)
{
	if(pintNCompra!=-1)
	ConsultandoDetalleCompra(pintNCompra);
}

void QComprasRegistradas::SlotEjecuta()
{
	EjecutaConsulta();
}
void QComprasRegistradas::EjecutaConsulta()
{
	ConsultaCompras();
	MuestraCompras();
}
void QComprasRegistradas::ConsultaCompras()
{
CQSisOpCompras lCQSCompras(SisDatCom);

lCQSCompras.Compras(
		new CQSisEmpresa("0",""),
		(const char *)QCtrFechaIni->ObtenFecha(),
		(const char *)QCtrFechaFin->ObtenFecha(),
		&CQSLCompras);
}
void QComprasRegistradas::MuestraCompras()
{
CQSisCompra *lCQSCompra;
int lintContador;

QTCompras->setNumRows(CQSLCompras.count());

for(lCQSCompra=CQSLCompras.first(),
    lintContador=0;
    lCQSCompra;
    lCQSCompra=CQSLCompras.next(),
    lintContador++)
SiscomAnexarRegistroALaTabla(
	lintContador,
	QTCompras,
	QStringList()						<<
	(*lCQSCompra)["Fecha"] 					<<
	(*lCQSCompra)["Factura"] 				<<
	(*lCQSCompra->Proveedor())["RazonSocial"] <<
	QString(lCQSCompra->Contacto()->ObtenPersona()->SRegistrosPro2["Nombre"]) +
	" "							      +
	(lCQSCompra->Contacto()->ObtenPersona()->SRegistrosPro2["APaterno"]));		
SiscomAjustaColumnas(QTCompras);
}
void QComprasRegistradas::ConsultandoDetalleCompra(int pintNCompra)
{
	ConsultaDetalleCompra(pintNCompra);
	MuestraDetalleCompra();

}
void QComprasRegistradas::ConsultaDetalleCompra(int pintNCompra)
{
CQSisOpCompras lCQSOCompras(SisDatCom);
CQSLDCompras.clear();
lCQSOCompras.DetalleCompra(new CQSisEmpresa("0",""),
			   CQSLCompras.at(pintNCompra),
			   &CQSLDCompras);
}
void QComprasRegistradas::MuestraDetalleCompra()
{
CQSisCompra *lCQSCompra;
int lintContador;

QTDetalleCompra->setNumRows(CQSLDCompras.count());
for(lintContador=0,
    lCQSCompra=CQSLDCompras.first();
    lCQSCompra;
    lintContador++,
    lCQSCompra=CQSLDCompras.next())
 SiscomAnexarRegistroALaTabla(
 	lintContador,
	QTDetalleCompra,
	QStringList() 			<<
	(*lCQSCompra->Producto())["Clave"] <<
	(*lCQSCompra)["Cantidad"]	   <<
	(*lCQSCompra)["Precio"]);
SiscomAjustaColumnas(QTDetalleCompra);
}
void QComprasRegistradas::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
