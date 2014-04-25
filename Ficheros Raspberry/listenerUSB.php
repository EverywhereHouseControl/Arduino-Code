<?php

function listener(){
		$fp =fopen('/dev/ttyACM0','r');//truncate
		sleep(1);
		while(true){
			$read = fread($fp,64);
                        if($read != 0){
                                echo "FECHA: "; echo date("d-m-Y "); 
				echo "HORA: "; echo date("H:i:s\n\r");
                                echo "SEÑAL: "; echo $read; echo "\n\r";
                        }
			sleep(2);
		}	
		fclose($fp);
}

listener();


?>
