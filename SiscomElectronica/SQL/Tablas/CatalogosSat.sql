drop table FormaPagoSat;
drop table MetodoPagoSat;
drop table UsoFacturaSat;
create table FormaPagoSat(IdFormaPago integer unique,
			  Codigo varchar(3) unique,
			  FormaPago varchar(35));

create table MetodoPagoSat(IdMetodoPago integer unique,
			   Codigo varchar(3) unique,
			   MetodoPago varchar(25));

create table UsoFacturaSat(IdUsoFactura integer unique,
			   Codigo	varchar(3) unique,
			   Uso		text);
