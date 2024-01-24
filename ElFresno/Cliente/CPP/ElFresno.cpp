#include <ElFresno.h>
#include <Seguridad3Protocolo2.h>
#include <IMP_FirmaSistema.h>

SiscomElFresno::SiscomElFresno(QWidget *pQWParent,
			       const char *pchrPtrName,
			       WFlags pWFlags):
		    SISCOMVentanaPrincipal(pQWParent,pchrPtrName,pWFlags),
		    intSistemaMultiUsuario(1)
{

setName("CfrmPrincipalSistemaTiendas");
SiscomIniciaVentana();

}

void SiscomElFresno::CargaFirmaUsuario()
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

void SiscomElFresno::CargaSistemaSeguridad()
{
SiscomDatCom *lSisDatCom=SISCOMVentanaPrincipal::ObtenDatosComunicacion();
Seguridad3Protocolo2 lSeguridad3Prot2(getenv("Aplicacion"),
                                      chrPtrIdPerfil,
				      lSisDatCom,
				      this);
}
