#include <iostream>
#include <random>
#include <clocale>
#include <limits>
#include <ctime>
#include <list>
#include <windows.h>

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
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    //5setlocale(LC_ALL, "Russian");

    int a = 1;

    
    while (true)
    {
        cout << "\nЗапустить программу: \n1) вычисляющую разницу между максимальным и минимальным элементами массива \n3)реализующую создание массива произвольного размера, вводимого с клавиатуры. \n4)вычисляющую сумму значений в каждом столбце (или строке) двумерного массива. \n5)осуществляющую поиск среди структур student структуру с заданными параметрами (фамилией, именем и т.д.). \n0)Выйти" << endl;
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
            break;
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
            break;
        }

        case 5:
        {
            struct student
            {
                string famil;
                string name;
                string facult;
                int Nomzach;
            };

            student stud;
            list<student> students;


            while (true)
            {
                cout << "Введите фамилию студента(Чтобы выйти введите #): ";
                cin >> stud.famil;
                if (stud.famil == "#") {
                    break;
                }

                cout << "Введите имя студента " << stud.famil << ": ";
                cin >> stud.name;

                cout << "Введите название факультета студента "
                     << stud.famil << " "
                     << stud.name << ": ";
                cin >> stud.facult;

                cout << "Введите номер зачётной книжки студента "
                     << stud.famil << " "
                     << stud.name << ": ";
                stud.Nomzach = enter();

                students.push_back(stud);
            }

            cout << "\nСписок студентов:\n";

            for (student stu : students)
            {
                cout << "Студент "
                     << stu.famil << " "
                     << stu.name
                     << " обучается на факультете "
                     << stu.facult
                     << ", номер зачётной книжки "
                     << stud.Nomzach
                     << endl;
            }

            string search;

            cout << "\nВведите данные о студенте для поиска (Формат: Фамилия Имя Факультет Номер_зачётной_книжки): ";
            cin >> search;

            bool found = false;

            for (student stu : students)
            {
                string student = stu.famil + " " + stu.name + " " + stu.facult + " " + to_string(stu.Nomzach);

                if (student.find(search) != std::string::npos)
                {

                    cout << "\nСтудент найден!\n";
                    cout << "Фамилия: " << stu.famil << endl;
                    cout << "Имя: " << stu.name << endl;
                    cout << "Факультет: " << stu.facult << endl;
                    cout << "Номер зачётной книжки: "
                         << stu.Nomzach << endl;

                    found = true;
                }
            }

            if (!found)
            {
                cout << "\nСтудент с такой фамилией не найден." << endl;
            }

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