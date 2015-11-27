<?php

$session_snmp = new SNMP(SNMP::VERSION_1, "192.168.0.180", "public");
$get_oid_humidade = $session_snmp->get("1.3.6.1.2.1.1.9.0");

echo "HUMIDADE > ".$get_oid_humidade;


?>