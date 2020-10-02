<html>
<style type="text/css">
    body{background-color:#E84717;}

#general{
    margin:auto;
    width:960;
    height:1000px;
    background-color:#5D7B73;
   
}
#head{
    width:960px;
    height:220px;
    background-image:url(PROYECTODWIMAGENES/LOGOOFICIAL.jpg);
    margin-top:0px;
}

#lista{
width:960px;
    height:40px;
    background-color:#DE937E;
    margin-top:0px}
#lista ul{
    list-style: none;
    margin:0;
    padding: 0;
}
#lista ul li{
     display: inline-block;
}
#lista ul li a{
  color: white;
  text-decoration:none;
  display: block;
  padding:10px 40px; 
}
#lista ul li a:hover{
   background-color:#85E817;
}



</style>
<center>
<div id="general">
<div id="head">
      </div>
     <div id="lista">
         <ul>
			<li><a href="index.html">INICIO</a></li>
			<li><a href="conocenos.html">CONOCENOS</a></li>
			<li><a href="fotos.html">FOTOS</a></li>
			<li><a href="login.php">COMUNIDAD</a></li>
			<li><a href="contactos.html">CONTACTOS</a></li>
			<li><a href="tienda.html">TIENDA</a></li>
		</ul>
	</div>
<form method="post" action="login1.php">
<table>
<tr><td colspan="2"><label>Login</label></td></tr>
<tr><td align="center" rowspan="5"><img src="PROYECTODWIMAGENES/candado.png"/></td><td><label>Usuario</label></td></tr>
<tr><td><input type="text" name="txtusuario"/></td></tr>
<tr><td><label>Password</label></td></tr>
<tr><td><input type="password" name="txtpassword"/></td></tr>
<tr><td><input type="submit" name="Ingresar"/></td></tr>
</table>
</form>
<h2> ve con la admistración de la academía para que genere tu usuario </h2>
</div>
</center>
</html>