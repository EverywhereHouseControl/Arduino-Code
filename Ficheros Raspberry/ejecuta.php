<?php
ini_set('error_reporting',E_ALL);
$output = array();
$command   = $_GET["command"]; 
$idDevice  = $_GET["iddevice"]; 
$idService = $_GET["idservice"]; 
$idAction  = $_GET["action"]; 
$data      = $_GET["data"];

$host = "127.0.0.1";
$user = "ehc";
$pass = "ehcontrol1314";
$database = "raspEHC";
$query = "SELECT serialPort FROM devices WHERE id = $idDevice";

$link = mysql_connect($host, $user, $pass)
	or die('No se pudo conectar: ' . mysql_error());

mysql_select_db($database)
	or die('No se pudo seleccionar la base de datos');
$result = mysql_query($query)
	or die('Consulta fallida: ' . mysql_error());
list($port) = mysql_fetch_array($result);
$port1 = "/dev/tty$port";

$arg2 ="$command-$idService-$idAction";
$valor = $port1.' '.$arg2;
echo exec("/usr/bin/python /home/ehc/scripts/enviar.py $valor");
exit(0);

?>
