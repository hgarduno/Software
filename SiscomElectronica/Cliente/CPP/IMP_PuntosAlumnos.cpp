#include <IMP_PuntosAlumnos.h>
#include <SiscomDesarrollo3Qt++.h>

#include <SiscomRegistros3.h>
#include <QCtrlAlumnos.h>
#include <CQSisPromocionesCliente.h>

#include <qlcdnumber.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qmessagebox.h>
QPuntosAlumnos *InstanciaPuntosAlumnos(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QPuntosAlumnos((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QPuntosAlumnos::QPuntosAlumnos(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				PuntosAlumnos(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QPuntosAlumnos::~QPuntosAlumnos()
{

}

void QPuntosAlumnos::ConectaSlots()
{
connect(QCtrAlumnos,
	SIGNAL(SignalAlumno(SiscomRegistro3 *)),
	SLOT(SlotAlumno(SiscomRegistro3 *)));

connect(QPBValidaPSel,
	SIGNAL(clicked()),
	SLOT(SlotValidaPSeleccion()));
connect(QPBReInicia,
	SIGNAL(clicked()),
	SLOT(SlotReInicia()));
connect(QTDatos,
	SIGNAL(doubleClicked(int,int,int,const QPoint &)),
	SLOT(SlotValidaPSeleccion(int,int,int,const QPoint &)));
connect(QPBTomaPromocion,
	SIGNAL(clicked()),
	SLOT(SlotTomaPromociones()));
		
}
void QPuntosAlumnos::SlotTomaPromociones()
{
SiscomRegistro3Lst lSisReg3LstPromAlumno=CQSMPromociones.Promociones();
CQSisOpPuntosElectronica lCQSOpPElectronica(SisDatCom);
SiscomContenidoRegistro3((SiscomRegistro3 *)chrPtrArgumentos[5]);
SiscomContenidoRegistro3(SisReg3Alumno);
CQSisPromocionesCliente lCQSPromosCliente(
	 		(SiscomRegistro3 *)chrPtrArgumentos[5],
			SisReg3Alumno,
			&lSisReg3LstPromAlumno,
			SisReg4ValidacionPPSel.CampoRegistroSubGrupo(0,0,0,"PuntosPromocion"));

lCQSOpPElectronica.TomaPromociones(&lCQSPromosCliente);
}
void QPuntosAlumnos::SlotValidaPSeleccion(int pintFilas,
					  int,
					  int,
					  const QPoint &)
{
  PromocionSeleccionada(pintFilas);
  if(ValidaPSeleccion())
  {

	MuestraValidacionPSeleccion();
	QCtrAlumnos->setEnabled(false);
  }
  else
  {
	ClienteNoTienePuntosSuficientes(pintFilas);
  }

}
void QPuntosAlumnos::SlotReInicia()
{
	SiscomDesarrollo3Qt::ColoreaFilas(QTDatos,Qt::white);
	CQSMPromociones.ReInicia();
	QPBTomaPromocion->setEnabled(false);
	QCtrAlumnos->setEnabled(true);
	SiscomDesarrollo3Qt::PasaFocoControl(QCtrAlumnos);
}
void QPuntosAlumnos::SlotValidaPSeleccion()
{
PromocionSeleccionada();
if(ValidaPSeleccion())
{
MuestraValidacionPSeleccion();
QCtrAlumnos->setEnabled(false);
}
else
{

}
}
void QPuntosAlumnos::SlotAlumno(SiscomRegistro3 *pSisReg3Alumno)
{
SisReg3Alumno=pSisReg3Alumno;
ConsultandoPuntosPromociones();
SiscomContenidoRegistro3(SisReg3Alumno);
}
void QPuntosAlumnos::IniciaVariables()
{
QCtrAlumnos->Servidor(SisDatCom);
QCtrAlumnos->IdExpendio(chrPtrArgumentos[0]);
QCtrAlumnos->IniciaControl();
SiscomDesarrollo3Qt::PasaFocoControl(QCtrAlumnos);
}

void QPuntosAlumnos::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
void QPuntosAlumnos::ConsultandoPuntosPromociones()
{
ConsultaPuntosPromociones();
MuestraPuntosPromociones();
TienePuntosElCliente();
}
void QPuntosAlumnos::MuestraPromociones()
{
const char *lchrPtrCampos[]={"nombre",
			"descripcion",
			"puntos",
			0};

SiscomDesarrollo3Qt::RegistrosALaTabla(
			lchrPtrCampos,
			QTDatos,
			CQSPPCliente.RegistrosSubGrupo(0,1));
SiscomDesarrollo3Qt::AjustaFilas(QTDatos);
SiscomDesarrollo3Qt::AjustaColumnas(QTDatos);
}
void QPuntosAlumnos::MuestraPuntosCliente()
{
QLCDNPuntos->display(CQSPPCliente.CampoRegistroSubGrupo(0,0,0,"PuntosCliente"));
}
void QPuntosAlumnos::MuestraPuntosPromociones()
{
MuestraPromociones();
MuestraPuntosCliente();
}
void QPuntosAlumnos::ConsultaPuntosPromociones()
{
CQSPPCliente.clear();
CQSisOpPuntosElectronica lCQSOPElectronica(SisDatCom);
lCQSOPElectronica.PuntosPromocionesCliente(
			chrPtrArgumentos[0],
			(*SisReg3Alumno)["idpersona"],
			(*SisReg3Alumno)["nombre"],
			&CQSPPCliente);
}
void QPuntosAlumnos::PromocionSeleccionada(int pintPromocion)
{

if(pintPromocion!=-1)
{
CQSMPromociones.Agrega(PromocionPorNumero(pintPromocion),
			pintPromocion);

}

}
void QPuntosAlumnos::PromocionSeleccionada()
{
SiscomRegistro3Lst *lSisReg3LstPromociones;

int lintContador;
int lintNPromociones=QTDatos->numRows();
for(lintContador=0;
    lintContador<lintNPromociones;
    lintContador++)
if(QTDatos->isRowSelected(lintContador))
     CQSMPromociones.Agrega(PromocionPorNumero(lintContador),
     			    lintContador);


}
int QPuntosAlumnos::ValidaPSeleccion()
{
SiscomRegistro3Lst lSisReg3LstSeleccion;
lSisReg3LstSeleccion=CQSMPromociones.Promociones();
if(EjecutaValidacionPSeleccion(&lSisReg3LstSeleccion))
{
SiscomEscribeLog3Qt("Si es posible la asingacion de promociones");
ActivaTomaPromocion();
MuestraPromocionesSeleccionadas();
return 1;
}
else
{
/*
 * Domingo 14 Agosto del 2011
 * En este punto se realiza la validacion de las promociones 
 * seleccionadas, pero si ya no alcanzaron los puntos que el 
 * cliente tiene, y ejecutamos la toma de validaciones, como
 * se anexo a la lista para la validacion la ultima promocion
 * la enviaremos al tomar las promociones, por tal motivo 
 * debo eliminar la ultima promocion para que solo se consideren
 * las que alcanzan con los puntos del cliente
 *
 */
return 0;
}

MuestraValidacionPSeleccion();
}
void QPuntosAlumnos::MuestraValidacionPSeleccion()
{
QLCDNSaldo->display(SisReg4ValidacionPPSel.CampoRegistroSubGrupo(0,0,0,"SaldoPuntos"));
QLCDNPPSel->display(SisReg4ValidacionPPSel.CampoRegistroSubGrupo(0,0,0,"PuntosPromocion"));
}
int QPuntosAlumnos::EjecutaValidacionPSeleccion(SiscomRegistro3Lst *pSisReg3LstSeleccion)
{
int lintRegreso;
if(pSisReg3LstSeleccion->count())
{
SisReg4ValidacionPPSel.clear();
CQSisOpPuntosElectronica lCQSOPElectronica(SisDatCom);
lCQSOPElectronica.ValidaPuntosPromocionesSel(pSisReg3LstSeleccion,
					     &SisReg4ValidacionPPSel); 
lintRegreso=SisReg4ValidacionPPSel.CampoRegistroSubGrupoInt(0,0,0,"EdoValidacion");
SiscomEscribeLog3Qt("El Numero de subregistros:%d",SisReg4ValidacionPPSel.count());
SiscomRegistro3LstContenido(SisReg4ValidacionPPSel.RegistrosSubGrupo(0,0));
SiscomEscribeLog3Qt("El Regreso:%d",lintRegreso);
return lintRegreso;
}
else
return 0;
}
void QPuntosAlumnos::ActivaTomaPromocion()
{
QPBTomaPromocion->setEnabled(true);
}
void QPuntosAlumnos::MuestraPromocionesSeleccionadas()
{
SiscomDesarrollo3Qt::ColoreaFilasSeleccionadas(QTDatos,
					       Qt::yellow,
					       CQSMPromociones.Filas());
SiscomDesarrollo3Qt::AjustaFilas(QTDatos);
SiscomDesarrollo3Qt::AjustaColumnas(QTDatos);
}
void QPuntosAlumnos::TienePuntosElCliente()
{
CQSMPromociones.FilasMaximas(QTDatos->numRows());
if(CQSPPCliente.SiscomCampoVsCantidad(0,0,0,"PuntosCliente",(float )0))
{
QPBValidaPSel->setEnabled(false);
SiscomDesarrollo3Qt::PasaFocoControl(QCtrAlumnos);
}
else
QPBValidaPSel->setEnabled(true);

}
void QPuntosAlumnos::ClienteNoTienePuntosSuficientes(int pintNFila)
{
SiscomRegistro3 *lSisReg3Promocion=PromocionPorNumero(pintNFila);
SiscomEscribeLog3Qt("No se pudo agregar la promocion:%d",pintNFila);
SiscomContenidoRegistro3(lSisReg3Promocion);
   QMessageBox::information(this,
   			    "Mensaje Del Sistema",
   			    QString().sprintf("No tienes suficientes puntos\n"
			    		      "Para agregar la promocion:%s",
					      (*lSisReg3Promocion)["nombre"]),
			    1);

   CQSMPromociones.Elimina(lSisReg3Promocion,pintNFila);
   
}

SiscomRegistro3 *QPuntosAlumnos::PromocionPorNumero(int pintNPromocion)
{
return CQSPPCliente.RegistroSubGrupo(0,1,pintNPromocion);
}
