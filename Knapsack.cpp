#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Метод динамического программирования
//Сложность O(N*W)
int dynamically(int W, const std::vector<int>& weights, const std::vector<int>& cost, int n)
{
    //Создаем таблицу Вес/кол-во для сохранения значений стоимости, как-то так...
    vector<vector<int>> table(W + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (weights[i - 1] <= j)
            {
                table[j][i] = max(table[j][i - 1], table[j - weights[i - 1]][i - 1] + cost[i - 1]);
            }
            else
            {
                table[j][i] = table[j][i - 1];
            }
        }
    }
    return table[W][n];
}
//Метод полного перебора
//Сложность 2^n
int bruteforse(int W, const std::vector<int>& weights, const std::vector<int>& cost, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    else if (weights[n - 1] > W)
    {
        return bruteforse(W, weights, cost, n - 1);
    }
    else
    {
        return max(cost[n - 1] + bruteforse(W - weights[n - 1], weights, cost, n - 1), bruteforse(W, weights, cost, n - 1));
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    //W - V рюкзака
    int W = 15;
    //weights - веса предметов
    vector<int> weights{ 6, 4, 3, 2, 5 };
    //cost - цена предметов
    vector<int> cost{ 5, 3, 1, 3, 6 };
    // кол-во ячеек массива
    int n = weights.size();
    cout << "Результат 1 метода: "<<dynamically(W, weights, cost, n) << endl;
    cout << "Результат 2 метода: " << bruteforse(W, weights, cost, n);
    return 0;
}
