#ifndef __QSISITERADORPERSONAS_H__
#define __QSISITERADORPERSONAS_H__
#include <qptrlist.h>
#include <stdio.h>
#include <QSisIconDatosPersona.h>

class QSisListaOperaciones:public QPtrList<QSisIconDatosPersona>
{
public:
	QSisListaOperaciones();
	QSisListaOperaciones &operator<<(QSisIconDatosPersona *);
};

class QSisListaOperacionesArchivo:public QSisListaOperaciones
{
public:
	QSisListaOperacionesArchivo(const char *,QIconView *);
private:
	const char *chrPtrArchivo;
	FILE *FlePtrArchivo;
	QIconView *QIVControl;
private:

	void AbreArchivo();
	void CreaLista();
};

#endif
