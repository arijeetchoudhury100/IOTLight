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
	/* query */
	if( $result = mysqli_query($connect, "select * from lightvalue") )
	{
		$row = mysqli_fetch_assoc($result);
    echo $row['status'];
	}
	mysqli_close($connect);
?>
