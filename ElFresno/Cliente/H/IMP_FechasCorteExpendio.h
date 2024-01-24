#ifndef __IMP_FECHASCORTEEXPENDIO_H__
#define __IMP_FECHASCORTEEXPENDIO_H__

#include <UIC_H_FechasCorteExpendio.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QPushButton;
class CSISCOMDatComunicaciones;
class QFechasCorteExpendio : public FechasCorteExpendio
{
    Q_OBJECT

public:
    QFechasCorteExpendio(CSISCOMDatComunicaciones*,
    			 QWidget* parent = 0,
			 const char* name = 0,
			 bool modal = FALSE,
			 WFlags fl = 0 );
    ~QFechasCorteExpendio();

};

#endif 
