#include <CQSisAlumnos.h>
CQSisAlumno::CQSisAlumno(SiscomRegistro3 *pSisReg3Expendio,
			 SiscomRegistro3 *pSisReg3GensAlumno)
{
SiscomAgregaRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaRegistro(0,pSisReg3Expendio);
SiscomAgregaRegistro(1,pSisReg3GensAlumno);
}
CQSisAlumno::CQSisAlumno()
{
SiscomAgregaRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();
}
void CQSisAlumno::Expendio(SiscomRegistro3 *pSisReg3Expendio)
{
   SiscomAgregaRegistro(0,pSisReg3Expendio);
}
void CQSisAlumno::Generales(SiscomRegistro3 *pSisReg3Generales)
{
   SiscomAgregaRegistro(1,pSisReg3Generales);
}
void CQSisAlumno::Telefonos(SiscomRegistro3Lst *pSisReg3Telefonos)
{
   SiscomAgregaRegistros(2,pSisReg3Telefonos);
}
void CQSisAlumno::CorreoElectronico(SiscomRegistro3Lst *pSisReg3LstCorreo)
{
SiscomAgregaRegistros(3,pSisReg3LstCorreo);
}
void CQSisAlumno::Grupo(SiscomRegistro3Lst *pSisReg3LstGrupo)
{
SiscomAgregaRegistros(4,pSisReg3LstGrupo);
}
void CQSisAlumno::Nombre(const char *pchrPtrNombre)
{
  SiscomActualizaCampoSubRegistro(0,1,0,"nombre",pchrPtrNombre);
}
void CQSisAlumno::APaterno(const char *pchrPtrAPaterno)
{
SiscomActualizaCampoSubRegistro(0,1,0,"apaterno",pchrPtrAPaterno);
}
void CQSisAlumno::AMaterno(const char *pchrPtrAMaterno)
{
SiscomActualizaCampoSubRegistro(0,1,0,"amaterno",pchrPtrAMaterno);
}
void CQSisAlumno::Boleta(const char *pchrPtrBoleta)
{
    SiscomActualizaCampoSubRegistro(0,1,0,"boleta",pchrPtrBoleta);
}
void CQSisAlumno::CorreoElectronico(const char *pchrPtrCorreoElectronico)
{
SiscomActualizaCampoSubRegistro(0,3,0,"correo",pchrPtrCorreoElectronico);
}
void CQSisAlumno::Grupo(const char *pchrPtrGrupo)
{
SiscomActualizaCampoSubRegistro(0,4,0,"grupo",pchrPtrGrupo);
}
void CQSisAlumno::Celular(const char *pchrPtrCelular)
{
SiscomActualizaCampoSubRegistro(0,2,0,"telefono",pchrPtrCelular);
}
void CQSisAlumno::TelefonoCasa(const char *pchrPtrTelefonoCasa)
{
SiscomActualizaCampoSubRegistro(0,2,1,"telefono",pchrPtrTelefonoCasa);
}

void CQSisAlumno::Escuela(const char *pchrPtrEscuela)
{
SiscomActualizaCampoSubRegistro(0,0,0,"escuela",pchrPtrEscuela);
}

const char *CQSisAlumno::Boleta()
{
 return CampoRegistroSubGrupo(0,1,0,"boleta");
}

const char *CQSisAlumno::CorreoElectronico()
{
 return CampoRegistroSubGrupo(0,3,0,"correo");
}
const char *CQSisAlumno::Celular()
{
return CampoRegistroSubGrupo(0,2,0,"telefono");
}
const char *CQSisAlumno::TelefonoCasa()
{
return CampoRegistroSubGrupo(0,2,1,"telefono");
}
const char *CQSisAlumno::Escuela()
{
return CampoRegistroSubGrupo(0,1,0,"escuela");
}
const char *CQSisAlumno::Grupo()
{
  return CampoRegistroSubGrupo(0,4,0,"grupo");
}
CQSisOpAlumno::CQSisOpAlumno(SiscomDatCom  *pSisDatCom):
	SiscomOperaciones3(pSisDatCom)
{

}
/*
 * Lunes 22 De Agosto 2011 
 * Faltara actualizar los campos de los datos generales 
 * ahorita al estar trabajando la informacion en un 
 * chorizo lineal, no se usa el manejo de subregistros 
 * ????, no se que quise decir, pero bueno
 *
 */
void CQSisOpAlumno::Alumno(CQSisAlumno *pCQSAlumno)
{
SiscomRegistro4 *lSisReg4Alumno=new SiscomRegistro4;

SiscomEnvia("ObtenDatosAlumno",
	    0,
	    pCQSAlumno,
	    lSisReg4Alumno);
SiscomContenidoRegistro4Log(lSisReg4Alumno);
pCQSAlumno->first();
pCQSAlumno->Telefonos(lSisReg4Alumno->RegistrosSubGrupo(0,1));
pCQSAlumno->Boleta(lSisReg4Alumno->CampoRegistroSubGrupo(0,0,0,"boleta"));
pCQSAlumno->CorreoElectronico(lSisReg4Alumno->RegistrosSubGrupo(0,2));
pCQSAlumno->Grupo(lSisReg4Alumno->RegistrosSubGrupo(0,3));
}
void CQSisOpAlumno::Actualiza(CQSisAlumno *pCQSAlumno)
{
SiscomRegistro4 *lSisReg4Alumno=new SiscomRegistro4;
SiscomEnvia("ActualizaDatosAlumno",
	    0,
	    pCQSAlumno,
	    lSisReg4Alumno);
SiscomContenidoRegistro4Log(lSisReg4Alumno);
}
