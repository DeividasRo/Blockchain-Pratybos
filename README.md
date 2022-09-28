# Maišos funkcija (v0.1)

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
|***a1.txt***|b4cf0bbb7bf6dc381f5799bb092595a6edd30d0d97a7b298847a14f943f8d918|
|***a2.txt***|7c206318b319b49bd7b8f118c1cafd05253c65ae5f48da3b4c957c5a8b17b1bb|
|***b1.txt***|02f857d1cb8a127fac17bababad397cc593a41d7208335e333c4af57f24a1777|
|***b2.txt***|105e889bd92ccd35beb165f0a87548864b9c9e9d3225eaa92162701de0ecc83d|
|***c1.txt***|3b7c05f3f20e405d9593e8988357c5ee60be13f5190767c10a40fd75cbce4555|
|***c2.txt***|a1b311d768c154790f5cfcbc1998d1cafa7107d183c873e5908fe95151015171|
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
Testing hash function collisions:
1# 25000 pairs of strings, 10 random symbols per string...
Collisions detected: 0

2# 25000 pairs of strings, 100 random symbols per string...
Collisions detected: 0

3# 25000 pairs of strings, 500 random symbols per string...
Collisions detected: 0

4# 25000 pairs of strings, 1000 random symbols per string...
Collisions detected: 0

```

### Tyrimas Nr. 4

#### Aprašymas

Ketvirto tyrimo metu ištirta, ar maišos funkcija turi lavinos (*avalanche*) efektą.
Tyrimo metu generuojama 100000 simbolių eilučių (*string'ų*) porų:
- 25000 porų po 10 atsitiktinių simbolių kiekvienoje simbolių eilutėje, kiekviena pora skiriasi 1 simboliu;
- 25000 porų po 100 atsitiktinių simbolių kiekvienoje simbolių eilutėje, kiekviena pora skiriasi 1 simboliu;
- 25000 porų po 500 atsitiktinių simbolių kiekvienoje simbolių eilutėje, kiekviena pora skiriasi 1 simboliu;
- 25000 porų po 1000 atsitiktinių simbolių kiekvienoje simbolių eilutėje, kiekviena pora skiriasi 1 simboliu.

Kiekvienoje poroje tikrinami abiejų simbolių eilučių *hash'ai* šešioliktainiu formatu ir dvejetainiu formatu. Tikrinamas kiekvienas simbolis ir nustatomas procentinis abiejų *string'ų* skirtingumas.

#### Rezultatai

Atlikus testus nustatyta, kad šešioliktainiame lygmenyje vidutinis skirtingumas lygus **92%**, o dvejetainiame lygmenyje vidutinis skirtumas lygus **49%**.

```
Testing hash function avalanche effect: 
1# 25000 pairs of strings, 10 random symbols per string, only 1 differing symbol per pair...
Min hex difference: 37%
Max hex difference: 100%
Average hex difference: 92%
Min bit difference: 18%
Max bit difference: 84%
Average bit difference: 49%

2# 25000 pairs of strings, 100 random symbols per string, only 1 differing symbol per pair...
Min hex difference: 50%
Max hex difference: 100%
Average hex difference: 92%
Min bit difference: 18%
Max bit difference: 81%
Average bit difference: 49%

3# 25000 pairs of strings, 500 random symbols per string, only 1 differing symbol per pair...
Min hex difference: 37%
Max hex difference: 100%
Average hex difference: 92%
Min bit difference: 18%
Max bit difference: 81%
Average bit difference: 49%

4# 25000 pairs of strings, 1000 random symbols per string, only 1 differing symbol per pair...        
Min hex difference: 50%
Max hex difference: 100%
Average hex difference: 92%
Min bit difference: 15%
Max bit difference: 84%
Average bit difference: 49%
```

## Išvados
