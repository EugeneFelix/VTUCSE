<?php
function selection_sort($data, $pos) {
	for ($i = 0; $i < count($data)-1; $i++) {
		$min = $i; for ($j = $i+1; $j < count($data); $j++) {
			if ($data[$j][$pos] < $data[$min][$pos]) {
				$min = $j;
			}
		} $data = swap_positions($data, $i, $min);
	} return $data;
}

function swap_positions($data1, $left, $right) {
	for ($j = 0; $j < 3; $j++) {
		$backup_old_data_right_value = $data1[$right][$j]; $data1[$right][$j] = $data1[$left][$j]; $data1[$left][$j] = $backup_old_data_right_value;
	} return $data1;
}
echo <<<END
<form action=10.php method=POST>
Student USN: <input type=text name=t1 size=15 maxlen=10>
<br>
Student Name:<input type=text name=t2 size=25>
<br>
Student CGPA::<input type=text name=t3 size=5>
<br>
<input type=submit name=ins value=Insert> &nbsp;&nbsp; <input type=submit name=sname value=SortByName> &nbsp;&nbsp; <input type=submit name=smarks value=SortByMarks>
</form>
END;
if (isset($_POST['ins'])) {
	try {
		$con = "mysql:host=localhost; dbname=studentdb";
		$pdo = new PDO($con, "root", "");
		$usn = $_POST['t1'];
		$name = $_POST['t2'];
		$marks = $_POST['t3'];
		$sql = "INSERT into student values('$usn','$name','$marks')";
		$result = $pdo->query($sql);
		echo "inserted...";
	} catch(Exception $e) {
		echo "DB Error"." ". $e;
	}
}
if (isset($_POST['sname'])) {
	try {
		$student_data = array();
		$con = "mysql:host=localhost; dbname=studentdb";
		$pdo = new PDO($con, "root", "");
		$sql = "SELECT * from student";
		$result = $pdo->query($sql); $cnt = 0;

		while (($row = $result->fetch())) {
			$student_data[$cnt][0] = $row['usn'];
			$student_data[$cnt][1] = $row['name']
			$student_data[$cnt][2] = $row['cgpa'];
			++$cnt;
		} $student_data = selection_sort($student_data, 1);
		echo "<table border><tr><th>USN<th>Name<th>CGPA</tr>"; for ($j = 0; $j < $cnt; $j++) {
			$usn = $student_data[$j][0]; $name = $student_data[$j][1];
			$marks = $student_data[$j][2];
			echo "<tr><td>$usn<td>$name<td>$marks";
		}
	} catch(Exception $e) {
		echo "DB Error";
	}
}
if (isset($_POST['smarks'])) {
	try {
		$student_data = array();
		$con = "mysql:host=localhost; dbname=studentdb";
		$pdo = new PDO($con, "root", "");
		$sql = "SELECT * from student";
		$result = $pdo->query($sql); $cnt = 0; while (($row = $result->fetch())) {
			$student_data[$cnt][0] = $row['usn']; $student_data[$cnt][1] = $row['name']; $student_data[$cnt][2] = $row['cgpa']; ++$cnt;
		}
		$student_data = selection_sort($student_data, 2);
		echo "<table border><tr><th>USN<th>Name<th>CGPA</tr>"; for ($j = 0; $j < $cnt; $j++) {
			$usn = $student_data[$j][0]; $name = $student_data[$j][1];
			$marks = $student_data[$j][2];
			"<tr><td>$usn<td>$name<td>$marks";
		}
	} catch(Exception $e) {
		echo "DB Error";
	}
}
?>