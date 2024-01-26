#include <SqlDirecciones.h>
#include <SiscomDesarrolloMacros.h>

#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <stdio.h>

int SqlRegistraDireccion(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaDireccion",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaDireccion",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToDirecciones);


SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaDireccion",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToDireccionesCliente);
SiscomReplicaMaquinaLocal("SqlInsertaDireccion", lchrArrBuffer, 0, pSiscomOpePtrDat);
}

int SqlActualizaDireccion(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaDireccion",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaDireccion",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateDireccion);

SiscomReplicaMaquinaLocal("SqlInsertaDireccion", lchrArrBuffer, 0, pSiscomOpePtrDat);
}


int SqlRegistraDatosCasa(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaDireccion",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaDireccion",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToDatosCasa);

SiscomReplicaMaquinaLocal("SqlInsertaDireccion", lchrArrBuffer, 0, pSiscomOpePtrDat);
}

void InsertToDirecciones(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
/*
const char *lchrPtrNumeroExterior,
	   *lchrPtrNumeroInterior;

lchrPtrNumeroExterior=SiscomObtenCampoRegistroProLChar("NumExterior",pSiscomRegProLPtrEnt);
lchrPtrNumeroInterior=SiscomObtenCampoRegistroProLChar("NumInterior",pSiscomRegProLPtrEnt);

*/
sprintf(pchrPtrSql,
	"insert into Direcciones values(%s,'%s','%s','%s','%s','%s','%s','%s','%s');",
	 SiscomObtenCampoRegistroProLChar("IdDireccion",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Calle",pSiscomRegProLPtrEnt),
	 SiscomCampoProLCharNulo("NumInterior",pSiscomRegProLPtrEnt),
	 SiscomCampoProLCharNulo("NumExterior",pSiscomRegProLPtrEnt),
	 SiscomCampoProLCharNulo("Colonia",pSiscomRegProLPtrEnt),
	 SiscomCampoProLCharNulo("DelegMunic",pSiscomRegProLPtrEnt),
	 SiscomCampoProLCharNulo("Estado",pSiscomRegProLPtrEnt),
	 SiscomCampoProLCharNulo("CodigoPostal",pSiscomRegProLPtrEnt),
	 SiscomCampoProLCharNulo("Referencias",pSiscomRegProLPtrEnt));
}

void UpdateDireccion(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
const char *lchrPtrNumeroExterior,
	   *lchrPtrNumeroInterior;

lchrPtrNumeroExterior=SiscomObtenCampoRegistroProLChar("NumExterior",pSiscomRegProLPtrEnt);
lchrPtrNumeroInterior=SiscomObtenCampoRegistroProLChar("NumInterior",pSiscomRegProLPtrEnt);

sprintf(pchrPtrSql,
	"update Direcciones set Calle='%s' ,			\n\
			        NumInterior='%s',		\n\
				NumExterior='%s',		\n\
				Colonia='%s',			\n\
				delegmunic='%s',		\n\
				estado='%s',			\n\
				codigopostal='%s',		\n\
				referencias='%s'		\n\
	  where iddireccion=%s ",
	 SiscomObtenCampoRegistroProLChar("Calle",pSiscomRegProLPtrEnt),
	 lchrPtrNumeroInterior ? lchrPtrNumeroInterior : "",
	 lchrPtrNumeroExterior ? lchrPtrNumeroExterior : "",
	 SiscomObtenCampoRegistroProLChar("Colonia",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("DelegMunic",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Estado",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("CodigoPostal",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Referencias",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdDireccion",pSiscomRegProLPtrEnt));
}

void InsertToDireccionesCliente(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DireccionesCliente(idcliente,iddireccion) values(%s,%s);",
	 SiscomObtenCampoRegistroProLChar("IdPersona",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdDireccion",pSiscomRegProLPtrEnt));
}

void InsertToDatosCasa(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DatosCasa values(%s,%s,%s);",
	 SiscomObtenCampoRegistroProLChar("IdDireccion",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdTipoVivienda",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("TiempoResidir",pSiscomRegProLPtrEnt));
}

int SqlDireccionesPersona(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
char lchrArrSql[256];
sprintf(lchrArrSql,
	"select * 				\n\
	 from direccionescliente inner join 	\n\
	      direcciones using(iddireccion) 	\n\
	 where idcliente=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio",
	 				     "IdPersona",
					     pSiscomOpePtrDat));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "DireccionesPersona%",
			      lchrArrSql);

}
