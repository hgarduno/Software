#include <SqlValidandoTransferencias.h>
#include <string.h>
#include <stdlib.h>
void SqlExistenciasProductosATransferir(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
char *lchrPtrSql=0;
sprintf(lchrArrSql,
	"select a.* 						\n\
	 from existenciaexpendiobodegas as a	inner join	\n\
	       matriz as b  on a.idexpendio=b.idempresa		\n\
	 where CveProducto in(");
lchrPtrSql=strdup(lchrArrSql);
FormaCondicionBusquedaProductos(pSAgsSiscom,&lchrPtrSql);
SiscomConsultaBaseAsignaArgumento("SqlValidaExistencia",
				   lchrPtrSql,
				   pSAgsSiscom);
SiscomLog("%s",lchrPtrSql);
}

void FormaCondicionBusquedaProductos(SArgsSiscom *pSAgsSiscom,char **pchrPtrCondicion)
{
char lchrArrPaso[128];
int lintContador=0;
LCamposSiscomPro2 *lLCSiscomPro2Regreso=pSAgsSiscom->LCSiscomPro2Dat;
SiscomLog("");
while(lLCSiscomPro2Regreso)
{
SiscomLog("%s",SiscomObtenDato(lLCSiscomPro2Regreso,"CveProducto"));
      if(lLCSiscomPro2Regreso->SCP2PtrSig)
      {
      sprintf(lchrArrPaso,"'%s',",SiscomObtenDato(lLCSiscomPro2Regreso,"CveProducto"));
      (*pchrPtrCondicion)=(char *)realloc(*pchrPtrCondicion,
      					  strlen(*pchrPtrCondicion)+
					  strlen(lchrArrPaso)+1);
	strcat(*pchrPtrCondicion,lchrArrPaso);
       }
       else
       {
         sprintf(lchrArrPaso,"'%s'",SiscomObtenDato(lLCSiscomPro2Regreso,"CveProducto"));
         (*pchrPtrCondicion)=(char *)realloc(*pchrPtrCondicion,
      					  strlen(*pchrPtrCondicion)+
					  strlen(lchrArrPaso)+1);
	 strcat(*pchrPtrCondicion,lchrArrPaso);
       }
lLCSiscomPro2Regreso=lLCSiscomPro2Regreso->SCP2PtrSig;
lintContador++;
}
*pchrPtrCondicion=(char *)realloc(*pchrPtrCondicion,strlen(*pchrPtrCondicion)+25);
strcat(*pchrPtrCondicion,") order by cveproducto;");
}

