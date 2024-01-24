#include <SepomexEstados.h>
#include <SepomexMunicipios.h>

FILE *gPtrFleArchivoLog;
int main(int pintArgc,
	 char **pchrPtrArgv)
{
gPtrFleArchivoLog=stdout;
SiscomDatCom lSisDatCom(atoi(pchrPtrArgv[1]),
	      pchrPtrArgv[2]);
SiscomParametrosConsulta lSPConsulta;

lSPConsulta<<new SiscomParametroConsulta("ConsultaEstados");
SepomexOpEstados lSOpEstados(&lSisDatCom,
			     &lSPConsulta);
SepomexEstados lSepEstados;
SepomexEstado *lSepEstado;
SepomexMunicipios lSepMunicipios;
SepomexMunicipio *lSepMunicipio;





	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Probando Sepomex");

	 lSOpEstados.SiscomConsulta("ConsultaSepomex",
	 			    (QPtrList<SiscomInformacion>*)&lSepEstados);
	for(lSepEstado=lSepEstados.first();
	    lSepEstado;
	    lSepEstado=lSepEstados.next())
	  printf("%s\t%s\n",
	  	 lSepEstado->SRegistrosPro2["NumEstado"],
		 lSepEstado->SRegistrosPro2["Estado"]);


lSPConsulta.clear();
	lSPConsulta << 
	new SiscomParametroConsulta("ConsultaMunicipios") <<
	new SiscomParametroConsulta("15");

SepomexOpMunicipios lSOpMunicipios(&lSisDatCom,
				   &lSPConsulta);

	
		lSOpMunicipios.SiscomConsulta("ConsultaSepomex",
					      (QPtrList<SiscomInformacion> *)&lSepMunicipios);

	for(lSepMunicipio=lSepMunicipios.first();
	    lSepMunicipio;
	    lSepMunicipio=lSepMunicipios.next())
	  printf("%s\t%s\n",
	  	 lSepMunicipio->SRegistrosPro2["NumMunicipio"],
		 lSepMunicipio->SRegistrosPro2["Municipio"]);
}
