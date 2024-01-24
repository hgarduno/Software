#ifndef __CQSISOBJETOSFRESNO_H__
#define __CQSISOBJETOSFRESNO_H__
#include <SISCOMComunicaciones++.h>
class CQSisPersFresno;
class CQSisPersFresnoLst;
class CQSisObjetosFresno
{
public:
	CQSisObjetosFresno();
	static CQSisPersFresno *Persona(SiscomRegistrosPro2 *);
	static void Personas(SiscomRegistrosPro2 *,CQSisPersFresnoLst *);

	static void NombreCompleto(CQSisPersFresno *,char *);
};

#endif
