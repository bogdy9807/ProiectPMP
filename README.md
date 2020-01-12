# Proiect Roboti Gemeni

Acest proiect consta in programarea a doi roboti astfel incat sa efectueze aceleasi miscari, miscari ce sunt indicate de catre utilizator printr-o conexiune wifi cu unul dintre roboti numit robot master. Miscarile sunt transmise prin bluetooth celui de-al doilea robot numit robot slave.
Robotii vor fi controlati prin doua placuta arduino mega 2560 utilizate pentru conexiuni. Pe una dintre placute (cea care controleaza robotul master) se va pune un modul bluetooth setat ca master si modulul de wifi. Pe cealalta placuta se va pune doar modulul bluetooth slave.

## Descrierea componentelor utilizate

Componentele utilizate sunt:

*doua punti H (pentru roboti)
*patru motoare DC 6v(pentru roboti)
*doua placi de dezvoltare arduino uno(pentru roboti)
*doua placi de dezvoltare arduino mega 2560(pentru modulele de conexiune)
*doua module bluetooth **HC-05** pentru comunicare placuta de control pentru robot master - placuta de control pentru robot slave
*un modul wifi **esp8266 esp-01** prin care utilizatorul transmite comenzile robotilor

## Setarea modulelor de conexiune

Instructiunile pentru setarea modulului wifi se gasesc [aici](https://www.instructables.com/id/Learn-How-to-Setup-the-Wifi-Module-ESP8266-by-Usin/)
Modulele de bluetooth necesita setare inainte de utilizare pentru ca amandoua sa comunice intre ele. Unul trebuie setat ca master (cel de pe placuta pe care se afla si modulul wifi) si celalalt ca slave. Indicatii despre setarea acestora se gasesc [aici](https://howtomechatronics.com/tutorials/arduino/how-to-configure-pair-two-hc-05-bluetooth-module-master-slave-commands/)

## Conectarea placutelor la roboti

Placuta mega2560 pe care se afla modulul wifi se va conecta la unul dintre roboti folosind pinii de iesire (13,12 si 11) ce se vor conecta la pinii de intrare (13,12 si A0) ai placutei uno a robotului master.
Cealalta placuta mega2560 pe care se afla modulul bluetooth slave se va conecta la robot prin pinii de iesire (13,12 si 10) ce se vor conecta la pinii de intrare (13,12 si A0) ai placutei uno a robotului slave.

## Incarcarea programelor pe placute

*Programul "robot.ino" se va incarca pe amandoi robotii deoarece amandoi functioneaza pe acelasi principiu.
*Programul "bluetoothMaster" se va incarca pe placuta mega2560 ce are modulul wifi conectat la ea.
*Programul "bluetoothSlave" se va incarca pe cealalta placuta mega2560.

## Utilizare

Pentru utilizarea proiectului, avem nevoie de un smartphone pentru a ne conecta la modulul wifi. Se cauta reteaua cu numele dat la setare si se utilizeaza parola stabilita. Dupa conexiune, intram pe pagina web 192.168.4.1 si va aparea interfata de control a robotilor.

*Apasand butonul UP robotii vor merge inainte
*Apasand butonul DOWN robotii vor merge inapoi
*Apasand butonul LEFT robotii vor merge la stanga
*Apasand butonul RIGHT robotii vor merge la dreapta