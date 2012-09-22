<?php
include_once "includes/showstore.inc";
?>
<div class='in-main'>
<?php
foreach($store as $key=>$value){
	echo "<div class='store-info shadow'>";
	echo "<span class='inline'><a href='".$_SERVER['NAME']."/showmenu/".$value['id']."'>".$value['name']."</a><span style='font-size:6pt;font-weight:bold;color:#707070;'>--".$value['storetype']."</span></span><br>";
	echo "<span class='inline'>".$value['address']."</span><br>";
	echo "<span class='inline'>".$value['phone']."</span><br>";
	echo "<span class='inline'>從".substr($value['open'],0,5)."到".substr($value['close'],0,5)."</span><br>";
	echo "<span class='inline'>瀏覽次數：".$value['click']."</span><br>";
	echo "</div>";
}
?>
</div>
