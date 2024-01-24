SELECT  case when
	cast('hgarduo' as varchar(20))=c.password

	then
	1
	else
	0
	end
from aplicaciones inner join 
     usuarios as b using(idAplicacion) inner join 
     firmas as c using(idUsuario) 
where NmbAplicacion='SISCOMTiendas' and firma='hgarduno';
