#ifndef __SISCOMPARAMETROCONSULTA3_H__
#define __SISCOMPARAMETROCONSULTA3_H__
#include <SiscomRegistros3.h>
/*!
 * Para ejecutar los proceso de consulta a el servidor <br>
 * se crea esta clase, la cual contendra un registro con la <br>
 * siguiente informacion:<br>
 * Nombre del campo:Parametro<br>
 */
 

class SiscomParametroConsulta3:public SiscomRegistro3
{
public:
	/*!
	 * Constructor de clase, copiara la informacion pchrPtrDato <br>
	 * en SiscomParametroConsulta3
	 * \param pchrPtrDato Informacion que se copiara en Parametro
	 */
	SiscomParametroConsulta3(const char *pchrPtrDato);

};

#endif
