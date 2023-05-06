/*
Program ten to zbior przepisow na rozmaite potrawy.
sposob dzialania:
1 - wybierz kategorie potrawy
2 - wybierz potrawe z wymienionych
3 - po wykonaniu powyzszych krokow, na ekranie wyswietli sie przepis na wybrana potrawe i skladniki potrzebne do jej wykonania

(wykorzystane przepisy pochodza ze strony www.kwestiasmaku.com)

zupy:
zupa ogorkowa
zupa pomidorowa
rosol
barszcz czerwony
barszcz bialy

dania glowne miesne:
golabki
pulpety
kotlety mielone
kotlety schabowe z pieczarkami
pierogi z miesem

dania glowne bezmiesne:
nalesniki
pierogi z serem i jagodami
pierogi z kapusta i grzybami
pierogi ruskie
kotlety jajeczne z kasza

desery:
sernik
tarta ze sliwkami
piernik czekoladowy
szarlotka
brownie
*/
#include <iostream>
using namespace std;
int main() {
    string skladniki[20][2] = {
        {"zupa ogorkowa", "mieso drobiowe (np. 1 skrzydlo indyka), 1,75 l wody, 1 lyzeczka soli, 1 lyzka ryzu bialego, 4 - 5 ziemniakow, marchew, pietruszka, plaster selera, kawaleczek pora, mala cebula, 1 listek laurowy, 2 - 3 ziela angielskie, kostka rosolowa BIO, ok. 250 g ogorkow kiszonych (4 -5 sztuk), 100 ml mleka, natka pietruszki, koperek, 1 lyzeczka maki, 150 ml smietany 18%."},
        {"zupa pomidorowa", "1 lyzka oliwy extra vergine, 1/2 lyzki masla, 1/2 cebuli, 2 - 3 zabki czosnku, 1 kg dojrzalych swiezych pomidorow, 1/2 lyzki octu winnego lub ryzowego, 1 lyzeczka cukru, 250 ml bulionu jarzynowego lub drobiowego, 2 lyzki posiekanej bazylii."},
        {"rosol", "1 kurczak o wadze okolo 2 kg, 300 g wolowiny, 10 serduszek i 5 zoladkow kurzych lub 1 szyja indycza, 3 litry wody, 2 marchewki, 1 pietruszka, 1 cebula, 2 galazki natki pietruszki, kawalek selera, pora, opcjonalnie liscia kapusty, 1 lyzka soli morskiej, 3 ziarenka ziela angielskiego, 1 lisc laurowy, 4 cale ziarenka pieprzu."},
        {"barszcz czerwony", "2 kg burakow ugotowanych, 2,5 litra bulionu jarzynowego lub miesnego, 1 srednia cebula (posiekana i podsmazona na 1 lyzce masla), 1 listek laurowy, 3 - 4 ziela angielskie, pare ziarenek czarnego pieprzu, 1 lyzka octu."},
        {"barszcz bialy", "300 g wolowiny z koscia, 200 g boczku wedzonego, 7 kawalkow surowej bialej kielbasy, mala marchew, pietruszka, seler, por, cebula, 300 g wedzonej kielbasy, 3 zabki czosnku, lisc laurowy, 4 ziarna ziela angielskiego, 10 ziarenek pieprzu czarnego, majeranek, pieprz ziolowy, 1 lyzka otrab pszennych, 1 - 2 lyzeczki tartego chrzanu, 1 lyzka soku z cytryny lub 1 lyzeczka octu, 100 ml smietanki kremowki 30%, 1 lyzka maki."},
        {"golabki", "700 g mielonej wieprzowiny, 100 g ryzu, 2 cebule, 1 biala lub wloska kapusta, 1,5 litra bulionu lub rosolu, 600 g przecieru pomidorowego, 1 lyzka maki, sol i pieprz, 1 lyzeczka suszonego oregano, 1/2 lyzeczki papryki w proszku, 1/2 lyzeczki tymianku."},
        {"pulpety", "500 g mielonego miesa, 1 cebula, 2 zabki czosnku, 1 lyzeczka suszonego oregano, 1/2 lyzeczki papryki w proszku, 3 lyzki bulki tartej lub ugotowanej kaszy jaglanej, 1 jajko, 125 ml bulionu drobiowego lub rosolu, oliwa, maslo, 350 ml przecieru pomidorowego."},
        {"kotlety mielone", "1 mala bulka, mleko lub woda do namoczenia bulki, 1/2 kg miesa mielonego, 1 srednia cebula starta na tarce, 1 jajko, okolo 1/4 szklanki zimnej wody, bulka tarta do obtoczenia, 1 lyzeczka soli, 1/2 lyzeczki czarnego pieprzu zmielonego."},
        {"kotlety schabowe z pieczarkami", "500 g pieczarek, 2 cebule, 1 kg schabu, 2 lyzki oleju, 2 lyzki masla, jajko, bulka tarta, olej do smazenia, sol, pieprz."},
        {"pierogi z miesem", "500 g ugotowanego miesa z rosolu, ugotowane warzywa z zupy (1 marchewka, 1/2 pietruszki), 300 g pieczarek, 1 duza cebula, 1 lyzka masla, 1 jajko."},
        {"nalesniki", "1 szklanka maki pszennej, 2 jajka, 1 szklanka mleka, 3/4 szklanki wody, szczypta soli, 3 lyzki masla lub oleju roslinnego"},
        {"pierogi z serem i jagodami", "2 szklanki maki, szczypta soli, 1 jajko, 1 szklanka goracej wody, 1 lyzeczka masla lub oleju, 100 g jagod, 100 g sera bialego zmielonego lub twarozku smietankowego, 2 lyzki drobno posiekanej miety, 2 lyzki brazowego cukru."},
        {"pierogi z kapusta i grzybami", "1 sloik litrowy suszonych grzybow, 1 kg kiszonej kapusty, 1 marchewka, 1 pietruszka, 3 cebule, 3 lyzki oleju, 600 g maki pszennej, 1/2 lyzeczki soli, 400 ml wrzacej wody, 50 g masla."},
        {"pierogi ruskie", "600 g maki pszennej, 2 szczypty soli, 400 ml wrzacej wody, 60 g masla, 500 g twarogu, 500 g ziemniakow, 2 lyzeczki soli, 1/2 lyzeczki zmielonego pieprzu ziolowego lub czarnego, 1 mala cebula."},
        {"kotlety jajeczne z kasza", "1/3 szklanki kaszy jaglanej, 1 szklanka mleka, 6 jajek, sol i pieprz, 1 lyzka bulki tartej, 1 lyzka posiekanego koperku, 1/2 lyzki posiekanego szczypiorku, bulka tarta do obtoczenia, maslo klarowane do smazenia."},
        {"sernik", "1 kg zmielonego twarogu, 250 g miekkiego masla, 1 i 1/3 szklanki cukru pudru, 6 jajek, 1 opakowanie cukru wanilinowego, 150 ml smietanki 36%, 4 lyzki maki ziemniaczanej."},
        {"tarta ze sliwkami", "400 g maki pszennej, 6 lyzek cukru, 1/3 lyzeczki soli, 300 g masla, 5 lyzek zimnej wody, 800 g sliwek, 1 lyzka soku z cytryny, 1 lyzeczka cynamonu, 1/4 szklanki cukru, 1/4 szklanki skrobi ziemniaczanej, 1 jajko."},
        {"piernik czekoladowy", "200 g maki pszennej, 100 g maki zytniej, 1 pelna lyzka kakao, szczypta soli, 2 lyzeczki proszku do pieczenia, po 1/2 lyzeczki mielonych gozdzikow, jalowca, cynamonu, galki muszkatolowej, szczypta czarnego pieprzu, 100 g masla, 180 g drobnego cukru, 100 g plynnego miodu, 3 jajka, 5 lyzek mleka, 100 g posiekanej gorzkiej lub deserowej czekolady."},
        {"szarlotka", "1,5 kg jablek (najlepiej twardych i kwasnych), 5 lyzek cukru, 1/2 lyzeczki cynamonu, 320 g maki, 250 g zimnego masla, 1,5 lyzeczki proszku do pieczenia, 5 lyzek cukru, 1 lyzka cukru wanilinowego, 1 jajko, Do posypania: cukier puder."},
        {"brownie", "200 g masla, 200 g gorzkiej czekolady, 3 jajka, 250 g cukru, 135 g maki, mala szczypta soli, dodatkowo: ok. 50 - 100 g gorzkiej czekolady na wierzch."}
    };
    string przepisy[20][2] = {
        {"zupa ogorkowa", "Mieso ugotowac w podanej ilosci osolonej wody do miekkosci (ok. 40 minut). Wyjac je z wywaru, obrac mieso od kosci i skory. Mieso zachowac, pokroic na kawalki. Do wywaru dodac surowy ryz, obrane i pokrojone w kostke ziemniaki, obrana i starta na tarce marchewke, pietruszke oraz selera i pora (w kawalku), a takze obrana cebule w calosci. Gotowac az warzywa beda miekkie (ok. 20 minut), nastepnie dodac listek laurowy, ziele angielskie i kostke rosolowa BIO. Ogorki pokroic w plastry, wlozyc do malego garnka, dodac lyzeczka masla i ok. 1/4 szklanki wody. Dusic pod przykryciem przez ok. 20 minut. Zmiksowac i dodac do garnka z zupa. Zagotowac. Make wymieszac z mlekiem i smietana, nastepnie stopniowo dodawac troche zupy, na koniec calosc przelac do zupy w garnku. Dodac odlozone mieso, zagotowac, posypac posiekana natka i koperkiem."},
        {"zupa pomidorowa", "W garnku na oliwie i masle zeszklic pokrojona w kosteczke cebule oraz pokrojony na plasterki czosnek. Wlac wino jesli je uzywamy i gotowac przez minute. Pomidory sparzyc wrzatkiem, obrac, pokroic na cwiartki, odciac szypulki, miazsz pokroic w kostke. Odlozyc ok. pol szklanki pokrojonych pomidorow a reszte wlozyc do garnka. Dodac ocet i cukier oraz skladniki opcjonalne jesli ich uzywamy (sos worcestershire, ajvar, chili), zagotowac. Wlac goracy bulion i znow zagotowac. Przykryc i gotowac przez ok. 5 minut. Zmiksowac recznym blenderem (zyrafa), ale niekoniecznie na idealnie gladki krem, i gotowac przez 1 minute. Dodac odlozone swieze pomidory i po zagotowaniu odstawic z ognia. Wymieszc z posiekana bazylia, nastepnie w razie potrzeby doprawic sola oraz pieprzem i skropic oliwa extra vergine."},
        {"rosol", "Jesli mamy calego kurczaka nalezy go pokroic na czesci - odciac szyje, skrzydelka, uda. Korpus pozostawic razem z piersiami. Wszystkie czesci kurczaka oraz wolowine i podroby oplukac, nastepnie wlozyc do duzego garnka i zalac zimna woda. Posolic i zagotowac na srednim ogniu. Po zagotowaniu zmniejszyc ogien i zszumowac wywar. Zmniejszyc ogien i gotowac na malym ogniu pod lekko uchylona pokrywa przez okolo 1 i 1/2 godziny. W miedzyczasie przygotowac warzywa: marchewke, pietruszke i selera obrac (lub dla wiekszego aromatu - tylko dokladnie umyc). Cebule, pora i natke oplukac (cebuli nie obierac, jej luski nadadza zupie ladnego koloru). Warzywa wlozyc do rosolu i zagotowac. Dodac przyprawy: ziele angielskie, lisc laurowy i czarny pieprz. Zmniejszyc ogien i gotowac na malym ogniu przez okolo 1 godzine lub do 1 i 1/2 godziny. Rosol podawac goracy, z ugotowanym makaronem, posiekana natka, pokrojona na cienkie plasterki marchewka z rosolu oraz kawalkami miesa z kurczaka."},
        {"barszcz czerwony", "Do wrzacego, czystego (przecedzonego) bulionu wlozyc ugotowane, obrane i pokrojone na plastry (lub wieksze kawalki) buraki. Gotowac na malym ogniu tylko przez okolo 10 - 15 minut. Na 5 minut przed koncem gotowania dodac lisc laurowy, ziele angielskie, czarny pieprz oraz podsmazona cebulke. Odstawic z ognia i zostawic na cala noc lub minimum 6 godzin. Barszcz doprowadzic prawie do zagotowania (od tego momentu barszczu nie mozna juz calkowicie zagotowac, bo zacznie zmieniac kolor na ciemniejszy). Odstawic z ognia, dodac ocet i przecedzic. Doprawic ewentualnie sola i pieprzem."},
        {"barszcz bialy", "Do duzego garnka wlac 2 litry wody, dodac wolowine, 1 lyzeczke soli i zagotowac. Gotowac pod przykryciem przez ok. 1 i 1/2 godziny. Dodac marchewke, pietruszke, pora, selera oraz opalona na palniku cebule, gotowac przez ok. 30 minut pod przykryciem. Dodac boczek, podziurkowana widelcem biala kielbase, zupe sprobowac i doprawic sola. Gotowac przez ok. 15 minut na malym ogniu pod przykryciem. Dodac wedzona kielbase, obrany czosnek (1 zabek mozna rozgniesc), lisc laurowy, ziele angielskie, pieprz czarny, pieprz ziolowy, majeranek, otreby, chrzan, sok z cytryny lub ocet. Gotowac przez ok. 5 minut. Smietanke wymieszac z 2 lyzkami wody oraz z maka. Nastepnie dodac do zupy i delikatnie zagotowac."},
        {"golabki", "Mieso wlozyc do wiekszej miski. Ryz ugotowac, ostudzic i dodac do miesa. Cebule obrac, zetrzec na tarce, dodac do miesa z ryzem. Doprawic sola (okolo pol lyzeczki), pieprzem (1/4 lyzeczki). Wszystko wymieszac i dobrze wyrobic dlonia. Uformowac niewielkie podluzne kotlety. Wyciac glab ze srodka kapusty, nastepnie wlozyc ja do duzego garnka z wrzatkiem (wycieta strona do dolu), gotowac przez okolo 10 minut na malym ogniu. Przewrocic kapuste na druga strone i gotowac przez ok. 5 minut. Wyjac kapuste z wrzatku i po przestudzeniu rozebrac ja z lisci, odciac delikatnie zgrubienia z kazdego liscia, nastepnie nakladac przygotowane porcje miesa. Zawijac jak krokiety (najpierw zalozyc lisc na mieso z jednej strony, pozniej zlozyc boki do srodka, nastepnie zwinac jak najciasniej do konca pozostala czesc liscia). Nie cala kapusta musi byc wykorzystana. Dno duzego i najlepiej szerokiego garnka wylozyc kilkoma liscmi kapusty (np. takimi, ktore sie porwaly). Na wierzchu ulozyc golabki laczeniem do dolu. Zagotowac bulion w innym garnku i zalac nim golabki. Postawic na gazie, przykryc i gotowac przez okolo 45 - 60 minut az kapusta bedzie miekka. W czasie gotowania nie mieszac golabkow, ewentualnie delikatnie potrzasnac garnkiem. Wywar z golabkow przelac do innego garnka. Dodac przecier pomidorowy oraz make rozmieszana wczesniej z kilkoma lyzkami zimnej wody. Zagotowac, doprawic sola, pieprzem, suszonym oregano, tymiankiem i papryka. Gotowac przez 10 minut bez przykrycia. Jesli dodajemy smietane nalezy rozprowadzac ja stopniowo z sosem, dodajac go po lyzce do smietany jednoczesnie mieszajac. Przelac do garnka z golabkami i gotowac calosc przez kilka minut na malym ogniu, od czasu do czasu potrzasnac garnkiem aby sos rownomiernie sie rozprowadzil."},
        {"pulpety", "Na patelni na lyzce oliwy zeszklic pokrojona w kosteczke cebule, pod koniec dodac starty 1 zabek czosnku oraz 1 lyzke masla, suszone oregano i papryke w proszku, wymieszac i chwile razem podsmazyc. Zdjac z patelni i zmielic razem z miesem lub drobniej posiekac na desce. Zmielone mieso wraz z podsmazona cebula umiescic w misce. Dodac bulke tarta lub ugotowana kasze, jajko, sos sojowy, doprawic sola oraz pieprzem i dokladnie wyrobic. Wilgotnymi dlonmi uformowac nieduze pulpeciki. Rozgrzac natluszczona oliwa patelnie i wlozyc pulpeciki. Gdy sie zrumienia od spodu przewrocic na druga strone i powtorzyc smazenie. Pod koniec na patelnie dodac starty drugi zabek czosnku i lekko go zrumienic. Na patelnie z pulpecikami wlac goracy bulion, przykryc pokrywa i gotowac przez ok. 5 - 7 minut, w miedzyczasie potrzasnac patelnia w celu przemieszania pulpecikow. Dodac przecier pomidorowy i zagotowac. Gotowac bez przykrycia przez okolo 10 minut (jesli uzywalismy indyka) lub ok. 15 minut (w przypadku innego miesa). W miedzyczasie 1 - 2 razy zamieszac. Sos sprobowac i doprawic w razie potrzeby sola, pieprzem, cukrem i suszonym oregano. Podawac z makaronem i tartym serem."},
        {"kotlety mielone", "Bulke zalac mlekiem lub woda, odstawic do namoczenia na okolo 10 - 15 minut. Do wiekszej miski wlozyc zmielone mieso, starta na drobnej tarce cebule, jajko, sol i pieprz oraz odcisnieta bulke, wszystko dobrze wymieszac. W trakcie wyrabiania miesa nalezy dodawac po troszku zimnej wody i wyrabiac tak dlugo az mieso wchlonie wode i nie bedzie przywierac do dloni. Im dluzej wyrabiamy, tym lepsze kotlety. Masa miesna moze wydawac sie dosc luzna, ale dzieki temu kotlety beda delikatniejsze, mniej zbite i twarde. Uformowac podluzne kotlety, obtoczyc w bulce tartej i klasc na dobrze rozgrzany olej na patelni. Po obsmazeniu z dwoch stron przelozyc kotlety do garnka lub naczynia zaroodpornego (bez przykrycia) i wstawic do rozgrzanego do 150 stopni C piekarnika, na okolo 15 minut. Unikniemy dlugiego smazenia, a kotlety beda w srodku idealnie miekkie."},
        {"kotlety schabowe z pieczarkami", "Pieczarki pokroic w kostke lub na plasterki. Cebule pokroic w kosteczke. Na patelni rozgrzac olej, wlozyc pieczarki i cebule, smazyc na wiekszym ogniu az pieczarki lekko sie zrumienia a plyn calkowicie odparuje. Na koniec dodac maslo, doprawic sola oraz pieprzem. Schab pokroic na cienkie kotlety, rozbic je jeszcze bardziej tluczkiem, doprawic sola i pieprzem. Na kazdy kotlet nalozyc farsz z pieczarek, zlozyc na pol, obtoczyc w jajku i bulce tartej, a nastepnie usmazyc na zloty kolor."},
        {"pierogi z miesem", "Pieczarki oczyscic szczoteczka lub gabka, pokroic na mniejsze czesci. Cebule obrac i pokroic w drobna kosteczke. Pieczarki i cebule wrzucic na dobrze rozgrzana patelnie z dodatkiem masla i na wiekszym ogniu odparowac i zrumienic co chwile mieszajac. Mieso drobiowe (bez skory), wolowe (razem z tluszczem), pieczarki, cebule oraz warzywa z wywaru zmielic w maszynce do miesa, dokladnie wyrobic, doprawic sola i pieprzem. Jesli nadzienie wyszlo za rzadkie, mozna podsmazyc je na patelni, jesli za sztywne, mozna dodac troszke rosolu. Do nadzienia dodac jajko i wymieszac. Szklanka wycinac kolka z rozwalkowanego ciasta, na srodek nakladac po jednej pelnej lyzce farszu (lub tyle ile sie zmiesci). Skladac ciasto na pol i zlepiac dokladnie brzegi, uwazajac aby nadzienie nie dostalo sie w miejsce sklejenia. Gotowe pierogi ukladac na stolnicy lub blacie podsypanych maka. Przykryc sciereczka do czasu gotowania, aby nie obeschly. W duzym garnku zagotowac osolona wode, i jak bedzie mocno wrzala, wlozyc pierwsza partie pierogow. Po ponownym zagotowaniu zmniejszyc ogien do sredniego i gotowac pierogi do miekkosci ciasta. Wylawiac lyzka cedzakowa i ukladac na talerzach. Podawac z wody lub odsmazac (ostudzone, wysuszone pierogi). Pierogi z wody mozna polewac roztopionym maslem a odsmazane posypac skwarkami i podawac z kwasna smietana."},
        {"nalesniki", "Make wsypac do miski, dodac jajka, mleko, wode i sol. Zmiksowac na gladkie ciasto. Dodac roztopione maslo lub olej roslinny i razem zmiksowac (lub wykorzystac tluszcz do smarowania patelni przed smazeniem kazdego nalesnika). Nalesniki smazyc na dobrze rozgrzanej patelni z cienkim dnem np. nalesnikowej. Przewrocic na druga strone gdy spod nalesnika bedzie juz ladnie zrumieniony i sciety."},
        {"pierogi z serem i jagodami", "Jagody szybko oplukac pod delikatnym strumieniem wody. Osuszyc na papierowych recznikach, wymieszac z serem bialym lub twarozkiem, posiekana mieta i brazowym cukrem. Make przesiac na stolnice lub do miski, dodac sol, maslo lub olej oraz jajko. Wymieszac i stopniowo dodawac goraca wode, w razie potrzeby dodac troche wiecej maki. Wyrabiac ciasto, az bedzie miekkie i elastyczne, przez okolo 5 minut. Ciasto rozwalkowac i mala szklanka wycinac kolka, nakladac po malej lyzeczce nadzienia, zlepiac brzegi. Pierogi wrzucac na wrzaca, lekko osolona wode i gotowac do miekkosci, przez okolo 2 minuty, od czasu ponownego zagotowania sie wody. Odsaczyc i zaraz podawac posypane brazowym cukrem lub cukrem pudrem i polane slodka smietanka."},
        {"pierogi z kapusta i grzybami", "Grzyby oplukac, zalac zimna woda i odstawic na 6 godzin lub na cala noc. Nastepnego dnia zagotowac, dodac obrana marchewke, pietruszke i gotowac az beda miekkie. Pod koniec gotowania doprawic sola i pieprzem. Kapuste odcisnac i ugotowac w 300 ml wody do miekkosci z dodatkiem soli do smaku (ok. 45 minut), dokladnie odcisnac. Grzyby, marchewke i pietruszke odcedzic, zachowujac wywar (wykorzystac do np. do zupy grzybowej). Bardzo dobrze odcisnac z wody i razem z kapusta zmielic w maszynce do miesa o bardzo duzych oczkach, ok 1 cm srednicy (lub drobno posiekac na desce). Na patelni na oleju zeszklic cebule, dodac do farszu. Skladniki farszu dobrze wyrobic, laczac wszystko razem, doprawic sola i pieprzem. Make przesiac do miski, dodac sol. Do goracej wody wlozyc maslo i roztopic, stopniowo wlewac do maki, mieszajac wszystko lyzka. Polaczyc skladniki i wylozyc je na podsypana maka stolnice. Zagniatac ciasto przez okolo 10 minut az bedzie gladkie i miekkie. Ciasto wlozyc do miseczki, szczelnie przykryc i odstawic na 30 minut. Ciasto podzielic na 4 czesci, kolejno rozwalkowywac na placki. Mala szklanka wycinac koleczka, na srodek nakladac farsz, skladac na pol i zlepiac brzegi w pierogi. Gotowac do miekkosci, przez okolo 3 minuty, ale najlepiej sprawdzic czy pierogi sa juz miekkie, odlawiajac jednego na lyzke cedzakowa i dotykajac palcem."},
        {"pierogi ruskie", "Make przesiac do miski, dodac sol. Do goracej wody wlozyc maslo i roztopic, stopniowo wlewac do maki, mieszajac wszystko lyzka. Polaczyc skladniki i wylozyc je na podsypana maka stolnice. Zagniatac ciasto przez okolo 8 - 10 minut az bedzie gladkie i plastyczne. Ciasto wlozyc do miseczki, przykryc folia, odstawic na 30 minut. W miedzyczasie zaczac przygotowywac farsz. Ziemniaki obrac, oplukac, wlozyc do garnka, dodac sol, przykryc zimna woda i zagotowac. Gotowac pod uchylona pokrywa przez okolo pol godziny lub do miekkosci. Odcedzic, wlozyc z powrotem do garnka i jeszcze gorace roztluc dokladnie tluczkiem do ziemniakow na gladka mase bez grudek. Ziemniaki calkowicie ostudzic, odparowac. Twarog pokruszyc, rozgniesc widelcem lub praska (sera nie mielimy w maszynce bo nadzienie wyjdzie za rzadkie). Wymieszac z ziemniakami, doprawic sola i pieprzem. Ciasto pierogowe podzielic na 4 czesci. Kolejno rozwalkowywac na placki. Mala szklanka wycinac kolka z ciasta, na srodek nakladac po jednej pelnej lyzce farszu (lub tyle ile sie zmiesci). Skladac ciasto na pol i zlepiac dokladnie brzegi, uwazajac aby nadzienie nie dostalo sie w miejsce sklejenia. Gotowe pierogi ukladac na stolnicy lub blacie podsypanych maka. W duzym garnku zagotowac osolona wode i jak bedzie mocno wrzala, wlozyc pierwsza partie pierogow (okolo 15 sztuk). Po ponownym zagotowaniu zmniejszyc ogien do sredniego i gotowac pierogi do czasu wyplyniecia na powierzchnie. Po wyplynieciu pierogow gotowac je jeszcze przez okolo 1,5 minuty (wylowic jednego pieroga lyzka cedzakowa i sprawdzic palcem czy ciasto jest juz miekkie, dokladny czas gotowania bedzie zalezal miedzy innymi od grubosci ciasta i wielkosci pierogow). Pierogi wylawiac lyzka cedzakowa i ukladac na talerzach. Od razu podawac lub po obeschnieciu schowac do pojemnikow i przechowywac w lodowce. Mozna tez zamrozic. Podawac np. z zeszklona na oleju lub smalcu cebula lub z roztopionym smalcem ze skwarkami oraz z gesta, kwasna smietana."},
        {"kotlety jajeczne z kasza", "Kasze jaglana wsypac do rondelka, wyplukac pod biezaca woda kilkakrotnie ja zmieniajac. Odcedzic, wlac mleko, przykryc pokrywka i zagotowac. Gotowac pod przykryciem bez otwierania rondla przez 15 minut. 5 jajek ugotowac na twardo, 1 zostawic surowe. Jajka do ugotowania wlozyc do garnka, zalac ciepla woda do calkowitego przykrycia, postawic na ogniu i zagotowac. Zmniejszyc ogien, przykryc i gotowac przez ok. 8 minut. Wylac goraca wode i zalac zimna, zbic skorupki i pozostawic w zimnej wodzie do ostudzenia. Nastepnie obrac ze skorupek. Kasze i ugotowane jajka wlozyc do duzej miski, dokladnie rozgniesc widelcem. Dodac surowe jajko, sol (ok. 1/2 lyzeczki), pieprz, 1 lyzke bulki tartej, koperek, szczypiorek oraz starty na tarce ser zolty jesli go uzywamy. Dokladnie wymieszac, uformowac 5 kotletow. Obtoczyc w bulce tartej. Rozgrzac min. ok. 1/2 cm warstwe masla klarowanego. Gdy bedzie gorace, wlozyc kotleciki, zmniejszyc ogien do umiarkowanego i smazyc powoli rumieniac przez ok. 3 minuty z kazdej strony, nastepnie dosmazac jeszcze po okolo 1 minucie z dwoch stron."},
        {"sernik", "Miekkie maslo ubic na puszysto, stopniowo dodawac po jednym zoltku na przemian z lyzka cukru pudru, caly czas dokladnie ubijajac skladniki. Zmniejszyc obroty miksera do srednich, dodac zmielony ser i polaczyc. Teraz dodawac po kolei: cukier wanilinowy, smietanke oraz make ziemniaczana caly czas miksujac skladniki na jednolita mase. Na koniec wymieszac (delikatnie, ale dokladnie) z ubitymi na sztywno bialkami. Przygotowac tortownice o srednicy minimum 26 cm (mierzona od srodka). Posmarowac ja maslem i wysypac bulka tarta lub mielonymi migdalami lub dno wylozyc papierem do pieczenia. Mase serowa wylozyc do tortownicy i wstawic do piekarnika nagrzanego do 170 stopni C. Piec przez 60 minut. Sernik studzic stopniowo wyjmujac z piekarnika (najpierw po trochu otwierajac drzwiczki i lekko wysuwajac sernik, w koncu wyjac z piekarnika). Zrumieniony wierzch sernika posypac cukrem pudrem lub polac polewa czekoladowa."},
        {"tarta ze sliwkami", "Make wsypac do miski, dodac cukier, sol, pokrojone w kostke maslo lub margaryne. Miksowac mieszadlem miksera przez okolo 1 minute az powstanie kruszonka (lub rozcierac wszystko palcami). Dodawac stopniowo zimna wode i jeszcze przez chwilke miksowac lub zagniatac reka, az ciasto zacznie laczyc sie w wieksze kawalki. Zlaczyc je wszystkie w jednolita kule. Podzielic na 2 czesci, rozplaszczyc na placki, zawinac w folie i wstawic do lodowki na 1 godzine. Wysoka ceramiczna forme (na ciasto typu pie) o srednicy dna ok. 24 - 25 cm posmarowac tluszczem. Mozna tez uzyc formy metalowej o srednicy 26 cm. Sliwki pokroic na kawaleczki usuwajac pestki. Przed pieczeniem wymieszac z sokiem z cytryny, cynamonem, cukrem i skrobia ziemniaczana. Piekarnik nagrzac do 190 stopni C. Polowe ciasta rozwalkowac (podsypujac maka lub pomiedzy dwoma arkuszami papieru do pieczenia) i wylozyc nim dno oraz boki formy (mozna doklejac brakujace miejsca). Druga czesc ciasta rozwalkowac i pokroic na paski. Do formy z ciastem wylozyc nadzienie sliwkowe i przykryc kratka z paskow ciasta. Wierzch mozna posmarowac roztrzepanym jajkiem (dla ladnego zrumienienia). Wstawic do piekarnika na srodkowy ruszt, pod forme kladac papier do pieczenia. Piec przez 60 minut. Wyjac z piekarnika i przestudzic."},
        {"piernik czekoladowy", "Podluzna forme o dlugosci okolo 23 cm wysmarowac maslem i oproszyc bulka tarta lub wylozyc papierem do pieczenia. Piekarnik nagrzac do 180 stopni C. Obydwa rodzaje maki wsypac do miski razem z kakao i wymieszac z sola, proszkiem do pieczenia oraz przyprawami. Maslo utrzec mikserem z cukrem na puszysty krem. Zmniejszyc nieco obroty miksera i dodawac po lyzce miod, a nastepnie po jednym zoltku. Mase wlac do miski z maka i dodajac mleko wymieszac wszystkie skladniki. Nastepnie polaczyc z posiekana czekolada, a na koncu delikatnie wymieszac z bialkami ubitymi na sztywna piane. Ciasto przelozyc do przygotowanej formy, wyrownac powierzchnie i piec przez okolo 40 - 45 minut, az wbity patyczek bedzie suchy. Po calkowitym ostudzeniu szczelnie zawinac i odlozyc w chlodne miejsce na kilka dni. Mozna tez wczesniej przekroic piernik na pol i przelozyc powidlami. Przed podaniem polac polewa czekoladowa lub lukrem."},
        {"szarlotka", "Jablka obrac, pokroic na cwiartki i wyciac gniazda nasienne. Pokroic na mniejsze kawalki i wlozyc do szerokiego garnka lub na gleboka patelnie. Dodac cukier i cynamon i smazyc przez ok. 20 minut co chwile mieszajac, az jablka zmiekna i zaczna sie rozpadac. Do maki dodac pokrojone w kostke zimne maslo, proszek do pieczenia, cukier i cukier wanilinowy. Skladniki polaczyc w jednolite ciasto (mikserem lub recznie), pod koniec dodac jajko (ciasto bedzie dosc miekkie). Podzielic je na pol i wlozyc obie polowki do zamrazarki na ok. 15 minut. Piekarnik nagrzac do 180 st C. Przygotowac nieduza forme. Wyjac jedna polowke ciasta z zamrazarki, pokroic nozem na plasterki i wylepic nimi spod formy. Nastepnie wylozyc na to jablka. Pozostale ciasto zetrzec na tarce bezposrednio na jablka (lub pokroic ciasto na plasterki i ulozyc na wierzchu). Wstawic do piekarnika i piec przez ok. 50 minut lub na zloty kolor. Upieczona szarlotke przestudzic i posypac cukrem pudrem."},
        {"brownie", "Piekarnik nagrzac do 160 stopni C. Przygotowac mala prostokatna foremke o wymiarach ok. 21 cm x 28 cm (lub o podobnej powierzchni). Posmarowac ja maslem i wylozyc papierem do pieczenia. Maslo pokroic w kostke i wlozyc do rondelka, dodac polamana na kosteczki czekolade i caly czas mieszajac roztopic na malym ogniu, odstawic z palnika. W oddzielnej misce rozmiksowac lub wymieszac rozga jajka z cukrem. Dodac do nich roztopiona czekolade z maslem zmiksowac lub wymieszac rozga na gladka mase. Dodac make oraz sol i zmiksowac na jednolite ciasto. Wylozyc do przygotowanej blaszki, wyrownac powierzchnie. Dodatkowa czekolade pokroic na kawalki i posypac po wierzchu ciasta. Wstawic do piekarnika i piec przez ok. 30 minut az ciasto lekko urosnie. Jesli uzywamy wiekszej blaszki, ciasto bedzie gotowe szybciej, jesli mniejszej - czas pieczenia nalezy wydluzyc. Po upieczeniu i ostudzeniu pokroic na male kawaleczki."}
    };
    // program tworzy zmienne do przechowywania wybranego przez uzytkownika typu potrawy i potrawy
    string category;
    string dish;
    // program wyswietla dostepne kategorie potraw i pobiera od uzytkownika wybrana kategorie i zwraca blad, jesli podana zostala kategoria nie jest dostepna
    cout << "dostepne kategorie potraw: \nzupa\ndanie glowne miesne\ndanie glowne bezmiesne\ndeser\nwpisz kategorie potrawy: ";
    getline(cin, category);
    // program wyswietla dostepne potrawy na podstawie wybranej poprzednio kategorii i pobiera od uzytkownika wybrana nazwe potrawy, po czym wyswietla skladniki potrzebne do wykonania tej potrawy i sam przepis na nia. Jesli uzytkownik podal nazwe potrawy, ktora nie jest dostepna, program zwraca blad
    if(category == "zupa") {
        cout << "dostepne zupy:\nzupa ogorkowa\nzupa pomidorowa\nrosol\nbarszcz czerwony\nbarszcz bialy\nwpisz nazwe potrawy: ";
        getline(cin, dish);
        if(dish == "zupa ogorkowa") {
            cout << "skladniki: \n" << skladniki[0][1] << "\n\n" << przepisy[0][1];
        } else if(dish == "zupa pomidorowa") {
            cout << "skladniki: \n" << skladniki[1][1] << "\n\n" << przepisy[1][1];
        } else if(dish == "rosol") {
            cout << "skladniki: \n" << skladniki[2][1] << "\n\n" << przepisy[2][1];
        } else if(dish == "barszcz czerwony") {
            cout << "skladniki: \n" << skladniki[3][1] << "\n\n" << przepisy[3][1];
        } else if(dish == "barszcz bialy") {
            cout << "skladniki: \n" << skladniki[4][1] << "\n\n" << przepisy[4][1];
        } else {
            cout << "wybrano niedostepny typ zupy";
        }
    } else if(category == "danie glowne miesne") {
        cout << "dostepne dania glowne miesne:\ngolabki\npulpety\nkotlety mielone\nkotlety schabowe z pieczarkami\npierogi z miesem\nwpisz nazwe potrawy: ";
        getline(cin, dish);
        if(dish == "golabki") {
            cout << "skladniki: \n" << skladniki[5][1] << "\n\n" << przepisy[5][1];
        } else if(dish == "pulpety") {
            cout << "skladniki: \n" << skladniki[6][1] << "\n\n" << przepisy[6][1];
        } else if(dish == "kotlety mielone") {
            cout << "skladniki: \n" << skladniki[7][1] << "\n\n" << przepisy[7][1];
        } else if(dish == "kotlety schabowe z pieczarkami") {
            cout << "skladniki: \n" << skladniki[8][1] << "\n\n" << przepisy[8][1];
        } else if(dish == "pierogi z miesem") {
            cout << "skladniki: \n" << skladniki[9][1] << "\n\n" << przepisy[9][1];
        } else {
            cout << "wybrano niedostepny typ dania glownego miesnego";
        }
    } else if(category == "danie glowne bezmiesne") {
        cout << "dostepne dania glowne bezmiesne:\nnalesniki\npierogi z serem i jagodami\npierogi z kapusta i grzybami\npierogi ruskie\nkotlety jajeczne z kasza\nwpisz nazwe potrawy: ";
        getline(cin, dish);
        if(dish == "nalesniki") {
            cout << "skladniki: \n" << skladniki[10][1] << "\n\n" << przepisy[10][1];
        } else if(dish == "pierogi z serem i jagodami") {
            cout << "skladniki: \n" << skladniki[11][1] << "\n\n" << przepisy[11][1];
        } else if(dish == "pierogi z kapusta i grzybami") {
            cout << "skladniki: \n" << skladniki[12][1] << "\n\n" << przepisy[12][1];
        } else if(dish == "pierogi ruskie") {
            cout << "skladniki: \n" << skladniki[13][1] << "\n\n" << przepisy[13][1];
        } else if(dish == "kotlety jajeczne z kasza") {
            cout << "skladniki: \n" << skladniki[14][1] << "\n\n" << przepisy[14][1];
        } else {
            cout << "wybrano niedostepny typ dania glownego bezmiesnego";
        }
    } else if(category == "deser") {
        cout << "dostepne desery:\nsernik\ntarta ze sliwkami\npiernik czekoladowy\nszarlotka\nbrownie\nwpisz nazwe potrawy: ";
        getline(cin, dish);
        if(dish == "sernik") {
            cout << "skladniki: \n" << skladniki[15][1] << "\n\n" << przepisy[15][1];
        } else if(dish == "tarta ze sliwkami") {
            cout << "skladniki: \n" << skladniki[16][1] << "\n\n" << przepisy[16][1];
        } else if(dish == "piernik czekoladowy") {
            cout << "skladniki: \n" << skladniki[17][1] << "\n\n" << przepisy[17][1];
        } else if(dish == "szarlotka") {
            cout << "skladniki: \n" << skladniki[18][1] << "\n\n" << przepisy[18][1];
        } else if(dish == "brownie") {
            cout << "skladniki: \n" << skladniki[19][1] << "\n\n" << przepisy[19][1];
        } else {
            cout << "wybrano niedostepny typ deseru";
        }
    } else {
        cout << "wybrano niedostepny typ potrawy";
    }
    return 0;
}