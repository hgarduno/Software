create table Ventas(IdVenta integer unique,
		    IdCliente integer references Clientes(IdCliente),
		    IdTipoVenta integer references TipoVentas(IdTipoVenta),
		    IdFormaEntrega integer references FormasEntrega(IdFormaEntrega),
		    Folio integer,
		    InstruccionesEntrega varchar(512),
		    Fecha timestamp without time zone);

create table ImporteVenta( IdVenta integer references Ventas(IdVenta) primary key,
			   Subtotal numeric(12,2),
			   Iva	numeric(5,2),
			   Total numeric(12,2));

create table EstatusVenta(IdVenta integer references Ventas(IdVenta),
			  IdEstatus integer references Estatus(IdEstatus));

create table DetalleVentas(IdVenta integer references Ventas(IdVenta),
			   IdProducto integer references Productos(IdProducto),
			   cantidad integer,
			   PrecioVenta numeric(12,2),
			   Iva	numeric(5,2),
			   total numeric(12,2));

create table VentaCredito(IdVenta integer references Ventas(IdVenta) unique,
			  IdFinanciadora integer references Financiadoras(IdFinanciadora),
			  IdPlazo	integer references Plazos(IdPlazo),
			  PagoQuincenal	numeric(10,2),
			  PagoTotal	numeric(10,2));

create table VendedorVenta(IdVenta integer references Ventas(IdVenta),
			   IdVendedor integer references Vendedores(IdVendedor));

