/*
Author: Manohar Mukku
Date: 20.07.2018
Desc: MLP Classifier
GitHub: https://github.com/manoharmukku/multilayer-perceptron-in-c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct {
    int n_hidden;
    int* hidden_layers_size;
    int hidden_activation_function;
    float regularization_parameter;
    int n_iterations_max;
    int momentum;
    int output_layer_size;
    int output_activation_function;
    int sample_size;
    int feature_size;
    double** data;
} parameters;

void initialize_weights(int n_layers, int* layer_sizes, double*** theta) {
    srand(time(0));

    int i, j, k;
    for (i = 0; i < n_layers - 1; i++)
        for (j = 0; j < layer_sizes[i+1]; j++)
            for (k = 0; k < layer_sizes[i] + 1; k++)
                theta[i][j][k] = rand() / (double)RAND_MAX;
}

void MLPClassifier(parameters* param) {
    int n_layers = param->n_hidden + 2;

    // Save the sizes of layers in an array
    int** layer_sizes = (int*)calloc(n_layers, sizeof(int));

    layer_sizes[0] = param->feature_size - 1;
    layer_sizes[n_layers-1] = param->output_layer_size;

    int i;
    for (i = 1; i < n_layers-1 ; i++)
        layer_sizes[i] = param->hidden_layers_size[i-1];


    // Create memory for the weight matrices between layers
    // theta is a pointer to the array of 2D arrays between the layers
    double*** theta = (double***)calloc((n_layers - 1), sizeof(double**));

    // Each 2D array between two layers i and i+1 is of size (layer_size[i+1] x (layer_size[i]+1))
    for (i = 0; i < n_layers - 1; i++)
        theta[i] = (double**)calloc(layer_sizes[i+1], sizeof(double*));

    int j;
    for (i = 0; i < n_layers - 1; i++)
        for (j = 0; j < layer_sizes[i+1]; j++)
            theta[i][j] = (double*)calloc((layer_sizes[i] + 1), sizeof(double));

    // Initialize the weights
    initialize_weights(n_layers, layer_sizes, theta);

    for (i = 0; i < param->n_iterations_max; i++) {
        
    }

    // Free the memory allocated in Heap
    for (i = 0; i < n_layers - 1; i++)
        for (j = 0; j < layer_sizes[i+1]; j++)
            free(theta[i][j]);

    for (i = 0; i < n_layers - 1; i++)
        free(theta[i]);

    free(theta);

    free(layer_sizes);
}