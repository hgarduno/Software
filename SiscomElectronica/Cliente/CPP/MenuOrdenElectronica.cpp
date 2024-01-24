
#include <MenuOrdenElectronica.h>
#include <IMP_CapturaDato.h>
#include <ProductosE.h>
#include <qaction.h>
#include <qobjectlist.h>
#include <SiscomDesarrollo3Qt++.h>

#include <CQSisSeguridadCajaVentas.h>
MenuOrdenElectronica::MenuOrdenElectronica(SiscomDatCom *pSisDatCom,
					   char **pchrPtrArgumentos,
					   ProductoE *pProducto,
					   const QPoint &pQPoint,
				           QWidget *pQWParent,
					   const char *pchrPtrName):
	QPopupMenu(pQWParent,pchrPtrName),
	SisDatCom(pSisDatCom),
	PProducto(pProducto),
	chrPtrArgumentos(pchrPtrArgumentos)
{
	IniciaOpciones();
	ColocaSeguridadCaja();
	popup(pQPoint);
}
void MenuOrdenElectronica::IniciaOpciones()
{
	QACabecera=AgregaOpcion("QACabecera",
				QString("Dispositivo:")+
				PProducto->SRegistrosPro2["CveProducto"] ,
				0);
	insertSeparator();
	QAEliminaProd=AgregaOpcion("QAEliminaProd",
				   "Elimina Productos",
				   SLOT(S_EliminaProductos()));
	insertSeparator();
	QAJgsSep=AgregaOpcion("QAJgsSep",
			      "Cotiza X Juegos Separados",
			      SLOT(S_JuegosSeparados()));
	QAJgs=AgregaOpcion("QAJgs",
			      "Cotiza X Juegos ",
			      SLOT(S_Juegos()));
	QACCliente=AgregaOpcion("QACCliente",
			      "Cambia El Cliente",
			      0);
	insertSeparator();
	QAPorDescuento=AgregaOpcion("QAPorDescuento",
				    "Porcentaje Descuento Al Producto",
				    SLOT(S_PorcentajeDescuento()));
				    
	QAPorDescuento=AgregaOpcion("QAPorDescuentoOrden",
				    "Porcentaje Descuento A La Orden",
				    SLOT(S_PorcentajeDescuentoOrden()));


}
void MenuOrdenElectronica::S_PorcentajeDescuentoOrden()
{
QCapturaDato lQCPorcentajeDesc("Porcentaje Descuento",
			"Porcentaje Descuento");
char lchrArrPorcentajeDesc[12];
	lQCPorcentajeDesc.ObtenDato(lchrArrPorcentajeDesc);
	emit SignalPorcentajeDescuentoOrden(atoi(lchrArrPorcentajeDesc));
}
void MenuOrdenElectronica::S_PorcentajeDescuento()
{
QCapturaDato lQCPorcentajeDesc("Porcentaje Descuento",
			"Porcentaje Descuento");
char lchrArrPorcentajeDesc[12];
	lQCPorcentajeDesc.ObtenDato(lchrArrPorcentajeDesc);
PProducto->SiscomActualizaCampo("PorDescuentoCaja",lchrArrPorcentajeDesc);
	emit SignalPorcentajeDescuento();
}
void MenuOrdenElectronica::S_JuegosSeparados()
{
QCapturaDato lQCNJuegos("Caputar Numero Juegos",
			"Numero De Juegos");
char lchrArrNumJuegos[12];
	lQCNJuegos.ObtenDato(lchrArrNumJuegos);
	intNumJuegosSep=atoi(lchrArrNumJuegos)-1;
	emit SignalJuegosSeparados(intNumJuegosSep);
}

void MenuOrdenElectronica::S_Juegos()
{
QCapturaDato lQCNJuegos("Caputar Numero Juegos",
			"Numero De Juegos");
char lchrArrNumJuegos[12];
	lQCNJuegos.ObtenDato(lchrArrNumJuegos);
	intNumJuegos=atoi(lchrArrNumJuegos);
	emit SignalCambioNumJuegos(intNumJuegos);
}
void MenuOrdenElectronica::S_EliminaProductos()
{
	emit SignalEliminaProductos();
}
int MenuOrdenElectronica::ObtenNumJuegos()
{
	return intNumJuegos;
}

QAction *MenuOrdenElectronica::AgregaOpcion(const char *pchrPtrName,	
					    QString pQSTexto,
					    const char *pchrPtrSlot)
{
QAction *lQAction=new QAction(pQSTexto,
			      QKeySequence(0),
			      this,
			      pchrPtrName);
	        if(pchrPtrSlot)
		connect(lQAction,
			SIGNAL(activated()),
			pchrPtrSlot);
	lQAction->addTo(this);
	return lQAction;
}
void MenuOrdenElectronica::MuestraEstadoControlesCaja()
{
SiscomRegistro3 *lSisReg3Control;
for(lSisReg3Control=SisReg3LstCCaja.first();
    lSisReg3Control;
    lSisReg3Control=SisReg3LstCCaja.next())
{
SiscomEscribeLog3Qt("%s (%s)",
		    (*lSisReg3Control)["nombreqt"],
		    (*lSisReg3Control)["estado"]);
}
}
void MenuOrdenElectronica::SeguridadControlesCaja()
{
CQSisOpControlCaja lCQSisOCCaja(SisDatCom);
lCQSisOCCaja.ControlesSeguridadCaja(chrPtrArgumentos[0],
				 getenv("IdCaja"),
				 &SisReg3LstCCaja);

}
void MenuOrdenElectronica::ColocaSeguridadCaja()
{
	SeguridadControlesCaja();
	AsignaNivelSeguridad();
}
void MenuOrdenElectronica::AsignaNivelSeguridad()
{
QObjectList *lQOLControles;
QObject *lQOControl;
QAction *lQAControl;
SiscomRegistro3 *lSisReg3Control;
lQOLControles=queryList();
for(lQOControl=lQOLControles->first();
    lQOControl;
    lQOControl=lQOLControles->next())
{
SiscomEscribeLog3Qt("%s",lQOControl->name());
if((lSisReg3Control=EstadoControl(lQOControl->name())))
  ((QAction *)lQOControl)->setEnabled(atoi((*lSisReg3Control)["estado"]));
}
}
SiscomRegistro3 *MenuOrdenElectronica::EstadoControl(const char *pchrPtrControl)
{
SiscomRegistro3 *lSisReg3Control;

for(lSisReg3Control=SisReg3LstCCaja.first();
    lSisReg3Control;
    lSisReg3Control=SisReg3LstCCaja.next())
{
  if(!strcmp((*lSisReg3Control)["nombreqt"],pchrPtrControl))
   return lSisReg3Control;
}
return 0;
}
