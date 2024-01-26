#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomCampo.h>
#include <zSiscomFechaHora.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnvio.h>
#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>
#include <stdio.h>
FILE *gPtrFleArchivoLog;
void *gzSiscomConexion;

void ProbandoDuplicar(zSiscomRegistro *pzSisRegPtrPrueba);

int main(int pintArgc,
	 char **pchrPtrArgv)

{
zSiscomRegistro lzSisRegDato;

gPtrFleArchivoLog=stdout;
lzSisRegDato.Agrega(new zSiscomCampo("Nombre",(const unsigned char *)"Heli"));
lzSisRegDato.Agrega(new zSiscomCampo("APaterno",(const unsigned char *)"Garduno"));
lzSisRegDato.Agrega(new zSiscomCampo("AMaterno",(const unsigned char *)"Esquivel"));
lzSisRegDato.Agrega(new zSiscomCampo("Edad",(const unsigned char *)"42"));
lzSisRegDato.Agrega(new zSiscomCampo("Estatura",(const unsigned char *)"1.78"));
lzSisRegDato.Agrega(new zSiscomCampo("FechaNacimiento",(const unsigned char *)"1972/03/20"));
lzSisRegDato.Agrega(new zSiscomCampo("Direcciones"));

lzSisRegDato<<
	new zSiscomCampo("Telefonos") <<
	new zSiscomCampo("Correos");

SiscomRegistroAlLog("Uno","Nada",10,&lzSisRegDato);

SiscomRegistroLog2(&lzSisRegDato);

zSiscomRegistro *lzSisRegistro1,
		*lzSisRegistro2,
		*lzSisRegistro3,
		*lzSisRegistro4;

lzSisRegistro1=new zSiscomRegistro;
lzSisRegistro2=new zSiscomRegistro;
lzSisRegistro3=new zSiscomRegistro;
lzSisRegistro4=new zSiscomRegistro;

zSiscomRegistro *lzSisRegTelefono1=new zSiscomRegistro,
		*lzSisRegTelefono2=new zSiscomRegistro;

(*lzSisRegTelefono1)					<<
	new zSiscomCampo("Telefono",(const unsigned char *)"015558766421") 	<<
	new zSiscomCampo("TipoTelefono",(const unsigned char *)"Casa")		<<
	new zSiscomCampo("Comentario",(const unsigned char *)"Horario de 8:00-20:00");

(*lzSisRegTelefono2)					<<
	new zSiscomCampo("Telefono",(const unsigned char *)"5548777298") 	<<
	new zSiscomCampo("TipoTelefono",(const unsigned char *)"Celular")		<<
	new zSiscomCampo("Comentario",(const unsigned char *)"Cualquier Horario");

(*lzSisRegistro1) 			 		<< 
	new zSiscomCampo("Nombre",(const unsigned char *)"Heli") 		<< 
	new zSiscomCampo("APaterno",(const unsigned char *)"Garduno") 		<<
	new zSiscomCampo("AMaterno",(const unsigned char *)"Esquivel") 		<<
	new zSiscomCampo("Edad",(const unsigned char *)"42")			<<
	new zSiscomCampo("FechaNacimiento",(const unsigned char *)"1972/03/20")	<<
	new zSiscomCampo("Direcciones")			<<
	new zSiscomCampo("Telefonos");

zSiscomRegistros *lzSisRegTelefonos=new zSiscomRegistros;
(*lzSisRegTelefonos)<< lzSisRegTelefono1 << lzSisRegTelefono2;
lzSisRegistro1->AsociadosAlCampo("Telefonos",lzSisRegTelefonos);
				

(*lzSisRegistro2) 			 		<< 
	new zSiscomCampo("Nombre",(const unsigned char *)"Said") 		<< 
	new zSiscomCampo("APaterno",(const unsigned char *)"Garduno") 		<<
	new zSiscomCampo("AMaterno",(const unsigned char *)"Esquivel") 		<<
	new zSiscomCampo("Edad",(const unsigned char *)"41")			<<
	new zSiscomCampo("FechaNacimiento",(const unsigned char *)"1973/03/24")	<<
	new zSiscomCampo("Direcciones")			<<
	new zSiscomCampo("Telefonos");
(*lzSisRegistro3) 			 		<< 
	new zSiscomCampo("Nombre",(const unsigned char *)"Azael") 		<< 
	new zSiscomCampo("APaterno",(const unsigned char *)"Garduno") 		<<
	new zSiscomCampo("AMaterno",(const unsigned char *)"Esquivel") 		<<
	new zSiscomCampo("Edad",(const unsigned char *)"40")			<<
	new zSiscomCampo("FechaNacimiento",(const unsigned char *)"1974/09/20")	<<
	new zSiscomCampo("Direcciones")			<<
	new zSiscomCampo("Telefonos");


(*lzSisRegistro4) 			 		<< 
	new zSiscomCampo("Nombre",(const unsigned char *)"Briseida") 		<< 
	new zSiscomCampo("APaterno",(const unsigned char *)"Garduno") 		<<
	new zSiscomCampo("AMaterno",(const unsigned char *)"Esquivel") 		<<
	new zSiscomCampo("Edad",(const unsigned char *)"39")			<<
	new zSiscomCampo("FechaNacimiento",(const unsigned char *)"1975/12/11")	<<
	new zSiscomCampo("Direcciones")			<<
	new zSiscomCampo("Telefonos");
LogSiscom("El numero de campos : %d ",lzSisRegistro4->NNodos());
zSiscomRegistros lzSisRegistros;
lzSisRegistros << 
	lzSisRegistro1 <<
	lzSisRegistro2 <<
	lzSisRegistro3 <<
	lzSisRegistro4 ;
LogSiscom("Se almacenaron %d Registros",lzSisRegistros.NNodos());
SiscomRegistrosLog(&lzSisRegistros);
LogSiscom("Esta es una prueba Del Log %s %d %f Ahhh y una direccion(%x)",
	  "Cadenitas",
	  20,
	  17.5,
	  lzSisRegistro1);


zSiscomRegistro lzSisRegistroPrueba;
zSiscomRegistro *lzSisRegistroReg;
lzSisRegistroReg=lzSisRegistroPrueba.Registro("%s[Carro] %s[Color] %s[Tamano] %s[Peso]",
					      "Accord",
					      "Azul Tormenta",
					      "Mediano",
					      "1.5Ton");
SiscomRegistroLog2(lzSisRegistroReg);
/*
zSiscomConexion lzSisConexion("127.0.0.1",5645);
zSiscomEnvio lzSisEnvio(&lzSisConexion,&lzSisRegistros);
printf("\n\nAhora la operacion\n");
zSiscomOperaciones lzSisOpPrueba(&lzSisConexion,"libSiscomElectronica.so","Familias");
zSiscomRegistros *lzSisRegRespuesta;
lzSisOpPrueba.Enviando();
lzSisRegRespuesta=lzSisOpPrueba.Respuesta();
LogSiscom("EL numero de Registros:%d",lzSisRegRespuesta->NNodos());
SiscomRegistrosLog(lzSisRegRespuesta);
LogSiscom("El Campo %s",
 	   lzSisRegistro4->Campo("Nombre"));
zSiscomRegistro *lzSisRegistroResp;
for(lzSisRegistroResp=lzSisRegRespuesta->Primer();
    lzSisRegistroResp;
    lzSisRegistroResp=lzSisRegRespuesta->Siguiente())
{
  LogSiscom("%s",lzSisRegistroResp->Campo("clave"));
}
*/
ProbandoDuplicar(lzSisRegistro1);
}
zSiscomRegistros *ReferenciasHeli()
{
zSiscomRegistros *lzSisRegsRegreso=new zSiscomRegistros;
zSiscomRegistro *lzSisRegRefer= new zSiscomRegistro,
		*lzSisRegRefer1=new zSiscomRegistro,
		*lzSisRegRefer2=new zSiscomRegistro;
(*lzSisRegRefer) <<new zSiscomCampo("Referencia",(const unsigned char *)"Entre Francisco Javier Mina y Mariano M");
(*lzSisRegRefer1) <<new zSiscomCampo("Referencia",(const unsigned char *)"Pasando la cancha de basquet");
(*lzSisRegRefer2) <<new zSiscomCampo("Referencia",(const unsigned char *)"antes de llegar a TJ");
(*lzSisRegsRegreso) << lzSisRegRefer << lzSisRegRefer1 << lzSisRegRefer2 ;
return lzSisRegsRegreso;
}
zSiscomRegistro *Direccion(const char *pchrPtrCalle,
			   const char *pchrPtrNumero,
			   const char *pchrPtrColonia,
			   const char *pchrPtrMunicipio,
			   const char *pchrPtrEstado,
			   const char *pchrPtrCP,
			   zSiscomRegistros *pzSisRegsReferencias)
{
zSiscomRegistro *lzSisRegDireccion=new zSiscomRegistro;
(*lzSisRegDireccion) 							<< 
  new zSiscomCampo("Calle",(const unsigned char *)pchrPtrCalle) 	<<
  new zSiscomCampo("Numero",(const unsigned char *)pchrPtrNumero) 	<<
  new zSiscomCampo("Colonia",(const unsigned char *)pchrPtrColonia) 	<<
  new zSiscomCampo("Municipio",(const unsigned char *)pchrPtrMunicipio) <<
  new zSiscomCampo("Estado",(const unsigned char *)pchrPtrEstado) 	<<
  new zSiscomCampo("CP",(const unsigned char *)pchrPtrCP)		<<
  new zSiscomCampo("Referencias",pzSisRegsReferencias);
  return lzSisRegDireccion;
}
zSiscomRegistros *Direcciones()
{
zSiscomRegistros *lzSisRegsDirecciones=new zSiscomRegistros;
   (*lzSisRegsDirecciones) << 
   Direccion("Eva Samano De Lopez Mateos",
             "28",
	     "Bo Tlacateco",
	     "Tepotzotlan",
	     "Mexico","54605",ReferenciasHeli()) <<
   Direccion("Av IPN",
             "2085",
	     "San Pedro Zacatenco",
	     "Gustavo A Madero",
	     "CDMX",
	     "07360",
	     ReferenciasHeli());;
return lzSisRegsDirecciones;
}
void MuestraDatos(zSiscomRegistro *pzSisRegistro)
{
zSiscomRegistro *lzSisRegistro;
SiscomRegistroLog2(pzSisRegistro);
SiscomRegistrosLog(pzSisRegistro->AsociadosDelCampo("Telefonos"));
for(lzSisRegistro=pzSisRegistro->AsociadosDelCampo("Direcciones")->Primer();
    lzSisRegistro;
    lzSisRegistro=pzSisRegistro->AsociadosDelCampo("Direcciones")->Siguiente())
{
   SiscomRegistroLog2(lzSisRegistro);
    SiscomRegistrosLog(lzSisRegistro->AsociadosDelCampo("Referencias"));
}
}
void ProbandoDuplicar(zSiscomRegistro *pzSisRegPtrPrueba)
{
zSiscomRegistro *lzSisRegPtrDuplicado;
LogSiscom("*********************** Iniciando la duplicada *****************");
pzSisRegPtrPrueba->AsociadosAlCampo("Direcciones",Direcciones());
MuestraDatos(pzSisRegPtrPrueba);
delete pzSisRegPtrPrueba;
lzSisRegPtrDuplicado=pzSisRegPtrPrueba->Duplica();
LogSiscom("******************************* Duplicados *******************");
MuestraDatos(lzSisRegPtrDuplicado);
}
