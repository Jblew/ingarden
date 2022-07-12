# ingarden
Interior garden on metal wall-mounted rack

In tribute to https://en.wikipedia.org/wiki/Roman_Ingarden



## Podłączenie elektryczne v2

- Myśl instead of czas
  - Jeśli wymyślę dobry sposób podłączania elektrycznego to zaoszczędzę też czas w przyszłych projektach
- Podstawy
  - Cieńszy i giętszy kabel — obliczyć straty
  - Lutowanie lub przykręcanie złącza na końcówkach
  - Podłączanie adaptera led do złączki na kablu
- Straty
  - Długość: 3m czyli w obie strony 6m
  - Max moc taśm: 0,5m x 6 taśm x 14,4w/m = 43,2w
  - Przy 12v natężenie (P=IxU => I=P/U) I = 43,2/12 = 3,6A
  - Przewód 0,75mm2 przy 6m opór 0.1368ohm czyli straty: 0.0684*3,6=0,49248W
  - Przewód 0,5mm2 przy 6m opór 0.2052ohm czyli straty: 0.2052*3,6=0,73W
  - Przewód 0,25mm2 przy 6m opór 0.2052ohm czyli straty: 0.4104*3,6=1,47W = 3,5%



## Taśma led biała

Jeśli biała to dopasować spektrum taśmy do chlorofilu. Taśma kanlux L60 ma dopasowane spektrum

1. Kanlux L60
   1. Np tu: https://allegro.pl/oferta/kanlux-tasma-led-l60-11w-m-12v-biala-neutralna-5m-12024477473?bi_s=ads&bi_m=listing:desktop:query&bi_c=MzdjNWY5YjQtNTI3Ni00NjZjLWEzMzUtYmRlMDQzOGRkNzVkAA&bi_t=ape&referrer=proxy&emission_unit_id=67477aee-d1df-499b-bda5-1b5068010afe



## Oświetlenie, wersja z taśmą [PL]

Elementy na pewno:

1. - [x] Profil aluminiowy 1m (do przecięcia) * 6 półek = 6*1m (w koszyku)
2. - [x] Taśma dwustronna do profilu
3. - [x] Złączki do taśm
4. - [x] Taśma LED 14,4W * 0,5m * 4 = 2m = 28,8W
5. - [x] Zasilacz LED IP65
6. - [x] Moduł PWM
7. - [x] Przetwornica step-down 12 -> 5v
8. Zabrać z Warszawy Arduino / moduły 5V (koniecznie 5V!)

W przyszłości:

1. Moduł DCF lub GPS (źródło czasu)
2. Czujnik otwarcia drzwi
3. Czujnik natężenia światła rozproszony
4. Skrzynka metalowa
5. Kabel z włącznikiem

Bezpieczeństwo:

1. Aluminiowe koryto bez osłonki
2. Zasilacz z zabezpieczeniem + małe natężenie nominalne
3. Cała elektronika w metalowej skrzynce
4. Zamontowane na aluminiowej półce (nie ma palnych elementów)



