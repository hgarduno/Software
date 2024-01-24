#ifndef __CQSISPERSFRESNO_H__
#define __CQSISPERSFRESNO_H__
#include <SISCOMComunicaciones++.h>

class CQSisPersFresno:public SiscomInformacion
{
public:
	CQSisPersFresno(
		const char *,
		const char *,
		const char *,
		const char *,
		const char *,
		const char *,
		const char *);


};

class CQSisPersFresnoLst:public QPtrList<CQSisPersFresno>
{
public:
	CQSisPersFresnoLst();
	CQSisPersFresnoLst &operator<<(CQSisPersFresno *);

};

class CQSisPersFresnoO:public SiscomOperaciones
{

public:
	CQSisPersFresnoO(SiscomDatCom *);
	void Empleados(CQSisPersFresnoLst *);
	void Borra(CQSisPersFresno *);
private:
	SiscomParametrosConsulta SPConsulta;
};
#endif
