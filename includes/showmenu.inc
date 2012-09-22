<?php
$sid=$_GET['sid'];
$search = mysql_query("select * from menu where storeid ='".$sid."' order by sort,price");
$num_row = mysql_num_rows($search);
if($num_row){
    $menu = array();
	$end = 20;
	if($_GET['page'])
		$start = ($_GET['page']-1) * $end;
	else
		$start = 0;
	if($num_row>$end)
		$search = mysql_query("select * from menu where storeid ='".$sid."' order by sort,price limit ".$start.",".$end);
    while($res = mysql_fetch_array($search,MYSQL_ASSOC)){
            $menu[] = $res;
    }
    foreach($menu as $key=>$value){
        	$menulist .= "<div class=\"hori\"><div class='sort'>".$value['sort']."</div>";
			$menulist .= "<div class=\"title\">".$value['name']."</div><div class=\"price\">".$value['price']."&nbsp;&nbsp;&nbsp;&nbsp;元</div></div>";
	}
}
else
    $menulist .= "<br>還沒有菜單喔！";
$menulist .= "<span class='inline'>[<a href='".$_SERVER['NAME']."/setmenu/".$sid."/".$_GET['page']."'>編輯菜單</a>]</span>";
mysql_free_result($search);
global $storinfo;
$storary = array();
$search = mysql_query("select * from store where id='".$sid."'");
$storary = mysql_fetch_array($search,MYSQL_ASSOC);
if($storary['last_ip'] != $ip){
	mysql_query("update store set click=click+1 where id='".$sid."'");
	mysql_query("update store set last_ip='".$ip."' where id='".$sid."'");
}
mysql_free_result($search);
$storinfo = "<div class='shadow'><span class='inline'>店名：".$storary['name']."</span><br>";
$storinfo .= "<span class='inline'>電話：".$storary['phone']."</span><br>";
$storinfo .= "<span class='inline'>地址：".$storary['address']."</span><br>";
$storinfo .= "<span class='inline'>外送限制：</span>";
if($sotrary['condition_limit'])
	$storinfo .= $storary['condition_limit']."人</span><br>";
else
	$storinfo .= "未設定</span><br>";
$storinfo .= "<span class='inline'>營業時間：".substr($storary['open'],0,5)."&nbsp;-&nbsp;".substr($storary['close'],0,5)."</span><br>";
$storinfo .= "<span class='inline'>更新時間：</span>".date("Y/m/d",$storary['update_date'])."<br>";
$storinfo .= "<span class='inline'>瀏覽次數：</span>".$storary['click']."</div><br>";
$storinfo .= "<span class='inline'>[<a href='".$_SERVER['NAME']."/setstore/".$sid."'>編輯店家</a>]</span>";
// Page
$pages = ceil($num_row/$end);
$pager = "<div class=\"in-page\">";
if( $pages > 1){
for($i=1;$i<=$pages;$i ++){
if($i == $_GET['page'])
	$pager .= "&nbsp;".$i."&nbsp;";
else
	$pager .= "&nbsp;<a href=\"".$_SERVER['NAME']."/showmenu/".$_GET['sid']."/".$i."\">".$i."</a>&nbsp;";
}
}
$pager .= "</div>";
?>
