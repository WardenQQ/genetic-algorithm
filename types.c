#include "types.h"

#include <stdlib.h>
#include "operators.h"

gene_t random_gene()
{
    gene_t g;

    g.direction = rand() % 8;
    g.step = MIN_STEP + rand() % (MAX_STEP - MIN_STEP + 1);

    return g;
}

void init_population(population_t *pop)
{
    int i, j;

    pop->size = REDUCED_POPULATION_SIZE;
    for (i = 0; i < pop->size; i++) {
        for (j = 0; j < MAX_GENES; j++) {
            pop->genotypes[i].genes[j] = random_gene();
        }
    }
}

void add_to_population(population_t *pop, genotype_t gtype)
{
    if (pop->size < MAX_POPULATION_SIZE) {
        pop->genotypes[pop->size] = gtype;
        pop->size++;
    }
}

void reduce_population(population_t *pop)
{
    int idexes[REDUCED_POPULATION_SIZE];
    int sorted_idexes[REDUCED_POPULATION_SIZE];
    int i;

    for (i = 0; i < REDUCED_POPULATION_SIZE; i++) {
        idexes[i] = i;
        sorted_idexes[i] = i;
    }

    for (i = REDUCED_POPULATION_SIZE; i < pop->size; i++) {
        /* TODO */
    }
}

void generate_next_population(
        population_t *pop,
        int nb_children,
        int nb_immigrants,
        int tournament_size,
        int mutation_probability)
{
    int i;
    genotype_t child;

    for (i = 0; i < nb_children; i++) {
        child = mutate(crossover(tournament_select(pop, tournament_size),
                                 tournament_select(pop, tournament_size)),
                       mutation_probability);
        child.fitness = evaluate(&child);
        add_to_population(pop, child);
    }

    reduce_population(pop);
}
