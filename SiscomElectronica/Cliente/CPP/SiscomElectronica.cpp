#include <SiscomDesarrollo3Qt++.h>
#include <SiscomRegistros3.h>
#include <SiscomElectronica.h>
#include <Seguridad3Protocolo2.h>

#include <CQSisSeguridadCajaVentas.h>
#include <stdlib.h>


#include <IMP_ExpendiosSE.h> 

#include <qobjectlist.h>
#include <qevent.h>
#include <qworkspace.h>
#include <qapplication.h>
#include <EmpresasN.h>
#include <Personas.h>

#include <IMP_FirmaTiendas.h>
/* Queretaro a 4 de diciembre del 2015 
 * se cambia la ventana de acceso, para 
 * ordenar mejor los iconos de los servidores
 */
#include <IMP_AccesoSiscomElectronica.h>

#include <qpopupmenu.h>

#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h> 

void *gzSiscomConexion;
SiscomElectronica::SiscomElectronica(zManejadorEjecucion *pzMnEjecucion,
			             QApplication *pQAppPrincipal):
			 SiscomVentanaPrincipal(pQAppPrincipal),
			 zMnEjecucion(pzMnEjecucion),
			 QAppPrincipal(pQAppPrincipal)
{
IniciaVariables();
setName("SISCOMVentanaPrincipal");
SiscomIniciaVentana();
ColocaEncabezado();
Redimensiona();
}
SiscomRegistro3 *SiscomElectronica::ExpendioRegistro3()
{
SiscomRegistro3 *lSisReg3Expendio=new SiscomRegistro3;
(*lSisReg3Expendio) 						<< 
new SiscomCampo3("IdExpendio",(*Expendio)["IdEmpresa"]) 	<<
new SiscomCampo3("RazonSocial",(*Expendio)["RazonSocial"]) 	<<
new SiscomCampo3("DireccionIp","")				<<
new SiscomCampo3("Puerto","");
return lSisReg3Expendio;
}
void SiscomElectronica::AccesoSiscomElectronica()
{
QAccesoSiscomElectronica lQAccSiscomElectronica(PrincipalQt(),this);
char **lchrPtrArgumentos;
if((Empleado=lQAccSiscomElectronica.EmpleadoFirmado()))
{
  SiscomComunicaciones(lQAccSiscomElectronica.Servidor());
  AsignaConexionVersion4(lQAccSiscomElectronica.Servidor());
  Expendio=lQAccSiscomElectronica.ExpendioSeleccionado();
  lchrPtrArgumentos=(char **)malloc(sizeof(char *)*10);
  lchrPtrArgumentos[0]=(char *)(*Expendio)["IdEmpresa"];
  lchrPtrArgumentos[1]=(char *)(*Empleado)["IdPersona"];
  lchrPtrArgumentos[2]=(char *)Expendio;
  lchrPtrArgumentos[3]=(char *)this;
  lchrPtrArgumentos[4]=(char *)(*Empleado)["TipoPersona"];
  lchrPtrArgumentos[5]=(char *)ExpendioRegistro3();
  lchrPtrArgumentos[6]=0;
  lchrPtrArgumentos[7]=0;
  SiscomArgumentos(lchrPtrArgumentos);
}
}
void SiscomElectronica::FirmaAlSistema()
{
char **lchrPtrArgumentos;
QFirmaTiendas lQFTiendas(PrincipalQt(),this);

if((Empleado=lQFTiendas.ObtenEmpleado()))
{
  SiscomComunicaciones(lQFTiendas.ObtenServidor());
  AsignaConexionVersion4(lQFTiendas.ObtenServidor());
  Expendio=lQFTiendas.ObtenExpendio();

  lchrPtrArgumentos=(char **)malloc(sizeof(char *)*10);
  lchrPtrArgumentos[0]=(char *)Expendio->SRegistrosPro2["IdEmpresa"];
  lchrPtrArgumentos[1]=(char *)Empleado->SRegistrosPro2["IdPersona"];
  lchrPtrArgumentos[2]=(char *)Expendio;
  lchrPtrArgumentos[3]=(char *)this;
  lchrPtrArgumentos[4]=(char *)Empleado->SRegistrosPro2["TipoPersona"];
  lchrPtrArgumentos[5]=(char *)ExpendioRegistro3();
  lchrPtrArgumentos[6]=0;
  SiscomArgumentos(lchrPtrArgumentos);
}
else
exit(0);
}
void SiscomElectronica::SiscomIniciaSeguridad()
{
const char *lchrPtrAplicacion=getenv("Aplicacion");
SiscomEscribeLog3Qt("Cargando El Sistema De Seguridad:%s %s",
		  lchrPtrAplicacion,
		  (*Empleado)["TipoPersona"]);
Seguridad3Protocolo2 lSeg3Prot2(lchrPtrAplicacion,
				(*Empleado)["TipoPersona"],
				SiscomComunicaciones(),
				this);
}
Persona *SiscomElectronica::ObtenEmpleado()
{
return Empleado;
}

void SiscomElectronica::ColocaEncabezado()
{
QString lQSEncabezado;
char lchrArrExpendioEmpleado[256];
sprintf(lchrArrExpendioEmpleado,
	"Expendio:%s Atendido Por:%s %s",
	(*Expendio)["RazonSocial"],
	(*Empleado)["Nombre"],
	(*Empleado)["APaterno"]);
lQSEncabezado.sprintf("%s",lchrArrExpendioEmpleado);
setCaption(lQSEncabezado);
}

