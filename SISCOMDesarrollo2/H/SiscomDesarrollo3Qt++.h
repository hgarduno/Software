#ifndef __SISCOMDESARROLLO3QT_H__
#define __SISCOMDESARROLLO3QT_H__
#include <stdio.h>
#include <qstringlist.h>
#include <qcolor.h>
class QLineEdit;
class QComboBox;
class QTextEdit;
class QWidget;
class QTable;
class QTabWidget;
class QFont;

class SiscomRegistro3Lst;
class SiscomRegistro3;
class SiscomCampo3;
class SiscomRegistro4;
/*!
 * \file SiscomDesarrollo3Qt++.h
 * \brief Con el desarrollo de la nueva version de trabajo basada<br>
 * unicamente en Qt, se crea este archivo para escribir las funciones<br>
 * que permitiran gestionar la escritura en el Log, dichas funciones <br>
 * se copiaron del Archivo SiscomFuncionesComunes.c y se agrego al nombre<br>
 * 3Qt, con esto se elimina la dependencia al enlazar los programas y se logra<br>
 * el objetivo de utilizar solo Clases de Qt en la interfaz
 */
/*!
 * \brief Funciones Comunes para manipular operaciones comunes en las interfaces <br>
 * basadas en Qt
 */
class SiscomDesarrollo3Qt
{
public:
	/*!
	 * \brief Constructor de la Clase
	 */
	SiscomDesarrollo3Qt();
	/*!
	 * \brief Coloca un QLineEdit en pQCBCombo y asigna el nombre pchrPtrName
	 * \param pQCBCombo Combo al que se asignara el edit
	 * \param[in] pchrPtrName Nombre que se asignara al QLineEdit
	 */
	static QLineEdit *ColocaEditAlCombo(QComboBox *pQCBCombo,
					   const char *pchrPtrName);
	/*!
	 * \brief Verifica si la informacion que contiene el QLineEdit y regresa<br>
	 * la cadena resultante, en caso de que la informacion en el QLineEdit <br>
	 * sea nula, la funcion regresara una cadena vacia
	 * \param pQLEControl
	 */
	static const char *ObtenInformacionDelEdit(QLineEdit *pQLEControl);
	static const char *ObtenInformacionDelEdit(QTextEdit *pQTEControl);
	static const char *InformacionEdit(QLineEdit *pQLEControl);
	static const char *InformacionEdit(QTextEdit *pQTEControl);
	static SiscomCampo3 *Campo3Edit(const char *pchrPtrNmbCampo,QLineEdit *);

	static void PasaFocoControl(QLineEdit *);
	static void PasaFocoControl(QWidget *);

	static void FocoAControl(QLineEdit *);
	static void FocoAControl(QWidget *);
	/*
	 * Domingo 14 de Octubre del 2012
	 * Simplemente se agregan estas funciones por comodidad 
	 * para acortar el nombre 
	 */
	static void PasaFoco(QLineEdit *);
	static void PasaFoco(QWidget *);
	/*!
	 * \brief Toma la informacion en pQSLCampos y la muestra en la fila <br>
	 * pintFila de la tabla pQTDatos
	 * \param pintFila Numero de fila en que se mostrara la informacion
	 * \param pQTDatos Tabla en la que se mostrara la informacion
	 * \param pQSLCampos Registro que se mostrara en la tabla
	 */
	static void RegistroALaTabla(int pintFila,
				      QTable *pQTDatos,
				      const QStringList &pQSLCampos);


