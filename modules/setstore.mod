<?php
include_once "includes/setstore.inc";
?>
<script type="text/javascript">
	function hide(){
		document.getElementById('formdiv').style.display = 'none';
	}
</script>
<div id="formdiv">
<form action="" method="post" enctype="multipart/form-data" onsubmit="hide();">
<ol>
<li><label>店名：</label>
<input name="name" required type="text" size="40" value="<?php echo $name ?>"/>
</li>
<li><label>電話：</label>
<input name="phone" required pattern="[0-9]+[-]?[0-9]+" type="text" size="40" value="<?php echo $phone ?>"/>
</li>
<li><label>地址：</label>
<input name="address" required type="text" size="40" autocomplete="on" value="<?php echo $address ?>"/>
</li>
<li><label>餐廳類型：</label>
<input name="storetype" type="text" size="40" value="<?php echo $storetype ?>"/>
<select name="storetype2" required>
<?php echo $typelist ?>
<select>
</li>
<li><label> 有沒有送餐限制：</label>
<input name="delivery" type="radio" value="0"<?php if($delivery=="0") echo "checked";?>>沒有
<input name="delivery" type="radio" value="1"<?php if($delivery=="1") echo "checked";?>>有
</li>
<li><label>限制是最少：</label>
<input name="condition" type="text" size="4" value="<?php echo $condition ?>"/>
<input name="condition2" type="radio" value="人份" <?php if($condition2=="人份") echo "checked";?>>人份
<input name="condition2" type="radio" value="元" <?php if($condition2=="元") echo "checked";?>>元
</li>
<li><label>營業時間：</label>
<input name="open" required type="time" step=1800 value="<?php echo $open ?>" />
到
<input name="close" required type="time" step=1800 value="<?php echo $close ?>" />
</li>
<input class="biggerbutton" type="submit" name="<?php if($error!="ok")
echo "submit\" value=\"確認資料"; else echo "submit2\" value=\"送出囉";?>"  />
</ol>
</form>
</div>
<?php
if($_POST['submit'])
{
	if(trim($error)!="ok"){
		switch(trim($error)){
			case "name":
				echo "你沒打店家名字喔。";
				break;
			case "address":
				echo "店家沒住址嗎？";
				break;
			case "phone":
				echo "沒電話就不能叫外送了啦";
				break;
			case "storetype":
				echo "這是快餐還是素食呢？";
				break;
			case "condition":
				echo "外送限制是啥啦";
				break;
			case "condition2":
				echo "沒限制你是填辛酸的喔";
				break;
			default:
				break;
		}
	}
}
?>
