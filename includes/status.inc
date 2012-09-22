<?php 
$store_sql = mysql_query("select * from store");
$num_store = mysql_num_rows($store_sql);
$num_menu = array();
$store = array();
$menu = array();
$menu_sql = array();
while($res = mysql_fetch_array($store_sql,MYSQL_ASSOC)){
	$store[] = $res;
	$menu_sql[$i] = mysql_query("select * from menu where storeid='".$res['storeid']."'");
	$num_menu[$i] = mysql_num_rows($menu_sql[$i]);
	while($res2 = mysql_fetch_array($menu_sql[$i],MYSQL_ASSOC)){
		$menu[] = $res2;
	}
	mysql_free_result($menu_sql[$i++]);
}
mysql_free_result($store_sql);
$site_sql = mysql_query("select * from site_r");
$site_sql_ip = mysql_query("select * from site_r order by ip");
$site_sql_last = mysql_query("select * from site_r order by last_day desc");
$site_sql_count = mysql_query("select * from site_r order by count_ desc");
$site_sql_history = mysql_query("select date_,request from ip_log where ip='".$_GET['ip']."'");
$site = array();
$ipp = array();
$last = array();
$count = array();
$history = array();
while($res = mysql_fetch_array($site_sql,MYSQL_ASSOC))
	$site[] = $res;
while($res = mysql_fetch_array($site_sql_ip,MYSQL_ASSOC))
	$ipp[] = $res;
while($res = mysql_fetch_array($site_sql_last,MYSQL_ASSOC))
	$last[] = $res;
while($res = mysql_fetch_array($site_sql_count,MYSQL_ASSOC))
	$count[] = $res;
while($res = mysql_fetch_array($site_sql_history,MYSQL_ASSOC))
	$history[] = $res;
$site_status .= "<table>";
$site_status .= "<tr><td>ID</td><td>ip</td><td>count</td><td>last</td></tr>";
if($_GET['op'] == 'ip'){
	foreach($ipp as $key=>$value){
	$site_status .= "<tr><td>".$value['id']."</td><td>".$value['ip']."</td>";
	$site_status .= "<td>".$value['count_']."</td><td>".$value['last_day'];
	}
}
elseif($_GET['op'] == "count")
	foreach($count as $key=>$value){
	$site_status .= "<tr><td>".$value['id']."</td><td>".$value['ip']."</td>";
	$site_status .= "<td>".$value['count_']."</td><td>".$value['last_day'];
	}
elseif($_GET['op'] == "last")
	foreach($last as $key=>$value){
	$site_status .= "<tr><td>".$value['id']."</td><td>".$value['ip']."</td>";
	$site_status .= "<td>".$value['count_']."</td><td>".$value['last_day'];
	}
elseif($_GET['op'] == "history")
	foreach($history as $key=>$value){
	$site_status .= "<tr><td>".$value['ip']."</td><td>".$value['request']."</td></tr>";
	}
else
	foreach($site as $key=>$value){
	$site_status .= "<tr><td>".$value['id']."</td><td><a href='/status/history/".$value['ip']."'>".$value['ip']."</td>";
	$site_status .= "<td>".$value['count_']."</td><td>".$value['last_day'];
	}
$site_status .= "</table>";
?>
