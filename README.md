# Executar os programas

## Passo 1
Compilar os programas:
Cada um dos três arquivos C deve ser compilado separadamente. Para compilar os programas, você pode usar o seguinte comando em um terminal:
```bash
gcc configurar_sistema.c -o configurar_sistema
gcc finalizar_sistema.c -o finalizar_sistema
gcc sistema_reservas.c -o sistema_reservas
```
Isso vai gerar três executáveis chamados `configurar_sistema`, `finalizar_sistema` e `sistema_reservas`.

## Passo 2
Execute o programa `configurar_sistema` para configurar as áreas de memória compartilhada:

```bash
./configurar_sistema
```

> [!NOTE]
> Você pode executar várias instâncias desse programa simultaneamente em diferentes terminais para simular múltiplos usuários interagindo com o sistema.

Isso criará e inicializará as áreas de memória compartilhada para armazenar o status das reservas e os códigos das turmas.

## Passo 3
Execute o programa `sistema_reservas` para começar a interagir com o sistema de reservas:


```bash
./sistema_reservas
```
Esse programa permite reservar, liberar salas e visualizar o status de todas as salas.

Nota: Você pode executar várias instâncias desse programa simultaneamente em diferentes terminais para simular múltiplos usuários interagindo com o sistema.

## Passo 4
Quando terminar de usar o sistema, execute o programa `finalizar_sistema` para remover as áreas de memória compartilhada:


```bash
./finalizar_sistema
```
Isso apagará as áreas de memória usadas pelo sistema de reservas.
