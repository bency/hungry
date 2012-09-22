<?php
for($i=$_GET['page']*10;$i<$_GET['page']*10+10;$i++){
if($i<10){
echo $i."<img src=\"http://18hmm-cgcomd.servik.com/".$_GET['col']."/00".$i.".jpg\">";
}
elseif($i<100){
echo $i."<img src=\"http://18hmm-cgcomd.servik.com/".$_GET['col']."/0".$i.".jpg\">";
}
else
echo $i."<img src=\"http://18hmm-cgcomd.servik.com/".$_GET['col']."/".$i.".jpg\">";
}
echo "<a href=\"/a.php?page=".($_GET['page']+1)."&col=".$_GET['col']."\">next</a>";
echo "<a href=\"/a.php?col=".($_GET['col']+1)."\">next col</a>";
?>
