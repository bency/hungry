<?php
$sid = $_GET['sid'];
if($_POST['submit'] || $_POST['submit2']){
	$error="ok";
	if($_POST['name']!="")
		$name = $_POST['name'];
	else
		$error = "name";
	if(($_POST['address'])!="")
		$address = $_POST['address'];
	else
		$error = "address";
	if(($_POST['phone']!=""))
		$phone= $_POST['phone'];
	else
		$error = "phone";
	if($_POST['storetype2']!="manual")
		$storetype=$_POST['storetype2'];
	else if($_POST['storetype'] != "")
		$storetype=$_POST['storetype'];
	else
		$error = "storetype";
	if($_POST['delivery']){
		$delivery = $_POST['delivery'];
		if($_POST['condition2'] == "" )
			$error="condition";
	}
	else{
		$delivery = $_POST['delivery'];
		if($_POST['condition']!="" || $_POST['condition2']!="")
			$error = "condition2";
	}
	$condition = $_POST['condition'];
	$open = $_POST['open'];
	$close = $_POST['close'];
}
if($sid && !$_POST['submit'] && !$_POST['submit2']){
$storary = array();
$search = mysql_query("select * from store where id='".$sid."'");
$storary = mysql_fetch_array($search,MYSQL_ASSOC);
mysql_free_result($search);
$name = $storary['name'];
$phone = $storary['phone'];
$address = $storary['address'];
$storetype = $storary['storetype'];
$delivery = $storary['delivery'];
$condition = $storary['condition'];
$condition2 = $storary['condition2'];
$close = $storary['close'];
$open = $storary['open'];
}
$type = array();
$search = mysql_query("select distinct storetype from store order by storetype");
while($row = mysql_fetch_array($search,MYSQL_ASSOC))
	$type[] = $row;
mysql_free_result($search);
$typelist .="<option value='mamual'>自定</option>";
if($storetype != "")
	$typelist .= "<option selected value='".$storetype."'>".$storetype."</option>";
foreach($type as $key=>$value){
	$typelist .= "<option value='".$value['storetype']."'>".$value['storetype']."</option>";
}
if($_POST['submit2']&& $error == "ok"){
$search = mysql_query("select storetype from store where storetype like '".$storetype."'");
if($_POST['storetype2'] != "manual")
	$storetype = $_POST['storetype'];
if($sid)
	$sql = "update store set name='".$name."',address='".$address."',phone='".$phone."',delivery='".$delivery."',condition_limit='".$condition."',storetype='".$storetype."',update_date='".time()."',condition2='".$condition2."',close='".$close."',open='".$open."' where id='".$sid."'";
else{
	$sql = "insert into store(name,address,phone,delivery,condition_limit,storetype,update_date,condition2,open,close,click) value('".$name."','".$address."','".$phone."','".$delivery."','".$condition."','".$storetype."','".time()."','".$condition2."','".$open."','".$close."','0')";
}
$result = mysql_query($sql);
if($result)
	echo "編輯完成<br/>";
else
	echo mysql_error();
$search = "select id from store where name='".$name."'";
$result = mysql_query($search);
if(!$result)
	die('Search new store id error'.mysql_error());
else{
	$id = mysql_fetch_row($result);
	$sid = $id[0];
}
echo "<a href='".$_SERVER['NAME']."/showmenu/".$sid."'>編輯菜單</a>";
}
?>
