#ifndef __ZCREDITOSCLIENTE_H__
#define __ZCREDITOSCLIENTE_H__
#include <zSiscomRegistro.h>

class zPersona;
class zDireccion;
class zCreditosCliente:public zSiscomRegistro
{

public:
	zCreditosCliente(zSiscomRegistros *pzSisRegsCreditosCliente);
	zSiscomRegistro *Cliente();
	zSiscomRegistros *Creditos();
	zDireccion *Direccion();
private:
	zSiscomRegistros *zSisRegsCreditosCliente;
	zSiscomRegistro *zSisRegCliente;
	zSiscomRegistros *zSisRegsCreditos;
	zDireccion *zDirCliente;
};



#endif
