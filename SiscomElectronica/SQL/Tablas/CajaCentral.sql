create table CajaCentral(
	IdVenta integer,
	IdExpendio	integer,
	IdCaja		integer references cajas(idcaja),
	Total	float,
	Estado	integer);
