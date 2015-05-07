#ifndef _GENOTYPE_H_
#define _GENOTYPE_H_

#define MAX_GENES 100
#define MAX_POPULATION_SIZE 200
#define REDUCED_POPULATION_SIZE 100
#define MIN_STEP 0
#define MAX_STEP 16

enum {
    NORTH = 0,
    NORTH_EAST = 1,
    EAST = 2,
    SOUTH_EAST = 3,
    SOUTH = 4,
    SOUTH_WEST = 5,
    WEST = 6,
    NORTH_WEST = 7
};

typedef struct {
    int step;
    int direction;
} gene_t;

typedef struct {
    gene_t genes[MAX_GENES];
    double fitness;
} genotype_t;

typedef struct {
    genotype_t genotypes[MAX_POPULATION_SIZE];
    int size;
} population_t;

gene_t random_gene();

void init_population(population_t *pop);
void add_to_population(population_t *pop, genotype_t child);
void reduce_population(population_t *pop);
void generate_next_population(
        population_t *pop,
        int nb_children,
        int nb_immigrants,
        int tournament_size,
        int mutation_probability);

#endif
