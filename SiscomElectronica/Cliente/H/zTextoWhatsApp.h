#ifndef __ZTEXTOWHATSAPP_H__
#define __ZTEXTOWHATSAPP_H__


class zOrdenVenta;
class zProductoCotizar;
class zTextoWhatsApp
{
public:
	zTextoWhatsApp(zOrdenVenta *);
	void CotizacionWhats(char **);
	~zTextoWhatsApp();
	static void PrecioProducto(zOrdenVenta *,char *);


	
private:
	void CadenaConNegritas(const char *pchrPtrCadena,char *pchrPtrNegritas);
	void AgregaLineaProducto(zProductoCotizar *,char *);
	void Cliente(char *pchrPtrCadena);
	void Total(char *pchrPtrCadena);
	void Lista(char **);
	void ReAsignaBuffer(int,char **pchrPtrCadena);
	void IniciaBuffer(char **pchrPtrCadena);
	int CadenaLlena(int,const char *,const char *);
	const char *DescripcionCotizacion();
	const char *CadenaDescripcionCotizacion();

private:
	zOrdenVenta *zOrdVenta;
};

#endif
