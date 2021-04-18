#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;


//__________________________________________________________Sea_Fight______________________________


void printField(char** arr, char** arr2, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << "\t\t";
        for (int k = 0; k < cols; k++)
        {
            cout << arr2[i][k] << ' ';
        }
        cout << endl;
    }

}
void initField(char** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            //координаты верт/цифры
            if (j == 0)
            {
                arr[i][j] = ' ';
            }
            if (j == 1)
            {
                arr[i][j] = (char)(48 + i - 1);
            }
            if (i == rows - 2)
            {
                arr[i][0] = '1';
                arr[i][1] = '0';
            }
            //координаты буквы/горизонт
            if (i == 0 && j > 2)
            {
                arr[0][j] = (char)(65 + j - 3);
            }

            //границы горизонт
            if (i == 1 || i == rows - 1)
            {
                arr[i][j] = '-';
            }
            //границы вертикаль
            if (j == 2 || j == cols - 1)
            {
                arr[i][j] = '|';
            }
            //затирание игрового поля и уголка
            if (i > 1 && j > 2 && i < rows - 1 && j < cols - 1)
            {
                arr[i][j] = ' ';
            }
            if (i == 0 && j < 2)
            {
                arr[i][j] = ' ';
            }
        }
    }
}

void setShips(char** arr, char** arr2, int rows, int cols, int freeArea[8][2])
{
    int nShips = 4;
    char x;
    int y;
    bool ret = false;
    do
    {
        do
        {
            ret = false;
            cout << "\nВведите координаты корабля (Буква / цифра) : \n";
            cout << "Буква\n";
            cin >> x;
            cout << "Цифра\n";
            cin >> y;
            system("cls");
            if (true)
            {
                for (int k = 0; k < 8; k++)
                {
                    if (arr[(y + 1) + freeArea[k][0]][(int)(x - 62) + freeArea[k][1]] == 'K')
                    {
                        ret = true;
                    }
                }
            }

            if (x < (char)65 || x >(char)74 || y < 1 || y >10 || ret == true)
            {
                cout << "Сюда нельзя поставить корабль, повторите ввод\n";
            }
        } while (x < (char)65 || x >(char)74 || y < 1 || y >10 || ret == true);

        //игровое поле
        for (int i = 1; i < rows - 1; i++)
        {
            for (int j = 2; j < cols - 1; j++)
            {
                // установка корабля по координатам
                if (j == (int)(x - 62) && i == y + 1)
                {
                    arr[i][j] = 'K';
                    nShips--;

                    //свободная зона возле корабля
                    //for (int k = 0; k < 8; k++)
                    //{
                    //    if (arr[i + freeArea[k][0]][j + freeArea[k][1]] == ' ')
                    //    {
                    //        arr[i + freeArea[k][0]][j + freeArea[k][1]] = (char)(-73);
                    //    }
                    //    
                    //}
                }
            }
        }
        printField(arr, arr2,rows, cols);
    } while (nShips!=0);
}
void setAiShips(char** arr, char** arr2, int rows, int cols, int freeArea[8][2])
{
    int nShips = 4;
    char x;
    int y;
    bool ret = false;

    do
    {
        do
        {
            ret = false;
            x = 65+(rand() % 9);
            y = rand() % 10;

            if (true)
            {
                for (int k = 0; k < 8; k++)
                {
                    if (arr[(y + 1) + freeArea[k][0]][(int)(x - 62) + freeArea[k][1]] == 'K')
                    {
                        ret = true;
                    }
                }
            }

            if (x < (char)65 || x >(char)74 || y < 1 || y >10 || ret == true)
            {
                cout << "Сюда нельзя поставить корабль, повторите ввод\n";
            }
        } while (x < (char)65 || x >(char)74 || y < 1 || y >10 || ret == true);

        //игровое поле
        for (int i = 1; i < rows - 1; i++)
        {
            for (int j = 2; j < cols - 1; j++)
            {
                // установка корабля по координатам
                if (j == (int)(x - 62) && i == y + 1)
                {
                    arr[i][j] = 'K';
                    nShips--;

                    //свободная зона возле корабля
                    //for (int k = 0; k < 8; k++)
                    //{
                    //    if (arr[i + freeArea[k][0]][j + freeArea[k][1]] == ' ')
                    //    {
                    //        arr[i + freeArea[k][0]][j + freeArea[k][1]] = (char)(-73);
                    //    }
                    //}
                }
            }
        }
        //printField(arr, arr2,rows, cols);
    } while (nShips != 0);
}

