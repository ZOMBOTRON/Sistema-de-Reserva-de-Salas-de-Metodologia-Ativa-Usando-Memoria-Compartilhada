#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define RESERVAS_KEY 1234
#define TURMAS_KEY 5678

int main() {
    int shm_reservas_id, shm_turmas_id;

    shm_reservas_id = shmget(RESERVAS_KEY, 0, 0666);
    shm_turmas_id = shmget(TURMAS_KEY, 0, 0666);

    if (shmctl(shm_reservas_id, IPC_RMID, NULL) == -1) {
        perror("Erro ao remover memória de reservas");
        exit(1);
    }

    if (shmctl(shm_turmas_id, IPC_RMID, NULL) == -1) {
        perror("Erro ao remover memória de turmas");
        exit(1);
    }

    printf("Sistema finalizado e memória compartilhada removida com sucesso.\n");

    return 0;
}
