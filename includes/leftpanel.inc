<?php
$search = mysql_query("select id,name from store order by click desc");
$leftstore = array();
while($rowR = mysql_fetch_array($search,MYSQL_ASSOC)){
$leftstore[] = $rowR;
}
foreach($leftstore as $key=>$value){
if($_GET['sid'] == $value['id'] || $_GET['edit'] == $value['id'])
	//$side .= "<a href=\"http://www.plurk.com/?status=[揪外送]有沒有人要一起訂 肚子餓.班西.tw/showmenu/".$value['id']." (".$value['name'].")來吃勒？？&qualifier=wonders\">[揪噗浪]</a>".$value['name']."<br>";
	$side .= $value['name']."<br>";
else
	$side .= "<a".$class." href=\"".$_SERVER['NAME']."/showmenu/".$value['id']."\">".$value['name']."</a><br>";
}
?>
