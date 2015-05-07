#ifndef _OPERATORS_H_
#define _OPERATORS_H_

#include "types.h"

#define MAX_TOURNAMENT_SIZE 20
#define MAX_PROBABILITY 100

genotype_t tournament_select(population_t *pop, int tournament_size);
genotype_t crossover(genotype_t parent1, genotype_t parent2);
genotype_t mutate(genotype_t gtype, int probability);
double evaluate(genotype_t *gtype);

#endif
