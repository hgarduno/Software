#include <CQSisGimnastas.h>
#include <SISCOMComunicaciones++.h>

CQSisGimnasta::CQSisGimnasta(const char *pchrPtrNombre,
			     const char *pchrPtrAPaterno,
			     const char *pchrPtrAMaterno,
			     const char *pchrPtrIdPersona):
		CQSisEntrenador(pchrPtrNombre,
				pchrPtrAPaterno,
				pchrPtrAMaterno,
				pchrPtrIdPersona)
{

}


CQSisLstGimnasta::CQSisLstGimnasta()
{

}
CQSisLstGimnasta &CQSisLstGimnasta::operator<<(CQSisGimnasta *pCQSGimnasta)
{
	append(pCQSGimnasta);
	return *this;
}

CQSisOpGimnasta::CQSisOpGimnasta(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{

}
void CQSisOpGimnasta::InsertaGimnasta(CQSisGimnasta *pCQSGimnasta,
				      SiscomRegistrosPro2 **pSRegistrosPro2)
{
		CQSLGimnasta << pCQSGimnasta;
		SiscomPonParametrosConsulta((SiscomInformacionLst *)&CQSLGimnasta);
		SiscomActualiza2SubRegistros("RegistraGimnasta",pSRegistrosPro2);
}
