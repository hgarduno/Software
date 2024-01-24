--- En un inicio se habia considerado el IdExpendio 
--- como parametro para esta funcion, pero regularmente
--- en la consulta se filtrara por IdExpendio, por lo 
--- que no se requiere pasar como parametro

create or replace function UltimoPrecio(pCveProducto varchar(30),
					pFechaVenta  date) 
 returns float as $$
declare
lintUltimoPrecio float;
begin

	select precio into lintUltimoPrecio
	from compras 
	where fecha::date<=pFechaVenta and 
	      cveproducto=pCveProducto  
	order by fecha desc
	limit 1;
	     

return lintUltimoPrecio;

 end;
$$ language plpgsql;
