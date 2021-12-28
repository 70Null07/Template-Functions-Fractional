#include "Fractional.h"

int _count_elem, MIN_RANGE, MAX_RANGE;
int print_menu(int key) {
    string menu[]{ "\t\t�������� ����� ����:",
        "\t\t1. �������� ������� ���� <int>, ��� ����������, ����� � ������� �������������� �� ������ � �������� ��������.",
        "\t\t2. �������� ������� ���� <double>, ��� ����������, ����� � ������� �������������� �� ������ � �������� ��������.",
        "\t\t3. �������� ������� ���� class ""Fractional""(����� � ������� �����), ��� ����������, ����� � ������� �������������� �� ������ � �������� ��������.",
        "\t\t7.��������� ������ � ����������" };
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
        cout << "\n\t\t�������, [n x m]" << endl;
        cout << "\t\t������� n: ";
        cin >> n;
        cout << "\t\t������� m: ";
        cin >> m;
        cout << "\t\t������� ����� � ������ ������� ��������� ��������� ����� ������: " << endl;
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
