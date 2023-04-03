<?php
	$f = fopen("./data/6_php_count.txt", "r+");
	$line = fgets($f);
	fseek($f, 0);
	$line++;
	echo "<h2>This webpage was visited " . $line." times during the current session</h2>";
	fwrite($f, $line);
	fclose($f);
?>
<html>
	<body>
	</body>
</html>