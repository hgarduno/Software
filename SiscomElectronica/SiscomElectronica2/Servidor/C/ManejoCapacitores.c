#include <ManejoCapacitores.h>
#include <ComunElectronica2.h>
#include <SiscomModuloOperaciones.h>
#include <string.h>
void ManejoCapacitores(char **pchrPtrEntrada,
		       char *pchrPtrSql)
{
SArgsSiscom lSisArgsSiscom;
OpManejoCapacitores lOpManejoCapacitores[]={
			{"CODIGO",ManejoCapacitoresCODIGO},
			{"VALOR",ManejoCapacitoresVALOR},
			{0,0}
			};
SiscomOperaciones2 lSisOpManejoCapacitor;
SiscomLog("Buscando un capacitor (%s)",*(pchrPtrEntrada+1));
ComunicacionExpendio(*(pchrPtrEntrada+4),&lSisArgsSiscom);
ArgumentosManejoCapacitores(&lSisArgsSiscom);
CopiaExpendioAArgumento(*(pchrPtrEntrada+4),&lSisArgsSiscom);
if(OperacionBusquedaCapacitor(*(pchrPtrEntrada+1),
			   &lSisArgsSiscom,
			   lOpManejoCapacitores,
			   &lSisOpManejoCapacitor))
{
 lSisOpManejoCapacitor(&lSisArgsSiscom);
 strcpy(pchrPtrSql,SiscomObtenCampoArgumento("CadenaSql",
 					     "Sql",
					     &lSisArgsSiscom));
 SiscomLog("%s",pchrPtrSql);
}
}

void ManejoCapacitoresCODIGO(SArgsSiscom *pSisArgsSiscom)
{
SiscomLog("Buscando un capacitor por codigo");
SiscomImprimeArgumento("DatosConsulta",pSisArgsSiscom);
}
const char *ObtenValorCapacitor(const char *pchrPtrDatoEntrada,
		char *pchrPtrValor)
{
while(isdigit(*pchrPtrDatoEntrada) || 
      *pchrPtrDatoEntrada=='.')
{
   *pchrPtrValor=*pchrPtrDatoEntrada;
   pchrPtrValor++;
   pchrPtrDatoEntrada++;
}
*pchrPtrValor=0;
return pchrPtrDatoEntrada;
}
void ObtenUnidad(const char *pchrPtrRestoCadena,
		 char *pchrPtrUnidad)
{
SiscomLog("Analizando la unidad:(%s)",pchrPtrRestoCadena);
 *pchrPtrUnidad=*pchrPtrRestoCadena;
 *(pchrPtrUnidad+1)=0;
}
int ObtenValorUnidades(SArgsSiscom *pSAgsSiscom,
		       char *pchrPtrValor,
		       char *pchrPtrUnidad)
{
const char *lchrPtrValor=SiscomObtenCampoArgumento("DatosConsulta","DatoOperacion",pSAgsSiscom);
const char *lchrPtrUnidad;
SiscomLog("Analizando:%s",lchrPtrValor);
lchrPtrUnidad=ObtenValorCapacitor(lchrPtrValor,pchrPtrValor);
ObtenUnidad(lchrPtrUnidad,pchrPtrUnidad);
}
const char *CondicionUnidadesNanos(SArgsSiscom *pSAgsSiscom)
{
char lchrArrRegreso[128];

sprintf(lchrArrRegreso,
	"where n='%s'",
	SiscomObtenCampoArgumento("ValorUnidad",
				  "Valor",
				  pSAgsSiscom));
return strdup(lchrArrRegreso);
}


const char *CondicionUnidadesPicos(SArgsSiscom *pSAgsSiscom)
{
char lchrArrRegreso[128];

sprintf(lchrArrRegreso,
	"where p='%s'",
	SiscomObtenCampoArgumento("ValorUnidad",
				  "Valor",
				  pSAgsSiscom));
return strdup(lchrArrRegreso);
}

