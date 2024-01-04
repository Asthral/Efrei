# Debian

---------------------------------------------------------------------------------------------
## STEP 1
### Installation du serveur

**Explication** : Nous allons télécharger une iso de debian 11, et configurer notre VM, afin de pouvoir configurer le serveur, et pouvoir le lancer.

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

---------------------------------------------------------------------------------------------
## STEP 2
### Accès sécurisé avec ssh

---------------------------------------------------------------------------------------------
## STEP 3
### Installer l'application web

---------------------------------------------------------------------------------------------
## STEP 4
### Sécurisé l'accès en https

---------------------------------------------------------------------------------------------
## STEP 5
### Installation du serveur

---------------------------------------------------------------------------------------------
## STEP 1
### Installation du serveur
