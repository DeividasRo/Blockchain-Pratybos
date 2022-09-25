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
|***a1.txt***|0838b0eecdddd11aac39a353bb91ccf256468788286464ff3a1787e0f781d442|
|***a2.txt***|8e7990524b9cf1a62a7883ef3dd0ec4ed007a734ae254443bc56a75c71c0f4fe|
|***b1.txt***|405f4d9a892d0834eeb0a0f1f8748d871b9d5b9c62242fa87163b51cb0ed0d3c|
|***b2.txt***|5d85eb2994f7ae87f36a0642e5ae2b340647fd2f7ffe891b6cb913afad37ab8f|
|***c1.txt***|c7d553870ea71629693abeec7ffe939a9c174581e5ae31b5f6e9ab0137671321|
|***c2.txt***|67f7097aae854cd4c918e411dfdcc9673c351f7c458c6b4856cbf1fc974549dc|
|***empty.txt***|e49b69c12de92c6f4a7484aa5cb0a9dcbf597fc7c6e00bf3d5a7914714292967|

### Tyrimas Nr. 2

#### Aprašymas

Antrojo tyrimo metu ištirta, ar maišos funkcija yra efektyvi (rezultatas pateikiamas greitai).
Tyrimui atlikti panaudotas tekstinis failas ***konstitucija.txt***, sudarytas iš 790 eilučių.
Kiekvieno eksperimento metu panaudota skirtingos apimties įvestis. Pirmo eksperimento metu apskaičiuotas tekstinio failo vienos eilutės apdorojimo laikas, antro eksperimento - dviejų eilučių, trečio - keturių, ketvirto - aštuonių ir t.t. Tai yra, kiekvieno eksperimento metu, įvesties apimtis buvo dvigubinama iki maksimalaus tiriamojo tekstinio failo eilučių skaičiaus.

#### Rezultatai

|Įvesties apimtis (eilučių kiekis)|1|2|4|8|16|32|64|128|256|512|790|
|---|---|---|---|---|---||---|---||---|---|
|**Maišos funkcijos veikimo laikas**|10ms|13ms|15ms|20ms|40ms|65ms|123ms|294ms|684ms|1496ms|2754ms|

### Tyrimas Nr. 3

### Tyrimas Nr. 4

### Tyrimas Nr. 5

## Išvados
