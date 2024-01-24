#ifndef __SQLTRANSFERENCIAS_H__
#define __SQLTRANSFERENCIAS_H__
#include <SiscomDesarrollo2.h>
void SqlTransferencias(SArgsSiscom *pSAgsSiscom);

void SqlInformacionTransferencia(int pintPtoCom,
				   const char *pchrPtrDirIp,
				   const char *pchrPtrIdTransferencia,
				   LCamposSiscomPro2 **pLCSiscomPro2Regreso);
void SqlProductosATransferir(int pintPtoCom,
				   const char *pchrPtrDirIp,
				   const char *pchrPtrIdTransferencia,
				   LCamposSiscomPro2 **pLCSiscomPro2Regreso);


char *SqlInsercionesAlExpendio(LCamposSiscomPro2 *pLCSiscomPro2InfTrans,
			      LCamposSiscomPro2 *pLCSiscomPro2ProdsTrans);

void SqlActualizaTransferenciaExitosa(int pintPuerto,const char *pchrPtrDirIp,const char *pchrPtrIdTransferencia);
#endif
