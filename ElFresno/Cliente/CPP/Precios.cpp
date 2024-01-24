#include <Precios.h>
#include <Personas.h>
#include <TiposPrecios.h>
Precio::Precio( const char *pchrPtrIdPrecio, 
	       const char *pchrPtrDescripcion, 
	       const char *pchrPtrPrecio, 
	       TipoPrecio *pTipoPrecio):
		chrPtrIdPrecio(pchrPtrIdPrecio),
		chrPtrDescripcion(pchrPtrDescripcion),
		chrPtrPrecio(pchrPtrPrecio),
		T_TipoPrecio(pTipoPrecio),
		chrPtrEdoRegistro("0")
{


}
void Precio::PonPersona(CQ_Persona *pCQPersona)
{
	CQPPersona=pCQPersona;
}
void Precio::PonDescripcion(const char *pchrPtrDescripcion)
{
	chrPtrDescripcion=pchrPtrDescripcion;
}

void Precio::PonPrecio(const char *pchrPtrPrecio)
{
	chrPtrPrecio=pchrPtrPrecio;
}

void Precio::PonTipoPrecio(TipoPrecio *pTipoPrecio)
{
	T_TipoPrecio=pTipoPrecio;
}

void Precio::PonEdoRegistro(const char *pchrPtrEdoRegistro)
{
	chrPtrEdoRegistro=pchrPtrEdoRegistro;
}
CQ_Persona *Precio::ObtenPersona()
{
	return CQPPersona;
}
const char *Precio::ObtenIdPrecio()
{
	return chrPtrIdPrecio;
}
const char *Precio::ObtenDescripcion()
{
	return chrPtrDescripcion;
}
const char *Precio::ObtenPrecio()
{
	return chrPtrPrecio;
}
TipoPrecio *Precio::ObtenTipoPrecio()
{
	return T_TipoPrecio;
}
const char *Precio::ObtenEdoRegistro()
{
	return chrPtrEdoRegistro;
}
CQPrecios::CQPrecios()
{

}
void CQPrecios::PonClave(const char *pchrPtrClave)
{
	chrPtrClave=pchrPtrClave;
}
CQCtrPrecios::CQCtrPrecios(CSISCOMDatComunicaciones *pCSisDatCom,
			   QStringList pQSLRegistro,
			   CQPrecios *pCQPrecios):
		CSisDatCom(pCSisDatCom)
{

	OperacionesPrecios(pQSLRegistro,pCQPrecios);
	AnalizaRespuesta(pCQPrecios);	

}
CQCtrPrecios::CQCtrPrecios(CSISCOMDatComunicaciones *pCSisDatCom,
			   CQCtrPrecios::CtrPrecios pCQCOperacion,
			   const char *pchrPtrProducto,
			   CQPrecios *pCQPrecios):
		CSisDatCom(pCSisDatCom),
		intNumParametrosRegPrecios(8),
		chrPtrParametrosRegPrecios("%s%s%s%s%s%s%s%s")
{
	switch(pCQCOperacion)
	{
	   case CQCtrPrecios::Registrar:
		   	RegistraLosPrecios(pchrPtrProducto,pCQPrecios);
	   break;
	}
}
void CQCtrPrecios::RegistraLosPrecios(const char *pchrPtrProducto,
					CQPrecios *pCQPrecios)
{
Precio *lP_Precio;
	CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
						   intNumParametrosRegPrecios);
	CQOGSvrSiscom->AnexaRegistro(chrPtrParametrosRegPrecios,
				     "RegistraPreciosDelProducto",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "");

	for(lP_Precio=pCQPrecios->first();
	    lP_Precio;
	    lP_Precio=pCQPrecios->next())
	CQOGSvrSiscom->AnexaRegistro(chrPtrParametrosRegPrecios,
				     "",
				     pchrPtrProducto,
				     lP_Precio->ObtenPersona()->ObtenIdPersona(),
				     "0",
				     lP_Precio->ObtenPrecio(),
				     lP_Precio->ObtenTipoPrecio()->ObtenNmbTipoPrecio(),
				     lP_Precio->ObtenEdoRegistro(),
				     lP_Precio->ObtenIdPrecio());

	 CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
         CQOGSvrSiscom->ObtenRespuesta();

}
void CQCtrPrecios::OperacionesPrecios(QStringList pQSLParametros,
				   CQPrecios *pCQPrecios)
{
	CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
						   2);
	CQOGSvrSiscom->AnexaRegistro("%s%s",
				     "OperacionesPrecios",
				     "");

	AnexaParametros(pQSLParametros);
	AnexaPrecios(pCQPrecios);

	 CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
         CQOGSvrSiscom->ObtenRespuesta();
}
void CQCtrPrecios::AnexaParametros(QStringList pQSLArgumentos)
{
int lintContador;
	for(lintContador=0;
	    lintContador<pQSLArgumentos.size();
	    lintContador++)
	CQOGSvrSiscom->AnexaRegistro("%s%s",
				     "",
				     (const char *)pQSLArgumentos[lintContador]);
	
	CQOGSvrSiscom->AnexaRegistro("%s%s",
				     "",
				     "");
}
void CQCtrPrecios::AnexaPrecios(CQPrecios *pCQPrecios)
{

}
void CQCtrPrecios::AnalizaRespuesta(CQPrecios *pCQPrecios)
{
Precio *lP_Precio;
	while(!CQOGSvrSiscom->SiguienteRegistro(QSLRegistro) &&
	       QSLRegistro.count()==12)
	{
	    pCQPrecios->PonClave((const char *)QSLRegistro[1]);
	    lP_Precio=new Precio((const char *)QSLRegistro[3], 
				 "",
				 (const char *)QSLRegistro[4],
				 new TipoPrecio((const char *)QSLRegistro[5],
						"",
						""));
	   lP_Precio->PonPersona(new CQ_Persona((const char *)QSLRegistro[6],
						(const char *)QSLRegistro[7],
						(const char *)QSLRegistro[8],
						(const char *)QSLRegistro[9],
						(const char *)QSLRegistro[10],
						(const char *)QSLRegistro[0]));
	   lP_Precio->PonEdoRegistro("1");
	   pCQPrecios->append(lP_Precio);
	
	}
}





	       
