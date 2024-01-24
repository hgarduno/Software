#ifndef __QSISBIBLIOTECAOPPERSONAS_H__
#define __QSISBIBLIOTECAOPPERSONAS_H__
#include <qptrlist.h>
class QSisBibliotecaOpPersonas
{
public:
	QSisBibliotecaOpPersonas(const char *,
				 const char *);
private:
	const char *chrPtrBiblioteca;
	const char *chrPtrFuncion;
};

class QSisBibliotecaOpsPersonas:public QPtrList<QSisBibliotecaOpPersonas>
{
public:
	QSisBibliotecaOpsPersonas();
	QSisBibliotecaOpsPersonas &operator<<(QSisBibliotecaOpPersonas *);



};
#endif
