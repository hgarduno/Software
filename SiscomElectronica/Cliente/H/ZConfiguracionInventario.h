#ifndef __ZCONFIGURACIONINVENTARIO_H__
#define __ZCONFIGURACIONINVENTARIO_H__
#include <stdio.h>
#include <zSiscomRegistro.h>

class ZConfiguracionInventario:public zSiscomRegistro
{
public:
	ZConfiguracionInventario(const char *pchrPtrArchivo);

private:
	FILE *FlePtrArchivo;
private:
	void AbreArchivo(const char *);
	void LeeConfiguracion();
	void Campos(const char *);
	void ProcesaLinea(const char *);
	void DatosLinea(const char *,char **,char **);



};


#endif
