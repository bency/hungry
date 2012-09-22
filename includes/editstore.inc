<?php
if($_POST['submit']){
	for($i=0;$_POST['del'][$i];$i++){
	mysql_query("delete from menu where storeid='".$_POST['del'][$i]."'");
	mysql_query("delete from store where id='".$_POST['del'][$i]."'");
	echo "刪除完畢<br>";
	}
}
$search = mysql_query("select * from store order by update_date desc");
$store = array();
while( $row = mysql_fetch_array($search,MYSQL_ASSOC) )
	$store[] = $row;
mysql_free_result($search);
foreach($store as $key=>$value){
$message .= "<input type='checkbox' value='".$value['id']."' name='del[]'><label>".$value['name']."</label><br>";
}
?>
