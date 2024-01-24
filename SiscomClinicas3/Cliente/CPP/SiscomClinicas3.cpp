#include <SiscomClinicas3.h>

#include <Seguridad3Protocolo2.h>
#include <IMP_FirmaSistema.h>
#include <qmessagebox.h>

FILE *gPtrFleArchivoLog3Qt;
SiscomClinicas3::SiscomClinicas3(QWidget *pQWParent,
				 const char *pchrPtrName,
				 WFlags pWFlags):
		SISCOMVentanaPrincipal(pQWParent,pchrPtrName,pWFlags),
		intSistemaMultiUsuario(1)
{

	setName("SiscomClinicas3");
	SiscomIniciaVentana();


}


void SiscomClinicas3::CargaFirmaUsuario()
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
void SiscomClinicas3::CargaSistemaSeguridad()
{
SiscomDatCom *lSisDatCom=SISCOMVentanaPrincipal::ObtenDatosComunicacion();
Seguridad3Protocolo2 lSeguridad3Prot2(getenv("Aplicacion"),
                                      chrPtrIdPerfil,
				      lSisDatCom,
				      this);

}
