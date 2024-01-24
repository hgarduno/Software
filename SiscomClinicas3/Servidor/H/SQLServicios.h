#ifndef __SQLSERVICIOS_H__
#define __SQLSERVICIOS_H__
#include <SiscomDesarrollo2.h>


void SQLServicio(SArgsSiscom *pSAgsSiscom);
void SQLGeneraRegistroServicio(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);

void SQLServicioMedico(SArgsSiscom *pSAgsSiscom);
void SQLGeneraRegistroServicioMedico(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);
void SQLServiciosMedicoRegistrados(SArgsSiscom *);


void SQLAnexaPreciosServicio(SArgsSiscom *);
void SQLAnexaPreciosServicioMedico(SArgsSiscom *);


void SQLPerfilServicioMedico(SArgsSiscom *pSAgsSiscom);
void SQLGeneraRegistroPerfilServicioMedico(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);


void SQLRegistroProductoServicio(SArgsSiscom *pSAgsSiscom);
void SQLGeneraRegistroProductoServicio(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);



void SQLRegistroEliminaServiciosMaterial(SArgsSiscom *pSAgsSiscom);
void SQLGeneraRegistroEliminaServicioMaterial(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);


void SQLServiciosRegistrados(SArgsSiscom *);
void SQLMaterialHospitalizado(SArgsSiscom *);
#endif
