#ifndef __SISCOMREGISTROS3_H__
#define __SISCOMREGISTROS3_H__
#include <SiscomCampos3.h>
#include <qmemarray.h>

/*! 
 * \brief Almacena la informacion de un registro
 *
 */
class SiscomRegistro3
{
public:
	/*! 
	 * \brief Constructor de la clase
	 */
	SiscomRegistro3();

	SiscomRegistro3(SiscomRegistro3 *);
	~SiscomRegistro3();
	/*!
	 * \brief Se sobre carga el operador para agregar el campo pSCampo3 
	 * \param[in] pSCampo3 Campo que se anexara al registro
	 */
	SiscomRegistro3 &operator << (SiscomCampo3 *pSCampo3);
	/*!
	 * \brief  Se sobre carga el operador, el cual regresara <br>
	 * el contenido del campo pchrPtrNmbCampo.
	 * \param[in] pchrPtrNmbCampo Nombre del campo del cual se desea <br>
	 * Obtener el registro
	 */
	const char *operator[](const char *pchrPtrNmbCampo);
	/*!
	 * \brief  Se sobre carga el operador, el cual regresara <br>
	 * el contenido del campo pintNCampo.
	 * \param[in] pintNCampo Numero del campo del cual se desea <br>
	 * Obtener el registro
	 */
	const char *operator[](int pintNCampo);
	SiscomCampo3 *Campo3(const char *pchrPtrCampo);
	/* Queretaro a 4 de diciembre del 2015
	 * No se porque no se habia agregado una funcion
	 * para manejar los campos a interos, float etc  ....
	 */

	int CampoAInt(const char *pchrPtrCampo);


	/*!
	 * \brief Coloca el apuntador de QPtrList en el primer campo del registro
	 */
	SiscomCampo3 *SiscomColocaPrimerCampo();
	/*!
	 * \brief Mueve el apuntador de QPtrList al siguiente campo
	 */
	SiscomCampo3 *SiscomSiguienteCampo();

	/*!
	 * Agrega los campos de pSisReg3Registro a los campos del registro <br>
	 * actual verificando si existen campos duplicados
	 */
	SiscomRegistro3 &operator+=(SiscomRegistro3 *pSisReg3Registro);
	void SiscomActualizaCampo(const char *pchrPtrNmbCampo,const char *pchrPtrDato);
	SiscomRegistro3 *Registro(const char *,const char *);
	void SiscomObtenCampos(SiscomCampo3Lst *);

	int EsElRegistro(const char *pchrPtrRegistro);
	/*
	 * Copia en la caden pchrPtrRegistro, lo que empezaremos
	 * a trabajar como el nombre del registro que se formara
	 * de concatenar todos los nombres de los campos
	 */
	void Registro(char *pchrPtrRegistro);

	int Campos();

	int EstaElCampo(const char *pchrPtrCampo);	


private:
	SiscomCampo3Lst SCampo3Lst;
private:
	int YaEstaElCampo(SiscomCampo3 *);
};
/*!
 * Manipula una lista de SiscomRegistro3
 */

class SiscomRegistro3Lst:public QPtrList<SiscomRegistro3>
{
public:
	/*!
	 * Constructor
	 */
	SiscomRegistro3Lst();
	~SiscomRegistro3Lst();
	/*!
	 * Agrega pSReg3Dato a la lista
	 * \param[in] pSReg3Dato Dato 
	 */
	SiscomRegistro3Lst &operator<<(SiscomRegistro3 *pSReg3Dato);
	SiscomRegistro3Lst &operator<<(SiscomRegistro3Lst &);
	/*!
	 * Obtiene el elemento pintNRegistro
	 * \param[in] pintNRegistro
	 */
	SiscomRegistro3 *operator[](int pintNRegistro);
	/*!
	 * Obtiene el valor del campo pchrPtrNmbCampo del registro
	 * actual
	 * \param[in] pchrPtrNmbCampo Campo
	 */
	const char *operator[](const char *pchrPtrNmbCampo);
	int operator++();
	/*! 
	 * Se sobre carga el operador, para permitir agregar pSCampo3
	 * al registro actual
	 * \param pSCampo3 Campo que se agregara al registro Actual
	 */
	SiscomRegistro3Lst &operator+=(SiscomCampo3 *pSCampo3);
	void SiscomElimina();
	int operator==(const char *pchrPtrRegistro);

	const SiscomRegistro3Lst &SiscomEliminaRegistros(const QMemArray<int> &pQMARegistros);

};

class SiscomRegistro3LstLst:public QPtrList<SiscomRegistro3Lst>
{
public:
	SiscomRegistro3LstLst();
	/*
	 * Se forma por fuera el nombre del registro, esto es
	 * util cuando se esta leyendo al informacion que llega
	 * del servidor
	 */
	void AgregaRegistro(const char *pchrPtrRegistro,
			    SiscomRegistro3 *pSisReg3Dato);
	/*
	 * Cuando ya se tiene el registro formado y se agregara
	 * a la lista de listas
	 * El nombre del registro se forma de manera interna
	 */
	void AgregaRegistro(SiscomRegistro3 *pSisReg3Dato);
	void SiscomAgregaRegistro(int pintNSubGrupo,SiscomRegistro3 *pSisReg3Dato);
	void ActualizaRegistro(int pintNSubGrupo,
				  int pintRegistro,
				  SiscomRegistro3 *pSisReg3Dato);
	void SiscomAgregaRegistros(int pintNSubGrupo,SiscomRegistro3Lst *);
	SiscomRegistro3Lst *operator[](int pintNGpoRegistro);
	void SiscomAgregaSubRegistro();
private:
};


void SiscomContenidoRegistro3Log(const char *pchrPtrArchivo,
				 const char *pchrPtrFuncion,
				 int pintNLinea,
				 SiscomRegistro3 *pSisReg3Dato);
void SiscomContenidoRegistroLstLog(const char *pchrPtrArchivo,
				   const char *pchrPtrFuncion,
				   int pintNLinea,
				   SiscomRegistro3Lst *pSRegistro3LstDat);
#define SiscomContenidoRegistro3(pSisReg3Registro) \
SiscomContenidoRegistro3Log(__FILE__,__FUNCTION__,__LINE__,pSisReg3Registro);
#define SiscomRegistro3LstContenido(pSRegistro3Lst)	\
SiscomContenidoRegistroLstLog(__FILE__,__FUNCTION__,__LINE__,pSRegistro3Lst);
#endif
