#include <SQLFamilias.h>
void SQLRegistroFamilias(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim,
		  *lLCSiscomPro2Act;
LCamposSiscomPro2 *lLCSiscomPro2Contador;
int lintNRegistros;
char lchrArrSQL[1024];
ObtenInformacionArgumento("Familias",
			  pSAgsSiscom,
			  &lLCSiscomPro2Prim,
			  &lLCSiscomPro2Act,
			  &lintNRegistros);
for(lLCSiscomPro2Contador=pSAgsSiscom->LCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
  sprintf(lchrArrSQL,
  	  "insert into Familia values(%s,'%s','%s');",
	  SiscomObtenDato(lLCSiscomPro2Contador,"IdFamilia"),
	  SiscomObtenDato(lLCSiscomPro2Contador,"Familia"),
	  SiscomObtenDato(lLCSiscomPro2Contador,"Dsc"));
  SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
  			  &lLCSiscomPro2Act,
			  &lintNRegistros,
			  "ComandoSQL,EdoRegistro",
			  lchrArrSQL,"");
}
AsignaInformacionArgumento("Familias",
			   pSAgsSiscom,
			   lLCSiscomPro2Prim,
			   lLCSiscomPro2Act,
			   lintNRegistros);
}
void SQLFamiliasRegistradas(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[1024];

	sprintf(lchrArrSQL,
		"select * from familia order by familia");
	EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}
