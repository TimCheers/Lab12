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
                test.NAME = NAME1 +  NAME0;
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
void substringSearch(string str, string substr, bool& f)
{
    int strl, substrl, res = -1;
    strl = str.size();
    substrl = substr.size();
    if (substrl != 0 && strl != 0)
    {
        int strl, substrl, res = 0;
        strl = str.size();
        substrl = substr.size();
        if (substrl != 0 && strl != 0)
        {
            for (int i = 0; i < strl - substrl + 1; i++)
            {
                if (str[i] == substr[0])
                {
                    for (int j = 0; j < substrl; j++)
                    {
                        if (str[i + j] == substr[j])
                        {
                            res++;
                        }
                    }
                    if (res != substrl)
                    {
                        res = 0;
                    }
                    else
                    {
                        i = strl;
                        cout << "Подстрока найдена, ";
                        f = 1;
                    }
                }
            }
        }
    }
}
void LineSearch(vector<STR> human,int n1,int d1, int d2, int d3)
{
    bool f = 0;
    for (int i = 0; i < n1; i++)
    {
        if (human[i].dat1 == d1 && human[i].dat2 == d2 && human[i].dat3 == d3)
        {
            cout << "номер искомого объекта: " << human[i].n << endl;
            f = 1;
        }
    }
    if (f == 0)
    {
        cout << "Объект не найден" << endl;
    }
}
int InterpolSearch(vector<STR>& A, int N, int key)
{
    int mid, left = 0, right = N - 1;
    while (A[left].dat1 <= key && A[right].dat1 >= key)
    {
        mid = left + ((key - A[left].dat1) * (right - left)) / (A[right].dat1 - A[left].dat1);
        if (A[mid].dat1 < key)
        {
            left = mid + 1;
        }
        else
        {
            if (A[mid].dat1 > key)
            {
                right = mid - 1;
            }
            else
            {
                return mid;
            }
        }
    }
    if (A[left].dat1 == key)
    {
        return left;
    }
    else
    {
        return -1;
    }
}
void Met3(int size, vector<STR>& A)
{
    cout << "\nДля интерполяционного поиска данные отсортированны по дню рождения в порядке возрастания\n\n";
    STR tmp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {

            if (A[j].dat1 > A[j + 1].dat1)
            {
                tmp.dat1 = A[j + 1].dat1;
                tmp.dat2 = A[j + 1].dat2;
                tmp.dat3 = A[j + 1].dat3;
                tmp.NAME = A[j + 1].NAME;
                tmp.No = A[j + 1].No;
                A[j + 1].dat1 = A[j].dat1;
                A[j + 1].dat2 = A[j].dat2;
                A[j + 1].dat3 = A[j].dat3;
                A[j + 1].NAME = A[j].NAME;
                A[j + 1].No = A[j].No;
                A[j].dat1 = tmp.dat1;
                A[j].dat2 = tmp.dat2;
                A[j].dat3 = tmp.dat3;
                A[j].NAME = tmp.NAME;
                A[j].No = tmp.No;
            }
        }
    }
    cout << "\t\t\tОТСОРТИРОВАННЫЙ МАССИВ:\n-------------------------------------------------------------\n";
    Print(A, size);
    cout << "\n-------------------------------------------------------------\n";
}
void DelByNumb(vector<STR>& human, int k, int& n)
{
    auto iter = human.cbegin();
    human.erase(iter + k-1);
    n--;
    for (int i = k-1; i < n; i++)
    {
        human[i].n--;
    }
    cout << "Элемент с номером " << k << " успешно удалён\n\n";
}
void AddByNumb(vector<STR>& human, int k, int& n)
{
    cin.ignore();
    STR tmp;
    tmp.n = k;
    cout << "Введите параметры\n";
    cout << "ФИО: ";
    getline(cin, tmp.NAME);
    cout << "Телефонный номер: ";
    cin >> tmp.No;
    cout << "Дата рождения:\nДень: ";
    cin >> tmp.dat1;
    cout << "Номер месяца: ";
    cin >> tmp.dat2;
    cout << "Год: ";
    cin >> tmp.dat3;
    cout << endl;
    auto iter = human.cbegin();
    human.emplace(iter + k - 1, tmp);
    n++;
    for (int i = k ; i < n; i++)
    {
        human[i].n++;
    }
    cout << "Элемент с номером " << k << " успешно добавен\n\n";
}
void DelByKey(vector<STR>& human, int& n, int k)
{
    auto iter = human.cbegin();
    human.erase(iter + k - 1);
    n--;
    for (int i = k - 1; i < n; i++)
    {
        human[i].n--;
    }
}
///////////////////////////////////////////////////////////МЕТОД БМ////////////////////////////////////////////////////////////////////////////////
void BMsearch(string str, string substr, bool& f)
{
    int stl, subctl;
    stl = str.size();
    subctl = substr.size();
    if (stl != 0 && subctl != 0 && stl >= subctl)
    {
        int i, p;
        int b[256];
        for (i = 0; i < 256; i++)
        {
            b[i] = subctl;
        }
        for (i = subctl - 2; i >= 0; i--)
        {
            if (b[int(unsigned char(substr[i]))] == subctl)
            {
                b[int(unsigned char(substr[i]))] = subctl - i - 1;
            }
        }
        p = subctl - 1;
        while (p < stl)
        {
            if (substr[subctl - 1] != str[p])
            {
                p += b[int((unsigned char)str[p])];
            }
            else
            {
                for (i = subctl - 1; i >= 0; i--)
                {
                    if (substr[i] != str[p - subctl + i + 1])
                    {
                        p += b[int((unsigned char)str[p])];
                        i = -1;
                    }
                    else if (i == 0)
                    {
                        cout << "Подстрока найдена, ";
                        f = 1;
                        p = stl;
                    }
                }
            }
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int KMPSearch(string strin, string substring) { //в качестве параметров в функцию передается строка и субстрока
    int  sl, ssl;
    int res = -1;
    sl = strin.length();                                            //присваивается длина строки
    ssl = substring.length();                                      //присваивается длина субстроки
    if (sl == 0)                                                    //проверка строки
        cout << "Неверно задана строка\n";
    else if (ssl == 0)                                            //проверка субстроки
        cout << "Неверно задана подстрока\n";
    else
    {                                                            //Если все нормально - поехали
        int  i, j = 0, k = -1;
        int* d;
        d = new int[1000];                                         //создали динамический одномерный массив
        d[0] = -1;                                                    //первый элемент делаем равным -1
        while (j < ssl - 1) {                                      //пока  j < кол-ва эл-тов строки
            while (k >= 0 && substring[j] != substring[k]) /*пока k больше или равно 0 и j-тый элемент субстроки не равен
                                                                           k-тому присваиваем k k-тый элемент динамического массива*/
                k = d[k];
            j++;                                                         //увеличиваем j
            k++;
            if (substring[j] == substring[k])                   //если j-ый элемент субстроки равен k-тому
                d[j] = d[k];                                             //присваиваем j-тому элементу динамического массива k-тый
            else                                                         //иначе
                d[j] = k;                                                 //присваиваем k
        }
        i = 0;
        j = 0;                                                         //обнулили i, j
        while (j < ssl && i < sl)
        {                               //пока j < длины субстроки и i < длины строки
            while (j >= 0 && strin[i] != substring[j])       // пока j >= 0 и i-ый элемент субстроки не равен j-ому
                j = d[j];                                                  //j присваивается j-ый элемент динамического массива
            i++;
            j++;                                                         //увеличиваем i и j
        }


        delete[] d;                                                 //удаляем динам. массив                                                
        res = j == ssl ? i - ssl : -1;                           // результатом будет i-ssl если j = ssl и -1 в противном случае
    }
    return res;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    system("chcp 1251>nul");
    setlocale(LC_ALL, "ru");
	srand(time(NULL));
    vector<STR> human;
    int n1=0;
    cout << "ВВЕДИТЕ КОМАНДУ" << endl << "Список доступных команд:\n\n1.стоп\t\t\t\t2.заполнить случайно\n3.вывести\t\t\t4.загрузить из файла\n5.сохранить в файле\t\t6.найти строку\n7.линейный поиск\t\t8.команды\n9.интерполяционный поиск\t10.удалить по номеру\n11.добавить\t\t\t12.удалить по ключу" << endl << endl;
    cout << "------------------------------------------------------------------------------------------" << endl << endl;
    cout << "13.метод БМ\t\t\t14.метод КМП" << endl << endl;
    string str = "слово";
    while (str!="стоп")
    {
        cout << "------------------------------------------------------------------------------------------" << endl<<endl;
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
            if (n1==0)
            {
                cout << "Вывод на экран невозможен." << endl<<endl;
            }
            else
            {
                Print(human, n1);
            }
        }
        if (str=="загрузить из файла")
        {
            GetFromF(human, n1);
        }
        if (str=="сохранить в файле")
        {
            if (n1 == 0)
            {
                cout << "Сохранение невозможно." << endl << endl;
            }
            else
            {
                SaveInF(human, n1);
            }
        }
        if (str == "найти строку")
        {
            int b = 0;
            string P;
            bool f = 0;
            cout << "Введите параметр поиска: "<<endl;
            getline(cin, P);
            for (int i = 0; i < n1; i++)
            {
                f = 0;
                substringSearch(human[i].NAME, P, f);
                if (f==1)
                {
                    b++;
                    cout << "номер искомой строки: " << human[i].n << endl;
                }
            }
            if (b == 0)
            {
                cout << "\nСтрока не найдена\n";
            }
        }
        if (str == "линейный поиск")
        {
            string P;
            int  dat01 = -1, dat02 = -1, dat03 = -1;
            cout << "Введите параметр поиска: ";
            while ((dat01 <= 0 || dat01 >= 30) || (dat02 <= 0 || dat02 >= 12) || (dat03 >= 2003 || dat03 < 1950))
            {
                cout << "День:\t"; cin >> dat01;
                cout << "Номер месяца:\t"; cin >> dat02;
                cout << "Год:\t"; cin >> dat03;
                if ((dat01 <= 0 || dat01 >= 30) || (dat02 <= 0 || dat02 >= 12) || (dat03 >= 2003 || dat03 < 1940))
                {
                    cout << "Введены некоректные данные! Введите дату рождения заново!" << endl;
                }
                LineSearch(human, n1, dat01, dat02, dat03);
            }
        }
        if (str=="команды")
        {
            cout << "Список доступных команд:\n\n1.стоп\t\t\t\t2.заполнить случайно\n3.вывести\t\t\t4.загрузить из файла\n5.сохранить в файле\t\t6.найти строку\n7.линейный поиск\t\t8.команды\n9.интерполяционный поиск\t10.удалить по номеру\n11.добавить\t\t\t12.удалить по ключу" << endl;
            cout << "------------------------------------------------------------------------------------------" << endl << endl;
            cout << "13.метод БМ\t\t\t14.метод КМП" << endl << endl;
        }
        if (str == "интерполяционный поиск")
        {
            Met3(n1, human);
            int key, ans;
            cout << "Введите параметр поиска(день рождения): " << endl;
            cin >> key;
            ans = InterpolSearch(human, n1, key);
            if (ans==-1)
            {
                cout << "Элемента нет" << endl;
            }
            else
            {
                cout << "Искомые элементы начинаются с " << ans-1 << " индекса" << endl;
            }
        }
        if (str == "удалить по номеру")
        {
            int No=-1;
            cout << "Введите номер удаляемого элемента: ";
            while (No <= 0 || No >= n1 + 1)
            {
                cin >> No;
                if (No <= 0 || No >= n1 + 1)
                {
                    cout << "Введено некоректное значение" << endl;
                }
            }
            DelByNumb(human, No, n1);
        }
        if (str == "добавить")
        {
            int No = -1;
            cout << "Введите номер добавляемого элемента: ";
            while (No <= 0 || No >= n1 + 2)
            {
                cin >> No;
                if (No <= 0 || No >= n1 + 2)
                {
                    cout << "Введено некоректное значение" << endl;
                }
            }
            AddByNumb(human, No, n1);
        }
        if (str == "удалить по ключу")
        {
            string P;
            bool f = 0, b = 0;
            cout << "Введите параметр удаления(ФИО): " << endl;
            getline(cin, P);
            for (int i = 0; i < n1; i++)
            {
                f = 0;
                substringSearch(human[i].NAME, P, f);
                if (f == 1)
                {
                    int k = human[i].n;
                    DelByKey(human, n1, k);
                    b = 1;
                    cout << " И удалена!\n";
                }
            }
            if (b==1)
            {
                cout << "\nЭлементы удалены\n\n";
            }
            else
            {
                cout << "Элементы не найдены\n";
            }
        }
        if (str == "метод БМ")
        {
            int b = 0;
            string P;
            bool f = 0;
            cout << "Введите параметр поиска: " << endl;
            getline(cin, P);
            for (int i = 0; i < n1; i++)
            {
                f = 0;
                BMsearch(human[i].NAME, P, f);
                if (f == 1)
                {
                    b++;
                    cout << "номер искомой строки: " << human[i].n << endl;
                }
            }
            if (b == 0)
            {
                cout << "\nСтрока не найдена\n";
            }
        }
        if (str == "метод КМП")
        {
            int b = 0;
            string P;
            int f = 0;
            cout << "Введите параметр поиска: " << endl;
            getline(cin, P);
            for (int i = 0; i < n1; i++)
            {
                f = 0;
                f = KMPSearch(human[i].NAME, P);
                if (f >-1)
                {
                    b++;
                    cout << "Подстрока найдена, номер искомой строки: " << human[i].n << endl;
                }
            }
            if (b == 0)
            {
                cout << "\nСтрока не найдена\n";
            }
        }
        if (str=="стоп")
        {
            cout << "Программа остановлена!" << endl << endl;
        }
    }
    return 0;
}


