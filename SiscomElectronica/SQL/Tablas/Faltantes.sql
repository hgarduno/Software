create table EstadosFaltantes(IdEdoFaltante integer unique,
			      Descripcion varchar(30));

create table Faltantes(IdFaltante	integer unique,
			IdEdoFaltante	integer references EstadosFaltantes(IdEdoFaltante),
			CveProducto varchar(25) references productos(cveproducto),
		        Veces	integer);

create table DetalleFaltante(IdFaltante	integer references Faltantes(IdFaltante),
			     Fecha timestamp without time zone);	
