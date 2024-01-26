create table Facturas(idfactura integer unique,
			idcompra integer references compras(idcompra),
			importe numeric(10,2),
			iva numeric(10,2),
			total numeric(10,2));

create table stock(idproducto integer references productos(idproducto),
		   existencia integer);

create table consignacion(idproducto integer references productos(idproducto),
			  existencia integer );


create table TiposTransferencia(IdTipoTransferencia integer unique,
				TipoTransferencia varchar(28));


create table TransferenciaPiso(IdTransferencia integer references Transferencias(IdTransferencia));
