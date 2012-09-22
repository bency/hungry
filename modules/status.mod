<?php 
include_once "includes/status.inc";
echo "Your IP:<a href='".$ip."'>".$ip."</a><br>";
echo "<a href='".$SERVER['NAME']."/status/site'>[Order By ID]</a>&nbsp;";
echo "<a href='".$SERVER['NAME']."/status/ip'>[Order By IP]</a>&nbsp;";
echo "<a href='".$SERVER['NAME']."/status/count'>[Order By Count]</a>&nbsp;";
echo "<a href='".$SERVER['NAME']."/status/last'>[Order By LastDay]</a>&nbsp;";
echo $menustatus;
echo $storestatus;
echo $site_status;
?>
