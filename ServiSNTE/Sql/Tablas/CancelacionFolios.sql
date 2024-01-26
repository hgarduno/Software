create table FolioCancelado(IdFolioCancelacion integer unique,
			    IdVenta integer references ventas(idventa),
			    Folio integer,
			    FolioNuevo integer,
			    Motivo varchar(256));
