﻿/*Задание 2. Крестики-нолики
Что нужно сделать
Старая добрая игра на страницах всех школьных тетрадей.

+ Поле размером 3 × 3 представлено в виде двумерного массива с типом элементов char.
- Участвуют два игрока, они ходят по очереди и ставят в указанные ими в стандартном вводе
координаты свой символ — X или O (буквы латинского алфавита).
- Как только у одного из игроков будет установлено подряд три крестика или три нолика, он побеждает.
- Если свободных клеток не осталось, а трёх совпадающих элементов
не найдено, то объявляется ничья.
- Для простоты не будем рассматривать диагональные совпадения — только строго
вертикальные и строго горизонтальные.

Изначально всё поле инициализируется символом пробела — ‘ ‘(для обозначения пробела кавычки одинарные и в одну сторону).
Это можно сделать сразу при объявлении либо с помощью вложенного цикла. На каждом ходе при занятой клетке или при
неверных координатах этой клетки должно быть выведено сообщение, и игрок должен указать координаты клетки повторно.
После каждого хода надо выводить в консоль текущее состояние всего игрового поля для наглядности.

Советы и рекомендации
Действия для обоих игроков одинаковые, отличаются только символом, который ставится на поле.
Игровой цикл не должен быть бесконечным. Игра имеет определённое максимальное количество шагов.
Не забывайте про случай ничьей.
Как и в предыдущем задании, здесь будет удобно сразу заполнить массив значениями false. Количество мест, доступных
для заполнения, заранее известно. В процессе заполнения из этой переменой нужно не забывать вычитать единицу.
Чтобы отметить место как занятое, нужно лишь написать places[i][j] = true;.
Проверку на победу игрока, которую надо осуществлять после каждого хода, можно сделать с помощью вложенного цикла,
сразу проверяя и вертикаль, и горизонталь, а как именно — попробуйте догадаться сами.
Здесь заранее известно число ходов — 3 * 3. Столько раз должен быть выполнен цикл, который спрашивает у очередного
игрока координаты.
Символ, который будет установлен в указанных координатах, можно на каждом шаге менять подобным образом:
if (gamer_name == 'X')
                gamer_name = 'O';
else
                gamer_name = 'X';

Что оценивается
Корректный ход игры, соответствующий правилам.
Правильный (желательно красивый) вывод игрового поля.
Понятный игроку интерфейс.*/
#include <iostream>

int const SIZE = 3;

// игравое поле
void printBoard(char board[SIZE][SIZE])
{
    std::cout << "  0 1 2" << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << i << " ";
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// проверка на горизонталь и вертикаль (диоганаль)
bool isWin(char board[SIZE][SIZE], char symbol)
{
    // Проверка горизонталей и вертикалей
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
        {
            return true; // Горизонтальная линия
        }

        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
        {
            return true; // Вертикальная линия
        }
    }

    // Диоганальная линия
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
    {
        return true; // Диагональные линии
    }

    return false;
}

bool isDraw(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                return false; // Найдена свободная клетка, игра не окончена
            }
        }
    }
    return true; // Все клетки заполнены, ничья
}

int main()
{
    char board[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }

    char player = 'X';
    int moves = 0;

    while (moves < SIZE * SIZE) {
        printBoard(board);

        int row, col;
        std::cout << "Ход игрока " << player << ". Введите координаты клетки (строка):  ";
        std::cin >> row;
        std::cout << "Ход игрока " << player << ". Введите координаты клетки (столбец): ";
        std::cin >> col;

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            std::cout << "Некорректные координаты. Попробуйте снова." << std::endl;
            continue;
        }

        board[row][col] = player;
        moves++;

        if (isWin(board, player)) {
            printBoard(board);
            std::cout << "Игрок " << player << " победил!" << std::endl;
            break;
        }
        else if (isDraw(board)) {
            printBoard(board);
            std::cout << "Ничья! Хотите сыграть еще раз?" << std::endl;
            break;
        }

        /*if (player == 'X')
            player = 'O';
        else
            player = 'X';*/
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}