const char *CondicionUnidadesMicros(SArgsSiscom *pSAgsSiscom)
{
char lchrArrRegreso[128];

sprintf(lchrArrRegreso,
	"where m='%s'",
	SiscomObtenCampoArgumento("ValorUnidad",
				  "Valor",
				  pSAgsSiscom));
return strdup(lchrArrRegreso);
}
void AsignaValorUnidadAArgumento(const char *pchrPtrValor,
				 const char *pchrPtrUnidad,
				 SArgsSiscom *pSAgsSiscom)
{
SiscomAnexaRegistroArgumento("ValorUnidad",
			     pSAgsSiscom,
			     "Valor,Unidad",
			     pchrPtrValor,
			     pchrPtrUnidad);
}
void FormaCadenaCapacitoresPicos(SArgsSiscom *pSAgsSiscom,
				 char *pchrPtrSql)
{
/*{ sprintf(pchrPtrSql*/
sprintf(pchrPtrSql,
	"SELECT	a.CveProducto,							\n\
		a.DscProducto,							\n\
		a.Unidad,							\n\
		a.IdFamilia,							\n\
		b.NmbUnidad,							\n\
		b.Abreviatura,							\n\
		c.NmbFamilia,							\n\
		e.precio,							\n\
		d.existencia as existencia,					\n\
		'' as eximinima							\n\
	from    productos as a							\n\
		inner join unidades as b using(unidad)				\n\
		inner join familias as c using(idFamilia)			\n\
		inner join existencias as d using(cveproducto)			\n\
		inner join precios as e on (a.cveproducto=e.cveproducto and	\n\
					    nmbtipoprecio='DEFAULT')		\n\
	where a.CveProducto like '%%%sp%%' and					\n\
	      d.idexpendio=%s							\n\
	      order by a.CveProducto",
			SiscomObtenCampoArgumento("ValorUnidad","Valor",pSAgsSiscom),
			SiscomObtenCampoArgumento("Expendio","Expendio",pSAgsSiscom));
/*}*/
}

void FormaCadenaCapacitoresNanos(SArgsSiscom *pSAgsSiscom,
				 char *pchrPtrSql)
{
SiscomPonPrimerRegistroArgumento("SqlCapacitor",pSAgsSiscom);
/*{ sprintf(pchrPtrSql*/
sprintf(pchrPtrSql,
	"SELECT	a.CveProducto,							\n\
		a.DscProducto,							\n\
		a.Unidad,							\n\
		a.IdFamilia,							\n\
		b.NmbUnidad,							\n\
		b.Abreviatura,							\n\
		c.NmbFamilia,							\n\
		e.precio,							\n\
		d.existencia as existencia,					\n\
		'' as eximinima							\n\
	from    productos as a							\n\
		inner join unidades as b using(unidad)				\n\
		inner join familias as c using(idFamilia)			\n\
		inner join existencias as d using(cveproducto)			\n\
		inner join precios as e on (a.cveproducto=e.cveproducto and	\n\
					    nmbtipoprecio='DEFAULT')		\n\
	where a.idfamilia=2  and						\n\
	      d.idexpendio=%s and 						\n\
	      (a.cveproducto like '%%%s%%' or					\n\
	       a.cveproducto like '%%%s%%' or 					\n\
	       a.cveproducto like '%%%s%%') 					\n\
	      order by a.CveProducto",
	      		SiscomObtenCampoArgumento("Expendio","Expendio",pSAgsSiscom),
	      		SiscomObtenCampoArgumento("SqlCapacitor","p",pSAgsSiscom),
	      		SiscomObtenCampoArgumento("SqlCapacitor","m",pSAgsSiscom),
	      		SiscomObtenCampoArgumento("SqlCapacitor","n",pSAgsSiscom));
/*}*/
}

