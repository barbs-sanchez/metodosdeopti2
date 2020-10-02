
<?php
$dbhost="localhost";
$dbuser="root";
$dbpass="";
$dbname="test";
$conn=mysqli_connect($dbhost,$dbuser,$dbpass,$dbname);
if (!$conn)
{
  die("No hay conexion: ".mysqli_connect_error());
}
$nombre=$_POST["txtusuario"];
$pass=$_POST["txtpassword"];
$query=mysqli_query($conn,"SELECT *FROM login WHERE usuario = '".$nombre."' and password = '".$pass."'");
$nr=mysqli_num_rows($query);
 if ($nr==0)
{
   header("Location:login.php");

}
?>
<html>
<head>
<meta charset="UTF-8">
<title>killer dogs team</title>
<style type="text/css">
    body{background-color:#E84717;}

#general{
    margin:auto;
    width:960;
    height:1500px;
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
</head>
<body background>
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
			<li><a href="#">TIENDA</a></li>
		</ul>
	</div>
  <h1> Bienvenido:  <?php echo "" .$nombre;?> </h1>
 <img src="PROYECTODWIMAGENES/comunicado.jpg" >
</div>
</body>
</html>
