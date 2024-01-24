#include <CQSisJueces.h>
CQSisJuez::CQSisJuez(const char *pchrPtrNombre,
		     const char *pchrPtrAPaterno,
		     const char *pchrPtrAMaterno,
		     const char *pchrPtrIdPersona):
		 CQSisEntrenador(pchrPtrNombre,
		 		 pchrPtrAPaterno,
				 pchrPtrAMaterno,
				 pchrPtrIdPersona)
{


}

CQSisLstJuez::CQSisLstJuez()
{

}
CQSisLstJuez &CQSisLstJuez::operator<<(CQSisJuez *pCQSJuez)
{
	append(pCQSJuez);
	return *this;
}

CQSisOpJuez::CQSisOpJuez(SiscomDatCom *pSisDatCom):
	SiscomOperaciones(pSisDatCom)
{

}

void CQSisOpJuez::InsertaJuez(CQSisJuez *pCQSJuez,
			      SiscomRegistrosPro2 **pSRegistrosPro2)
{

	CQSLJuez << pCQSJuez;
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&CQSLJuez);
	SiscomActualiza2SubRegistros("RegistraJuez",pSRegistrosPro2);


}
