#include "Class.h"
int main()
{
	setlocale(0, "");
    int n = -1;
	Fraction del1, del2;
    std::cin >> del1 >> del2;
    std::cout << "1 - Вычислить сложение дробей;\n2 - Вычислить разность дробей;\n3 - Вычислить произведение дробей;\n4 - Вычислить частное дробей;\n5 - Найти большую дробь;\n6 - Переприсвоить дробь;\n7 - Вывести дробь;\n8 - Проверка на равенство;\n0 - Завершить программу;\n";
    while (n != 0)
    {
        std::cin >> n;
        switch (n)
        {

            case 1:
            {
                std::cout << "Cумма дробей: " << del1 + del2 << '\n';
                break;
            }
            case 2:
            {
               std::cout << "Разность дробей: " << del1 - del2 << '\n';
               break;
            }
            case 3:
            {
                std::cout << "Произведение дробей: " << del1 * del2 << '\n';
                break;
            }
            case 4:
            {
                std::cout << "Частное дробей: " << del1 / del2 << '\n';
                break;
            }
            case 5:
            {
                if (del1 < del2)
                std::cout << del1 << "< " << del2 << '\n';
                else std::cout << del1 << "> " << del2 << '\n';
                break;
            }
            case 6:
            {
                del1 = del2;
                std::cout << del1 << '\n';
                break;
            }
            case 7:
            {
                std::cout << del1 << '    ' << del2 << '\n';
                break;
            } 
            case 8:
            {
                if (del1 == del2)
                    std::cout << "Дроби равны\n";
                else std::cout << "Дроби не равны\n";
                break;
            }
        }
    }
}
