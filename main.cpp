#include <iostream>
#include <random>
#include <clocale>
#include <limits>
#include <ctime>

using namespace std;

int enter()
{
    int answer;
    while (true)
    {
        cin >> answer;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << "You enter incorrect answer/ Please TRY AGAIN: \n"
                 << endl;
        }
        else
        {
            break;
        }
    }
    return answer;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int a = 1;

    
    while (true)
    {
        cout << "Запустить программу: \n1) вычисляющую разницу между максимальным и минимальным элементами массива \n3)реализующую создание массива произвольного размера, вводимого с клавиатуры. \n4)вычисляющую сумму значений в каждом столбце (или строке) двумерного массива. \n5)осуществляющую поиск среди структур student структуру с заданными параметрами (фамилией, именем и т.д.). \n0)Выйти" << endl;
        a = enter();
        switch (a)
        {

        case 1:
        {
            int arr[10];

            srand(time(nullptr));

            for (int i = 0; i < 10; i++)
            {
                arr[i] = rand();
                cout << arr[i] << endl;
            }

            int max = arr[0], min = arr[0];

            for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
            {
                if (min > arr[i])
                {
                    min = arr[i];
                }

                if (max < arr[i])
                {
                    max = arr[i];
                }
            }

            cout << "Min: " << min
                 << "\nMax: " << max
                 << "\nResult: " << max - min << endl;

            break;
        }

        case 3:
        {
            setlocale(LC_ALL, "Russian");
            int n = 0;
            do
            {
                cout << "Длина массива: ";
                n = enter();
                if (n <= 0)
                {
                    cout << "больше, больше!. Try again.\n";
                }
            } while (n <= 0);

            int *otv = new int[n];

            for (int i = 0; i < n; i++)
            {
                otv[i] = enter();
            }

            int i = 0;
            while (i < n)
                printf(" %d", otv[i++]);
            cin.clear();
        }

        case 4:
        {
            int otv[5] = {0, 0, 0, 0, 0};

            int a[5][5] = {{0, 1, 2235, 3, 4}, {0, 100, 2, 3, 4}, {0, 1, 200, 3, 4}, {12, 1, 2, 3, 4}, {0, 1, 2, 3, 40}};

            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    otv[i] = otv[i] + a[i][j];
                }
            }
            int i = 0;
            while (i < 5)
                printf(" %d", otv[i++]);
            cin.clear();
        }

        case 5:
        {
            struct student
            {
                string famil;
                string name;
                string facult;
                int Nomzach;
            } stud[3];

            for (int i = 0; i < 3; i++)
            {

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

            cout << "\nСписок студентов:\n";

            for (int i = 0; i < 3; i++)
            {
                cout << "Студент "
                     << stud[i].famil << " "
                     << stud[i].name
                     << " обучается на факультете "
                     << stud[i].facult
                     << ", номер зачётной книжки "
                     << stud[i].Nomzach
                     << endl;
            }

            string searchFamil;

            cout << "\nВведите фамилию студента для поиска: ";
            cin >> searchFamil;

            bool found = false;

            for (int i = 0; i < 3; i++)
            {

                if (stud[i].famil == searchFamil)
                {

                    cout << "\nСтудент найден!\n";
                    cout << "Фамилия: " << stud[i].famil << endl;
                    cout << "Имя: " << stud[i].name << endl;
                    cout << "Факультет: " << stud[i].facult << endl;
                    cout << "Номер зачётной книжки: "
                         << stud[i].Nomzach << endl;

                    found = true;
                }
            }

            if (!found)
            {
                cout << "\nСтудент с такой фамилией не найден." << endl;
            }
            cin.clear();

            break;
        }
        case 0:{
            return 1;
        }

        default:
        {
            cout << "Такой программы нет." << endl;
            break;
        }
        }
    }

    return 0;
}