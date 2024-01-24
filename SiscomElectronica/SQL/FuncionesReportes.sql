create or replace function UltimaCompra(pcveproducto varchar(30),
				        pfechaInicio date,
					pfechaFin    date,
					pidExpendio integer) returns refcursor as $$
declare 
regreso record;
begin
  select fecha::date,cantidad,precio,razonsocial into regreso
  from compras  inner join 
       empresas on proveedor=idempresa
  where fecha::date>=pfechaInicio and
        fecha::date<=pfechaFin and
	cveproducto=pcveproducto  and
	idexpendio=pidExpendio
  order by fecha desc
  limit 1;
  return regreso;
end;
$$ language plpgsql;
create or replace function ExistenciaActual(pcveproducto varchar(30),
					pidExpendio integer) returns float  as $$
declare 
lExistencia varchar(10);
begin
	select existencia+exbodegas into lExistencia
	from existenciaexpendiobodegas
	where idexpendio=pidExpendio and 
	      cveproducto=pcveproducto; 
	return lExistencia;
end;
$$ language plpgsql;
create or replace function TotalVentas(pcveproducto varchar(30),
				        pfechaInicio date,
					pfechaFin    date,
					pidExpendio integer) returns float as $$
declare 
ltotventas float;
begin
	select sum(cantidad) into ltotventas
	from ventas
	where fechahora::date>=pfechaInicio and 
	      fechahora::date<=pfechafin    and
	      idexpendio=pidExpendio        and
	      cveproducto=pcveproducto;
	return ltotventas;
end;
$$ language plpgsql;


create or replace function TotalCompras(pcveproducto varchar(30),
				        pfechaInicio date,
					pfechaFin    date,
					pidExpendio integer) returns float as $$
declare 
ltotventas float;
begin
	select sum(cantidad) into ltotventas
	from compras
	where fecha::date>=pfechaInicio and 
	      fecha::date<=pfechafin    and
	      idexpendio=pidExpendio        and
	      cveproducto=pcveproducto;
	return ltotventas;
end;
$$ language plpgsql;

