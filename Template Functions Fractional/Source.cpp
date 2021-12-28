#include "Fractional.h"

int _count_elem, MIN_RANGE, MAX_RANGE;
int print_menu(int key) {
    string menu[]{ "\t\tВыберите пункт меню:",
        "\t\t1. Создание массива типа <int>, его сортировка, вывод и среднее арифметическое по четным и нечетным столбцам.",
        "\t\t2. Создание массива типа <double>, его сортировка, вывод и среднее арифметическое по четным и нечетным столбцам.",
        "\t\t3. Создание массива типа class ""Fractional""(целая и дробная части), его сортировка, вывод и среднее арифметическое по четным и нечетным столбцам.",
        "\t\t7.Закончить работу с программой" };
    int _count_elem = sizeof(menu) / sizeof(string);
    if (key != 1)
        for (int i = 0; i < _count_elem; i++)
        {
            cout << menu[i] << endl;
        }
    return _count_elem - 1;
}

double rand(double MIN_RANGE, double MAX_RANGE)
{
    return MIN_RANGE + (rand() % static_cast<unsigned int>((MAX_RANGE - MIN_RANGE) * 1000)) / 1000.;
}

template<typename Type>
void sort(Type** array, int str, int col)
{
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < col - 1; j++)
        {
            if (array[i][j] > array[i][j + 1])
            {
                swap(array[i][j], array[i][j + 1]);
                j = -1;
            }
        }
    }
}

template<typename Type>
void average(Type** array, double str, double col, double& a, double& b)
{
    double avg_even = 0, avg_odd = 0;
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < str; i++)
        {
            if (j % 2 != 0) avg_odd += array[i][j];
            else avg_even += array[i][j];
        }
    }
    a = avg_even / (ceil(col / 2) * str);
    b = avg_odd / (floor(col / 2) * str);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int count_elem = print_menu(1), variant = 0;

    srand(time(NULL));
    do
    {
        int m, n;
        cout << "\n\t\tМатрица, [n x m]" << endl;
        cout << "\t\tВведите n: ";
        cin >> n;
        cout << "\t\tВведите m: ";
        cin >> m;
        cout << "\t\tВведите левую и правую границы диапазона генерации через пробел: " << endl;
        cin >> MIN_RANGE >> MAX_RANGE;
        print_menu(0);
        cin >> variant;
        switch (variant) {
        case 1:
        {
            int** mas = new int* [n];
            for (int i = 0; i < n; i++)
            {
                mas[i] = new int[m];
                for (int j = 0; j < m; j++)
                {
                    mas[i][j] = rand() % MAX_RANGE + MIN_RANGE;
                    cout << mas[i][j] << " ";
                }
                cout << endl;
            }
            sort(mas, n, m);
            cout << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << mas[i][j] << " ";
                }
                cout << endl;
            }
            double a, b;
            average(mas, n, m, a, b);
            cout << a << " " << b;
        }
            break;
        case 2:
        {
            double** mas = new double* [n];
            for (int i = 0; i < n; i++)
            {
                mas[i] = new double[m];
                for (int j = 0; j < m; j++)
                {
                    mas[i][j] = rand(MIN_RANGE, MAX_RANGE);
                    cout << mas[i][j] << " ";
                }
                cout << endl;
            }
            sort(mas, n, m);
            cout << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << mas[i][j] << " ";
                }
                cout << endl;
            }
            double a, b;
            average(mas, n, m, a, b);
            cout << a << " " << b;
        }
            break;
        case 3:
        {
            Fractional** mas = new Fractional * [n];
            for (int i = 0; i < n; i++)
            {
                mas[i] = new Fractional[m];
                for (int j = 0; j < m; j++)
                {
                    mas[i][j] = rand(MIN_RANGE, MAX_RANGE);
                    cout << mas[i][j] << " ";
                }
                cout << endl;
            }
            sort(mas, n, m);
            cout << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << mas[i][j] << " ";
                }
                cout << endl;
            }
            double a, b;
            average(mas, n, m, a, b);
            cout << a << " " << b;
        }
            break;
        default:
            break;
        }
    } while (variant != count_elem);

    return 0;
}
