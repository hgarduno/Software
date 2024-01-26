create table TiposFolio(IdTipoFolio integer unique,
			Folio varchar(25));

create table Folios(IdFolio integer unique ,
		    IdTienda integer references Tiendas(IdTienda),
		    IdTipoFolio integer references TiposFolio(IdTipoFolio),
		    Inicio integer,
		    Fin    integer,
		    primary key(IdTienda,IdTipoFolio,Inicio,Fin)); 


create table FolioActual(IdTipoFolio integer references TiposFolio(IdTipoFolio),
			 Folio integer);
