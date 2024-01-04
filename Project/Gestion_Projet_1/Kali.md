# Kali

---------------------------------------------------------------------------------------------
## STEP 1
### Scan du réseau avec nmap

**Explication** : Nous allons utiliser l'outil nmap, servant à scaner le réseau (les ports, les services utilisers, adresse MAC, ip sur le réseau 192.168.0.0/16 etc...) très pratique.

Dans notre cas nous scannons notre réseau car nous somme en local, nous identifions l'ip de la machine cible et nous utilisons des paramètres en plus afin d'avoir le maximum d'information.

**Commande** : `nmap 192.168.73.0/24`

**Commande** : `sudo nmap -n -PN -sS 192.168.73.133`

![Kali_1_Nmap](https://github.com/Asthral/Efrei/assets/151788916/3df156d7-f3c8-4656-9bf9-90a9dd453d49)

---------------------------------------------------------------------------------------------
## STEP 2
### Ettercap, spoofing

**Explication** : Nous allons faire une attaque MITM, concistant à espoinner le réseau, et voir les paquets important qui y passe, notamment les user:password etc...

**Commande** : `sudo ettercap -T -q -i eth0`

![Kali_2_MITMettercap](https://github.com/Asthral/Efrei/assets/151788916/e65ec558-e145-4a87-ab05-fb2fb2bc50da)

---------------------------------------------------------------------------------------------
## STEP 3
### DDOS

**Explication** : Nous allons pour cette fois DDOS le serveur, avec un tool appelé Slowloris, qui va envoyer un multitide de paquets, afin de faire déborder le serveur qui va ensuite crasher. (dans notre cas nous avions une session mais la page ne se recharge plus)

![Kali_3_SlowlorisDDOS](https://github.com/Asthral/Efrei/assets/151788916/56410e22-47ba-46a5-9e63-5ef3c09ba240)

---------------------------------------------------------------------------------------------
## STEP 4
### Hydra Brute Force

**Explication** : Pour finir, avec un test encore une fois très basique, Hydra, qui va tester chaque possibilités d'une liste que nous lui donnons, afin qu'il les testes et trouve le mot de passe / nom d'utilisateur cherché.

/!\ j'ai créer un fichier avec le mot de passe pour montrer que ça fonctionne, mais Roo.123.oot n'est pas dans rockyou, et la wordlist probable fais 27Go...

**Commande** : `unzip /usr/share/wordlists/rockyou.tar.gz -d Desktop/`

**Commande** : `hydra -l root -P Desktop/rockyou.txt 192.168.73.133 http-post-form "/nextcloud/index.php/login:user=^USER^&password=^PASS^:Nom d'utilisateur ou mot de passe incorrect"`

![Kali_4_HydraBruteForce](https://github.com/Asthral/Efrei/assets/151788916/94586ab1-6c94-477f-a9b5-8582738d788a)

