<?php
switch($_GET['id'])
{
	case '21':
		$module = "modules/setstore.mod";
		$header = "編輯店家";
		break;
	case '22':
		$module = "modules/setmenu.mod";
		$header = "編輯菜單";
		break;
	case '11':
		$module = "modules/showstore.mod";
		$header = "所有店家列表-肚子餓";
		break;
	case '12':
		$query = mysql_query("select * from store where id='".$_GET['sid']."'");
		$store = array();
		$res = mysql_fetch_row($query,MYSQL_ASSOC);
		$module = "modules/showmenu.mod";
		$header = "「".$res['name']."」的菜單列表-肚子餓";
		$description = "店名：".$res['name']."<br>店址位於：".$res['address']."<br>營業時間為".$res['open']."至 ".$res['close']."<br>外送專線：".$res['phone'];
		break;
	case '23':
		$module = "modules/editstore.mod";
		$header = "修改店家資訊";
		break;
	case '31':
		$module = "modules/status.mod";
		$header = "肚子餓了沒";
		break;
	default:
		$module = "modules/index.mod";
		$header = "肚子餓了沒";
		$description = "肚子餓是一個你肚子餓想不到東西吃的時候的好朋友，他可以告訴你哪裡好吃、哪裡可以吃、哪裡可以外送、什麼時候可以外送，是你生活及待在實驗室的好朋友！";
		break;
}
?>
