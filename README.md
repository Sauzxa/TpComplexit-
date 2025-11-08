# Guide d'Exécution :



## Pour compiler les fichiers C :

- Cliquez droit sur `compile.sh` et cliquez sur "Run Code"
- Ou bien utilisez la commande : `bash compile.sh` (pour Linux), ou simplement `./compile.sh` (il faut être dans le répertoire parent)

## Pour exécuter :

Depuis le terminal (cmd, PowerShell, bash, shell n'importe lequel) :

```bash
./dist/Random100 Docs/primes10.txt
./dist/Random1000 Docs/primes10.txt
./dist/Test-1 Docs/primes10.txt
./dist/Test-2 Docs/primes10.txt
./dist/Test-3 Docs/primes10.txt
```

## Structure des dossiers :

```
TpComplexit-/
└── Tp0/                    # Dossier parent contenant tout le TP0
	├── src/                # Fichiers source C
	│   ├── Random100.c
	│   ├── Random1000.c
	│   ├── Test-1.c
	│   ├── Test-2.c
	│   └── Test-3.c
	├── Docs/               # Documentation et données
	│   ├── primes10.txt    # Fichier de nombres premiers
	│   └── TP 0 Creation de donnees de tests.pdf
	├── dist/               # Exécutables compilés
	├── compile.sh          # Script de compilation
	└── GuideExecution.md   # Ce fichier
```
