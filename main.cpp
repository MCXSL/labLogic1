#include <iostream>
#include <random>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {
    int a = 1;
    std::string answer;
    std::cin >> answer;
    switch (a) {
        case '1':
            int arr[10];
            // Источник энтропии для инициализации движка
            std::random_device rd;

            // Сам движок (Вихрь Мерсенна)
            std::mt19937 gen(rd());

            // Распределение для целых чисел от 1 до 100
            std::uniform_int_distribution<> distrib(1, 100);

            for (int i = 0; i < 10; i++) {
                arr[i] = distrib(gen);
            }


            break;
    }




}