#include <SqlImpresion.h>

void SqlInsertaTicketImpreso(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				       "SqlTicketImpreso",
				       SqlInsertandoTicketImpreso);
}


void SqlInsertaTicketImpresoTotal(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				       "SqlTicketImpreso",
				       SqlInsertandoTicketImpresoTotal);
}

void SqlInsertaTicketImpresoHistorial(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				       "SqlTicketImpreso",
				       SqlInsertandoTicketImpresoHistorial);
}
int EsElTotalDeLaOrden(LCamposSiscomPro2 *pLCSiscomPro2Dat)
{

return strcmp(SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"),
	       "TotalOrden");

}
int TicketYaRegistrado(LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
 return SiscomObtenDato(pLCSiscomPro2Dat,"EdoImpresion")[0]=='1';
}
void SqlInsertandoTicketImpreso(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				LCamposSiscomPro2 **pLCSiscomPro2Prim,
				LCamposSiscomPro2 **pLCSiscomPro2Act,
				int *pintPtrNRegistros)
{
char lchrArrSql[256];
char lchrArrFechaHora[25];       
if(EsElTotalDeLaOrden(pLCSiscomPro2Dat))
{
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHora);
if(!TicketYaRegistrado(pLCSiscomPro2Dat))
sprintf(lchrArrSql,
	"insert into TicketImpreso values(%s,%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdCaja"),
	SiscomObtenDato(pLCSiscomPro2Dat,"NoOrden"),
	lchrArrFechaHora);
else
sprintf(lchrArrSql,
	"update TicketImpreso set Fecha='%s' where idventa=%s",
	lchrArrFechaHora,
	SiscomObtenDato(pLCSiscomPro2Dat,"NoOrden"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
                        pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
}

void SqlInsertandoTicketImpresoTotal(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				LCamposSiscomPro2 **pLCSiscomPro2Prim,
				LCamposSiscomPro2 **pLCSiscomPro2Act,
			int *pintPtrNRegistros)
{
char lchrArrSql[256];
if(!EsElTotalDeLaOrden(pLCSiscomPro2Dat))
{
 if(!TicketYaRegistrado(pLCSiscomPro2Dat))
sprintf(lchrArrSql,
	"insert into TicketImpresoTotal values(%s,%s);",
	SiscomObtenDato(pLCSiscomPro2Dat,"NoOrden"),
	SiscomObtenDato(pLCSiscomPro2Dat,"Importe"));
 else
 sprintf(lchrArrSql,
 	"update TicketImpresoTotal set total=%s where idventa=%s",
	SiscomObtenDato(pLCSiscomPro2Dat,"Importe"),
	SiscomObtenDato(pLCSiscomPro2Dat,"NoOrden"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
                        pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
}

void SqlInsertandoTicketImpresoHistorial(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				LCamposSiscomPro2 **pLCSiscomPro2Prim,
				LCamposSiscomPro2 **pLCSiscomPro2Act,
				int *pintPtrNRegistros)
{
char lchrArrSql[256];
char lchrArrFechaHora[25];       
if(EsElTotalDeLaOrden(pLCSiscomPro2Dat))
{
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHora);
sprintf(lchrArrSql,
	"insert into TicketImpresoHistorial values(%s,'%s',%s,'%s',%s,%s);",
	SiscomObtenDato(pLCSiscomPro2Dat,"NoOrden"),
	lchrArrFechaHora,
	SiscomObtenDato(pLCSiscomPro2Dat,"Cantidad"),
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"),
	SiscomObtenDato(pLCSiscomPro2Dat,"Precio"),
	SiscomObtenDato(pLCSiscomPro2Dat,"Importe"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
                        pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
}

void SqlTicketYaRegistrado(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[128];
int lintNRegRegreso=0;
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
LCamposSiscomPro2 *lLCSiscomPro2Dat;
sprintf(lchrArrSql,
	"select *		\n\
	 from ticketImpreso	\n\
	 where idventa=%s",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"NoOrden"));
SiscomLog("%s",lchrArrSql);
SiscomLog("%s %d",pSAgsSiscom->chrArrDirIpAD,pSAgsSiscom->intPtoComAD);
SiscomConsultaBaseSinEnvio(lchrArrSql,
			   pSAgsSiscom,
			   &lintNRegRegreso,
			   &lLCSiscomPro2Reg);

for(lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Dat;
    lLCSiscomPro2Dat;
    lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
if(lintNRegRegreso)
  SiscomAsignaDatoCampo2("EdoImpresion","1",lLCSiscomPro2Dat);
else
  SiscomAsignaDatoCampo2("EdoImpresion","0",lLCSiscomPro2Dat);
}
