#include <Personas2.h>
CQCtrActualizaPersona::CQCtrActualizaPersona(CSISCOMDatComunicaciones *pCSisDatCom,
					     QStringList pQSLArgumentos,
					     CQ_Personas *pCQPersonas):
			CQPersonas(pCQPersonas),
			SISCOMOperacionesEnvio(pCSisDatCom,
					       pQSLArgumentos,
					       "libRNSistemaElFresno.so",
					       "RNOperacionesElFresno",
					       "OperacionesPersonas2")
{
	SISCOMEjecutaEnvio();
	AnalizaRespuesta();
}
void CQCtrActualizaPersona::AnalizaRespuesta()
{

}
void CQCtrActualizaPersona::SISCOMIniciaRegistroEnvio()
{
	SISCOMRegEnvioDat <<
	        new SISCOMCampoEnvio("Servicio") 		<<
		new SISCOMCampoEnvio("ParametrosOperacion") 	<<
		new SISCOMCampoEnvio("RFC")			<<
		new SISCOMCampoEnvio("Nombre")			<<
		new SISCOMCampoEnvio("APaterno")		<<
		new SISCOMCampoEnvio("AMaterno")		<<
		new SISCOMCampoEnvio("Apodo")			<<
		new SISCOMCampoEnvio("Calle")			<<
		new SISCOMCampoEnvio("Numero")			<<
		new SISCOMCampoEnvio("CP")			<<
		new SISCOMCampoEnvio("Colonia")			<<
		new SISCOMCampoEnvio("Municipio")		<<
		new SISCOMCampoEnvio("Estado")			<<
		new SISCOMCampoEnvio("Referencias")		<<
		new SISCOMCampoEnvio("Telefono")		<<
		new SISCOMCampoEnvio("Correo");
	SISCOMPonRegistroEnvio(SISCOMRegEnvioDat);
}
void CQCtrActualizaPersona::SISCOMRegistrosEnvio()
{
CQ_Persona *lCQPersona=CQPersonas->at(0);
CQ_Apodos lCQApodos=lCQPersona->ObtenApodos();
CQ_Direcciones lCQDirecciones=CQPersonas->at(0)->ObtenDirecciones();
CQ_Direccion *lCQDireccion=lCQDirecciones.at(0);
CQ_Telefonos lCQTelefonos=CQPersonas->at(0)->ObtenTelefonos();
CQ_Telefono *lCQTelefono=lCQTelefonos.at(0);
	  SISCOMRegEnvioDat["RFC"]->PonContenido(lCQPersona->ObtenRFC());
	  SISCOMRegEnvioDat["Nombre"]->PonContenido(lCQPersona->ObtenNombre());
	  SISCOMRegEnvioDat["APaterno"]->PonContenido(lCQPersona->ObtenAPaterno());
	  SISCOMRegEnvioDat["AMaterno"]->PonContenido(lCQPersona->ObtenAMaterno());
	  SISCOMRegEnvioDat["Apodo"]->PonContenido(lCQApodos.at(0)->ObtenApodo());
	  if(lCQDireccion)
	  {
	  SISCOMRegEnvioDat["Calle"]->PonContenido(lCQDireccion->ObtenCalle());
	  SISCOMRegEnvioDat["Numero"]->PonContenido(lCQDireccion->ObtenNumero());
	  SISCOMRegEnvioDat["CP"]->PonContenido(lCQDireccion->ObtenCP());
	  SISCOMRegEnvioDat["Colonia"]->PonContenido(lCQDireccion->ObtenColonia());
	  SISCOMRegEnvioDat["Municipio"]->PonContenido(lCQDireccion->ObtenDelegacion());
	  SISCOMRegEnvioDat["Estado"]->PonContenido(lCQDireccion->ObtenEstado());
	  SISCOMRegEnvioDat["Referencias"]->PonContenido(lCQDireccion->ObtenReferencias());
	  }
	  if(lCQTelefono)
	  SISCOMRegEnvioDat["Telefono"]->PonContenido(lCQTelefono->ObtenTelefono());
	SISCOMAnexaRegistro(SISCOMRegEnvioDat);
	 SISCOMAnexaRegistroVacio();
}

