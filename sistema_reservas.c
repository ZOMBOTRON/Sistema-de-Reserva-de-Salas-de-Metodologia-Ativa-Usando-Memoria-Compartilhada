#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define NUM_SALAS 10
#define RESERVAS_KEY 1234
#define TURMAS_KEY 5678

void reservarSala(int *reservas, int *turmas) {
    int sala, codigoTurma;

    printf("Informe o número da sala que deseja reservar (0-9): ");
    scanf("%d", &sala);

    if (sala < 0 || sala >= NUM_SALAS) {
        printf("Número de sala inválido.\n");
        return;
    }

    if (reservas[sala] == 1) {
        printf("A sala %d já está reservada.\n", sala);
    } else {
        printf("Informe o código da turma: ");
        scanf("%d", &codigoTurma);
        reservas[sala] = 1;
        turmas[sala] = codigoTurma;
        printf("Sala %d reservada com sucesso para a turma %d.\n", sala, codigoTurma);
    }
}

void liberarSala(int *reservas, int *turmas) {
    int sala;

    printf("Informe o número da sala que deseja liberar (0-9): ");
    scanf("%d", &sala);

    if (sala < 0 || sala >= NUM_SALAS) {
        printf("Número de sala inválido.\n");
        return;
    }

    if (reservas[sala] == 0) {
        printf("A sala %d já está disponível.\n", sala);
    } else {
        reservas[sala] = 0;
        turmas[sala] = 0;
        printf("Sala %d foi liberada.\n", sala);
    }
}

void visualizarStatus(int *reservas, int *turmas) {
    printf("\nStatus das salas:\n");
    for (int i = 0; i < NUM_SALAS; i++) {
        if (reservas[i] == 0) {
            printf("Sala %d: disponível\n", i);
        } else {
            printf("Sala %d: reservada pela turma %d\n", i, turmas[i]);
        }
    }
}

int main() {
    int shm_reservas_id, shm_turmas_id;
    int *reservas, *turmas;
    int opcao = 0;

    shm_reservas_id = shmget(RESERVAS_KEY, NUM_SALAS * sizeof(int), 0666);
    shm_turmas_id = shmget(TURMAS_KEY, NUM_SALAS * sizeof(int), 0666);

    reservas = (int *)shmat(shm_reservas_id, NULL, 0);
    turmas = (int *)shmat(shm_turmas_id, NULL, 0);

    while (opcao != 4) {
        printf("\nSistema de Reserva de Salas\n");
        printf("1. Reservar Sala\n");
        printf("2. Liberar Sala\n");
        printf("3. Visualizar Status das Salas\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            reservarSala(reservas, turmas);
        } else if (opcao == 2) {
            liberarSala(reservas, turmas);
        } else if (opcao == 3) {
            visualizarStatus(reservas, turmas);
        } else if (opcao == 4) {
            printf("Saindo do sistema...\n");
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    shmdt(reservas);
    shmdt(turmas);

    return 0;
}
