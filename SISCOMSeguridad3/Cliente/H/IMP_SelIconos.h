#ifndef __CQSISSELICONOS_H__
#define __CQSISSELICONOS_H__

#include <UIC_H_SelIconos.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QIconView;
class QIconViewItem;
class QLabel;
class QLineEdit;

class CQSisSelIconos : public SelIconos
{
    Q_OBJECT

public:
	enum BTN_SelIconos
	{
		BTN_Aceptar ,
		BTN_Cancelar
	};
    CQSisSelIconos( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CQSisSelIconos();
	BTN_SelIconos ObtenLaSeleccion();
	QString ObtenArchivo();
private:
	void ConectaSlots();
	void SeleccionaDirectorio(QString &);
	void CargaArchivos(QString ,QStringList &);
	void MuestraIconos(QString ,QStringList );
private:
	BTN_SelIconos Boton;
private slots:
	void SlotSeleccionaDirectorio();
	void SlotSeleccionaIcono(QIconViewItem *);
	void SlotAceptar();
	
};

#endif 
