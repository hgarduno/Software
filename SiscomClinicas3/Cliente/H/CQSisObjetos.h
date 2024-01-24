#ifndef __CQSISOBJETOS_H__
#define __CQSISOBJETOS_H__
#include <SISCOMComunicaciones++.h>
class CQSisServicio;
class CQSisTipoPrecio;
class CQSisPersona;
class CQSisConsulta;
class CQSisExpediente;
class CQSisCotizando;
class CQSisReceta;
class CQSisPrecioServicio;
class CQSisMatHosp;
class CQSisLstReceta;
class CQSisLstTipoPrecio;
class CQSisLstServicio;
class CQSisLstPersona;
class CQSisLstConsulta;
class CQSisLstExpediente;
class CQSisLstCotizando;
class CQSisLstPrecioServicio;
class CQSisLstMatHosp;
class CQSisObjetos
{
public:
	CQSisObjetos();

	static CQSisServicio *Servicio(SiscomRegistrosPro2 *);
	static CQSisTipoPrecio *TipoPrecio(SiscomRegistrosPro2 *);
	static CQSisPersona *Persona(SiscomRegistrosPro2 *);
	static CQSisConsulta *Consulta(SiscomRegistrosPro2 *);
	static CQSisExpediente *Expediente(SiscomRegistrosPro2 *);
	static CQSisExpediente *Expediente2(SiscomRegistrosPro2 *);
	static CQSisCotizando *Cotizando(SiscomRegistrosPro2 *);
	static CQSisReceta *CQSReceta(SiscomRegistrosPro2 *);
	static CQSisPrecioServicio *PrecioServicio(SiscomRegistrosPro2 *);
	static CQSisMatHosp *MaterialHospitalizado(SiscomRegistrosPro2 *);
	static void Recetas(SiscomRegistrosPro2 *,CQSisLstReceta *);
	static void TipoPrecios(SiscomRegistrosPro2 *,CQSisLstTipoPrecio *);
	static void Personas(SiscomRegistrosPro2 *,CQSisLstPersona *);
	static void Servicios(SiscomRegistrosPro2 *,CQSisLstServicio *);
	static void Consultas(SiscomRegistrosPro2 *,CQSisLstConsulta *);
	static void NombreCompleto(CQSisPersona *,char *);
	static void Expedientes(SiscomRegistrosPro2 *,CQSisLstExpediente *);
	static void Expedientes2(SiscomRegistrosPro2 *,CQSisLstExpediente *);
	static void Cotizando(SiscomRegistrosPro2 *,CQSisLstCotizando *);
	static void PreciosServicio(SiscomRegistrosPro2 *,CQSisLstPrecioServicio *);
	static void MaterialesHospitalizado(SiscomRegistrosPro2 *,CQSisLstMatHosp *);

private:
	

};

#endif
