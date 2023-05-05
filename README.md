# Solução do Problema das N-Rainhas em OpenMP e MPI

Este repositório contém 2 programas para a solução do problema das N-rainhas, onde o objetivo é posicionar N rainhas em um tabuleiro de NxN de forma que nenhuma delas se ataque.
O primeiro programa utiliza a biblioteca OpenMP para a paralelização do processo de resolução do problema. Já o segundo é uma extensão do primeiro com uma camada a mais de paralelismo utilizando MPI.

## Compile and Run V1
O programa recebe dois argumentos na linha de comando:

- O número de rainhas N
- O número de threads que serão utilizadas para resolver o problema (opcional)

Para compilar o programa, execute o seguinte comando no terminal:
```
    gcc -fopenmp codv1.c -o codv1
```

Para executar o programa, use o seguinte comando:
```
    ./codv1 <n> <t>
```
Onde n é o tamanho do tabuleiro e t é o número de threads que serão utilizadas para resolver o problema. Se o argumento t não for especificado, o programa executará de forma sequencial.

## Compile and Run V2
O programa recebe dois argumentos na linha de comando 3:

- O número de processos MPI
- O número de rainhas N
- O número de threads que serão utilizadas para resolver o problema (opcional)

Para compilar o programa, execute o seguinte comando no terminal:
```
    mpicc -fopenmp codv2.c -o codv2
```

Para executar o programa, use o seguinte comando:
```
    mpirun -np <p> ./codv2 <n> <t>
```
Onde p é o número de processos, n é o tamanho do tabuleiro e t é o número de threads que serão utilizadas para resolver o problema. Se o argumento t não for especificado, o programa executará de forma sequencial.

## Avalicação de Desempenho
Neste repositório, encontra-se o arquivo 'Avaliação de Desempenho.pdf', que apresenta uma análise comparativa entre o desempenho do programa na sua forma sequencial e na sua forma paralela, considerando diferentes números de threads. A avaliação de desempenho visa avaliar a eficiência do programa, fornecendo informações relevantes sobre o tempo de execução e o speedup alcançado em cada uma das abordagens.

## Intregrantes do Grupo
- Alessandra Rosa Galvão
- Kayara da Silveira Pereira

## Licença
Este programa é de código aberto e pode ser utilizado livremente.
