#include <SiscomTiendas41.h>
#include <SiscomDesarrollo3Qt++.h>
#include <IMP_FirmaSistema.h>
#include <SiscomRegistros3.h>
#include <Seguridad3Protocolo2.h>
#include <CQSisEmpleados.h>
#include <stdlib.h>
SiscomTiendas41::SiscomTiendas41(QWidget *pQWParent):
			SiscomVentanaPrincipal(pQWParent)

{
SiscomEscribeLog3Qt("");
setName("SiscomTiendas4Menus");
SiscomIniciaVentana();
}
void SiscomTiendas41::FirmaAlSistema()
{
SiscomEscribeLog3Qt("Cargando ...");
QFirmaSistema lQFUsuario;
if(!lQFUsuario.OpcionFirma())
exit(0);
else
{
SiscomComunicaciones(lQFUsuario.ServidorSiscom());
Argumentos(lQFUsuario.Usuario(),
	   lQFUsuario.IdAplicacion(),
	   lQFUsuario.IdPerfil());

}
}
void SiscomTiendas41::Argumentos(SisUsuarioSeg3 *pSisUsrSeg3,
				  const char *pchrPtrIdAplicacion,
				 const char *pchrPtrIdPerfil)
{
char **lchrPtrArgumentos;
int lintContador;
lchrPtrArgumentos=(char **)malloc(sizeof(char *)*100);
 CQSEmpleado=new CQSisEmpleado((*pSisUsrSeg3)["IdPersona"],
					(*pSisUsrSeg3)["Nombre"],
					(*pSisUsrSeg3)["APaterno"],
					(*pSisUsrSeg3)["AMaterno"],
					"",
					"",
					"",
					pchrPtrIdPerfil,
					pchrPtrIdAplicacion);
lchrPtrArgumentos[0]=(char *)CQSEmpleado;
SiscomEscribeLog3Qt("%s %s %s %s",
		  (*pSisUsrSeg3)["Nombre"],
		  (*pSisUsrSeg3)["APaterno"],
		   pchrPtrIdAplicacion,
		   pchrPtrIdPerfil);
lchrPtrArgumentos[9]=(char *)pchrPtrIdAplicacion;
for(lintContador=10;
    lintContador<100;
    lintContador++)
lchrPtrArgumentos[lintContador]=(char *)malloc(256);
SiscomArgumentos(lchrPtrArgumentos);
}

void SiscomTiendas41::SiscomIniciaSeguridad()
{
SiscomEscribeLog3Qt("Iniciando El sistema de seguridad");
SiscomEscribeLog3Qt("IdPersona:%s",(*CQSEmpleado)["IdPersona"]);
SiscomEscribeLog3Qt("IdAplicacion:%s",(*CQSEmpleado)["IdAplicacion"]);
SiscomEscribeLog3Qt("IdPerfile:%s",(*CQSEmpleado)["IdPerfil"]);
Seguridad3Protocolo2 lSeg3Prot2(SiscomAplicacion(),
				(*CQSEmpleado)["IdPerfil"],
				SiscomComunicaciones(),
				this);
}
