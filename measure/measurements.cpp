//
// Created by Filip Persson on 2024-05-07.
//

#include "measurements.h"

double avg(const std::vector<double>&vec){
    double sum = std::accumulate(std::begin(vec), std::end(vec), 0.0);
    return sum/vec.size();
}

double standardAv(const std::vector<double>& vec){
    std::valarray<double> valArr(vec.data(), vec.size());

    double sum = std::accumulate(std::begin(valArr), std::end(valArr), 0.0);
    auto N = valArr.size();
    auto medel = sum / N;

    std::valarray<double> dev_squared = std::pow(valArr - medel, 2);
    double sum_dev_squared = std::accumulate(std::begin(dev_squared), std::end(dev_squared), 0.0);

    return std::sqrt(sum_dev_squared * (1.0 / (N - 1)));
}