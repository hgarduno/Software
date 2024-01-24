#ifndef __CQSISNIVEL_H__
#define __CQSISNIVEL_H__
#include <SISCOMComunicaciones++.h>

class CQSisNivel:public SiscomInformacion
{
public:
	CQSisNivel(const char *,
		   const char *,
			 const char *);
	int operator==(CQSisNivel *);
private:
	void SiscomFormaRegistro();
	void SiscomAnexaRegistro();
private:
	const char *chrPtrIdNivel;
	const char *chrPtrNivel;
	const char *chrPtrDescripcion;

};

class CQSisLstNivel:public QPtrList<CQSisNivel>
{
public:
	CQSisLstNivel();
	CQSisLstNivel &operator<<(CQSisNivel *);

};

class CQSisOpNivel:public SiscomOperaciones
{
public:
	CQSisOpNivel(SiscomDatCom *);
	void InsertaCompetencia(CQSisNivel *,SiscomRegistrosPro2 **);
private:
	CQSisLstNivel CQSLClase;
};

#endif
