#include <CQSisObjetosFresno.h>
#include <CQSisPersFresno.h>

CQSisObjetosFresno::CQSisObjetosFresno()
{

}

CQSisPersFresno *CQSisObjetosFresno::Persona(SiscomRegistrosPro2 *pSRegistrosPro2)
{

return new CQSisPersFresno(
		(*pSRegistrosPro2)["nombre"],
		(*pSRegistrosPro2)["apaterno"],
		(*pSRegistrosPro2)["amaterno"],
		(*pSRegistrosPro2)["rfc"],
		(*pSRegistrosPro2)["idpersona"],
		(*pSRegistrosPro2)["tipopersona"],
		(*pSRegistrosPro2)["nmbtipopersona"]);


}
void CQSisObjetosFresno::Personas(SiscomRegistrosPro2 *pSRegistrosPro2,
				  CQSisPersFresnoLst *pCQSPersFresnoL)
{
for(;
    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
    ++(*pSRegistrosPro2))
  (*pCQSPersFresnoL) << Persona(pSRegistrosPro2);

}
void CQSisObjetosFresno::NombreCompleto(
			  CQSisPersFresno *pCQSPersFresno,
			  char *pchrPtrNombre)
{
sprintf(pchrPtrNombre,
	"%s %s %s",
	(*pCQSPersFresno)["Nombre"],
	(*pCQSPersFresno)["APaterno"],
	(*pCQSPersFresno)["AMaterno"]);
}
