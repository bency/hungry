<?php
$link = mysql_connect('127.0.0.1','root','ddyoinejjmj');
if(!$link){
	die('連線失敗'.mysql_error());
}
mysql_select_db("hungry");
mysql_query("set character_set_client=latin1");
mysql_query("set character_set_connection=latin1");
mysql_query("set character_set_results=latin1");
mysql_query("set names 'latin1'");
?>
