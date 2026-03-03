/**
 * @file main.cpp
 * @brief Тестирование и сравнение алгоритмов сортировки для записей ЗАГСа
 * @mainpage
 */

#include "zags_record.h"
#include "sorts.h"
#include "utils.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


/**
 * @brief Точка входа программы
 * Алгоритм работы:
 * 
 * 1. Создание выходного файла times.csv
 * 
 * 2. Цикл по файлам zags_N.csv (N=5,...,50000)
 * 
 * 3. Для каждого размера:
 * Загрузка данных ->
 * Измерение времени 4 сортировок ->
 * Запись результатов в CSV ->
 * Сохранение отсортированных данных
 * @return 0 при успехе
 */
int main() {
    std::ofstream times("times.csv");
    times << "size,selection_ms,shaker_ms,quicksort_ms,stdsort_ms\n";
    
    std::vector<std::string> sizes = {"5", "10", "20", "50", "100", "200", "500", "1000", "2000", "5000"};
    
    for (const auto& size_str : sizes) {
        std::string filename = "data/zags_" + size_str + ".csv";
        std::cout << "Testing " << filename << std::endl;
        
        auto data = read_csv(filename);
        if (data.empty()) {
            std::cout << "Skipping empty file" << std::endl;
            continue;
        }
        
        size_t n = data.size();
        
        double t_sel = measure_time(selection_sort, data);
        double t_shk = measure_time(shaker_sort, data);
        double t_qck = measure_time([&](auto& v){ quick_sort(v, 0, v.size()-1); }, data);
        double t_std = measure_time([](auto& v){ std::sort(v.begin(), v.end()); }, data);
        
        times << n << "," << t_sel << "," << t_shk << "," << t_qck << "," << t_std << "\n";
        
        std::sort(data.begin(), data.end());
        write_csv(data, "sorted-data/sorted_" + size_str + ".csv");
    }
    
    std::cout << "Results in times.csv" << std::endl;
    return 0;
}
