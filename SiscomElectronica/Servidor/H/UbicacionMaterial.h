#ifndef __UBICACIONMATERIAL_H__
#define __UBICACIONMATERIAL_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void Estantes(int pintSocket,
                             SiscomRegistroProL *pSiscomRegProLPtrPrim,
                             SiscomRegistroProL *pSiscomRegProLPtrAct);

void UbicacionDeLaDescripcion(int pintSocket,
                             SiscomRegistroProL *pSiscomRegProLPtrPrim,
                             SiscomRegistroProL *pSiscomRegProLPtrAct);
void AsignaCajaProducto(int pintSocket,
                             SiscomRegistroProL *pSiscomRegProLPtrPrim,
                             SiscomRegistroProL *pSiscomRegProLPtrAct);
void CajasMaterial(int pintSocket,
                             SiscomRegistroProL *pSiscomRegProLPtrPrim,
                             SiscomRegistroProL *pSiscomRegProLPtrAct);
void RegistraCajaMaterial(int pintSocket,
                             SiscomRegistroProL *pSiscomRegProLPtrPrim,
                             SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviandoCajasMaterial(SiscomOperaciones *pSiscomOpePtrDato);
int EnviandoRegistroCajaMaterial(SiscomOperaciones *pSiscomOpePtrDato);
int AsignaIdCajaMaterial(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoCajaMaterial(SiscomOperaciones *pSiscomOpePtrDato);
int EnviandoCajaProducto(SiscomOperaciones *pSiscomOpePtrDato);
int EnviandoEstantes(SiscomOperaciones *pSiscomOpePtrDato);

int EstaCaja(SiscomRegistroProL *pSisRegProLPtrProducto);
int EstaEstante(SiscomRegistroProL *pSisRegProLPtrProducto);
int EstaCajaYEstante(SiscomRegistroProL *pSisRegProLPtrProducto);
int EstaCajaPorId(SiscomRegistroProL *pSisRegProLPtrProducto);
int EstaEstantePorId(SiscomRegistroProL *pSisRegProLPtrProducto);
int EstaEstanteYCajaPorId(SiscomRegistroProL *pSisRegProLPtrProducto);

int ElCampoEsValido(const char *pchrPtrCampo,
		    SiscomRegistroProL *pSisRegProLPtrRegistro);
void MuestraProductosPorCaja(const char *pchrPtrArchivo,
			     const char *pchrPtrFuncion,
			     int pintNoLinea,
			     SiscomRegistroProL *pSisRegProLPtrProdPorCaja);

#define LOGProductosPorCaja(pSisRegProLPtrProdPorCaja) \
  MuestraProductosPorCaja(__FILE__,__FUNCTION__,__LINE__,pSisRegProLPtrProdPorCaja);
#endif
