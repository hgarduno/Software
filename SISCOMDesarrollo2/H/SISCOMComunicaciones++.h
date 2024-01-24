
/*! \file SISCOMComunicaciones++.h
 *
 * Archivo que contiene la informacion de los datos'
 * que se deben manejar para poder establecer la 
 * intercomunicacion con el servidor.
 *
 * Autor: Heli Garduno Esquivel
 * Fecha: 2007-05-30
 *
 */




#ifndef __SISCOMCOMUNICACIONES_H__
#define __SISCOMCOMUNICACIONES_H__
extern "C"{
#include <SiscomDesarrollo2.h>
};

#include <qptrlist.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qlabel.h>
#include <qaction.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>

#include <SiscomRegistrosPro2.h>
#include <SiscomRegistroPro2.h>
#include <SiscomComunicaSrv.h>
#include <SiscomDatCom.h>
#include <SiscomOperaciones.h>
#include <SiscomInformacion.h>
#include <SiscomGeneralOperacionesSrv.h>


/*
 * Con la nueva funcion que permite anexar una nuevo registro
 * antes de crear la lista, si se hereda de la clase SiscomInformacion2
 * por alguna razon truena el proceso, el comportamiento que se 
 * observa es que la lista simplemente ligada de los registros
 * pierde el valor
 *
 * La referencia de este error se encuenta el proyecto SiscomTrampolin
 * en la clase CQSisEntrenador
 *
 *
 *
 */
class SiscomInformacion2:public SiscomInformacion
{
public:
	SiscomInformacion2();
	virtual ~SiscomInformacion2();
	void SiscomAsignaInformacion();
	void SiscomAnexaCampos(const SiscomInformacion &);
	void MuestraCampos(const char *,SiscomRegistroPro2 );
private:
	virtual void SiscomFormaRegistro();
	virtual void SiscomAnexaRegistro();

};
class SiscomParametroConsulta:public SiscomInformacion
{
public:
	SiscomParametroConsulta(const char *);

};
class SiscomParametrosConsulta:public QPtrList<SiscomParametroConsulta>
{

public:
	SiscomParametrosConsulta();
	SiscomParametrosConsulta &operator <<(SiscomParametroConsulta *);


};

class SiscomArgumentosPantalla
{
public:
	SiscomArgumentosPantalla();

};

class QSisHEspacio:public QHBoxLayout
{
	public:
		QSisHEspacio(QWidget *,
			     int ,
			     int,
			     const char *);
	QSisHEspacio &operator+=(QVBoxLayout *);
};

class CQSisLstMenu:public QPtrList<QAction>
{
public:
	CQSisLstMenu();
	CQSisLstMenu &operator<<(QAction *);
	QAction *operator[](const char *);

};

void SiscomPasaFocoControl(QLineEdit *);
void SiscomPasaFocoControl(QWidget *);
void SiscomAnexarRegistroALaTabla(int,QTable *,QStringList );
void SiscomAnexarRegistroALaTabla(int,QPixmap ,QTable *,QStringList );
void SiscomAjustaColumnas(QTable *);
void SiscomAjustaFilas(QTable *);
QLineEdit *SiscomColocaEditAlCombo(QComboBox *,const char *);
QMemArray<int> SiscomFilasSeleccionadas(QTable *);
const char *SiscomObtenInformacionDelEdit(QLineEdit *);
const char *SiscomObtenInformacionDelEdit(QTextEdit *);
QVBoxLayout *SiscomCreaEspacioVerticalEtiquetaCombo(QWidget *,
						    const char *,
						    const char *,
						    const char *,
						    QComboBox **,
						    QLabel **);
QVBoxLayout *SiscomCreaEspacioVerticalEtiquetaEdit(QWidget *,
						    const char *,
						    const char *,
						    const char *,
						    QLineEdit **,
						    QLabel **);
QVBoxLayout *SiscomCreaEspacioVerticalEtiquetaTextEdit(QWidget *,
						    const char *,
						    const char *,
						    const char *,
						    QTextEdit **,
						    QLabel **);
QVBoxLayout *SiscomCreaEspacioVerticalButton(QWidget *,
					     const char *,
					     const char *,
					     QPushButton **);

QLabel *SiscomCreaEtiqueta(QWidget *pQWParent,
			   const char *pchrPtrDato,
			   const char *pchrPtrNombre);
QTable *SiscomCreaTabla(QWidget *pQWParent,
			const char *pchrPtrName,
			int pintNFilas,
			const QStringList  &pQSLNombres);
QVBoxLayout *SiscomCreaDisplayEtiqueta(
				QWidget *pQWParent,
				const char *pchrPtrNmbEtiqueta,
				const char *pchrPtrTextoEtiqueta,
				const char *pchrPtrNmbDisplay,
				int pintNumDigitos,
				QLCDNumber **pQLCDNDisplay,
				QLabel **pQLEtiqueta);

void SiscomArgumentosConsulta(SiscomParametrosConsulta *,char *,...);
/*
 *
 *
 * SiscomArgumentosConsulta(&SPConsulta,"%s%s%s",chrPtrId);
 *
 *
 */

void SiscomEliminaFilasTabla(QTable*);
void SiscomEliminaFilasTabla(QTable*,int,int);
#endif
