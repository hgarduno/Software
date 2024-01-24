#include <CSisDatosSemana.h>
#include <stdlib.h>
CSisDatoHora::CSisDatoHora(const char *pchrPtrHora,
			   const char *pchrPtrImporte,
			   const char *pchrPtrOrdenes):
	chrPtrHora(pchrPtrHora),
	chrPtrImporte(pchrPtrImporte),
	chrPtrOrdenes(pchrPtrOrdenes)
{
	fltImporte=atof(chrPtrImporte);
	fltOrdenes=atof(chrPtrOrdenes);
}

const char *CSisDatoHora::ObtenHora()
{
	return chrPtrHora;
}
const char *CSisDatoHora::ObtenImporteChar()
{
	return chrPtrImporte;
}
float CSisDatoHora::ObtenImporte()
{
	return fltImporte;
}
CSisDatoHoras::CSisDatoHoras()
{

}
CSisDatoHoras &CSisDatoHoras::operator<<(CSisDatoHora *pCSDatoHora)
{
	append(pCSDatoHora);
	return *this;
}
float *CSisDatoHoras::ObtenImportes(int *pintPtrNN)
{
float *lfltPtrDatos=(float *)malloc(sizeof(float)*(*pintPtrNN=count()));
CSisDatoHora *lCSisDtHora;
int lintContador=0;
  for(lCSisDtHora=first();
      lCSisDtHora;
      lCSisDtHora=next())
   lfltPtrDatos[lintContador++]=lCSisDtHora->ObtenImporte();
return lfltPtrDatos;
}
CSisDatoDia::CSisDatoDia(const char *pchrPtrDia,
			 const char *pchrPtrFecha):
	chrPtrDia(pchrPtrDia),
	chrPtrFecha(pchrPtrFecha)
{

}
void CSisDatoDia::AnexaDatoDia(CSisDatoHora *pCSDatHora)
{
	CSDatHoras << pCSDatHora;
}
const char *CSisDatoDia::ObtenDia()
{
	return chrPtrDia;
}
const char *CSisDatoDia::ObtenFecha()
{
	return chrPtrFecha;
}
CSisDatoHoras &CSisDatoDia::ObtenDatosHoras()
{
	return CSDatHoras;
}
void CSisDatoDia::PonImporteDia(const char *pchrPtrImporteDia)
{
	chrPtrImporteDia=pchrPtrImporteDia;
	fltImporteDia=atof(pchrPtrImporteDia);
}
const char *CSisDatoDia::ObtenImporteDiaChar()
{
	return chrPtrImporteDia;
}
float CSisDatoDia::ObtenImporteDia()
{
	return fltImporteDia;
}

CSisDatosDias::CSisDatosDias()
{

}
CSisDatosDias &CSisDatosDias::operator<<(CSisDatoDia *pCSDatDia)
{
	append(pCSDatDia);
	return *this;
}

CSisDatosSemana::CSisDatosSemana(const char *pchrPtrFecha,
		       const char *pchrPtrInicioSemana,
		       const char *pchrPtrFinSemana,
		       const char *pchrPtrNoSemana):
		   chrPtrFecha(pchrPtrFecha),
		   chrPtrInicioSemana(pchrPtrInicioSemana),
		   chrPtrFinSemana(pchrPtrFinSemana),
		   chrPtrNoSemana(pchrPtrNoSemana)
{


}

void CSisDatosSemana::AnexaDia(CSisDatoDia *pCSDatDia)
{
	CSDatosDias << pCSDatDia;
}
void CSisDatosSemana::PonImporteSemana(const char *pchrPtrImporteSemana)
{
	chrPtrImporteSemana=pchrPtrImporteSemana;
}
const char *CSisDatosSemana::ObtenInicioSemana()
{
	return chrPtrInicioSemana;
}
const char *CSisDatosSemana::ObtenFinSemana()
{
	return chrPtrFinSemana;
}
const char *CSisDatosSemana::ObtenImporteSemana()
{
	return chrPtrImporteSemana;
}
CSisDatosDias &CSisDatosSemana::ObtenDias()
{
	return CSDatosDias;
}
CSisDatosSemanas::CSisDatosSemanas()
{

}
CSisDatosSemanas &CSisDatosSemanas::operator<<(CSisDatosSemana *pCSDtsSemana)
{
	append(pCSDtsSemana);
	return *this;

}