void FormaCadenaCapacitoresMicros(SArgsSiscom *pSAgsSiscom,
				 char *pchrPtrSql)
{
/*{ sprintf(pchrPtrSql*/
sprintf(pchrPtrSql,
	"SELECT	a.CveProducto,							\n\
		a.DscProducto,							\n\
		a.Unidad,							\n\
		a.IdFamilia,							\n\
		b.NmbUnidad,							\n\
		b.Abreviatura,							\n\
		c.NmbFamilia,							\n\
		e.precio,							\n\
		d.existencia as existencia,					\n\
		'' as eximinima							\n\
	from    productos as a							\n\
		inner join unidades as b using(unidad)				\n\
		inner join familias as c using(idFamilia)			\n\
		inner join existencias as d using(cveproducto)			\n\
		inner join precios as e on (a.cveproducto=e.cveproducto and	\n\
					    nmbtipoprecio='DEFAULT')		\n\
	where a.CveProducto like '%%%s%%' and					\n\
	      d.idexpendio=%s							\n\
	      order by a.CveProducto",
			SiscomObtenCampoArgumento("ValorUnidad","Valor",pSAgsSiscom),
			SiscomObtenCampoArgumento("Expendio","Expendio",pSAgsSiscom));
/*}*/
}
void FormaCadenaConsultaProductosCapacitores(SArgsSiscom *pSAgsSiscom)
{
void (*GenerandoCadenaSql[])(SArgsSiscom *pSAgsSiscom,char *)=
		{FormaCadenaCapacitoresMicros,
		 FormaCadenaCapacitoresNanos,
		0,
		FormaCadenaCapacitoresPicos
		};
char lchrArrSqlProductoCapacitores[1024];
int lintIndice;
const char *lchrPtrUnidad;
SiscomImprimeArgumento("SqlCapacitor",pSAgsSiscom);
SiscomImprimeArgumento("ValorUnidad",pSAgsSiscom);
if(ConsultandoCodigoCapacitor(pSAgsSiscom))
{
lchrPtrUnidad=SiscomObtenCampoArgumento("ValorUnidad","Unidad",pSAgsSiscom);
SiscomLog("La Unidad:%s",lchrPtrUnidad);
lintIndice=ObtenIndiceArregloAjustado(lchrPtrUnidad);
SiscomLog("La Unidad(%s) El Indice:%d",lchrPtrUnidad,lintIndice);
SiscomImprimeArgumento("SqlCapacitor",pSAgsSiscom);
GenerandoCadenaSql[lintIndice](pSAgsSiscom,lchrArrSqlProductoCapacitores);
SiscomLog("%s",lchrArrSqlProductoCapacitores);
SqlProductosCapacitores(lchrArrSqlProductoCapacitores,pSAgsSiscom);
SiscomLog("----------------------------------------");
FiltraResultados(pSAgsSiscom);
SiscomLog("----------------------------------------");
}
else
GenerandoCadenaSqlSinCodigoCapacitores(pSAgsSiscom,lchrArrSqlProductoCapacitores);

CopiaCadenaProductosCapacitor(lchrArrSqlProductoCapacitores,pSAgsSiscom);
}
const char *BuscaUnCapacitorPorUnidad(LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
char lchrArrUnidad[128];
char lchrArrCaracter[20];
const char *lchrPtrCveProducto;
while(pLCSiscomPro2Dat)
{
lchrPtrCveProducto=SiscomObtenDato(pLCSiscomPro2Dat,"cveproducto");
SiscomLog("%s",lchrPtrCveProducto);
while(*lchrPtrCveProducto)
{
sprintf(lchrArrCaracter,
	 "%c (%d) (%d) (%c)",
	 *lchrPtrCveProducto,
	 (unsigned )(*lchrPtrCveProducto),
	 -75,
	 -75);
SiscomLog("%s",lchrArrCaracter);
lchrPtrCveProducto++;

}
pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig;
}
/*
while(pLCSiscomPro2Dat)
{
  
pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig;
}
*/
}
void FiltraResultados(SArgsSiscom *pSAgsSiscom)
{
SiscomImprimeArgumento("SqlProductosRes",pSAgsSiscom);
SiscomImprimeArgumento("ValorUnidad",pSAgsSiscom);
SiscomImprimeArgumento("SqlCapacitor",pSAgsSiscom);
BuscaUnCapacitorPorUnidad(SiscomArgumentoOperacionPrim("SqlProductosRes",pSAgsSiscom));
}
void GenerandoCadenaSqlSinCodigoCapacitores(SArgsSiscom *pSAgsSiscom,
					    char *pchrPtrSql)
{
 
/*{ sprintf(pchrPtrSql*/
sprintf(pchrPtrSql,
	"SELECT	a.CveProducto,							\n\
		a.DscProducto,							\n\
		a.Unidad,							\n\
		a.IdFamilia,							\n\
		b.NmbUnidad,							\n\
		b.Abreviatura,							\n\
		c.NmbFamilia,							\n\
		e.precio,							\n\
		d.existencia as existencia,					\n\
		'' as eximinima							\n\
	from    productos as a							\n\
		inner join unidades as b using(unidad)				\n\
		inner join familias as c using(idFamilia)			\n\
		inner join existencias as d using(cveproducto)			\n\
		inner join precios as e on (a.cveproducto=e.cveproducto and	\n\
					    nmbtipoprecio='DEFAULT')		\n\
	where a.CveProducto like '%%%s%%' and					\n\
	      d.idexpendio=%s		  and					\n\
	      a.idfamilia=2							\n\
	      order by a.CveProducto",
			SiscomObtenCampoArgumento("ValorUnidad","Valor",pSAgsSiscom),
			SiscomObtenCampoArgumento("Expendio","Expendio",pSAgsSiscom));
/*}*/
}
int ConsultandoCodigoCapacitor(SArgsSiscom *pSAgsSiscom)
{
int lintNRegistros;
SqlCodigoCapacitor(pSAgsSiscom);
if(!SiscomArgumentosNumeroRegistros("SqlCapacitor",pSAgsSiscom))
{
SiscomLog("No hay registros ...");
return 0;
}
else
return 1;

}
void ManejoCapacitoresVALOR(SArgsSiscom *pSAgsSiscom)
{
char lchrArrValor[25],
     lchrArrUnidad[2];
SiscomImprimeArgumento("DatosConsulta",pSAgsSiscom);
ObtenValorUnidades(pSAgsSiscom,lchrArrValor,lchrArrUnidad);
AsignaValorUnidadAArgumento(lchrArrValor,lchrArrUnidad,pSAgsSiscom);
SiscomLog("Buscando el capacitor de %s %s ",lchrArrValor,lchrArrUnidad);
pSAgsSiscom->Condicion=ObtenCondicionManejoCapacitor(lchrArrUnidad);
SiscomImprimeArgumento("ValorUnidad",pSAgsSiscom);
FormaCadenaConsultaProductosCapacitores(pSAgsSiscom);
}
void PasaAMayusculas(char **pchrPtrCadenas)
{
  while(*pchrPtrCadenas)
  {
    SiscomCambiaMayusculas(*pchrPtrCadenas);
    pchrPtrCadenas++;
  }
}

