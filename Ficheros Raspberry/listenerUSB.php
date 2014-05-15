<?php

function listener(){
		//change to use Zigbee /dev/ttyACM0 -> /dev/ttyUSB0
		$fp =fopen('/dev/ttyUSB0','r');//truncate
		sleep(1);
		while(true){
			$read = fread($fp,64);
                        if($read != FALSE){
				//UPDATE dataBase
				list($command, $idDevice, $idService, $data) = explode("-", $read);
				$ext = "command=$command&iddevice=$idDevice&idservice=$idService&action=0&data=$data";
				$host = "http://ehcontrol.net";
				$url = "$host/EHControlConnect/index.php?$ext";
				$ch = curl_init($url);
				$result = curl_exec($ch);
				curl_close($ch);
				//file log
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