void SiscomElectronica::closeEvent(QCloseEvent *pQCEvent)
{
/* CDMX a 25 de Julio 2020
 * Viendo el Log del servidor se observa un SigSeg , esta 
 * parte ya no se use desde hace mucho tiempo, se tendra que
 * revisar si , la seguridad en cajas de vuelve a integrar 
CQSisControlesCaja lCQSisContsCaja;
CQSisOpControlCaja lCQSisOCCaja(SiscomComunicaciones());
lCQSisOCCaja.ControlesSeguridadCaja(Expendio->SRegistrosPro2["IdEmpresa"],
                                    getenv("IdCaja"),
				     &lCQSisContsCaja);


if(lCQSisContsCaja.EsVerdaderoEntero("intSePuedeCerrarOrden"))
pQCEvent->accept();
*/
pQCEvent->accept();
}

void SiscomElectronica::SiscomIniciaMenuVentanas()
{
 QPMVentanas=new QPopupMenu(0);
 QPMVentanas->insertItem("Arregla Ventanas",10,10);
 QPMVentanas->insertSeparator();

 SiscomMenuVentanas(QPMVentanas);
}

void SiscomElectronica::SlotCargaModuloAdministracion()
{
SiscomEscribeLog3Qt("Cargando el modulo de adminsitracion");

}

void SiscomElectronica::customEvent(QCustomEvent *pQCEvent)
{
	if(pQCEvent->type()==12345)
	SiscomEscribeLog3Qt("-adfafdafaf-");
}
void SiscomElectronica::AsignaConexionVersion4(SiscomDatCom *pSisDatCom)
{
   gzSiscomConexion=new zSiscomConexion(pSisDatCom->SiscomObtenDireccionIp(),
   					pSisDatCom->SiscomObtenPuertoCom());

}
void SiscomElectronica::SeleccionandoExpendio()
{
QExpendiosSE lQExsSiscom;

}
void SiscomElectronica::MasGrandeLetra()
{
QFont lQFTLetra=this->font();
int lintTamano=lQFTLetra.pointSize();
 lQFTLetra.setPointSize(++lintTamano);
 this->setFont(lQFTLetra);
}
void SiscomElectronica::MasPequenaLetra()
{
QFont lQFTLetra=this->font();
int lintTamano=lQFTLetra.pointSize();
 lQFTLetra.setPointSize(--lintTamano);
 this->setFont(lQFTLetra);
}

void SiscomElectronica::keyPressEvent(QKeyEvent *pQKEvent)
{

	if(pQKEvent->state()==Qt::AltButton)
	{
	  if(pQKEvent->key()==Qt::Key_Tab)
	  {
	    SiscomEscribeLog3Qt("Cambiando de expendio");
	    /*
	    SeleccionandoExpendio();

	    */
	  }

	}
	else
	if(pQKEvent->state()==Qt::ControlButton)
	{
	   if(pQKEvent->key()==Qt::Key_Equal)
	   {
	        MasGrandeLetra(); 
		SiscomEscribeLog3Qt("Mas grande la letra");
	   }
	   else
	  if(pQKEvent->key()==Qt::Key_Minus)
	  {
		SiscomEscribeLog3Qt("Mas chica la letra");
		MasPequenaLetra();
	  }
	}
}
void SiscomElectronica::resizeEvent(QResizeEvent *pQResizeEvent)
{
 /*
   SiscomEscribeLog3Qt("Tamano de la ventana ->> (%d,%d) ",
   			pQResizeEvent->size().width(),
			pQResizeEvent->size().height());

  */
   /*zXYModulos.X("QAModuloVentas",pQResizeEvent->size().width()/2); */
   zXYModulos.X("QAModuloVentas",10);
}

void SiscomElectronica::OrganizaVentanas()
{
QWorkspace *lQWSVentanas;
QWidgetList lQWListVentanas;
QWidget *lQWVentana;
zXY *lzXYModulo;

if((lQWSVentanas=AreaTrabajoSiscom()))
{
lQWListVentanas=lQWSVentanas->windowList();
zXYModulos.Inicia();
for(lQWVentana=lQWListVentanas.first();
    lQWVentana;
    lQWVentana=lQWListVentanas.next())
{
   if((lzXYModulo=zXYModulos.Modulo(lQWVentana->name())))
   {
   PosicionVentana(lQWVentana,lzXYModulo);
   lzXYModulo->Incrementa();
   }
   
}
}
}
void SiscomElectronica::PosicionVentana(QWidget *pQWVentana,zXY *pzXY)
{
pQWVentana->parentWidget()->setGeometry(pzXY->XActual(),
					pzXY->YActual(),
					pQWVentana->size().width(),
					pQWVentana->size().height());
}
/* Tepotzotlan Mexico 
 * Sabado 4 Julio 2020 (en Medio del COVID )
 *
 */
void SiscomElectronica::IniciaVariables()
{
     zXYPedido.X(0);
     zXYPedido.Y(0);
     zXYPedido.Modulo("QAModuloPedido");
     zXYPedido.IncrementoX(45);
     zXYPedido.IncrementoY(20);

     zXYVenta.Modulo("QAModuloVentas");
     zXYVenta.Y(0);
     zXYVenta.IncrementoX(45);
     zXYVenta.IncrementoY(20);

     zXYModulos << zXYPedido;
     zXYModulos << zXYVenta;
}
void SiscomElectronica::Redimensiona()
{
  resize(1000,800);

}
