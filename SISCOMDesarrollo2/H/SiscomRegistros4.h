#ifndef __SISCOMREGISTROS4_H__
#define __SISCOMREGISTROS4_H__
#include <SiscomRegistros3.h>

class SiscomRegistro4:public QPtrList<SiscomRegistro3LstLst>
{ public:
	SiscomRegistro4();
	/*
	 * Revisar para eliminar 
	 *
	 */
	void AgregaDato(SiscomRegistro3 *pSisReg3Dato);

	void SiscomAgregaRegistro();
	void SiscomAgregaRegistro(int pintNSubGrupo,SiscomRegistro3 *);
	void ActualizaRegistro(int pintNSubGrupo,int pintRegistro,SiscomRegistro3 *);
	void SiscomAgregaRegistro(int pintIndice,int pintNSubGrupo,SiscomRegistro3 *);
	void SiscomAgregaRegistros(int pintSubGrupo,SiscomRegistro3Lst *);
	int SiscomCampoVsCadena(int pintNDato,
				int pintNGrupo,
				int pintNRegistro,
				const char *pchrPtrNmbCampo,
				const char *pchrPtrCadena);
	int SiscomCampoVsCantidad(int pintNDato,
				int pintNGrupo,
				int pintNRegistro,
				const char *pchrPtrNmbCampo,
				float );
	int SiscomCampoVsCantidad(int pintNDato,
				int pintNGrupo,
				int pintNRegistro,
				const char *pchrPtrNmbCampo,
				int );
	SiscomRegistro3LstLst *GrupoRegistros(int pintNGrupo);
	SiscomRegistro3 *RegistroSubGrupo(int pintNDato,
					  int pintNGrupo,
					  int pintNRegistro);
	SiscomRegistro3 *RegistroPrincipal();
	SiscomRegistro3 *RegistroPrincipal(int pintNRegistro);
	const char *CampoRegistroPrincipal(const char *pchrPtrCampo);
	const char *CampoRegistroPrincipal(int pintNRegistro,const char *pchrPtrCampo);
	const char *CampoRegistroSubGrupo(int pintNDato,
					  int pintNGrupo,
					  int pintNRegistro,
					  const char *pchrPtrNmbCampo);

	int CampoRegistroSubGrupoInt(int pintNDato,
					  int pintNGrupo,
					  int pintNRegistro,
					  const char *pchrPtrNmbCampo);
	float CampoRegistroSubGrupoFloat(int pintNDato,
					  int pintNGrupo,
					  int pintNRegistro,
					  const char *pchrPtrNmbCampo);
	SiscomRegistro3Lst *RegistrosSubGrupo(int pintNDato,
					  int pintNGrupo);

	void SiscomAgregaSubRegistro();

	int Registros();
	SiscomRegistro4 &operator<<(SiscomRegistro3 *);
	SiscomRegistro4 &AgregandoRegistro(SiscomRegistro3 *);
	void SiscomActualizaCampoSubRegistro(int pintNDato,
					     int pintNGrupo,
					     int pintNRegistro,
					     const char *pchrPtrNmbCampo,
					     const char *pchrPtrDato);

	void SiscomLimpia();
	/* Viernes 23 de Noviembre 2012
	 * Funcion que elimina todo el grupo de registros, incluyendo 
	 * el registro principal
	 */
	void EliminaGrupoRegistros(int pintGrupo);
	void EliminaGrupoRegistros(int pintNRegistro,int pintGrupo);
	void EliminaRegistroDelGrupo(int pintNRegisro,int pintGrupo,int pintRegistro);
private:
	char chrArrNmbRegistroP[2048];
};
void SiscomContenidoRegistro4(const char *pchrPtrArchivo,
			      const char *pchrPtrFuncion,
			      int pintNLinea,
			      SiscomRegistro4 *pSisReg4Registro);

#define SiscomContenidoRegistro4Log(pSisReg4Registro)			\
SiscomContenidoRegistro4(__FILE__,__FUNCTION__,__LINE__,pSisReg4Registro)
#endif
