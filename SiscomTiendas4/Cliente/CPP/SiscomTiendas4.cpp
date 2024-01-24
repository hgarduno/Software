#include <SiscomTiendas4.h>
#include <SiscomCpuInfo3.h>
#include <SiscomDesarrollo3Qt++.h>
#include <Seguridad3Protocolo2.h>
#include <CQSisPerfilUtilizacion.h>
#include <CQSisEmpleados.h>
#include <QSisServidorMensajes.h>
#include <IMP_FirmaSistema.h>
#include <IMP_Pedidos.h>
#include <qmessagebox.h>

#include <dlfcn.h>

SiscomTiendas4::SiscomTiendas4(QWidget *pQWParent,
				 const char *pchrPtrName,
				 WFlags pWFlags):
			SISCOMVentanaPrincipal(pQWParent,pchrPtrName,pWFlags)
{

	CargaBibliotecaNivelesUtilizacion();
	SiscomCargaFlagMultiUsuario();
	setName("SiscomTiendas4Menus");
	SiscomIniciaVentana();
	SiscomEsAutenticaLaClave();
	SiscomEsValidaMacAddress();
	PerfilPrincipal();
	AsignaIdAplicacionModulos(chrPtrIdAplicacion);
	IniciaServidorMensajes();

}
void SiscomTiendas4::IniciaServidorMensajes()
{
/*
 * Queretaro
 * 12 Enero 2010 
 *
 * Esto fue para el prototipo de las gaseras 
	QSSvrMensajes=new QSisServidorMensajes(this,"QSSvrMensajes",5666);

*/

}
void SiscomTiendas4::ObtenDatosComunicacion()
{
const char *lchrPtrPto=getenv("PtoComSvr"),
  	   *lchrPtrDirIp=getenv("DirIpSvr");
printf("ObtenDatosComunicacion\n");
	if(lchrPtrPto &&
	   lchrPtrDirIp)
	PonDatosComunicaciones(atoi(lchrPtrPto),
				lchrPtrDirIp);
	else
	  QMessageBox::information(this,
	  			    "Mensaje Del Sistema",
				    "NO estan definidas las variables\nPtoComSvr,DirIpSvr");

}
/* 
 *
 * Para resolver est parte y poderla integrar al esquema de negocio
 * de escalabilidad, se debera escribir una biblioteca, la cual se
 * remplazara para el tipo de cliente, un cliente, monousuario,
 * contendra una biblioteca vacia, una cliente multiusuario debera
 * cargar el sistema de firmas
 *
 */
