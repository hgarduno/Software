#ifndef __CQSISTRAMPOLINCOMUN_H__
#define __CQSISTRAMPOLINCOMUN_H__
#include <SISCOMComunicaciones++.h>
class CQSisError:public SiscomInformacion2
{
public:
	CQSisError(const char *);
private:
	const char *chrPtrMensaje;
private:
	void SiscomAnexaRegistro();
	void SiscomFormaRegistro();
};

class CQSisLstError:public QPtrList<CQSisError>
{
public:
	CQSisLstError();
	CQSisLstError &operator<<(CQSisError *);
};
#endif
