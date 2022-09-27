# Maišos funkcija

## Pseudokodas

## Eksperimentinis tyrimas-analizė

### Tyrimas Nr. 1

#### Aprašymas

Pirmojo tyrimo metu ištirta, ar:
1. Maišos funkcijos įėjimas gali būti bet kokio dydžio simbolių eilutė.
2. Įvedus betkokį maišos funkcijos įėjimą, jos išėjimas visuomet yra to paties, fiksuoto dydžio rezultatas (64 simbolių hex'as).
3. Maišos funkcija yra deterministinė - tam pačiam įvedimui visuomet tas pats išvedimas.

Šiam tyrimui atlikti panaudoti 7 skirtingi tekstiniai failai:
- ***a1.txt*** ir ***a2.txt*** sudaryti tik iš vieno, tačiau skirtingo simbolio;
- ***b1.txt*** ir ***b2.txt*** sudaryti iš 1200 atsitiktinai sugeneruotų simbolių;
- ***c1.txt*** ir ***c2.txt*** sudaryti iš 4380 simbolių ir abu failai skiriasi tik vienu simboliu;
- ***empty.txt*** - visiškai tuščias failas.

Visi testavimui naudoti failai saugomi text-files aplanke.

#### Rezultatai

| Failo vardas | Maišos funkcijos rezultatas|
|:------------:|----------------------------|
|***a1.txt***|a0cd56986528376c04cc452513642a84feb361fe8091828992e261965f743234|
|***a2.txt***|6d582b52a8bd4aa6c95938efdef1574e33261c344d04ff435f771c5c92e14ffe|
|***b1.txt***|c868f1e7011ab44966871c8c704331fa93aae7e1ea1393d5f954096138dab141|
|***b2.txt***|2e9d97f2e7efd25c80727a9996b657ef755f81f40ce6f5c01fa16f74de2fd754|
|***c1.txt***|c7a6734b0ed436e569499e207f8db3569c64654de5dd1179f69a8bcd371433ed|
|***c2.txt***|dbfc90d0128ed57e75137dbb63d750cd803e86d6f987f2e2eac068562b4ed076|
|***empty.txt***|e49b69c12de92c6f4a7484aa5cb0a9dcbf597fc7c6e00bf3d5a7914714292967|

### Tyrimas Nr. 2

#### Aprašymas

Antrojo tyrimo metu ištirta, ar maišos funkcija yra efektyvi (rezultatas pateikiamas greitai).
Tyrimui atlikti panaudotas tekstinis failas ***konstitucija.txt***, sudarytas iš 790 eilučių.
Kiekvieno eksperimento metu panaudota skirtingos apimties įvestis. Pirmo eksperimento metu apskaičiuotas tekstinio failo vienos eilutės apdorojimo laikas, antro eksperimento - dviejų eilučių, trečio - keturių, ketvirto - aštuonių ir t.t. Tai yra, kiekvieno eksperimento metu, įvesties apimtis buvo dvigubinama iki maksimalaus tiriamojo tekstinio failo eilučių skaičiaus. Rezultatai pateikti mikrosekundėmis (1s = 1000000μs).

#### Rezultatai

|Įvesties apimtis (eilučių kiekis)|1|2|4|8|16|32|64|128|256|512|790|
|---------------------------------|-|-|-|-|--|--|--|---|---|---|---|
|**Maišos funkcijos veikimo laikas**|11μs|13μs|15μs|20μs|40μs|65μs|123μs|294μs|684μs|1496μs|2754μs|

<kbd><img src="https://user-images.githubusercontent.com/99316667/192141188-50fc191f-b791-4318-a39e-2f997a35573f.png"></kbd>


### Tyrimas Nr. 3

#### Aprašymas

Trečiojo tyrimo metu ištirta, ar maišos funkcija yra praktiškai atspari kolizijoms. Tyrimo metu generuojama 100000 simbolių eilučių (*string'ų*) porų:
- 25000 porų po 10 atsitiktinių simbolių kiekvienoje simbolių eilutėje;
- 25000 porų po 100 atsitiktinių simbolių kiekvienoje simbolių eilutėje;
- 25000 porų po 500 atsitiktinių simbolių kiekvienoje simbolių eilutėje;
- 25000 porų po 1000 atsitiktinių simbolių kiekvienoje simbolių eilutėje.

Kiekvienoje poroje tikrinami abiejų simbolių eilučių *hash'ai*. Jeigu jie sutampa, aptinkama kolizija.

#### Rezultatai

Atlikus visus testus, kolizijų neaptikta.

```
1# Testing 25000 pairs of strings, each string consists of 10 random symbols...
Collisions detected: 0
2# Testing 25000 pairs of strings, each string consists of 100 random symbols...
Collisions detected: 0
3# Testing 25000 pairs of strings, each string consists of 500 random symbols...
Collisions detected: 0
4# Testing 25000 pairs of strings, each string consists of 1000 random symbols...
Collisions detected: 0
```

### Tyrimas Nr. 4

## Išvados
