## Swappy-Konkurs
Konkursik dla licealistów, w którym mają zaprogramować sztuczną inteligencję, której celem jest najwiekszy możliwy wynik w grze [Swappy 10](http://swappy10.com/).

Gdy "Swappy Tool.exe" jest odpalone działają następujące skróty:
- alt-a - zaznacza pole
- alt-s - pokazuje wartości planszy
- alt-x - wykonuje jeden ruch
- alt-z - włącza ciągłe wykonywanie ruchów

#### Jak to się robi?
1. Odpalam "Swappy Tool.exe"
    - Zamiast tego można skompilowac "Swappy Tool.ahk" za pomocą [AutoHotkey](https://autohotkey.com/), szczególnie jeżeli nie ufam plikom .exe z internetu i z resztą bardzo dobrze.
2. Najeżdżam myszką pod cyfrą każdej z komórek na jednej przekątnej i naciskam **alt-a** przy każdej, żeby zaznaczyć ich pozycje na potrzeby skryptu (jak na załączonym poniżej "gdzie.png")
    - naciskam **alt-s** i sprawdzam, czy to co widzę ma sens
3. Piszę kod (w przykładzie macie w c++)
    - Z pliku "plansza.txt" można wczytać aktualny status planszy, gdzie -1 oznacza puste pole, a pozostałe liczby to wartości komórek (w plansza.txt jest poprawny przykład)
    - Do pliku "ruch.txt" należy zapisać swoją propozycję kolejnego ruchu w postaci 14 literek "o" oraz 2 literek "x" oddzielonymi pustymi znakami, które wyznaczają dwie komórki do wciśnięcia przez "Swappy Tool.exe" (w ruch.txt jest przykład)
    - Po każdym ruchu należy zamknąć plik i zakończyć proces (ostatnie 2 linijki w przykładzie)
4. Kompiluję kod i tworzę plik o nazwie "Swapper.exe"
    - naciskam **alt-x** i sprawdzam, czy skrypt robi to co mój program mu kazał
5. Powtarzam kroki 3-4 dopóki nie jestem zadowolony, a wtedy naciskam **alt-z** i patrzę jak dzieje się magia
6. Powtarzam kroki 3-5 dopóki nie jestem już na serio zadowolony, a wtedy wysyłam Jackowi na maila (jacgulij@gmail.com) sam kod z punktu 3. i wierzę, że on sobie poradzi z kompilacją
    - Nalegam na mało tekstu w samym mailu (lepiej w komentarzach w kodzie), ale podpiszcie się "Imię Nazwisko KLASA" i jaki macie rekord punktów oraz największą wartość komórki

![Zobacz "gdzie.png"](https://github.com/Jacykow/Swappy-Konkurs/blob/master/gdzie.png "Nie trzeba w kropki, ale myszka musi być w komórkach i nie na liczbach, bo skrypt sprawdza po kolorze")

#### Uwagi
- Jak coś nie działa to spokojnie napiszcie, a chwała tym co sami poprawią i też wyślą
- Wszystkie skróty działają tylko wtedy, gdy komórki na stronie [Swappy 10](http://swappy10.com/) nie zmieniają swojej pozycji na ekranie oraz są widoczne, gdy skrypt sprawdza ich wartości
