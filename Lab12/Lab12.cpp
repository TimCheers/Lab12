#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <vector> 
using namespace std;
struct STR
{
    string NAME;
    int dat1;
    int dat2;
    int dat3;
    string No;
    int n;
};
int random(int a, int b)
{
    if (a > 0) return a + rand() % (b - a);
    else return a + rand() % (abs(a) + b);
}
void Fill(vector<STR> &human, int n1)
{
    human.clear();
    ifstream nameM1("NameM.txt");
    ifstream nameW1("NameW.txt");
    ifstream surnameM1("surnameM.txt");
    ifstream surnameW1("surnameW.txt");
    ifstream patronymicM1("patronymicM.txt");
    ifstream patronymicW1("patronymicW.txt");
    string nameM[42];
    string nameW[41];
    string surnameM[100];
    string surnameW[100];
    string patronymicM[65];
    string patronymicW[57];
    for (int i = 0; i < 42; i++)
    {
        string row;
        nameM1 >> row;
        nameM[i] = row;
    }
    for (int i = 0; i < 41; i++)
    {
        string row;
        nameW1 >> row;
        nameW[i] = row;
    }
    for (int i = 0; i < 100; i++)
    {
        string row;
        surnameM1 >> row;
        surnameM[i] = row;
    }
    for (int i = 0; i < 100; i++)
    {
        string row;
        surnameW1 >> row;
        surnameW[i] = row;
    }
    for (int i = 0; i < 65; i++)
    {
        string row;
        patronymicM1 >> row;
        patronymicM[i] = row;
    }
    for (int i = 0; i < 57; i++)
    {
        string row;
        patronymicW1 >> row;
        patronymicW[i] = row;
    }
    nameM1.close();
    nameW1.close();
    surnameM1.close();
    surnameW1.close();
    patronymicM1.close();
    patronymicW1.close();
    int r;
    for (int i = 0; i < n1; i++)
    {
        r = random(0,20);
        if (r<=10)
        {
            STR test;
            test.NAME = surnameM[random(0, 100)];
            test.NAME = test.NAME + ' ' + nameM[random(0, 42)];
            test.NAME = test.NAME + ' ' + patronymicM[random(0, 65)];
            test.dat1 = random(1, 31);
            test.dat2 = random(1, 12);
            test.dat3 = random(1950, 2005);
            test.No = '8';
            test.No += std::to_string(random(100, 999));
            test.No += std::to_string(random(1000000, 9999999));
            test.n = i + 1;
            human.push_back(test);
        }
        else
        {
            STR test;
            int n1, n2;
            test.NAME = surnameW[random(0, 100)];
            test.NAME = test.NAME + ' ' + nameW[random(0, 41)];
            test.NAME = test.NAME + ' ' + patronymicW[random(0, 57)];
            test.dat1 = random(1, 31);
            test.dat2 = random(1, 12);
            test.dat3 = random(1940, 2005);
            test.No = '8';
            test.No += std::to_string(random(100, 999));
            test.No += std::to_string(random(1000000, 9999999));
            test.n = i + 1;
            human.push_back(test);
        }
    }
    cout << "Заполнение прошло успешно!" << endl;
}
void Print(vector<STR> human, int n1)
{
    for (int i = 0; i < n1; i++)
    {
        cout << human[i].n << ')'<<'\t';
        cout << human[i].NAME << endl<<'\t';
        cout << human[i].dat1 << '.' << human[i].dat2 << '.' << human[i].dat3 << endl<<'\t';
        cout << human[i].No << endl << endl;
    }
}
void SaveInF(vector<STR> human, int n1)
{
    string NameF;
    cout << "Введите название файла для сохранения:";
    cin >> NameF;
    NameF += ".txt";
    ofstream F(NameF);
    for (int i = 0; i < n1; i++)
    {
        F << human[i].n << endl;
        F << human[i].NAME << endl;
        F << human[i].dat1 << ' ' << human[i].dat2 << ' ' << human[i].dat3 << endl;
        F << human[i].No << endl;
    }
    F.close();
    cout << "Сохранение прошло успешно!" << endl;
}
void GetFromF(vector<STR> &human, int &n1)
{
    human.clear();
    string NameF1;
    bool f = 0;
    while (f==0)
    {
        cout << "Введите название файла для чтения:";
        cin >> NameF1;
        NameF1 += ".txt";
        ifstream F1(NameF1);
        if (!F1.is_open())
        {
            cout << "Ошибка чтения файла" << endl;
        }
        else
        {
            f = 1;
            int i = 0;
            n1 = -1;
            string NAME0,NAME1;
            int dat01;
            int dat02;
            int dat03;
            string No0;
            int n0;
            while (!F1.eof())
            {
                STR test;
                F1 >> n0;
                F1 >> NAME1;
                getline(F1, NAME0);
                F1 >> dat01;
                F1 >> dat02;
                F1 >> dat03;
                F1 >> No0;
                test.NAME = NAME1 + ' ' + NAME0;
                test.dat1 = dat01;
                test.dat2 = dat02;
                test.dat3 = dat03;
                test.n = n0;
                test.No = No0;
                human.push_back(test);
                i++;
                n1++;
            }
            cout << "Чтение прошло успешно!" << endl;
        }
    }
}
void substringSearch(string str, string substr)
{
    int strl, substrl, res = -1;
    str = str.size();
    substrl - substr.size();
    if (strl != 0 && substrl != 0)
    {
        for (int i = 0; i < strl - substrl + 1; i++)
        {
            for (int j = 0; j < substrl; j++)
            {
                if (substr[j] != str[i + 1])
                {
                    break;
                }
                else if (j == substrl - 1)
                {
                    res = i;
                    break;
                }
            }
        }
        if (res != -1)
        {
            cout << "Подстрока найдена. подстрока начинается с " << res;
        }
        else
        {
            cout << "Подстроки нет в строке!" << endl;
        }
    }
}
void DelByNumb(vector<STR>& human, int k)
{
    auto iter = human.cbegin();
    human.erase(iter + k-1);
}
int main()
{
    system("chcp 1251>nul");
    setlocale(LC_ALL, "ru");
	srand(time(NULL));
    vector<STR> human;
    int n1=0;
    cout << "Введите команду" << endl << "Список доступных команд: стоп, заполнить случайно, вывести, загрузить из файла, сохранить в файле." << endl;
    string str = "слово";
    while (str!="стоп")
    {
        getline(cin, str);
        cout << endl;
        if (str=="заполнить случайно")
        {
            cout << "Введите количество элементов(не менее 100): ";
            while (n1 < 100)
            {
                cin >> n1;
                if (n1 < 100)
                {
                    cout << "Введено некоректное значение. Введите значение заново";
                }
            }
            Fill(human, n1);
        }
        if (str=="вывести")
        {
            Print(human, n1);
        }
        if (str=="загрузить из файла")
        {
            GetFromF(human, n1);
        }
        if (str=="сохранить в файле")
        {
            SaveInF(human, n1);
        }
    }
    return 0;
}


