<?php
include_once "includes/setmenu.inc";
?>
<script language="JavaScript">
function addRow(){
for(i = 0; i < 5; i++){
	var obj=document.getElementById('aaa');
	var input=document.createElement('input');
	var input2=document.createElement('input');
	var input3=document.createElement('input');
	var br=document.createElement('br');
	input.name='name[]';
	input.placeholder='輸入料理名稱';
	input2.name='price[]';
	input2.placeholder='$$';
	input2.min='0';
	input2.type='number';
	input2.id='number';
	input3.name='sort[]';
	input3.placeholder='飯 or 麵 or 蓋飯';
	input3.type='text';
	input3.size='14';
	obj.appendChild(input);
	obj.appendChild(input2);
	obj.appendChild(input3);
	obj.appendChild(br);
}
}
 </script>
<?php if($_POST['store']||$_GET['edit']){//沒點選店家不會顯示新增選項?>
<form name="form1" method="post" action="">
<div class="left-col">
<?php
echo $message;
?>
<input type="submit" value="確定新增或修改菜單" name="menu">
</div>
<div class="right-col" id="aaa">
<input type="text" name="name[]" placeholder="輸入料理名稱"/>
<input type="number" id="number" placeholder="$$" step='0.5' min=0 name="price[]" size='1'/>
<input type='text' name="sort[]" placeholder='飯 or 麵 or 蓋飯' size=14>
<input type="button" value="增加欄位" onclick="addRow();" name="submitmenu"/><br>
</div>
</form>
<?php }
/*
<form method="post" action="">
<select name="store">
<?php
if($_POST['store']!=""||$_GET['edit']!=""){
echo "<option>".$s."</option>";
}
else{
echo "<option>===請選店家===</option>";
}
foreach($store as $key=>$value){
echo "<option>".$value['name']."</option>";
}
?>
</select>
<input type="submit" value="就是這間" />
</form>
*/
?>
