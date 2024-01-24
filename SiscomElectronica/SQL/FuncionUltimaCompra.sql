

create or replace function UltimaCompra(pCveProducto varchar(30),
					pIdExpendio integer,
					pNmbTipoPrecio varchar(30))
	returns refcursor as $$
begin

	open $1 for select	
	h.fecha::date,
	h.fecha::time,
	h.CveProducto,
	h.precio as PrecioCompra, 
	h.cantidad,
	h.numfactura,
	a.Precio as PrecioVenta,  
	b.IdEmpresa as IdProveedor, 
	b.RazonSocial as Proveedor
from   compras as h 
	left outer join precios as a on (h.CveProducto=a.CveProducto and
					 NmbTipoPrecio='DEFAULT') 
	left outer join empresas as b on(proveedor=b.idempresa)    
where 	h.CveProducto=pCveProducto	and
	h.idExpendio=-1165857915
order by h.fecha desc
limit 1 ;
	return ref;

end;
$$ language plpgsql;