void Hshot(char** arr, char** arr2, int rows, int cols, int freeArea[8][2], int& AiShips, bool& Finish)
{
    char x;
    int y;
    bool ret = false;
    do
    {
        ret = false;
        do
        {
            cout << "\nВведите координаты выстрела (Буква / цифра) : \n";
            cout << "Буква\n";
            cin >> x;
            cout << "Цифра\n";
            cin >> y;

            if (x < (char)65 || x >(char)74 || y < 1 || y >10)
            {
                cout << "Сюда нельзя выстрелить, повторите ввод\n";
            }
        } while (x < (char)65 || x >(char)74 || y < 1 || y >10);

        //игровое поле
        for (int i = 1; i < rows - 1; i++)
        {
            for (int j = 2; j < cols - 1; j++)
            {
                // если попал
                if (j == (int)(x - 62) && i == y + 1)
                {
                    if (arr2[i][j] == 'K')
                    {
                        arr2[i][j] = 'X';
                        AiShips--;
                        //свободная зона возле корабля
                        for (int k = 0; k < 8; k++)
                        {
                            if (arr2[i + freeArea[k][0]][j + freeArea[k][1]] == ' ')
                            {
                                arr2[i + freeArea[k][0]][j + freeArea[k][1]] = (char)(-73);
                            }
                        }
                    }
                    ret = true;
                }
                //если промазал
                if (j == (int)(x - 62) && i == y + 1 && arr2[i][j] != 'X')
                {
                    if (arr2[i][j] != 'K')
                    {
                        arr2[i][j] = (char)(-73);
                    }
                }
            }
        }
        printField(arr, arr2, rows, cols);
        if (AiShips == 0)
        {
            cout << "YOU WINNER !!!";
            Finish = true;
        }
    } while (ret == false);
        
}
void AIshot(char** arr, char** arr2, int rows, int cols, int freeArea[8][2], int& HShips, bool& Finish)
{
    char x;
    int y;
    bool ret = false;
    do
    {
        ret = false;
        do
        {
            x = 65 + (rand() % 9);
            y = rand() % 10;

            if (x < (char)65 || x >(char)74 || y < 1 || y >10)
            {
                cout << "Сюда нельзя выстрелить, повторите ввод\n";
            }
        } while (x < (char)65 || x >(char)74 || y < 1 || y >10);

        //игровое поле
        for (int i = 1; i < rows - 1; i++)
        {
            for (int j = 2; j < cols - 1; j++)
            {
                // если попал
                if (j == (int)(x - 62) && i == y + 1)
                {
                    if (arr[i][j] == 'K')
                    {
                        arr[i][j] = 'X';
                        HShips--;
                        //свободная зона возле корабля
                        for (int k = 0; k < 8; k++)
                        {
                            if (arr[i + freeArea[k][0]][j + freeArea[k][1]] == ' ')
                            {
                                arr[i + freeArea[k][0]][j + freeArea[k][1]] = (char)(-73);
                            }
                        }
                    }
                    ret = true;
                }
                //если промазал
                if (j == (int)(x - 62) && i == y + 1 && arr[i][j] != 'X')
                {
                    if (arr[i][j] != 'K')
                    {
                        arr[i][j] = (char)(-73);
                    }
                }
            }
        }
        printField(arr, arr2, rows, cols);
        if (HShips == 0)
        {
            cout << "YOU LOOSE";
            Finish = true;
        }
    } while (ret == false);
    
}


void Game(char** arr, char** arr2, int rows, int cols, int freeArea[8][2], int& AiShips, int& HShips)
{
    int step = 1;
    bool Finish = false;
    do
    {
        if (step % 2 == 0)
        {
            cout << "Твой ход :\n";
            Hshot(arr, arr2, rows, cols, freeArea, AiShips, Finish);
            cout << "Ход "<<step<<"\tH Ships : " << HShips << "\tAi Ships : " << AiShips << endl;
            step++;
        }
        else
        {
            cout << "Ход АИ:\n";
            AIshot(arr, arr2, rows, cols, freeArea, HShips, Finish);
            cout << "Ход " << step << "\tH Ships : " << HShips << "\tAi Ships : " << AiShips << endl;
            step++;
        }
    } while (Finish==false);
    
}

//0 - 48    57 - 98
//A - 65    J - 74

int main()
{
    setlocale(LC_ALL, "RUS");
    srand(NULL());

    int rows = 13, cols = 14, HShips = 4, AiShips = 4;
    int freeArea[8][2] = { {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1} };
    

    // создание поля
    char** field_1 = new char* [rows];
    for (int i = 0; i < rows; i++)
    {
        field_1[i] = new char[cols];
    }
    //создание поля АИ
    char** field_2 = new char* [rows];
    for (int i = 0; i < rows; i++)
    {
        field_2[i] = new char[cols];
    }

    initField(field_1, rows, cols);
    initField(field_2, rows, cols);
    setShips(field_1, field_2, rows, cols, freeArea);
    setAiShips(field_2, field_1, rows, cols, freeArea);

    Game(field_1, field_2, rows, cols, freeArea, AiShips, HShips);


    //удаление полей
    for (int i = 0; i < rows; i++)
    {
        delete[]field_1[i];
    }
    delete[]field_1;
    for (int i = 0; i < rows; i++)
    {
        delete[]field_2[i];
    }
    delete[]field_2;
}




//_______________________________________________________________Каталог текстов песен

