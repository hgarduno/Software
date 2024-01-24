#included <zProductosExpendio.h>

zProductosExpendio::zProductosExpendio(zEmpresa *pzEExpendio)
{
  (*this)  <<
  	new zSiscomCampo("Expendio",pzEExpendio) <<
	new zSiscomCampo("Productos");
}
