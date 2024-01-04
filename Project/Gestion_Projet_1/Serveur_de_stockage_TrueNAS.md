# TrueNAS

---------------------------------------------------------------------------------------------
## STEP 1
### Confgue TrueNAS, finalisation

**Explication** : Nous allons donc créer et configuré un serveur truenas depuis son iso, avec une configuration normal, afin d'obtenir son ip de connection, pour en arriver jusque la : 

![TrueNAS_1_FinishConfigue](https://github.com/Asthral/Efrei/assets/151788916/6c991957-1eb5-4909-8a85-e38ce0d420c2)

---------------------------------------------------------------------------------------------
## STEP 2
### Acces Login au TrueNAS

**Explication** : Nous allons donc pouvoir nous connecter sur un navigateur avec `http://192.168.73.129/` nous amenant à la page de connection, dans laquel nous entrons root:root (Reset passwd root avec 7 dans le terminal si il est oublié)

![TrueNAS_2_AccesLogin](https://github.com/Asthral/Efrei/assets/151788916/5a46768e-5ad3-4fd1-a36a-1a5b1b2dc84f)

---------------------------------------------------------------------------------------------
## STEP 3
### Ajout des disques

**Explication** : Nous allons créer et ajouter un disque sur VMware pour truenas afin de débuter le Raid Miroir, car il est nécessaire d'avoir plusieurs disques (si l'un est perdu, l'autre peut-donc prendre la relève), il existe plusieurs type de Raid mais nous allons rester sur celui-ci.

![TrueNAS_DisqueSTockage](https://github.com/Asthral/Efrei/assets/151788916/a7561b5b-5e6f-46f7-85a2-d25d28edc1db)

---------------------------------------------------------------------------------------------
## STEP 4
### Création Pool, Dataset + Permission, ACL

**Explication** : Création d'un pool via TrueNas avec les différentes configurations à faire (permission, DataSet, Groupe, ACL etc...)

Ajout du disque dur (20Go) : 

![TrueNAS_4_ConfiguePool](https://github.com/Asthral/Efrei/assets/151788916/048f4e07-df8a-42d6-b1c0-1a92072a92f5)

Création des DataSet (chaque utilisateur), j'ai pris les noms de mes camarades :

![TrueNAS_4_AddDataSet](https://github.com/Asthral/Efrei/assets/151788916/fe4dc794-0c62-48df-acba-7e6257827352)

Gestion des permissions ACL 1 :
Qui à quoi comment permission, et de quel type. 

![TrueNAS_4_ACLPermission](https://github.com/Asthral/Efrei/assets/151788916/9e3f98f6-0e52-4971-b883-6dfc9e18432e)

Gestion des permissions ACL 2 :
Spécification des groupes qui auront leur permission particulière, dans notre cas il y aura le groupe utilisateur et le groupe admin.

![TrueNAS_4_ConfiguePermissionACL](https://github.com/Asthral/Efrei/assets/151788916/5515ee22-d0b9-471b-a889-63d22aec1bd0)

**Resultat** :

![TrueNAS_4_PoolsResultat](https://github.com/Asthral/Efrei/assets/151788916/9035f2cc-3ccb-4fe2-aedd-28155ef1dafc)

---------------------------------------------------------------------------------------------
## STEP 5
### acces par NFS / SMB

**Explication** : Nous allons faire un partage de dossier à distance, tout comme le fais windows en NFS, nous allons le faire en SMB sur kali (problème windows), en commencant par la création d'utilisateur, puis l'ajout des dossiers et enfin la connection aux dossiers.

Ajouts des utilisateurs pouvans se connecter : 

![TrueNAS_5_CreateUser](https://github.com/Asthral/Efrei/assets/151788916/7bc436be-88d8-4aff-90e9-e3a2cd0d9727)

ajout de fichier accessible par SMB : 

![TrueNAS_5_SMBAdd](https://github.com/Asthral/Efrei/assets/151788916/31bac52e-f5ec-4195-9770-ed50e86df15a)

**Command** : `smbclient` //ip/repertoir -U utilisateur

Sur kali : 

![TrueNAS_Devinette](https://github.com/Asthral/Efrei/assets/151788916/ce04f941-0512-4115-8acb-4732b65ae4a1)

Nous pouvons créer ajouter changer des dossiers / fichiers depuis l'utilisateur erwan créé précédemment, pour accedé entre autre à son espace de stockage privée.

### AD

**Explication** : Configuration global du réseau de notre serveurde stockage

![TrueNAS_5_ChangeConfigueNetWork](https://github.com/Asthral/Efrei/assets/151788916/e4e0be20-208a-4b69-aed8-1d82eb290888)

Configuration du domain pour l'AD :

![TrueNAS_5_ADConfigue](https://github.com/Asthral/Efrei/assets/151788916/79c4791f-9b15-47bd-be20-c7c9a8b6a542)

---------------------------------------------------------------------------------------------
## STEP 6
### 

**Explication** : Installer wireguard, specifier une commande qui créer un fichier .conf et qui l'active automatiquement pour activer le vpn (visible avec ifconfig) ensuite)

Commmande wireguard à configue pour le truenas :

![TrueNAS_6_WireguardAutoCommande](https://github.com/Asthral/Efrei/assets/151788916/c5654df3-7544-457c-b88c-6f54e49308e8)

vpn isible par terminal Kali (problème d'activation sur TrueNAS, je l'ai fais manuellement) :

![TrueNAS_6_wireguardfinaly](https://github.com/Asthral/Efrei/assets/151788916/256579da-d1a2-4e90-a272-a7ab77e97fe3)


