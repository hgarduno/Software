#ifndef __ZCELDACORTE_H__
#define __ZCELDACORTE_H__
#include <zSiscomRegistro.h>


class zCeldaCorte:public zSiscomRegistro
{
public:
	zCeldaCorte(int pintFila,
		    int pintColumna,
		    const char *pchrPtrCampo,
		    const char *pchrPtrValor,
		    const char *pchrPtrColor);

	zCeldaCorte();
	void Campo(const char *pchrPtrCampo);
	void Fila(const char *pchrPtrFila);
	void Columna(const char *pchrPtrColumna);
	void Valor(const char *pchrPtrFila);
	void Editable(const char *pchrPtrEditable);
	void Color(const char *pchrPtrColor);

	const char *Campo();
	const char *Fila();
	const char *Columna();
	int Valor();
	int Editable();
	const char *Color();

	int FilaInt();
	int ColumnaInt();
private:
	int intFila;
	int intColumna;
};

#endif
