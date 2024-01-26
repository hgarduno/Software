#include <zSiscomEnvio.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomCampo.h>

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
zSiscomEnvio::zSiscomEnvio()
{

}
zSiscomEnvio::zSiscomEnvio(zSiscomConexion *pzSisConexion,
			   zSiscomRegistros *pzSisRegsEnvio):
			   zSisConexion(pzSisConexion),
			   zSisRegsEnvio(pzSisRegsEnvio)
{
Registros();
}

zSiscomEnvio::zSiscomEnvio(zSiscomConexion *pzSisConexion):
			 zSisConexion(pzSisConexion)
{

}
void zSiscomEnvio::Envio(zSiscomRegistros *pzSisRegistros)
{
   zSisRegsEnvio=pzSisRegistros;
}
void zSiscomEnvio::Registros()
{
zSiscomRegistro *lzSisRegistro;
int lintNRegistros=zSisRegsEnvio->NNodos();
for(lzSisRegistro=zSisRegsEnvio->Primer();
    lzSisRegistro;
    lzSisRegistro=zSisRegsEnvio->Siguiente())
   Registro(lintNRegistros,lzSisRegistro);
Cadena("00000");
}
void zSiscomEnvio::NRegistrosNCampos(int pintNRegistros,
				    zSiscomRegistro *pzSisRegistro)
{
char lchrArrEnvio[11];
sprintf(lchrArrEnvio,
	"%05d%05d",
	pintNRegistros,
	pzSisRegistro->NNodos());
Cadena(lchrArrEnvio);
}
int zSiscomEnvio::TamanoCampo(zSiscomCampo *pzSisCampo)
{
return pzSisCampo->Dato() ? strlen(pzSisCampo->Nombre()) +
 			       strlen((const char *)pzSisCampo->Dato()):
			       strlen(pzSisCampo->Nombre());
}
char *zSiscomEnvio::MemoriaCadenaEnvio(zSiscomCampo *pzSisCampo)
{
char *lchrPtrEnvio;
int lintTamanoEnvio=TamanoCampo(pzSisCampo)+12;
lchrPtrEnvio=(char *)malloc(lintTamanoEnvio);
return lchrPtrEnvio;
}
void zSiscomEnvio::Campo(zSiscomCampo *pzSisCampo)
{
char *lchrPtrCadenaEnvio=MemoriaCadenaEnvio(pzSisCampo);
sprintf(lchrPtrCadenaEnvio,
	"%05d%s%05d%s",
	(int )strlen(pzSisCampo->Nombre()),
	pzSisCampo->Nombre(),
	pzSisCampo->Dato() ? (int )strlen((const char *)pzSisCampo->Dato()) : 0,
	pzSisCampo->Dato() ? (const char *)pzSisCampo->Dato() : "");
Cadena(lchrPtrCadenaEnvio);
free(lchrPtrCadenaEnvio); 
}
void zSiscomEnvio::Registro(int pintNRegistros,
			   zSiscomRegistro *pzSisRegistro)
{
zSiscomCampo *lzSisCampo;
   NRegistrosNCampos(pintNRegistros,pzSisRegistro);
   for(lzSisCampo=pzSisRegistro->Primer();
       lzSisCampo;
       lzSisCampo=pzSisRegistro->Siguiente())
   {
	Campo(lzSisCampo);
	Asociados(lzSisCampo);
   }
}
void zSiscomEnvio::Asociados(zSiscomCampo *pzSisCampo)
{
 if(pzSisCampo->Asociados())
 {
 	Cadena("1");
	RegistrosSinFinal(pzSisCampo->Asociados());
	Cadena("0000000000");
 }
 else
 	Cadena("0");
}
void zSiscomEnvio::RegistrosSinFinal(zSiscomRegistros *pzSisRegistros)
{
zSiscomRegistro *lzSisRegistro;
int lintNRegistros=pzSisRegistros->NNodos();
for(lzSisRegistro=pzSisRegistros->Primer();
    lzSisRegistro;
    lzSisRegistro=pzSisRegistros->Siguiente())
   Registro(lintNRegistros,lzSisRegistro);
}
void zSiscomEnvio::Cadena(const char *pchrPtrCadena)
{
int lintTamano=strlen(pchrPtrCadena);
if((write(zSisConexion->Socket(),pchrPtrCadena,lintTamano)!=lintTamano))
printf("%s",pchrPtrCadena);
else
{
printf("%s",pchrPtrCadena);
fflush(stdout);
}
}
zSiscomConexion *zSiscomEnvio::Conexion()
{
   return zSisConexion;
}
