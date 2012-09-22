  <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd[1]">
<?php
session_start();
include "connect.php";
include "includes/content.inc";
include "includes/function.inc";
include "includes/index.inc";
global $ip;
$ip = getip();
$date = date("Y/m/d H:i:s");
$a = mysql_query("insert into ip_log(ip,date_,request) values('".$ip."','".$date."','".$_SERVER['REQUEST_URI']."')");
if(!$a)
	die('ㄎㄎ'.mysql_error());
$sql = mysql_query("select ip from site_r where ip='".$ip."'");
if(mysql_num_rows($sql)==0)
	mysql_query("insert into site_r(ip,count_,last_day) values('".$ip."','1','".$date."')");
else
	mysql_query("update site_r set count_=count_+1,last_day='".$date."' where ip='".$ip."'");

?>
<html>
<!-- Google Like Start-->
<script type="text/javascript" src="http://apis.google.com/js/plusone.js">
  {lang: 'zh-TW'}
</script>
<!-- Google Like End-->
<body>
<?php include('includes/head.inc'); ?>
<div id="contain">
	<div id="top">
		<div id="top-left"></div>
		<div id="top-right"></div>
	</div>
	<div class="logo">
		<div id="in-logo"></div>
	</div>
<div class="sub-bar">
	<div class="tab-menu">
		<ol>
		<lh><a href="/showstore">店家總覽</a></lh>
		<lh><a href="/setstore">新增店家</a></lh>
		<lh><a href="/">回到美味的首頁</a></lh>
		<lh><g:plusone></g:plusone></lh>
		</ol>
	</div>
</div>
	<div class="left-panel">
		<div id="panel-top"></div>
		<div class="in-left-top"></div>
		<?php include "modules/leftpanel.mod";?>
		<div class="in-left-bottom"></div>
	</div>
	<div class="main-contain">
		<?php include $module;?>
	</div>
	<div class="page"><?php echo $pager;?></div>
	<div class="footer">更新時間:<?php echo date("Y-m-d H:i:s",getlastmod()) ?><br>
	瀏覽人次：<?php echo $people; ?>
	</div>
</div>
<div>
</div>
</body>
</html>
