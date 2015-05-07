#include <stdlib.h>

#include "operators.h"

genotype_t tournament_select(population_t *pop, int tournament_size)
{
    genotype_t tournament[MAX_TOURNAMENT_SIZE];
    int i;
    int max;
    
    for (i = 0; i < tournament_size && i < MAX_TOURNAMENT_SIZE; i++) {
        tournament[i] = pop->genotypes[rand() % REDUCED_POPULATION_SIZE];
    }

    max = 0;
    for (i = 0; i < tournament_size && i < MAX_TOURNAMENT_SIZE; i++) {
        if (tournament[i].fitness > tournament[max].fitness) {
            max = i;
        }
    }

    return tournament[max];
}

genotype_t crossover(genotype_t parent1, genotype_t parent2)
{
    int i = 0;
    int cutpoint;
    genotype_t result;

    /*
     * We want to have the cutpoint in [1;MAX_GENES-1] so that the crossover
     * always includes parent1 and parent2 genes.
    */
    cutpoint = rand() % (MAX_GENES - 1) + 1;

    for (i = 0; i < cutpoint; i++) {
        result.genes[i] = parent1.genes[i];
    }
    for (i = cutpoint; i < MAX_GENES; i++) {
        result.genes[i] = parent2.genes[i];
    }

    return result;
}

genotype_t mutate(genotype_t gtype, int probability)
{
    int p, i;
    genotype_t result;

    for (i = 0; i < MAX_GENES; i++) {
        p = rand() % MAX_PROBABILITY;

        if (p < probability) {
            result.genes[i] = random_gene();
        } else {
            result.genes[i].direction = gtype.genes[i].direction;
            result.genes[i].step = gtype.genes[i].step;
        }
    }

    return result;
}

double evaluate(genotype_t *gtype)
{
    int i;
    double fitness = 0.0;

    for (i = 0; i < MAX_GENES; i++) {
        fitness += gtype->genes[i].step;
    }

    return fitness;
}