//// стереть содержимое фаила
//        //ofstream file("text.txt", ios_base::trunc);
//        //file.close();
//
//        ////открывает фаил для записи
//        //ofstream file("text.txt", ios_base::out);
//        //file << "Testing";
//        //file.close();

 //обращение к имеющемуся фаилу
        ////ifstream имя_объекта
        //char text[50];

//ifstream file_in("text.txt");
        //if (!file_in.is_open())
        //{
        //    cout << "file not found";
        //}
        //else
        //{
        //    file_in >> text;
        //    cout << text << endl;
        //    file_in.getline(text, 50);
        //    cout << text << endl;
        //    file_in.close();
        //}


//struct Songs
//{
//    string name;
//    string text;
//    string autor;
//    short int year;
//};
//void addText(Songs* cat)
//{
//    string text;
//    int x;
//    do
//    {
//        cout << "Добавление текста :\n1) с клавиатуры\n2) из фаила\n";
//        cin >> x;
//    } while (x != 1 && x != 2);
//    
//    switch (x)
//    {
//    case 1:
//        int index;
//        cout << "Выберите текст из каталога (0-4)\n";
//        cin >> index;
//        getline(cin, text);
//        cat[index].text.append(text);
//        break;
//
//    case 2:
//        ifstream file("song_text.txt");
//        if (!file.is_open())
//        {
//            cout << "file not found";
//        }
//        else
//        {
//            int index;
//            cout << "Выберите текст из каталога (0-4)\n";
//            cin >> index;
//            file >> cat[index].text;
//            cout << cat[index].text << endl;
//            file.close();
//        }
//        break;
//    }
//
//
//
//
//}
//void printSong(Songs* pesn)
//{
//    for (int i = 0; i < 4; i++)
//    {
//        cout << "\nНазвание : " << pesn[i].name;
//        cout << "\nАвтор : " << pesn[i].autor;
//        cout << "\nГод : " << pesn[i].year;
//        cout << "\nТекст : " << pesn[i].text << endl;
//    }
//    
//}
//void delText(Songs *cat)
//{
//    int x;
//    cout << "Выберите текст из каталога (0-4)\n";
//    cin >> x;
//    cat[x].text.clear();
//}
//void changeText(Songs* pesnya)
//{
//    int x;
//    string newText;
//    cout << "Выберите текст из каталога для изменения (0-4)\n";
//    cin >> x;
//    cout << "Введите новый текст\n";
//    cin >> newText;
//    pesnya[x].text.clear();
//    pesnya[x].text = newText;
//
//}
//void showText(Songs* pesnya)
//{
//    int x;
//    cout << "Выберите текст из каталога (0-4)\n";
//    cin >> x;
//    cout << pesnya[x].text;
//}
//void saveText(Songs pesnya)
//{
//    ofstream file;
//    file.open("song_text.txt"); //создание оъекта
//    file << pesnya.text;
//    file.close();
//}
//void searchSong(Songs pesnya, string serchWord)
//{
//    getline(cin, serchWord);
//
//    if (pesnya.autor.compare(serchWord))
//    {
//       
//        cout << pesnya.name << endl;
//    }
//
//
//}
//
//void Menu()
//{
//    cout << "1) добавить текст песни\n 2)Удаление текста\n 3) Изменение текста\n 4) Отображение";
//
//    addText()
//}
//int main()
//{
//    setlocale(LC_ALL, "RUS");
//    SetConsoleCP(1251);             
//    SetConsoleOutputCP(1251);
//    
//    Songs Catalog[10];
//    Catalog[0].autor = "Сплин ";
//    Catalog[0].name = "Вирус";
//    Catalog[0].text = "На этом видео кто-то невидимый\nТихо крадётся сквозь туман\nГород без имени, улицы вымерли\nЛюди закрылись по домам";
//    Catalog[0].year = 2020;
//
//    Catalog[1].autor = "Полина Гагарина ";
//    Catalog[1].name = "Ты выдумал меня";
//    Catalog[1].text = "Первый Куплет: Полина Гагарина\nМы встретились с тобой в невероятный год\nКогда уже иссякли мира силы\nВсё было в трауре, всё никло от невзгод \nИ были свежи лишь могилы";
//    Catalog[1].year = 2021;
//
//    Catalog[2].autor = "Ночные Снайперы ";
//    Catalog[2].name = "31 весна";
//    Catalog[2].text = "Рассвет, в соломе крылья, паутина, провода\nЯ мягким тигром сторожу тебя в окне\nИ обалдевшая от нежности вода несовершенна\n";
//    Catalog[2].year = 2019;
//
//    Catalog[3].autor = " Пикник ";
//    Catalog[3].name = "Египтянин";
//    Catalog[3].text = "Будто я египтянин,\nИ со мною и Солнце и зной,\nИ царапает небо когтями\nЛегкий Сфинкс, что стоит за спиной.";
//    Catalog[3].year = 2018;
//
//
//    string x;
//    
//    
//
//}

