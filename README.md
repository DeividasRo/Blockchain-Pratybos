# Maišos funkcija (v0.1)

## Pseudokodas

Pseudokodas pavaizduoja funkcijos Hash() pagrindinius skaičiavimus ir veikimo principą.

```
Sub Hash(string INPUT)
    Initialize var MAX_PRIME with desired prime value
    Initialize array HEX_ARR of with 8 32bit prime hex values
    Initialize array PRIMES with 30 different primes values smaller than MAX_PRIME
    for i = 0 to INPUT length - 1:
        Initialize var ASCII set to INPUT[i] ascii value 
        Initialize X set to PRIMES[ASCII MOD 30] / (MAX_PRIME + ASCII / 10) * pow(2, 32)
        for j = 0 to 8:
            Initialize var TEMP with no value
            HEX_ARR[j] = HEX_ARR[j] xor X
            TEMP = HEX_ARR[j]
            HEX_ARR[j] = HEX_ARR[j] >> 5
            HEX_ARR[j] = HEX_ARR[j] xor TEMP
    Append all HEX_ARR values in 32bit format and push them to var HEX_HASH
    Return HEX_HASH as string
```

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

Tekstinio failo turinio *hash'avimui* naudojama komandinės eilutės komanda `prog <filename.txt>`.

#### Rezultatai

| Failo vardas | Maišos funkcijos rezultatas|
|:------------:|----------------------------|
|***a1.txt***|c8adfafc04f699d80e4f72453e2910606afd3dddf71533a7e9cc2ac5480f7e52|
|***a2.txt***|0042925fcc19f17bc6a01ae6f6c678c3a212557e3ffa5b042123426680e016f1|
|***b1.txt***|7d66569cb76d6c6fbd83f3098c6ad877da0dcd62432ccb2a5d049095f9e0e7bb|
|***b2.txt***|6fc089d6a5cbb325af252c439ecc073dc8ab1228518a14604fa24fdfeb4638f1|
|***c1.txt***|44e204be8ee93e4d8407a12bb5ee8a55e3899f407aa899086480c2b7c064b599|
|***c2.txt***|de2d109a14262a691ec8b50f2f219e7179468b64e0678d2cfe4fd6935aaba1bd|
|***empty.txt***|9b05688c510e527f5be0cd196a09e6673c6ef372a54ff53abb67ae851f83d9ab|

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

Testas paleidžiamas komandinės eilutės komanda `prog colltest`.

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

Testas paleidžiamas komandinės eilutės komanda `prog avaltest`.

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

Apibendrinant, maišos funkciją pavyko pritaikyti visiems iškeltiems reikalavimams. Stipriausia šios realizacijos pusė - trumpas rezultato apskaičiavimo laikas. Nors praktiškai kolizijų nerasta, didesnėje skirtingų simbolių imtyje ir testuojant skirtingų ilgių *string'ų* poras kolizijų turėtų atsirasti ir jų būtų daugiau, nei įmanoma išvengti turint optimaliausią maišos funkcijos realizaciją. Pirminiai skaičiai naudojami skaičiavimuose parinkti ganėtinai atsitiktinai, taip pat galima būtų paeksperimentuoti su jų bendru kiekiu ir papildomu panaudojimu skaičiavimuose. 
