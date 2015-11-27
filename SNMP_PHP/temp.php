<?php

$session_snmp = new SNMP(SNMP::VERSION_1, "177.154.114.180", "public");
$get_iod_temperature = $session_snmp->get("1.3.6.1.2.1.1.8.0");

echo "TEMPERATURE >".$get_iod_temperature;

?>