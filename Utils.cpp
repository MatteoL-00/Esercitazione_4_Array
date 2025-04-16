#include <stdio.h>
#include "Utils.hpp"

data_t read_data(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return (data_t) {0};
    }

    data_t data;
    fscanf(fp, "Initial Investment;%lf\n", &data.initial_investment);
    fscanf(fp, "Number of Assets;%d\n", &data.num_assets);
    for (int i = 0; i < data.num_assets; i++) {
        fscanf(fp, "%lf;%lf\n", &data.weights[i], &data.returns[i]);
    }

    fclose(fp);
    return data;
}

double calculate_rate_of_return(data_t data) {
    double rate_of_return = 0;
    for (int i = 0; i < data.num_assets; i++) {
        rate_of_return += data.weights[i] * data.returns[i];
    }
    return rate_of_return;
}

double calculate_final_value(data_t data, double rate_of_return) {
    return data.initial_investment * (1 + rate_of_return);
}

void print_results(data_t data, double rate_of_return, double final_value) {
    printf("Initial Investment = %.2f, Number of Assets = %d\n", data.initial_investment, data.num_assets);
    printf("Weights = [ ");
    for (int i = 0; i < data.num_assets; i++) {
        printf("%.2f ", data.weights[i]);
    }
    printf("]\n");
    printf("Returns = [ ");
    for (int i = 0; i < data.num_assets; i++) {
        printf("%.2f ", data.returns[i]);
    }
    printf("]\n");
    printf("Rate of Return = %.4f\n", rate_of_return);
    printf("Final Value = %.2f\n", final_value);
}

void write_results(const char *filename, data_t data, double rate_of_return, double final_value) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    fprintf(fp, "Initial Investment = %.2f, Number of Assets = %d\n", data.initial_investment, data.num_assets);
    fprintf(fp, "Weights = [ ");
    for (int i = 0; i < data.num_assets; i++) {
        fprintf(fp, "%.2f ", data.weights[i]);
    }
    fprintf(fp, "]\n");
    fprintf(fp, "Returns = [ ");
    for (int i = 0; i < data.num_assets; i++) {
        fprintf(fp, "%.2f ", data.returns[i]);
    }
    fprintf(fp, "]\n");
    fprintf(fp, "Rate of Return = %.4f\n", rate_of_return);
    fprintf(fp, "Final Value = %.2f\n", final_value);

    fclose(fp);
}
