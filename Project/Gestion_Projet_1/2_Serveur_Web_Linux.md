# Debian

---------------------------------------------------------------------------------------------
## STEP 1
### Installation du serveur

**Explication** : Nous allons télécharger une iso de debian 11, et configurer notre VM, et arriver ici : 

![Capture d'écran 2024-01-04 220052](https://github.com/Asthral/Efrei/assets/151788916/fa4a66af-13af-4bd4-a372-b2028f5cc227)

---------------------------------------------------------------------------------------------
## STEP 2
### Accès sécurisé avec ssh

**Explication** : Nous allons installer Openssh puis nous connecter au serveur debian par ssh

/!\ suite au DDOS du serveur je ne peux plus me connecter depuis Kali, je l'ai donc fais depuis mon serveur TrueNAS

**Commande** : `pkg install openssh-server`

**Explication** : Nous allons maintenant pouvoir nous connecter. Pour être sur vous pouvez faire `systemctl status ssh` pour être sur qu'il soit actif.

**Commande** : `ssh astral@192.168.73.133`

![TrueNAS_ConnectDebianSSH](https://github.com/Asthral/Efrei/assets/151788916/b1c18bde-6203-4c46-acee-dfc615f54ace)

---------------------------------------------------------------------------------------------
## STEP 3
### Installer l'application web

En commençant pas installer tout le nécessaire :

**Commande** : `apt install imagemagick php-imagick libapache2-mod-php php-common php-mysql php-fpm php-gd php-curl php-zip php-xml php-mbstring php-bz2 php-intl php-bcmath php-gmp mariadb-server mysql unzip apache2`

![Debian_1_AptInstall](https://github.com/Asthral/Efrei/assets/151788916/20dd34ef-a427-453a-8426-795fd317ee8e)

**Explication** : ajout d'une Base de données mysql, avec les commandes entré :

**Commande** : `create database nextcloud; create user nextclouduser@localhost identified by 'votre-mot-de-passe'; grant all privileges on nextcloud.* to nextclouduser@localhost identified by 'votre-mot-de-passe'; flush privileges; exit;`

![Debian_2_DataBaseConfigue](https://github.com/Asthral/Efrei/assets/151788916/66f8b51a-8412-42f6-a396-b3756034cac3)

**Explication** : Nous récupérons le contenu nécessaire à la création de nextcloud, que nous dézipons par la suite.

**Commande** : `wget https://download.nextcloud.com/server/releases/latest-24.zip && unzip latest-24.zip -d /var/www/html`

![Debian_3_TakeNextcloud](https://github.com/Asthral/Efrei/assets/151788916/2a6e69f8-8fd0-4cfd-88dc-a846c30ffa51)

**Explication** : Et nous finissons par modifier les permissions, car sans cela nous ne pouvons voir la page.

**Commande** : `chown -R www-data:www-data /var/www/html/nextcloud/` 

**Explication** : En entrant http://ip/nextcloud nous avons accès au serveur web :

![Debian_3_RootConnexion](https://github.com/Asthral/Efrei/assets/151788916/376a22b1-68c0-43b3-af0a-48dd1e48cdc2)

![Debian_3_ConnectéRoot](https://github.com/Asthral/Efrei/assets/151788916/6fbd2bac-62f4-40f4-ae1b-b29f3e14fffc)

---------------------------------------------------------------------------------------------
## STEP 4
### Sécurisé l'accès en https

---------------------------------------------------------------------------------------------
## STEP 5
### Installation du serveur

---------------------------------------------------------------------------------------------
## STEP 1
### Installation du serveur
