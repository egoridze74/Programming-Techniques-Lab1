/**
 * @file sorts.h
 * @brief Объявления алгоритмов сортировки
 */

#ifndef SORTS_H
#define SORTS_H

#include "zags_record.h"
#include <vector>

/**
 * @brief Сортировка выбором
 * @param arr Ссылка на вектор для сортировки
 */
void selection_sort(std::vector<ZagsRecord>& arr);

/**
 * @brief Шейкер-сортировка
 * @param arr Ссылка на вектор для сортировки
 */
void shaker_sort(std::vector<ZagsRecord>& arr);

/**
 * @brief Быстрая сортировка
 * @param arr Ссылка на вектор для сортировки
 */
void quick_sort(std::vector<ZagsRecord>& arr, int low, int high);

#endif
