#include <QSisBibliotecaOpPersonas.h>
QSisBibliotecaOpPersonas::QSisBibliotecaOpPersonas(const char *pchrPtrBiblioteca,
						   const char *pchrPtrFuncion):
				chrPtrBiblioteca(pchrPtrBiblioteca),
				chrPtrFuncion(pchrPtrFuncion)
{



}

QSisBibliotecaOpsPersonas::QSisBibliotecaOpsPersonas()
{


}
QSisBibliotecaOpsPersonas &QSisBibliotecaOpsPersonas::operator<<(QSisBibliotecaOpPersonas *pQSisBibOpPersonas)
{
	append(pQSisBibOpPersonas);
	return *this;
}
