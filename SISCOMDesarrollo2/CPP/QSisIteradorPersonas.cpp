#include <QSisIteradorPersonas.h>
#include <SISCOMComunicaciones++.h>

QSisListaOperaciones::QSisListaOperaciones()
{

}

QSisListaOperaciones &QSisListaOperaciones::operator<<(QSisIconDatosPersona *pQSisIconDatPersona)
{
	append(pQSisIconDatPersona);
	return *this;
}


QSisListaOperacionesArchivo::QSisListaOperacionesArchivo(const char *pchrPtrArchivo,
							 QIconView *pQIVControl):
					chrPtrArchivo(pchrPtrArchivo),
					QIVControl(pQIVControl)
{

	AbreArchivo();
	CreaLista();

}

void QSisListaOperacionesArchivo::AbreArchivo()
{
	if(!(FlePtrArchivo=fopen(chrPtrArchivo,"r")))
	 perror("QSisListaOperacionesArchivo::fopen");
}
void QSisListaOperacionesArchivo::CreaLista()
{
char lchrArrLinea[256];
char lchrArrBuffer[256];
char **lchrPtrDatos;
	while(!SiscomLeeLineaArchivo(FlePtrArchivo,lchrArrLinea))
	 if(SiscomAnalizaCadenas(lchrArrLinea,'@',lchrArrBuffer,&lchrPtrDatos)==2)
	 	(*this) << new QSisIconDatosPersona(lchrPtrDatos[0],
						    lchrPtrDatos[1],
						    0,
						    QIVControl);
}
