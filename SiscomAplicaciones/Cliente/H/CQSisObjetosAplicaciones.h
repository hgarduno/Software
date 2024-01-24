#ifndef __CQSISOBJETOSAPLICACIONES_H__
#define __CQSISOBJETOSAPLICACIONES_H__
#include <SISCOMComunicaciones++.h>

class CQSisDireccion;
class CQSisLstDireccion;
class SisMedCom;
class SisLstMedCom;
class CQSisObjetosAplicaciones
{
public:
	CQSisObjetosAplicaciones();
	static CQSisDireccion *Direccion(SiscomRegistrosPro2 *);
	static SisMedCom *MedioComunicacion(SiscomRegistrosPro2 *);
	static void Direcciones(SiscomRegistrosPro2 *,CQSisLstDireccion *);
	static void MediosComunicacion(SiscomRegistrosPro2 *,SisLstMedCom *);


};


#endif
