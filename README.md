# Multithreaded-Banking-Simulation

## Opis projektu
Ten projekt demonstruje wykorzystanie wątków w C do symulacji operacji bankowych, takich jak wpłaty i wypłaty, z użyciem mechanizmów synchronizacji (mutexów i zmiennych warunkowych). Program implementuje system zabezpieczający sekcje krytyczne oraz zapewniający poprawność operacji na wspólnym zasobie.

## Pliki
- `zad1.c`: Podstawowa wersja programu, która symuluje wpłaty i wypłaty w oparciu o sekcje krytyczne zabezpieczone muteksem.
- `zad2.c`: Rozszerzona wersja programu, dodająca logikę oczekiwania na wystarczające saldo przed wykonaniem wypłaty oraz dodatkowe mechanizmy synchronizacji.

## Funkcjonalności
1. Symulacja równoczesnych wpłat i wypłat na wspólne konto.
2. Zabezpieczenie sekcji krytycznych przy użyciu:
   - Muteksów (`pthread_mutex_t`).
   - Zmiennych warunkowych (`pthread_cond_t`).
3. Obsługa sytuacji, w których saldo nie wystarcza na wypłatę, za pomocą oczekiwania na zmiennej warunkowej.