char *ObtenOperacion(const char *pchrPtrConsulta,
		     char ***pchrPtrCadenas)
{
char lchrArrBuffer[128];
int lintRegreso;
SiscomLog("%s",pchrPtrConsulta);
if((lintRegreso=SiscomAnalizaCadenas(pchrPtrConsulta,
		        ' ',
			lchrArrBuffer,
			pchrPtrCadenas)))
{
PasaAMayusculas(*pchrPtrCadenas);
return *((*pchrPtrCadenas)+1);
}
return 0;
}
int OperacionBusquedaCapacitor(const char *pchrPtrConsulta,
				SArgsSiscom *pSAgsSiscom,
				OpManejoCapacitores *pOpManejoCapacitores,
				SiscomOperaciones2 *pSisOperRegreso)
{
char *lchrPtrOperacion;
char **lchrPtrCadenas;
	lchrPtrOperacion=ObtenOperacion(pchrPtrConsulta,&lchrPtrCadenas);
	CopiaDatosConsultaAArgumentos(lchrPtrCadenas,pSAgsSiscom);
   while(pOpManejoCapacitores->chrPtrOperacion)
   {
	if(!strcmp(pOpManejoCapacitores->chrPtrOperacion,lchrPtrOperacion))
	{
	*pSisOperRegreso=pOpManejoCapacitores->gSiscomOperacion;
	return 1;
	}
	pOpManejoCapacitores++;
   }
  return 0;
}
void CopiaDatosConsultaAArgumentos(char **pchrPtrDatos,
				   SArgsSiscom *pSAgsSiscom)
{
SiscomAnexaRegistroArgumento("DatosConsulta",
			     pSAgsSiscom,
			     "Operacion,DatoOperacion",
			     *(pchrPtrDatos+1),
			     *(pchrPtrDatos+2));
}

void CopiaExpendioAArgumento(const char *pchrPtrExpendio,
			     SArgsSiscom *pSAgsSiscom)
{
SiscomAnexaRegistroArgumento("Expendio",
			     pSAgsSiscom,
			     "Expendio,Vacio",
			     pchrPtrExpendio,
			     "");

}
void CopiaCadenaProductosCapacitor(const char *pchrPtrSql,
				   SArgsSiscom *pSAgsSiscom)
{
SiscomAnexaRegistroArgumento("CadenaSql",
			     pSAgsSiscom,
			     "Sql,Vacio",
			     pchrPtrSql,
			     "");

}
void ArgumentosManejoCapacitores(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(6,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"DatosConsulta",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlCapacitor",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"ValorUnidad",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(3,"CadenaSql",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(4,"Expendio",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(5,"SqlProductosRes",pSAgsSiscom);
}
int ObtenIndiceArregloAjustado(const char *pchrPtrUnidad)
{
return (int )(*pchrPtrUnidad)-77;
}

CondicionManejoCapacitor ObtenCondicionManejoCapacitor(const char *pchrPtrUnidad)
{
typedef struct CondicionesManejoCapacitor
{
 CondicionManejoCapacitor zCondManCap;
}zCondicionesManejoCapacitor;
SiscomLog("La funcion es la %d",ObtenIndiceArregloAjustado(pchrPtrUnidad));
zCondicionesManejoCapacitor lCondManCapacitor[]={CondicionUnidadesMicros, /* 77 M */
						 CondicionUnidadesNanos,  /* 78 N */
						 0, 			  /* 79 O */
						 CondicionUnidadesPicos,  /* 80 P */
						 0};
return lCondManCapacitor[ObtenIndiceArregloAjustado(pchrPtrUnidad)].zCondManCap;	
}
