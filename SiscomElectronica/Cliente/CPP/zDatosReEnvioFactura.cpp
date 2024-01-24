#include <zDatosReEnvioFactura.h>
#include <zSiscomRegistros.h>
#include <zSiscomDesarrollo4.h>
zDatosReEnvioFactura::zDatosReEnvioFactura(zSiscomRegistro *pzSisRegDatReEnvio):
				zSisRegsCorreos(0),
				zSisRegCorreo(0)
{
   *this=(*(zDatosReEnvioFactura *)pzSisRegDatReEnvio);
}

const char *zDatosReEnvioFactura::RFC()
{
  return (const char *)CampoAsociado("Empresa","rfc");
}
const char *zDatosReEnvioFactura::RazonSocial()
{
  return (const char *)CampoAsociado("Empresa","razonsocial");
}

const char *zDatosReEnvioFactura::Correo()
{
    if(IniciaReCorridoCorreos())
    {

    }
    else 
    {
	 if(SiguienteCorreo())
	 {

	 }
	 else
	 return 0;
    }

     return (const char *)zSisRegCorreo->Campo("correo");
}
const char *zDatosReEnvioFactura::Correo(int pintNCorreo)
{
const char *lchrPtrCorreo;
  if((lchrPtrCorreo=(const char *)zSisRegsCorreos->CampoRegistro(pintNCorreo,"correo")))
  {
	return lchrPtrCorreo;	

  }
  else
  return 0;
}
int zDatosReEnvioFactura::IniciaReCorridoCorreos()
{
    if(!zSisRegsCorreos && 
       !zSisRegCorreo) 
    {
	zSisRegsCorreos=AsociadosDelCampo("Correos");
	zSisRegCorreo=zSisRegsCorreos->Primer();
	return 1;
    }
    else
    	return 0;
}
int zDatosReEnvioFactura::SiguienteCorreo()
{
     if((zSisRegCorreo=zSisRegsCorreos->Siguiente()))
     return 1;
     else
     return 0; 
return 0;
}

void zDatosReEnvioFactura::Inicia()
{
    zSisRegsCorreos=0;
    zSisRegCorreo=0;
}
