#include <Errores.h>
void EnviaMensajeErrorCliente(const char *pchrPtrFuncion,
			      const char *pchrPtrMensaje,
			      SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim=0,
		  *lLCSiscomPro2Act=0;
int lintNRegistros=0;
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNRegistros,
			"Funcion,	\
			 Error",
			 pchrPtrFuncion,
			 pchrPtrMensaje);
SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
		      lintNRegistros,
		      "Respuesta",
		      lLCSiscomPro2Prim);
SiscomImprimeContenidoProtocolo2("",lLCSiscomPro2Prim);
close(pSAgsSiscom->intSocketCliente);
}
void ErrorDatosPersonalesInvalidos(SArgsSiscom *pSAgsSiscom)
{
EnviaMensajeErrorCliente("SiscomValidaNombreVacio",
			 "Nombre o Apellido Paterno Vacio",
			 pSAgsSiscom);
}
void ErrorPersonaEnNormalizados(SArgsSiscom *pSAgsSiscom)
{
EnviaMensajeErrorCliente("SiscomPersonaEnNormalizados",
			 "Persona Ya Registrada",
			 pSAgsSiscom);
}
void ErrorPasswordDiferente(SArgsSiscom *pSAgsSiscom)
{
EnviaMensajeErrorCliente("SiscomVerificaPassword",
			 "Passwords Diferentes",
			 pSAgsSiscom);

}
void ErrorPasswordVacio(SArgsSiscom *pSAgsSiscom)
{
EnviaMensajeErrorCliente("SiscomPasswordVacio",
			 "Password Vacio",
			 pSAgsSiscom);

}
void ErrorFirmaYaRegistrada(SArgsSiscom *pSAgsSiscom)
{

EnviaMensajeErrorCliente("SiscomFirmaYaRegistrada",
			 "La firma ya esta registrada",
			 pSAgsSiscom);

}
void ManejadorErrores(SArgsSiscom *pSAgsSiscom)
{

pSAgsSiscom->SiscomError[1]=ErrorDatosPersonalesInvalidos;
pSAgsSiscom->SiscomError[2]=ErrorPersonaEnNormalizados;
pSAgsSiscom->SiscomError[3]=ErrorPasswordDiferente;
pSAgsSiscom->SiscomError[4]=ErrorPasswordVacio;
pSAgsSiscom->SiscomError[5]=ErrorFirmaYaRegistrada;

}
