/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaDescripcionCotizacion.ui'
**
** Created: lun abr 1 18:57:48 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURADESCRIPCIONCOTIZACION_H
#define CAPTURADESCRIPCIONCOTIZACION_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTextEdit;
class QLineEdit;
class QButtonGroup;

class CapturaDescripcionCotizacion : public QDialog
{
    Q_OBJECT

public:
    CapturaDescripcionCotizacion( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaDescripcionCotizacion();

    QPushButton* QPBAceptar;
    QPushButton* pushButton1_2;
    QLabel* textLabel2;
    QTextEdit* QTEDescripcion;
    QLabel* textLabel1_3;
    QLineEdit* QLENombre;
    QLabel* textLabel1;
    QLineEdit* QLETelefono;
    QLabel* textLabel1_2;
    QLineEdit* QLEPagaCon;
    QLabel* textLabel1_2_2;
    QLineEdit* QLEHora;
    QButtonGroup* QBGEscuelas;

protected:
    QGridLayout* CapturaDescripcionCotizacionLayout;
    QHBoxLayout* layout14;
    QVBoxLayout* layout3;
    QVBoxLayout* layout28;
    QHBoxLayout* layout32;
    QVBoxLayout* layout31;
    QSpacerItem* spacer1;
    QVBoxLayout* layout1;
    QVBoxLayout* layout1_2;
    QVBoxLayout* layout1_2_2;
    QGridLayout* QBGEscuelasLayout;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURADESCRIPCIONCOTIZACION_H
