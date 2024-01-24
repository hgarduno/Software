#ifndef __SQLEMPLEADOS_H__
#define __SQLEMPLEADOS_H__
#include <SiscomDesarrollo2.h>

void SQLFirma(SArgsSiscom *);
void SQLUsuario(SArgsSiscom *);
void SQLPersonaPerfil(SArgsSiscom *);
void SQLAdicionales(SArgsSiscom *);



void SQLGeneraRegistroFirma(LCamposSiscomPro2 *,
			    LCamposSiscomPro2 **,
			    LCamposSiscomPro2 **,
			    int *);
void SQLGeneraRegistroUsuario(LCamposSiscomPro2 *,
			    LCamposSiscomPro2 **,
			    LCamposSiscomPro2 **,
			    int *);
void SQLGeneraRegistroPersonaPerfil(LCamposSiscomPro2 *,
			    LCamposSiscomPro2 **,
			    LCamposSiscomPro2 **,
			    int *);
void SQLGeneraRegistroAdicionales(LCamposSiscomPro2 *,
			    LCamposSiscomPro2 **,
			    LCamposSiscomPro2 **,
			    int *);


void SQLEmpleadosRegistrados(SArgsSiscom *pSAgsSiscom);
#endif
