//пусть пользователь вводит имя текстового файла
//в этом файле должен храниться массив целых чисел. Перед массивом идет одно число - длина массива
//надо вывести этот массив в консоль
//надо создать новый файл с именем out.txt и вывести туда сумму чисел в массиве

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    string fname;
    int size = 100, value;
    int* arr = new int [size] {};
    cout << "Введите имя файла для считывания данных [input.txt]: " << endl;
    cin >> fname;
    ifstream fileInput(fname);
    if (fileInput.is_open()) {
        int i = 0;
        fileInput >> size;
        while (fileInput >> value) {
            arr[i] = value;
            i++;
        }
    }
    fileInput.close();

    int sum = 0;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
        sum += arr[i];
    }
    cout << "Сумма элементов массива = " << sum << endl;

    string oname;
    cout << "Введите имя файла для сохранения данных [output.txt]: " << endl;
    cin >> oname;
    ofstream fileOutput(oname);
    if (fileOutput.is_open()) {
        fileOutput << sum << endl;
    }
    fileOutput.close();

    delete[] arr;
    return 0;
}