void SiscomTiendas4::CargaFirmaUsuario()
{
if(intSistemaMultiUsuario)
{
QFirmaSistema lQFUsuario;
if(!lQFUsuario.OpcionFirma())
exit(0);
else
{
PonDatosComunicaciones(lQFUsuario.ServidorSiscom());
chrPtrIdAplicacion=lQFUsuario.IdAplicacion();
chrPtrIdPerfil=lQFUsuario.IdPerfil();
UsuarioSeguridad3(lQFUsuario.Usuario());
}
}
else
ObtenDatosComunicacion();
}
void SiscomTiendas4::AsignaIdAplicacionModulos(const char *pchrPtrIdAplicacion)
{
 (SISCOMVentanaPrincipal::SiscomArgumentos()).SiscomAsignaDatoArgumento(
 				9,pchrPtrIdAplicacion);
}
const char **SiscomTiendas4::ArgumentosPantalla(const char *pchrPtrPantalla)
{
CQSisParametrosModulo *lCQSPModulo;
	lCQSPModulo=(SISCOMVentanaPrincipal::SiscomArgumentos())[pchrPtrPantalla];
return 	lCQSPModulo->Parametros();

}
void SiscomTiendas4::CargaSistemaSeguridad()
{

SisDatCom=SISCOMVentanaPrincipal::ObtenDatosComunicacion();
Seguridad3Protocolo2 lSeguridad3Prot2(getenv("Aplicacion"),
				      chrPtrIdPerfil,
				      SisDatCom,
				      this);


}
void SiscomTiendas4::AsignaPerfilVentas(const char *pchrPtrPantalla)
{
/*
 * Queretaro
 * 12 Enero 2010
 * Con el cambio a la version de ventas, con soporte SiscomDesarrollo3Qt++
 * se debera analizar que es lo pasara con esta funcionalidad
 * por lo pronto la elimino
 */

/*
const char **lchrPtrArgumentos;
lchrPtrArgumentos=ArgumentosPantalla(pchrPtrPantalla);
lchrPtrArgumentos[5]=(char *)PerfilVentas();
*/
}
void SiscomTiendas4::CargaArgumentos()
{
/*
 * Se debe crear en la clase SISCOMVentanaPrincipal 
 * un objeto que contenga la informacion de los argumentos
 * como una lista, ya que cada modulo, contine una copia 
 * de los argumentos particular, entonces para poder 
 * hacer referencia al grupo de argumentos en particular de una ventana
 * no es posible hacerlo desde el planteamiento actual de la variable 
 * chrPtrArgumentos, ya que esta variable contendra el valor
 * del ultimo modulo que se leyo
 *
 *
 *
 */
/*
AsignaPerfilVentas("QAVentas");
AsignaPerfilVentas("QACaja");
AsignaPerfilVentas("QAOrdenesCaja");
AsignaEmpleado("QACaja");
*/
}
void SiscomTiendas4::AsignaEmpleado(const char *pchrPtrPantalla)
{
const char **lchrPtrArgumentos;
SisUsuarioSeg3 *lSUSeg3Firmado;
lchrPtrArgumentos=ArgumentosPantalla(pchrPtrPantalla);
lSUSeg3Firmado=(SisUsuarioSeg3 *)lchrPtrArgumentos[0];
lchrPtrArgumentos[0]=(char *)new CQSisEmpleado(
					(*lSUSeg3Firmado)["IdPersona"],
					(*lSUSeg3Firmado)["Nombre"],
					(*lSUSeg3Firmado)["APaterno"],
					(*lSUSeg3Firmado)["AMaterno"],
					"",
					"",
					"",
					chrPtrIdPerfil,
					chrPtrIdAplicacion);
}
const char *SiscomTiendas4::ValidaVariableAmbiente(const char *pchrPtrVariable,
						   const char *pchrPtrMensaje)
{
const char *lchrPtrVariable;
if((lchrPtrVariable=getenv(pchrPtrVariable)))
return lchrPtrVariable;
else
{
printf("SiscomTiendas4::ValidaVariableAmbiente::{%s}\n",
	pchrPtrMensaje);
exit(0);
}

}
CQSisPerfilVentas *SiscomTiendas4::PerfilVentas()
{
/*
const char *lchrPtrFuncionUtilizacionVentas;
CQSisPerfilVentas *(*GeneraPerfilVentas)();


lchrPtrFuncionUtilizacionVentas=ValidaVariableAmbiente(
				"FuncionUtilizacionVentas",
				"SiscomTiendas4::PerfilVentas:No se ha definido la variable de ambiente \"FuncionUtilizacionVentas\"\n");

GeneraPerfilVentas=(CQSisPerfilVentas *(*)())FuncionModuloDinamico(lchrPtrFuncionUtilizacionVentas);
return GeneraPerfilVentas();
*/
}
void SiscomTiendas4::PerfilPrincipal()
{
/*
const char *lchrPtrFuncionUtilizacionVentas;
CQSisLstMenu lCQSLMenu=OpcionesMenu();
QAction *lQAMenu;
void (*GeneraPerfilVentas)(void *);


lchrPtrFuncionUtilizacionVentas=ValidaVariableAmbiente(
				"FuncionUtilizacionPrincipal",
				"SiscomTiendas4::PerfilVentas:No se ha definido la variable de ambiente \"FuncionUtilizacionVentas\"\n");

GeneraPerfilVentas=(void (*)(void *))FuncionModuloDinamico(lchrPtrFuncionUtilizacionVentas);
GeneraPerfilVentas((void *)&lCQSLMenu);

*/
}
void SiscomTiendas4::SiscomCargaFlagMultiUsuario()
{
/*
int (*SiscomMultiUsuario)();
SiscomMultiUsuario=(int (*)())FuncionModuloDinamico(
				"SiscomEsSistemaMultiUsuario");
intSistemaMultiUsuario=SiscomMultiUsuario();
*/
intSistemaMultiUsuario=1;
}
void SiscomTiendas4::SiscomEsAutenticaLaClave()
{
SiscomCpuInfo *lSisCpuInfo;
SiscomCpuInfo lSisCpuInfoSistema("/proc/cpuinfo");
SiscomCpuInfo *(*SiscomCpuInfoDatos)();

SiscomCpuInfoDatos=(SiscomCpuInfo *(*)())FuncionModuloDinamico("CpuInfo");

if((lSisCpuInfo=SiscomCpuInfoDatos()))
{
SiscomEscribeLog3Qt("%s",(*lSisCpuInfo)["model name"]);
if(lSisCpuInfoSistema==lSisCpuInfo)
SiscomEscribeLog3Qt("Si es el cpu Valido");
else
{
SiscomEscribeLog3Qt("Cpu Invalido");
exit(0);
}
}
else
SiscomEscribeLog3Qt("No se pudo iniciar la informacion Cpu Info");


SiscomEscribeLog3Qt("Validando El Cpu");

/*
void (*SiscomValidando)(const char *);
SiscomValidando=(void (*)(const char *))FuncionModuloDinamico(
				"SiscomValidaAutenticidad");
SiscomValidando(SiscomCPUInfo());

*/

}
void SiscomTiendas4::SiscomEsValidaMacAddress()
{
/*
void (*SiscomValidando)(const char *);
SiscomValidando=(void (*)(const char *))FuncionModuloDinamico(
				"SiscomValidaMacAddres");
SiscomValidando(SiscomMacAddress());
*/
}
void *SiscomTiendas4::FuncionModuloDinamico(const char *pchrPtrFuncion)
{
void *lvidPtrFuncion;
    if((lvidPtrFuncion=dlsym(vidANivelUtilizacion,pchrPtrFuncion)))
    return lvidPtrFuncion;
    else
    {
	printf("SiscomTiendas4::FuncionModuloDinamico:(dlsym):{%s}\n",
		dlerror());
	exit(0);
    }
}

