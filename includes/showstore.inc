<?php
$end = "16";
if($_GET['page']!="")
	$start = ($_GET['page']-1)*$end;
else
	$start = 0;
$search = mysql_query("select * from store order by update_date desc");
$num_row = mysql_num_rows($search);
if($num_row>$end)
	$search = mysql_query("select * from store order by update_date desc limit ".$start.",".$end);
else
	$search = mysql_query("select * from store order by update_date desc limit ".$start.",".$num_row);
$store = array();
while( $row = mysql_fetch_array($search,MYSQL_ASSOC) )
	$store[] = $row;
mysql_free_result($search);
$pages = ceil($num_row/$end);
$pager = "<div>";
for($i=1;$i<=$pages;$i ++){
	if($i == $_GET['page'])
		$pager .= "&nbsp;".$i."&nbsp;";
	else{
		if($_GET['sid'])
			$pager .= "&nbsp;<a href=\"".$_SERVER['NAME']."/showstore/".$_GET['sid']."/".$i."\">".$i."</a>&nbsp;";
		else
			$pager .= "&nbsp;<a href=\"".$_SERVER['NAME']."/showstore/0/".$i."\">".$i."</a>&nbsp;";
	}
}
$pager .= "</div>";
echo mysql_error();
?>
