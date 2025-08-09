# penguins-bootloaders

Utilizzare i bootloaders di Debian per avviare molte distribuzioni, è molto comodo semplificando il codice di penguins-eggs, tuttavia nella versione attuale: `/bootloaders` è semplicemente un folder sotto penguins-eggs e si scontra con diversi problemi:
* il pacchetto cresce, ha già superato i 50 Mb e stiamo ai limiti con github per la penguins-eggs-ppa;
* non posso più costruire i pacchetti per i386 ed arm64, perchè - di fatto - sto includendo solo codice amd64.

A questo punto ho deciso di staccare `/bootloaders` da penguins-eggs e creare dei nuovi pacchetti, da cui eggs dipenderà: `penguins-bootloaders-pc` e `penguins-bootloaders`. 

Dpvremmo, quindi, creare tre pacchetti diversi - uno per ogni architeturra - due per i pc ed uno per le SBC.
* `penguins-bootloaders-pc-i386`
* `penguins-bootloaders-pc-amo64`
* `penguins-bootloaders-arm84`

penguins-eggs dovrà riportare come dipendenza `penguins-bootloaders-pc|penguins-bootloaders` per assicurarsi di avere - sempre - disponibili su `/usr/lib/penguins-bootloaders`, per l'architettura specifica i bootloader appropriati.

## git-buildpackage
Assicurati che sul sistema siano installati:
```
sudo apt-get install \
    build-essential \
    devscripts \
    dh_make \
    git-buildpackage 
```

## Workflow
* Tutto lo sviluppo avviene in upstream e NON con la cartella `debian`;
* Il branch `master` contiene il codice unito alla cartella `debian`. Serve solo per la pacchettizzazione.

Fai tutte le modifiche al pacchetto in upstream, e fai il commit su upstrame.
1. git checkout master
2. fai il lavoro ed alla fine fai il commit su upstream
3. git tag 1.4

Passaggio a master
1. git checkout master
2. git merge 1.4
3. dch -v 1.4-1 "Rilascio versione 1.4."
4. git add debian/changelog
5. git commit -m "Release 1.4-1"


# Cosa faremo per le altre distribuzioni
Fare tutto questo lavoro per ogni distribuzione sarebbe tedioso, per cui accetteremo due limitazioni: non potremo avviare con Secure Boot ed avremo un 30 MB di spazio in più su ogni ISO creata co le varie distro.L'idea è di copiare il contenuto di `/usr/lib/bootloaders` e creare con esso dei pacchetti specifici per: alpine, aur, el9, fc42 ed opensuse.

* `penguins-bootloaders-alpine`
* `penguins-bootloaders-aur`
* `penguins-bootloaders-el9`
* `penguins-bootloaders-fc42`
* `penguins-bootloaders-opensuse`

