# Objektinis2uzdt


### V1.1
### Kaip paleisti programą?<br>
Norint susiinstaliuoti programą reikia turėti mingw ir parsisiųsti visus failus iš git repozitorijos (https://github.com/Nojus15/Objektinis2uzdt.git). Vėliau naudojantis cmd(command prompt) nueiti į direktoriją, kurioje yra failai ir parašyti komandą "mingw32-make" jei naudojate Windows'us, jei kitą OS, tada parašyti "make". Programa suinstaliuota, ją paleisti galima su komanda "./main". Norint ištrinti reikia parašyti "mingw32-make clean".
### Kaip veikia programa:<br>
- Pradžioje pasirenkate ar norite generuoti failą, ar ne. Jei taip, reikia įvesti failo pavadinimą, studentų kiekį ir pažymių kiekį. Failas bus sugeneruotas ir programa baigta.
- Jei pasirinkote negeneruoti failo, tada reikia pasirinkti ar duomenis noresite įvedinėti ranka (įveskite 1), ar skaityti iš failo (įveskite 0).
- Jei pasirinkote duomenis nuskaityti iš failo reikalingi tolimesni žingsniai:
  - Pasirinkti konteinerio tipą. 1 - vector, 2 - list, 3 - deque.
  - Pasirinkti strategijos tipą. 1 - greitesne bet naudoja daugiau atminties, 2 - letesne, bet naudoja mažiau atminties.
  - Įvesti failo pavadinimą. Jei paliksite tuščia bus nuskaitomas studentai.txt failas.
  - Toliau programa išves rezultatus į 2 skirtingus failus. Jei vidurkis ir mediana didesni už 5, duomenys vedami į "kietiakai.txt", kitu atveju į "vargsai.txt".
- Jei pasirinkote rašyti ranka, reikalingi tolimesni žingsniai:
  - Reikia pasirinkti ar egzamino vertinimas bus rašomas ranka (įvesti 1), ar generuojamas automatiškai(įvesti 0).
  - Toliau reikia pasirinkti ar pažymiai bus rašomi ranka (įvesti 1), ar generuojami automatiškai(įvesti 0).
  - Tada pradedamas studentų įvedimas. Studentų kiekis yra dinamiškas. Jei norite įvesti studentą, reikia spausti 1, jei pabaigti - 0. <br>
  - Įvedus 1 pradedamas naujo studento duomenų ivedimas. Pradžioje ivedamas vardas ir pavardė.
  - Vėliau įvedamas egzamino rezultatas.<br>
  - Po to seka pažymių ivedimas. Jeigu pažymiai vedami ranka, tai baigus juos vesti reikia ivesti 0. Jei generuojami automatiškai, tai norint sugeneruoti dar viena pažymį reikia   ivesti 1, o norint sustoti - 0.<br>
  - Suvedus šiuos duomenis vel paklausiama ar norite įvesti dar vieną studentą. Taip ciklas kartosis kol šiame žingsnyje įvesite 0.
  - Rezultatai suvedami į "rez.txt" failą.


(Pažymių vidurkis sudaromis vadovaujantis šia formule: galutinis = 0.4 * vidurkis + 0.6 * egzaminas)<br>
(Pažymių mediana sudaroma vadovaujantis šia formule: mediana = 0.4 * pažymių mediana + 0.6 * egzaminas)<br>

### Spartos analizė pagal strategijas:<br>

#### Struct ir class spartos palyginimas 
#### Bendras programos veikimo laikas be generavimo naudojant vektoriu ir pirmą strategiją
| Students       | 100.000          | 1.000.000      |
| :----------    | :------------    | :-------       |
| Struct         | 1.572413 s       | 9.413181 s     |
| Class          | 0.552313 s       | 5.47949 s      |

#### Programos (naudojant class ir vector) veikimo laikas priklausomai nuo optimizavimo lygio
| Students       | 1000          | 10.000      | 100.000      | 1.000.000     | 10.000.000   |
| :----------    | :------------ | :-------    | :---------   | :----------   | :----------  |
| O1             | 0.0147449 s   | 0.100956 s  | 0.584785 s   | 5.61137 s     | 57.8394 s    |
| O2             | 0.0132218 s   | 0.100368 s  | 0.55616 s    | 5.52116 s     | 58.4422 s    |
| O3             | 0.0134734 s   | 0.10079 s   | 0.558621 s   | 5.45973 s     | 58.3061 s    |