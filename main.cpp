#pragma once

#include <stdio.h>
#include "Utils.hpp"

int main() {
    data_t data = read_data("data.txt");
    double rate_of_return = calculate_rate_of_return(data);
    double final_value = calculate_final_value(data, rate_of_return);

    print_results(data, rate_of_return, final_value);
    write_results("result.txt", data, rate_of_return, final_value);

    return 0;
}
