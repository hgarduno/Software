











delete from direccionescliente ;
			   
delete from direcciones;

delete from importeventa where idventa in( select idventa
 from	personas as a inner join 
 	clientes as b  on a.idpersona=b.idcliente  inner join
	ventas as c  using(idcliente)
where rfc!='' and idpersona>=10000);


delete from detalleventas where idventa in( select idventa
 from	personas as a inner join 
 	clientes as b  on a.idpersona=b.idcliente  inner join
	ventas as c  using(idcliente)
where rfc!='' and idpersona>=10000);

delete from vendedorventa where idventa in( select idventa
 from	personas as a inner join 
 	clientes as b  on a.idpersona=b.idcliente  inner join
	ventas as c  using(idcliente)
where rfc!='' and idpersona>=10000);

delete from ventacredito where idventa in( select idventa
 from	personas as a inner join 
 	clientes as b  on a.idpersona=b.idcliente  inner join
	ventas as c  using(idcliente)
where rfc!='' and idpersona>=10000);

delete from ventas where idventa in(select idventa
 from	personas as a inner join 
 	clientes as b  on a.idpersona=b.idcliente  inner join
	ventas as c  using(idcliente)
where rfc!='' and idpersona>=10000);
	
delete from direccionescliente where idcliente in(
select idcliente
 from	personas as a inner join 
 	clientes as b  on a.idpersona=b.idcliente  inner join
	ventas as c  using(idcliente)
where rfc!='' and idpersona>=10000);
delete from clientes  where idcliente  in(
select idcliente
 from	personas as a inner join 
 	clientes as b  on a.idpersona=b.idcliente 
where rfc!='' and idpersona>=10000);




delete from personas where rfc!='' and idpersona>=10000;
