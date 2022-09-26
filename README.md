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
|--------------|----------------------------|
|***a1.txt***|6bed734dae0812b9cfec60f0d8440f513593442b4bb1a75c59c24443945417e1|
|***a2.txt***|729ae908b77f88fcd69bfab5c13395142ce4de6e52c63d1940b5de068d238da4|
|***b1.txt***|6fd95bd1a6ab1e7fc136b6bad7f29bcc341b4dd74da239e35ee5a3579f6b1b77|
|***b2.txt***|efd7acff26a5e9514138419457fc6ce2b415baf9cdaccecddeeb54791f65ec59|
|***c1.txt***|ff37cfe636458a4851d8228d471c0ffba4f5d9e0dd4cadd4ce0b37600f858f40|
|***c2.txt***|0cfd28a4c58f6d0aa212c5cfb4d6e8b9573f3ea22e864a963dc1d022fc4f6802|
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

### Tyrimas Nr. 4

## Išvados
