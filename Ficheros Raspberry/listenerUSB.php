<?php

function listener(){
		$fp =fopen('/dev/ttyACM0','r');//truncate
		sleep(1);
		while(true){
			echo fread($fp,64);
			sleep(2);
		}	
		fclose($fp);
}

listener();


?>
