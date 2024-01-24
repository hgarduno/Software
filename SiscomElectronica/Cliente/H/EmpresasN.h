#ifndef __EMPRESASN_H__
#define __EMPRESASN_H__
#include <SISCOMComunicaciones++.h>
#include <qptrlist.h>
#include <Direcciones.h>
#include <MediosComunicacion.h>
#include <Personas.h>
class EmpresaN:public SiscomInformacion
{
public:
	EmpresaN(const char *,
		const char *,
		const char *,
		const char *pchrPtrPtoComAd=0,
		const char *pchrPtrDirIp=0,
		const char *pchrPtrBaseDatos=0);
	const Direcciones &ObtenDirecciones();
	const MediosComunicacion &ObtenMedios();
	const Personas &ObtenContactos();

	void AnexaDireccion(Direccion *);
	void AnexaMedioComunicacion(MedioComunicacion *);
	void AnexaContacto(Persona *);

private:
	Direcciones DDirecciones;
	MediosComunicacion MMedios;
	Personas PContactos;


};

class EmpresasN:public QPtrList<EmpresaN>
{
public:
	EmpresasN();
	EmpresasN &operator<<(EmpresaN *);

};

class ConsultaEmpresasN
{
public:
	ConsultaEmpresasN(SiscomDatCom *,
			 const char *,
			 EmpresasN &);
	ConsultaEmpresasN(SiscomDatCom *);
	EmpresaN *ObtenMatriz();
	const char *EstadoConexion();
private:
	void GeneraEmpresasN(const SiscomComunicaSrv *,EmpresasN &);
private:
	SiscomDatCom *SisDatCom;
	const char *chrPtrEdoConexion;

};
class QRegistroEnvioEmpresa:public SiscomInformacion
{
public:
	QRegistroEnvioEmpresa(EmpresaN *);
private:
	EmpresaN *Empresa;
private:
	void AnexaGenerales();
	void AnexaDirecciones();
	void AnexaContactos();
	void AnexaTelefonos();
	void FormaCamposRegistro();
};
class QRegistrosEnvioEmpresa:public QPtrList<QRegistroEnvioEmpresa>
{
public:
	QRegistrosEnvioEmpresa();
	QRegistrosEnvioEmpresa &operator<<(QRegistroEnvioEmpresa *);
private:
};
class OpEmpresas
{
public:
	OpEmpresas(SiscomDatCom *);
	void RegistraEmpresas(EmpresasN &);
private:
	SiscomDatCom *SisDatCom;
};
#endif
