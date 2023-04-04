<?php
function displayMatrix($data) {
	foreach($data as $row) {
		foreach($row as $col) {
			echo $col." ";
		}
		echo "<br>";
	}
}

function addMatrix($f, $s) {
	$r1 = count($f);
	$c1= count($f[0]);
	$r2 = count($s);
	$c2= count($s[0]);
	$summat = array();
	if($r1==$r2 && $c1==$c2) {
		for($i=0;$i<$r1;$i++) {
			for($j=0;$j<$c1;$j++) {
				$summat[$i][$j] = $f[$i][$j] + $s[$i][$j];
			}
		}
		print "Matrix A:<br>";
			displayMatrix($f);
		print "Matrix B:<br>";
			displayMatrix($s);
		print "Sum:<br>";
			displayMatrix($summat);
		} else {
			echo "Not possible";
		}
	}
?>