<?php
function displayMatrix($data) {
	foreach ($data as $row) {
		foreach ($row as $col) {
			echo $col." ";
		}
		echo "<br>";
	}
}

function addMatrix($f, $s) {
	$r1 = count($f);
	$c1 = count($f[0]);
	$r2 = count($s);
	$c2 = count($s[0]);
	$summat = array();
	if ($r1 == $r2 && $c1 == $c2) {
		for ($i = 0; $i < $r1; $i++) {
			for ($j = 0; $j < $c1; $j++) {
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
function mulMatrix($f, $s) {
	$r1 = count($f); $c1 = count($f[0]); $r2 = count($s); $c2 = count($s[0]); $prod = array(); //echo $c1." ".$r2;
	if ($c1 == $r2) {
		for ($i = 0; $i < $r1; $i++) {
			for ($j = 0; $j < $c2; $j++) {
				$prod[$i][$j] = 0; for ($k = 0; $k < $c1; $k++) {
					$prod[$i][$j] = $prod[$i][$j]+($f[$i][$k]*$s[$k][$j]);
				}
			}
		}
		print "Matrix A:<br>";
		displayMatrix($f);
		echo "Matrix B:<br>";
		displayMatrix($s);
		print "Prouct Matrix:<br>";
		displayMatrix($prod);
	} else
		echo "Matrix Multiplication not possible";
}
function calc($num1, $num2, $opr) {
	switch ($opr) {
		case '+': echo "Sum of $num1 and $num2 is ".($num1+$num2)."<br>";
			break;
		case '-': echo "Difference of $num1 and $num2 is ".($num1-$num2)."<br>";
			break;
		case '*': echo "Product of $num1 and $num2 is ".($num1*$num2)."<br>";
			break;
		case '/': echo "Quotient of $num1 divided divided by $num2 is ".($num1/$num2)."<br>";
			break;
	}
}
function transpose($mat) {
	$transpose = array();
	$r1 = count($mat); $c1 = count($mat[0]); for ($i = 0; $i < $r1; $i++) {
		for ($j = 0; $j < $c1; $j++) {
			$transpose[$j][$i] = $mat[$i][$j];
		}
	}
	print "Given Matrix:<br>"; displayMatrix($mat); print
	"Transpose of Matrix:<br>"; displayMatrix($transpose);
}
echo "Demonstration of Calculator with argments (100, 300)<br>";
$num1 = 100;
$num2 = 300;
calc($num1, $num2, '+');
calc($num1, $num2, '-');
calc($num1, $num2, '*');
calc($num1, $num2, '/');
echo "<hr>";
$mat = array(array(1, 2), array(3, 4));
transpose($mat);
echo "<hr>";
$fir = array(array(1, 2), array(3, 4));
$sec = array(array(5, 6), array(7, 8));
mulMatrix($fir, $sec);
echo "<hr>";
addMatrix($fir, $sec);
?>