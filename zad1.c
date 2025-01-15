#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_THREADS 10
#define NUM_OPERATIONS 10
#define AMOUNT 100

// Globalne zmienne
int saldo = 0;
pthread_mutex_t mutex;
pthread_cond_t cond_sekcja = PTHREAD_COND_INITIALIZER;
int sekcja_krytyczna = 1;

// Funkcja do wpłat
void* wplata(void* arg) {
    int id = *((int*)arg);
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        pthread_mutex_lock(&mutex);

        while (sekcja_krytyczna == 0) {
            pthread_cond_wait(&cond_sekcja, &mutex);
        }

        // Sekcja krytyczna
        sekcja_krytyczna = 0;
        printf("Sekcja krytyczna otwarta.\n");
        pthread_mutex_unlock(&mutex);

        int temp = saldo; // Tymczasowa wartość
        saldo = temp + AMOUNT;
        printf("Wątek %d wpłaca %d. Bieżące saldo: %d\n", id, AMOUNT, saldo);

        pthread_mutex_lock(&mutex);
        sekcja_krytyczna = 1;
        pthread_cond_signal(&cond_sekcja);
        printf("Sekcja krytyczna zamknięta.\n");
        pthread_mutex_unlock(&mutex);

        usleep(rand() % 100000); // Losowe opóźnienie
    }
    return NULL;
}

// Funkcja do wypłat
void* wyplata(void* arg) {
    int id = *((int*)arg);
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        pthread_mutex_lock(&mutex);

        while (sekcja_krytyczna == 0) {
            pthread_cond_wait(&cond_sekcja, &mutex);
        }

        // Sekcja krytyczna
        sekcja_krytyczna = 0;
        printf("Sekcja krytyczna otwarta.\n");
        pthread_mutex_unlock(&mutex);

        int temp = saldo; // Tymczasowa wartość
        saldo = temp - AMOUNT;
        printf("Wątek %d wypłaca %d. Bieżące saldo: %d\n", id, AMOUNT, saldo);

        pthread_mutex_lock(&mutex);
        sekcja_krytyczna = 1;
        pthread_cond_signal(&cond_sekcja);
        printf("Sekcja krytyczna zamknięta.\n");
        pthread_mutex_unlock(&mutex);

        usleep(rand() % 100000); // Losowe opóźnienie
    }
    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Inicjalizacja muteksu
    pthread_mutex_init(&mutex, NULL);

    // Tworzenie wątków wpłacających
    for (int i = 0; i < NUM_THREADS / 2; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, wplata, &thread_ids[i]);
    }

    // Tworzenie wątków wypłacających
    for (int i = NUM_THREADS / 2; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, wyplata, &thread_ids[i]);
    }

    // Oczekiwanie na zakończenie wszystkich wątków
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Zwalnianie zasobów
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_sekcja);

    printf("Koniec programu. Końcowe saldo: %d\n", saldo);

    return 0;
}