void SiscomTiendas4::CargaBibliotecaNivelesUtilizacion()
{
const char *lchrPtrModuloUtilizacionVentas;
lchrPtrModuloUtilizacionVentas=ValidaVariableAmbiente(
				"UtilizacionVentas",
				"SiscomTiendas4::PerfilVentas:No se ha definido la variable de ambiente \"UtilizacionVentas\"\n");


  if(!(vidANivelUtilizacion=dlopen(lchrPtrModuloUtilizacionVentas,RTLD_LAZY)))
  {

	printf("SiscomTiendas4::CargaBiblitoecaNivelesUtilizacion:(dlopen):%s\n",
		dlerror());
	exit(0);

  }
}


void SiscomTiendas4::customEvent(QCustomEvent *pQCEvent)
{
QMensajeInterfaz *lQMensaje;
	switch(pQCEvent->type())
	{
	case 68000:
	/*
	 lQMensaje=(QMensajeInterfaz *)pQCEvent;
	 SRegistrosPro2Mensaje=new SiscomRegistrosPro2(
	 				lQMensaje->ObtenNumeroRegistros(),
					lQMensaje->ObtenMensaje());
	*/
	 for(; 
	     !SRegistrosPro2Mensaje->SiscomEsElUltimoRegistro() &&
	     !SRegistrosPro2Mensaje->SiscomEsFinRegistro();
	     ++(*SRegistrosPro2Mensaje))
	  ++(*SRegistrosPro2Mensaje);
	  for(; 
	     !SRegistrosPro2Mensaje->SiscomEsElUltimoRegistro(); 
	     ++(*SRegistrosPro2Mensaje))
	 SRegistrosPro2Mensaje->SiscomColocaPrimerRegistro();
	 QPedido=new QPedidos(SisDatCom,
	 		      (char **)0,
			      SRegistrosPro2Mensaje,
	 		      (QWidget *)ObtenAreaTrabajo(),
			      "QPedido");

	 		      
	break;
	case 68001:
		QMessageBox::information(0,
					 "Aviso Del Sistema",
					 "Registrar a un cliente Nuevo");
	break;
	}
}
