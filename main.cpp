#include <iostream>

void OnLessonExercise1()
{
    //используя указатели, напишите алгоритм обмена значениями между двумя целыми числами
    //int a = 1, b = 7;
    //int *ptrA = &a, *ptrB = &b;

    int a = 1, b = 7;

    int* pA = &a;
    int* pB = &b;

    int* pCopyA = &a;

    pA = pB;
    pB = pCopyA;

    std::cout << "a = " << *pA << " b = " << *pB << std::endl;
}

void OnLessonExercise2()
{
    // формулировка из OnLessonExercise1, между тремя указателями
    // по примеру 2 3 4 ->> 3 4 2

    int a = 2, b = 3, c = 4;

    int* pA = &a;
    int* pB = &b;
    int* pC = &c;

    int* pCopyA = &a;

    pA = pB;
    pB = pC;
    pC = pCopyA;

    std::cout << "a = " << *pA << " b = " << *pB << " c = " << *pC << std::endl;
}

int CustomAbs(int iInput)
{
    return (iInput < 0) ? -iInput : iInput;
}

bool IsGoodInput (int iMin, int iMax)
{
    if (iMax < iMin)
    {
        std::cout << "Maximim should be greater than minimum" << std::endl;
        return false;
    }
    else if (iMax == iMin)
    {
        std::cout << "Maximim int with maximum dividers is: " << iMin << std::endl;
        return false;
    }
    return true;
}

void Exercise1()
{
    //найти число из диапазона [a, b] (вводятся пользователем) с максимальным количеством делителей

    std::cout << "Enter a, b to find from [a,b] number with max dividers" << std::endl;

    int iMin = 0;
    int iMax = 0;
    int iCurrentMaxDivInt = 0;
    int iCurrentMaxDividers = 0;

    std::cin >> iMin >> iMax;
    if (!IsGoodInput(iMin, iMax))
        return;

    for (int i = iMin; i <= iMax; i++)
    {
        int iDividers(1); // 1 учитывает то, что число делится на само себя без остатка
        for (int k = 1; k <= CustomAbs(i)/2; k++)
        {
            if (!(i%k))
                iDividers++;
        }

        if (iCurrentMaxDividers <= iDividers)
        {
            iCurrentMaxDividers = iDividers;
            iCurrentMaxDivInt = i;
        }
    }

    std::cout << "Maximim int with maximum dividers is: " << iCurrentMaxDivInt << std::endl;
}

void Exercise2()
{
    // найти следующее простое число после заданного. Пользователь вводит произвольное число,
    // требуется найти следующее простое. Ввод = 45, вывод 47. Ввод 5061, вывод 5077

    std::cout << "Enter number to find next prime number" << std::endl;

    int iInput = 0;
    int iNextPrimeNumber = 0;
    bool bExtraDivFound = false;
    std::cin >> iInput;

    if (iInput <= 1)
    {
        std::cout << "Next prime number is 2";
        return;
    }

    while(true)
    {
        ++iInput;
        for (int i = 2; i <= iInput/2; i++)
        {
            if (!(iInput%i))
            {
                bExtraDivFound = true;
                break;
            }
        }

        if (!bExtraDivFound)
        {
            iNextPrimeNumber = iInput;
            break; //бреак выше?
        }
        else
            bExtraDivFound = false;

    }

    std::cout << iNextPrimeNumber << std::endl;
}

int main()
{
    //OnLessonExercise1();
    //OnLessonExercise2();
    //Exercise1();
    //Exercise2();
    return 0;
}

