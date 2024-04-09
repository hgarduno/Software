/****************************************************************************
** Form interface generated from reading ui file 'UI/DescripcionCotizacion.ui'
**
** Created: lun abr 1 18:57:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DESCRIPCIONCOTIZACION_H
#define DESCRIPCIONCOTIZACION_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTextEdit;

class DescripcionCotizacion : public QDialog
{
    Q_OBJECT

public:
    DescripcionCotizacion( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~DescripcionCotizacion();

    QPushButton* QPBAceptar;
    QLabel* textLabel2;
    QTextEdit* QTEDescripcion;

protected:
    QGridLayout* DescripcionCotizacionLayout;
    QHBoxLayout* layout11;
    QVBoxLayout* layout10;

protected slots:
    virtual void languageChange();

};

#endif // DESCRIPCIONCOTIZACION_H
