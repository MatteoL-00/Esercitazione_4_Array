#pragma once

typedef struct {
    double initial_investment;
    int num_assets;
    double weights[8];
    double returns[8];
} data_t;

data_t read_data(const char *filename);
double calculate_rate_of_return(data_t data);
double calculate_final_value(data_t data, double rate_of_return);
void print_results(data_t data, double rate_of_return, double final_value);
void write_results(const char *filename, data_t data, double rate_of_return, double final_value);
