create table Gastos(IdGasto integer unique,
		    Gasto	varchar(25));

create table ImporteGasto(IdImporteGasto integer unique,
			  IdGasto integer references Gastos(idGasto),
			  Fecha timestamp without time zone,
			  Importe numeric(10,2));

create table DescripcionGasto(IdImporteGasto integer references ImporteGasto(IdImporteGasto),
			      Descripcion text);

create table Empleados(IdPersona integer references personas(IdPersona));
