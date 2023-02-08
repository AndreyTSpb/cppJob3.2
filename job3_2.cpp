#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

const int N = 3; //кол-во элементов в массиве по горизонтале
const int M = 3; //кол-во элементов в массиве по вертикале
int arr[N][M]; //Исходный двумерный массив
int maxLenght = 1; //Максимальная количество знаков в массиве

// Глобальные прототипы - используются не только в базовом вызове
void row(char c); //прототип - функция отрисовки строк
void viewMatrix(int,int); //пототип - отображение матрицы

int main(){
    // Локальные прототипы
    string numRowString(int num, int max); //прототип -
    void fillMatrix(); //прототип заполнения матрицы
    void getLength(); // прототип
    void maxElement(); //прототип поиска максимального значения

    fillMatrix(); //ввод двумерного массива
	  getLength(); //максиммальная длинна символов в числе

	  maxElement();
	  return 0;
}

//Функция прверки максимольной введенной длинны
void getLength(){
    for(int i = 0; i< M; i++){
        for(int j = 0; j < N; j++){
            int qnt = to_string(arr[i][j]).size();
            if(maxLenght < qnt){
                maxLenght = qnt;
            }
        }
    }
    maxLenght = maxLenght+2;
}

//Функция вывода двумерного массива в консоль
void viewMatrix(int col, int rows){

    cout << " Двумерный массив: " << endl;
    //отмечаем цветом
    const string red("\033[0;31m"); //красный
    const string yellow("\033[0;33m"); //желтый
    const string reset("\033[0m"); //сброс
    //
    int s = 2;
    if(N>9){
        s = to_string(N).size();
    }
    cout << setw(s+2); //уголок лев.верх
    //колонки
    for(int j = 0; j < N; j++){
        cout<<"|"<<setw(maxLenght-2)<< "["<<j<<"]";
        if(j == N-1){
            cout << "|" << endl;
        }
    }
    row('=');
    for(int i = 0; i< M; i++){
        //строки
        string rStr = to_string(i);
        if(i == rows){
            rStr = yellow + rStr + reset; //отмечаем строку
        }
        cout << ""<< "[" << rStr << "]";
        //выболрка элементов
        for(int j = 0; j < N; j++){
            if(j == col && i == rows){
                 cout << "|" << red << setw(maxLenght) << arr[i][j] << reset;
            }else{
                 cout << "|" << setw(maxLenght) << arr[i][j];
            }
            if(j == N-1){
                cout << "|";
            }
        }
        cout << endl;
        if(i == M-1){
            row('=');
        }else{
            row('-');
        }
    }
}

//Функция заполнения двумерного массива с клавиатуры
void fillMatrix(){
    cout << "Укажите данные для двумерного массива " << N << " на "<< M << endl;
    for(int i = 0; i< M; i++){
        for(int j = 0; j < N; j++){
            cout << "arr["<<i<<"]["<< j <<"]= ";
            cin >> arr[i][j];
        }
    }
}

//Отрисовка строк
void row(char c){
    for(int j = 0; j < N+(maxLenght*N)+4; j++){
        cout << c;
    }
    cout << endl;
}


void maxElement(){
    // Локальные прототипы
    string numRowString(int num, int max); //объявление функции

    int col, rows, max;
    col = 0;
    rows = 0;
    max = arr[0][0];

    for(int i = 0; i < M; i++ ){
        for(int j = 0; j < N; j++){
            if(max < arr[i][j]){
                max = arr[i][j];
                col = j;
                rows = i;
            }
        }
    }

    viewMatrix(col,rows);
    row('*');
    cout << numRowString(rows,max)<< '\n';
}

string numRowString(int num, int max){
    return "Максимальное значение массива: "+to_string(max)+" находится в строке : "+to_string(num);
}
