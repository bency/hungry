<?php
if($_POST['menu']){
	for($i=0;$_POST['name'][$i];$i++){
		$sql = "insert into menu(name,price,update_date,storeid,sort) value('".$_POST['name'][$i]."','".$_POST['price'][$i]."','".time()."','".$_GET['edit']."','".$_POST['sort'][$i]."')";
		mysql_query($sql);
	}
	for($i=0;$_POST['oname'][$i];$i++){
		$sql = "update menu set name='".$_POST['oname'][$i]."',price='".$_POST['oprice'][$i]."',sort='".$_POST['osort'][$i]."' where id='".$_POST['id'][$i]."' and storeid='".$_GET['edit']."'";
		mysql_query($sql);
	}
	for($i=0;$_POST['del'][$i];$i++){
		$sql = "delete from menu where id='".$_POST['del'][$i]."' and storeid='".$_GET['edit']."'";
		mysql_query($sql);
	}
	$sql = "update store set update_date='".time()."' where id='".$_GET['edit']."'";
	mysql_query($sql);
}

$cid = $_GET['edit'];
// 產生店家列表
/*
$search = mysql_query("select * from store");
$store = array();
while($row = mysql_fetch_array($search,MYSQL_ASSOC)){
		$store[] = $row;
}
mysql_free_result($search);
if($_GET['edit']!=""&&$_POST['store']==""){
	$cid = $_GET['edit'];
$search = mysql_query("select name from store where id='".$cid."'");
$name = mysql_fetch_row($search,MYSQL_ASSOC);
$s=$name['name'];
}
else{
$s = $_POST['store'];
$search = mysql_query("select id from store where name='".$_POST['store']."'");
$res= mysql_fetch_array($search,MYSQL_ASSOC);
global $cid;
$cid = $res['id'];
mysql_free_result($search);
}
*/
$search = mysql_query("select * from menu where storeid ='".$cid."' order by sort");
$num_row = mysql_num_rows($search);
if($num_row){
	$message .= "<table><tr><td>名稱</td><td>價格</td><td>刪除</td></tr>";
    $menu = array();
    $end = 15;
    if($_GET['page'])
        $start = ($_GET['page']-1) * $end;
    else
        $start = 0;
    if($num_row>$end)
        $search = mysql_query("select * from menu where storeid ='".$cid."' order by sort limit ".$start.",".$end);
    while($res = mysql_fetch_array($search,MYSQL_ASSOC)){
            $menu[] = $res;
    }
    foreach($menu as $key=>$value){
		$message .= "<tr><td><input type='text' value='".$value['name']."' placeholder='輸入料理名稱' name='oname[]'></td>";
		$message .= "<td><input type='number' value='".$value['price']."' id='number' step='0.5' name='oprice[]' min='0'>";
		$message .= "<input size=14 type='text' value='".$value['sort']."' placeholder='飯 or 麵 or 蓋飯' name='osort[]'>";
		$message .= "<input value='".$value['id']."' type='hidden' name='id[]'></td>";
		$message .= "<td><input value='".$value['id']."' type='checkbox' name='del[]'></td></tr>";
    }
	$message .= "</table>";
}
else
	$message = "還沒有菜單喔！";
mysql_free_result($search);
echo mysql_error();
$pages = ceil($num_row/$end);
$pager = "<div class=\"in-page\">";
if( $pages > 1){
for($i=1;$i<=$pages;$i ++){
	if($i == $_GET['page'])
		$pager .= "&nbsp;".$i."&nbsp;";
	else
		$pager .= "&nbsp;<a href=\"".$_SERVER['NAME']."/setmenu/".$_GET['edit']."/".$i."\">".$i."</a>&nbsp;";
	}
}
$pager .= "</div>"; 
?>
