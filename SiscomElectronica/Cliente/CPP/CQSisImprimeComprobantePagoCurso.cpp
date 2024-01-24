#include <CQSisImprimeComprobantePagoCurso.h>
#include <SiscomDesarrollo3Qt++.h>
CQSisImprimeComprobantePagoCurso::CQSisImprimeComprobantePagoCurso(
				SiscomRegistro3 *pSisReg3Alumno,
				SiscomRegistro3 *pSisReg3Curso,
				SiscomRegistro3 *pSisReg3Costo)
{

(*this)									<<
new SiscomCampo3("Nombre",(*pSisReg3Alumno)["Nombre"])			<<
new SiscomCampo3("APaterno",(*pSisReg3Alumno)["APaterno"])		<<
new SiscomCampo3("AMaterno",(*pSisReg3Alumno)["AMaterno"])		<<
new SiscomCampo3("Correo",(*pSisReg3Alumno)["Correo"])			<<
new SiscomCampo3("Telefono",ComunicacionTelefonica(pSisReg3Alumno))	<<
new SiscomCampo3("Curso",(*pSisReg3Curso)["curso"])			<<
new SiscomCampo3("Costo",(*pSisReg3Costo)["costo"])			<<
new SiscomCampo3("fecha",(*pSisReg3Alumno)["fecha"])			<<
new SiscomCampo3("HoraInicio",(*pSisReg3Alumno)["horainicio"]);
}
const char *CQSisImprimeComprobantePagoCurso::ComunicacionTelefonica(SiscomRegistro3 *pSisReg3Alumno)
{
   return *((*pSisReg3Alumno)["Celular"]) ? 
   	   (*pSisReg3Alumno)["Celular"] : 
	   (*pSisReg3Alumno)["Telefono"];
}
