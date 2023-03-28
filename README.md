# Solução do Problema das N-Rainhas em OpenMP

Este programa é uma solução para o problema das N-rainhas, onde o objetivo é posicionar N rainhas em um tabuleiro de NxN de forma que nenhuma delas se ataque.
O programa utiliza a biblioteca OpenMP para a paralelização do processo de resolução do problema.

## Compile and Run
O programa recebe dois argumentos na linha de comando:

- O número de rainhas N
- O número de threads que serão utilizadas para resolver o problema (opcional)

Para compilar o programa, execute o seguinte comando no terminal:
```
    gcc -fopenmp cod.c -o cod
```

Para executar o programa, use o seguinte comando:
```
    ./cod <n> <t>
```
Onde n é o tamanho do tabuleiro e t é o número de threads que serão utilizadas para resolver o problema. Se o argumento t não for especificado, o programa executará de forma sequencial.

## Avalicação de Desempenho
Neste repositório, encontra-se o arquivo 'Avaliação de Desempenho.pdf', que apresenta uma análise comparativa entre o desempenho do programa na sua forma sequencial e na sua forma paralela, considerando diferentes números de threads. A avaliação de desempenho visa avaliar a eficiência do programa, fornecendo informações relevantes sobre o tempo de execução e o speedup alcançado em cada uma das abordagens.

## Intregrantes do Grupo
- Alessandra Rosa Galvão
- Kayara da Silveira Pereira

## Licença
Este programa é de código aberto e pode ser utilizado livremente.