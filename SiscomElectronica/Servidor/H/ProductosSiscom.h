#ifndef __PRODUCTOSSISCOM_H__
#define __PRODUCTOSSISCOM_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
#include <SiscomDesarrollo4/H/SiscomFuncionesComunes.h>

void ValidandoCompraProductoSiscom(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct);
void IdCompraProductoSiscom(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct);

void ComprandoProductoSiscom(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct);
void GeneraIdentificadorRegistroProductosSiscom(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct);
int EnviaComprandoProductoSiscom(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaIdentificadorCompraSiscom(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoProductoSiscom(SiscomOperaciones *pSiscomOpePtrDato);
int ValidandoExistenciaParaCompraSiscom(SiscomOperaciones *pSiscomOpePtrDato);
char *CondicionExistenciaDefinicionProducto(SiscomRegistroProL *pSiscomRegProLPtrDato);

int NoSeRegistraNoAlcanza(SiscomOperaciones *pSiscomOpePtrDato);
#endif
