<?php
$setting_file = __DIR__ . "/config.ini";
$setting = parse_ini_file($setting_file);
$host = $setting['host'];
$username = $setting['username'];
$password = $setting['password'];
$link = mysql_connect($host, $username, $password);
if(!$link){
	die('連線失敗'.mysql_error());
}
mysql_select_db("hungry");
mysql_query("set character_set_client=latin1");
mysql_query("set character_set_connection=latin1");
mysql_query("set character_set_results=latin1");
mysql_query("set names 'latin1'");
?>