	static void RegistroALaTabla(int pintFila,
				      QTable *pQTDatos,
				      const char *pchrPtrCampos[],
				      SiscomRegistro3 *pSisReg3Dato);
	/*!
	 * \brief  Toma la informacion pSRegistro3Lst y la despliega en la Tabla<br>
	 * pQTDatos, los campos que se deberan mostrar se pasan en el arreglo pintPtrCamposM.
	 * \param[in] pchrPtrCamposM Campos que se mostraran
	 * \param[in] pQTDatos Tabla
	 * \param[in] pSRegistro3Lst Informacion
	 */
	static void RegistrosALaTabla(const char *pchrPtrCamposM[],
				      QTable *pQTDatos,
				      SiscomRegistro3Lst *pSRegistro3Lst);
	static void RegistrosALaTabla(QTable *pQTDatos,
				      SiscomRegistro3Lst *pSisReg3LstDat,
				      const char *pchrPtrConcatena[],
				      const char *pchrPtrAnexa[]);
	static void RegsPrincipal4ALaTabla(const char *pchrPtrCamposM[],
					   QTable *pQTDato,
					   SiscomRegistro4 *pSisReg4Dat);
	static void AjustaColumnas(QTable *);
	static void AjustaFilas(QTable *);
	static void EliminaFilas(QTable *);
	static void EliminaFilasSeleccionadas(QTable *);
	/*!
	 * Llena el combo pQCBCombo con los datos del campo pchrPtrCampo <br>
	 * de la lista de registros pSRegistro3Lst.
	 * \param[in] pchrPtrNmbCampo Campo que se mostrara en el combo
	 * \param[in] pQCBCombo Combo
	 * \param[in] pSRegistro3Lst Registros 
	 */
	static void RegistrosAlCombo(
				     const char *pchrPtrNmbCampo,
				     QComboBox *pQCBCombo,
				     SiscomRegistro3Lst *pSRegistro3Lst);
	static void Registros4PrincipalAlCombo(const char *pchrPtrNmbCampo,
					       QComboBox *pQCBCombo,
					       SiscomRegistro4 *pSisReg3Dat);
	static void ParametrosConsulta3(SiscomRegistro3Lst *,
					char *,
					...);
	static void ImprimeContenido(SiscomRegistro3Lst *);
	static int LeeLinea(FILE *,char *);
	static void EliminaCaracteres(const char *pchrPtrCaracteres,
				      char *pchrPtrCadena);
	static void EliminaCaracter(char pchrCaracter,
				    char *pchrPtrCadena);
	static void EliminaEspaciosInicio(char *pchrPtrCadena);
	static void EliminaEspaciosFinal(char *pchrPtrCadena);
	static int CadenasPorSeparador(const char *pchrPtrCadena,
				       char pchrSeperador,
				       char ***pchrPtrCadenas);
	static int CadenasPorSeparador2(const char *pchrPtrCadena,
				       char pchrSeperador,
				       char ***pchrPtrCadenas);
	static void CadenasPorSeparador(const char *pchrPtrCadena,
					char pchrSeparador,
					char *pchrPtrCadena1,
					char *pchrPtrCadena2);
	static const char *ObtenCadenaSeparador(const char *pchrPtrCadena,
						char pchrSeparador);
	static void CopiaCadenaPorSeparador(const char *pchrPtrBase,
					    const char *pchrPtrCadena,
					    char **pchrPtrCadenas);
	
	static void LiberaCadenas(char **pchrPtrCadenas);
	static void FechaHoy(char *pchrPtrDia,
			     char *pchrPtrMes,
			     char *pchrPtrA_o);
	static void FechaHoy(int *pintPtrDia,
			     int *pintPtrMes,
			     int *pintPtrA_o);
	static void ColoreaFilasSeleccionadas(QTable *pQTDatos,
				 const QColor &pQColor);
	static void ColoreaFilasSeleccionadas(QTable *pQTDatos,
				 const QColor &pQColor,
				 const QMemArray<int> &pQMAFilas);
	static void ColoreaFilas(QTable *pQTable,
				 const QColor &pQColor);

	static void ColoreaCelda(int pintFila,
				 int pintColumna,
				 QTable *pQTabla,
				 const QColor &pQColor);


	static void EliminaPaginasQTabWidget(QTabWidget *pQTWControl);
	static SiscomRegistro3 *Registro3(const char *pchrPtrFormato,
					 ...);
	static const char *CadenaEntreSeparadores(
				const char *pchrPtrEntrada,
				char pchrSepInicio,
				char pchrSepFin,
				char *pchrPtrCadena);


	static int TipoLetraPerfil(const char *pchrPtrArchivo,QFont *);


};

extern "C" 
{

extern FILE *gPtrFleArchivoLog3Qt;
void SiscomMensajesLog3Qt(const char *pchrPtrArchivo,
			 const char *pchrPtrFuncion,
			 int pintNoLinea,
			 const char *pzCadenaFormato,...);

void SiscomEliminaCaracter3Qt(char pchrCaracter,
			   char *pchrPtrCadena);
void SiscomFechaLocal3Qt(char *pchrPtrFecha);


#if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ > 95)
#define SiscomEscribeLog3Qt(...) SiscomMensajesLog3Qt(__FILE__,__FUNCTION__,__LINE__,__VA_ARGS__)
#else
#define SiscomEscribeLog3Qt(...) SiscomMensajesLog3Qt(__FILE__,__FUNCTION__,__LINE__,##args)
#endif

};
#endif
