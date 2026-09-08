#include <iostream>
#include <random>
#include <clocale> // для setlocale
#include <windows.h> // для SetConsoleCP и SetConsoleOutputCP
#include <limits>
#include <ctime>

using namespace std;


int enter() {
    int answer;

    while (true) {
        cin >> answer;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You enter incorrect answer. Please TRY AGAIN: \n" << endl;
        }
        else {
            break;
        }
    }

    return answer;
}

int main() {
    // Настраиваем локаль
    setlocale(LC_ALL, "Russian");

    // Дополнительно задаём кодовую страницу для консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a = 1;

    cout << "Please choice program 1 - 5" << endl;
    a = enter();

    switch (a) {

        case 1: {
            int arr[10];

            srand(time(nullptr));

            for (int i = 0; i < 10; i++) {
                arr[i] = rand();
                cout << arr[i] << endl;
            }

            int max = arr[0], min = arr[0];

            for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
                if (min > arr[i]) {
                    min = arr[i];
                }

                if (max < arr[i]) {
                    max = arr[i];
                }
            }

            cout << "Min: " << min
                 << "\nMax: " << max
                 << "\nResult: " << max - min << endl;

            break;
        }

        case 2: {

            struct student {
                string famil;
                string name;
                string facult;
                int Nomzach;
            } stud[3];

            for (int i = 0; i < 3; i++) {

                cout << "Введите фамилию студента: ";
                cin >> stud[i].famil;

                cout << "Введите имя студента " << stud[i].famil << ": ";
                cin >> stud[i].name;

                cout << "Введите название факультета студента "
                     << stud[i].famil << " "
                     << stud[i].name << ": ";
                cin >> stud[i].facult;

                cout << "Введите номер зачётной книжки студента "
                     << stud[i].famil << " "
                     << stud[i].name << ": ";
                stud[i].Nomzach = enter();
            }

            // Вывод всех студентов
            cout << "\nСписок студентов:\n";

            for (int i = 0; i < 3; i++) {
                cout << "Студент "
                     << stud[i].famil << " "
                     << stud[i].name
                     << " обучается на факультете "
                     << stud[i].facult
                     << ", номер зачётной книжки "
                     << stud[i].Nomzach
                     << endl;
            }

            // Поиск студента
            string searchFamil;

            cout << "\nВведите фамилию студента для поиска: ";
            cin >> searchFamil;

            bool found = false;

            for (int i = 0; i < 3; i++) {

                if (stud[i].famil == searchFamil) {

                    cout << "\nСтудент найден!\n";
                    cout << "Фамилия: " << stud[i].famil << endl;
                    cout << "Имя: " << stud[i].name << endl;
                    cout << "Факультет: " << stud[i].facult << endl;
                    cout << "Номер зачётной книжки: "
                         << stud[i].Nomzach << endl;

                    found = true;
                }
            }

            if (!found) {
                cout << "\nСтудент с такой фамилией не найден." << endl;
            }

            break;
        }

        default: {
            cout << "Такой программы нет." << endl;
            break;
        }
    }

    return 0;
}
