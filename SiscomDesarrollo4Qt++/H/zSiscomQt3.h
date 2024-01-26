#ifndef __ZSISCOMQT3_H__
#define __ZSISCOMQT3_H__
#include <qstring.h>
#include <qcolor.h>
class QLineEdit;
class QTextEdit;
class QComboBox;
class QTable;
class QPushButton;
class QWidget;
class QFont;

class zSiscomRegistros;
class zSiscomQt3
{
public:
	zSiscomQt3();
	static QLineEdit *EditAlCombo(QComboBox *pQCBCombo,const char *pchrPtrNombre);
	static void RegistrosAlCombo(QComboBox *pQCBCombo,
				     const char *pchrPtrCampo,
				     zSiscomRegistros *pzSisRegistros);
	static void Foco(QLineEdit *);
	static void Foco(QTextEdit *);
	static void Foco(QPushButton *);
	static void Foco(QWidget *);
	static const char *Texto(QLineEdit *pQLEControl);
	static const char *Texto(QTextEdit *pQLEControl);
	static int TextoValido(QLineEdit *pQLEControl);
	static int TextoValido(QTextEdit *pQTETexto);
	static int TextoValido(const QString &pQStrTexto);
	static void AjustaColumnasTabla(QTable *);
	static void AjustaFilasTabla(QTable *);
	static void AjustaTabla(QTable  *);
	static void LlenaTabla(const char *pchrPtrCampo[],
				      zSiscomRegistros *pzSisRegistros,
				      QTable *pQTDatos);
	
	static void LimpiaTabla(QTable *pQTable);
	static void RegistrosSeleccionados(QTable *pQTDatos,
				        zSiscomRegistros *pzSisRegistros,
					zSiscomRegistros *pzSisRegsSeleccionados);

    static void SiscomALetra(double lfltDato,
            char **pchrArrALetraPtr);
    static void SiscomALetraSinPesos(double lfltDato,
            char **pchrArrALetraPtr);

    
    static void SiscomALetraSinDecimal(double lfltDato,
            char **pchrArrALetraPtr);

    static void ALUnidades(char *pchrArrNumeroLetra,
                char *pchrArrNumero);

    static void ALDecenas(char *pchrArrNumeroLetra,
               char *pchrArrNumero);

    static void ALCentenas(char *pchrArrNumeroLetra,
                char *pchrArrNumero);

    static void ALMillares(char *pchrArrNumeroLetra,
                char *pchrArrNumero);

    static void ALMillones(char *pchrArrNumeroLetra,
                char *pchrArrNumero);

   static int LeeTipoLetra(const char *pchrPtrArchivo,QFont *);
   static int GuardaTipoLetra(const char *pchrPtrArchivo,QFont *);
   static void HabilitaPasaFoco(QWidget *pQWControl);
   static void ColoreaFilas(QTable *pQTDatos,
   					 const QColor &pQColor,
					 int *pintPtrFilas);
};

#endif
