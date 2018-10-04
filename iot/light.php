<!DOCTYPE html>
<html>
	<head>
		<title>Status of light</title>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
	</head>
<body>
<?php
	$db_host = "localhost";
	$db_user = "laxus";
	$db_pass = "Laxus#1996";		// NOTE: *never* specify the password like this in a real script
	$db_name = "iot";

	$connect = mysqli_connect($db_host, $db_user, $db_pass, $db_name);

	/* check connection */
	if( mysqli_connect_errno($connect) )
	{
		echo "Failed to connect to MySQL: " . mysqli_connect_error();
		exit();
	}
  if(isset($_GET['lightOn'])){
  	mysqli_query($connect,"update lightvalue set status='on'");
  }
  if(isset($_GET['lightOff'])){
  	mysqli_query($connect,"update lightvalue set status='off'");
  }
	/* query */
	if( $result = mysqli_query($connect, "select * from lightvalue") )
	{
		$row = mysqli_fetch_assoc($result);
    echo $row['status'];
	}
	mysqli_close($connect);
?>
</body>
</html>
