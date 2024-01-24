create table ProcesoContabilidad(
		IdProceso 	integer unique,
		FechaIni	date,
		FechaFin	date,
		Descripcion	text,
		primary key (FechaIni,FechaFin));

create table FacturasCompras(
		IdProceso	integer references ProcesoContabilidad(IdProceso),
		numfactura 	varchar(50),
		primary key(numfactura));
create table OrdenesFacturadas(
		IdProceso	integer references ProcesoContabilidad(IdProceso),
		IdVenta		integer);
create table ResultadoContable(
		idProceso integer references ProcesoContabilidad(idProceso),
		cveproducto 	varchar(25),
		cantidad 	numeric(10,2),
		ventatotal	numeric(10,2),
		ganancia	numeric(10,2),
		existencia	numeric(10,2),
		Importeexistencia	numeric(10,2),
		edocalculo	integer,
		primary key(idProceso,cveproducto));
