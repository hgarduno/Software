#include <SiscomElectronicaMemoriaComun.h>
#include <stdlib.h>

LCamposSiscomPro2 **IniciaMemoriaComun(int pintPtoComAD,
			const char *pchrPtrDirIpSvrAD,
			int *pintPtrTamMemoria)
{
LCamposSiscomPro2 **lLCSiscomPro2Reg;
SiscomLog("Se Cargara la funcion para Iniciar La Memoria Comun");
SiscomLog("Datos Servidor AD:%d,%s",
		  pintPtoComAD,
		  pchrPtrDirIpSvrAD);
/* Para este caso, solo se tendra informacion de los expendios 
 * en la memoria, si se requiriera, mas datos se deberia de iniciar
 * esta variable como una matriz
 */
lLCSiscomPro2Reg=(LCamposSiscomPro2 **)malloc(sizeof(LCamposSiscomPro2 *));
					     
*lLCSiscomPro2Reg=CargaYLeeDatosExpendios(pintPtoComAD,pchrPtrDirIpSvrAD);
*pintPtrTamMemoria=1;
return lLCSiscomPro2Reg;

}
LCamposSiscomPro2 *CargaYLeeDatosExpendios(int pintPtoComAD,
		       const char *pchrPtrDirIpSvrAD)
{
SiscomOperacionesServidor lSOpServidor;
	lSOpServidor.EjecutaProcesoAntes=0;
	SiscomIniciaComunicacionesSrv(pchrPtrDirIpSvrAD,
				      pintPtoComAD,
				      &lSOpServidor);
	SiscomInformacionOperaciones("ConsultaSQL","Consultas",&lSOpServidor);
	SiscomAnexaRegistroPro2(
		&lSOpServidor.LCSiscomPro2EPrim,
		&lSOpServidor.LCSiscomPro2EAct,
		&lSOpServidor.intNRegistros,
		"ConsultaSQL",
		"							\n\
									\n\
select a.idempresa,							\n\
       ptocomad,							\n\
       diripsvrad,							\n\
       basedatos,							\n\
       razonsocial,							\n\
       c.idempresa as matriz						\n\
from expendios as a inner join						\n\
	expendioabierto as d using(idempresa) left outer join		\n\
     empresas as b using(idempresa) left outer join			\n\
     matriz as c using(idempresa)					\n\
order by razonsocial");
	SiscomOperacionesServidores(&lSOpServidor);
	return lSOpServidor.LCSiscomPro2;
}
