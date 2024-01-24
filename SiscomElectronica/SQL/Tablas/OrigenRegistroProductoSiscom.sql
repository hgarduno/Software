create table OrigenProductoSiscom(IdCompra integer references 
						   CompraProductosSiscom (IdCompra),
				  CveProducto varchar(50) references Productos(CveProducto),
				  Origen varchar(25));
