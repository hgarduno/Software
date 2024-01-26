#ifndef __SQLSISCOMADMINISTRACIONSEGURIDAD_H__
#define __SQLSISCOMADMINISTRACIONSEGURIDAD_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

int SqlSiscomMenusSistema(SiscomOperaciones *pSiscomOpePtrDat);
int SqlUsuarioSistema(SiscomOperaciones *pSiscomOpePtrDat);
void SqlPopupMenus(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql);
void SqlPopupMenusPropiedades(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql);
void SqlOpcionesPopupMenu(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql);
void SqlMenus(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql);
#endif
