<?php

function listener(){
		$fp =fopen('/dev/ttyACM0','r');//truncate
		sleep(1);
		while(true){
			$read = fread($fp,64);
                        if($read != 0){
				list($command, $idDevice, $idService, $data) = explode("-", $read);
				header("Location: ehcontrol.net/EHControlConnect/index.php
?command=$command&iddevice=$idDevice&idservice=$idService&action=0&data=$data");
				$fp2 = fopen('/home/ehc/log.txt','a+');
				$date = date("d-m-Y");
				$hour = date("H:i:s");
				fwrite($fp2,"FECHA: $date HORA: $hour SEÑAL: $read \n\r");
				fclose($fp2);				                                
				/*echo "FECHA: "; echo date("d-m-Y "); 
				echo "HORA: "; echo date("H:i:s\n\r");
                                echo "SEÑAL: "; echo $read; echo "\n\r";*/
                        }
			sleep(2);
		}	
		fclose($fp);
}

listener();


?>
