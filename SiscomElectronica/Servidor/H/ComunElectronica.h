#ifndef __COMUNELECTRONICA_H__
#define __COMUNELECTRONICA_H__
#include <SiscomDesarrollo2.h>

void ElectronicaComunicacionExpendio(LCamposSiscomPro2 *,
				     int *,
				     char *);


void ElectronicaComunExpendio2(const char *,
				int *,
				char *);

void ConexionNoDisponibleAlExpendio(int pintNRegistros,
				    int pintPuertoAccesoDatos,
				    const char *pchrPtrDirIpAccesoDatos,
				    LCamposSiscomPro2 *pLCSiscomPro2Sqls);

void ElectronicaComunicacionExpendio2(const char *pchrPtrIdExpendio,
				     int *pintPtrPtoCom,
				     char *pchrPtrDirIpSvr,
				     char *pchrPtrBaseDatos);
int InsertandoAlExpendio(int pintNRegistros,
			  LCamposSiscomPro2 *pLCSiscomPro2Expendio,
			  LCamposSiscomPro2 *pLCSiscomPro2SqlAlExpendio,
			  LCamposSiscomPro2 **pLCSiscomPro2EdoExpendioPrim,
			  LCamposSiscomPro2 **pLCSiscomPro2EdoExpendioAct);
void SiscomElectronicaInsertaSistema(SArgsSiscom *pSAgsSiscom,const char *pchrPtrArgumento);

void InsertandoALosExpendios(int pintNRegistros,
			    LCamposSiscomPro2 *pLCSiscomPro2SqlAlExpendio,
			    LCamposSiscomPro2 **pLCSiscomPro2EdoExpendioPrim);


void GenerandoSqlsRegistroProductos(LCamposSiscomPro2 *pLCSiscomPro2,
			     LCamposSiscomPro2 *pLCSiscomPro2Expendios,
			     LCamposSiscomPro2 *pLCSiscomPro2IniTipoPrecio,
			     int pintIdPublicoEnGeneral,
			     int *pintPtrNRegistros,
			     LCamposSiscomPro2 **pLCSiscomSqlPrim,
			     LCamposSiscomPro2 **pLCSiscomSqlAct);

			       
int RegistrandoProductoExpendios(LCamposSiscomPro2 *pLCSiscomPro2,
			     	  LCamposSiscomPro2 *pLCSiscomPro2Expendios,
			     	  LCamposSiscomPro2 *pLCSiscomPro2IniTipoPrecio,
			     	  int pintIdPublicoEnGeneral,
				  LCamposSiscomPro2 **pLCSiscomPro2EdoConExpPrim,
				  LCamposSiscomPro2 **pLCSiscomPro2EdoConExpAct);
#endif
