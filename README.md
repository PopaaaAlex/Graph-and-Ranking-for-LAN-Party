# NUME PROIECT: Graf si Clasament LanParty

## Rulare Program
./checker.sh

## Descriere
Datele sunt citite din fișierul de intrare pentru a simula un turneu de LanParty. La finalul simulării, se construiește un graf orientat, iar prestigiul este calculat în funcție de numărul de victorii obținute de fiecare echipă.
Clasamentul se aseamana cu algoritmul PageRank[1]:

## Cerințe:

### Task_1:
  Echipele vor fi reprezentate de vârfurile grafului, iar poziția din fișier determină și poziția în graf, fiind folosită pentru a crea matricea de adiacență.
  Drumul dintre cele două echipe este de la echipa care a pierdut către echipa care a câștigat.
### Task_2:
  Prestigiul fiecărei echipe este calculat în funcție de numărul de victorii obținute și de ponderea turneului, în acest caz ponderea fiind q = 0.15, conform formulei[2]



  [1]: Sergey Brin and Lawrence Page. The anatomy of a large-scale hypertextual web search engine. Computer Networks and ISDN Systems, Proceedings of the Seventh International World Wide Web Conference, 30(1):107–117, 1998.
  https://snap.stanford.edu/class/cs224w-readings/Brin98Anatomy.pdf
  
  [2]: Pr = (q * pow((2 - q), r)) / (pow(2, l) + pow((2 - q), l) * (q - 1));
  q - reprezinta ponderea
  l - inaltimea arborelui
