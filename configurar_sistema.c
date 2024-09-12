#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define NUM_SALAS 10
#define RESERVAS_KEY 1234
#define TURMAS_KEY 5678

int main() {
    int shm_reservas_id, shm_turmas_id;
    int *reservas, *turmas;

    shm_reservas_id = shmget(RESERVAS_KEY, NUM_SALAS * sizeof(int), IPC_CREAT | 0666);
    if (shm_reservas_id == -1) {
        perror("Erro ao criar memória compartilhada para reservas");
        exit(1);
    }

    shm_turmas_id = shmget(TURMAS_KEY, NUM_SALAS * sizeof(int), IPC_CREAT | 0666);
    if (shm_turmas_id == -1) {
        perror("Erro ao criar memória compartilhada para turmas");
        exit(1);
    }

    reservas = (int *)shmat(shm_reservas_id, NULL, 0);
    turmas = (int *)shmat(shm_turmas_id, NULL, 0);

    for (int i = 0; i < NUM_SALAS; i++) {
        reservas[i] = 0;  // Sala disponível
        turmas[i] = 0;    // Nenhuma turma associada
    }

    printf("Sistema de reserva de salas configurado com sucesso!\n");

    shmdt(reservas);
    shmdt(turmas);

    return 0;
}
