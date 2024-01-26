#ifndef __SISCOMADMINISTRACIONSEGURIDAD_H__
#define __SISCOMADMINISTRACIONSEGURIDAD_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void SiscomCargaMenus(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);
int SiscomEnviaMenusSistema(SiscomOperaciones *pSiscomOpePtrDat);
int SiscomValidaUsuarioFirmado(SiscomOperaciones *pSiscomOpePtrDato);
int ERRORUsuarioInvalido(SiscomOperaciones *pSiscomOpePtrDato);

void CreaPopupMenu(SiscomRegistroProL *pSiscomRegProLPtrPopupMenu,
		   SiscomRegistroProL **pSiscomRegProLPtrMenusSistemaPrim,
		   SiscomRegistroProL **pSiscomRegProLPtrMenusSistemaAct);
void AgregaPropiedadesPopupMenu(SiscomRegistroProL *pSiscomRegProLPtrPopupMenu,
				SiscomOperaciones *pSiscomOpePtrDato,
				SiscomRegistroProL *pSiscomRegProLPtrMenusSistemaAct);

void AgregaMenusPopupMenu(SiscomRegistroProL *pSiscomRegProLPtrPopupMenu,
				SiscomOperaciones *pSiscomOpePtrDato,
				SiscomRegistroProL *pSiscomRegProLPtrMenusSistemaAct);
#endif
