#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

int toInt(string in)
{
    stringstream strstrm(in);

    int x;
    strstrm >> x;

    return x;
}

void insertionSort(int array[], int size)
{
    for (int j = 1; j < size; j++)
    {
        int key = array[j];
        int i = j - 1;
        for (;(0 <= i) && (array[i] > key);i--) {
            array[i + 1] = array[i];
        }
        array[i + 1] = key;
    }
}

void operate(int a[], int size)
{

    insertionSort(a,size);

    cout << endl <<"Resault of sorting :" << endl << endl;

    for (int i = 0; i < size; i++)
    {
        cout << to_string(a[i]) << endl
            //  << endl
             ;
    }

    cout << endl;

}

void getInputs()
{

    cout << "Please input your list . after input all items , type '*' ." << endl
         << endl;

    int size = 0;
    int *list = new int[0];
    int *tempList = new int[0];

    while (1)
    {
        string input;

        // cout << endl; 
        cout << "Input " << size + 1 << " >>  ";
        cin >> input;

        if (input != "*")
        {

            ++size;
            tempList = new int[size];
            for (int i = 0; i < size - 1; i++)
            {
                tempList[i] = list[i];
            }
            tempList[size - 1] = toInt(input);
            list = tempList;
        }
        else
        {
            tempList = new int[0];
            operate(list, size);

            break;
        }
    }
}

int main(int argc, char *argv[])
{

    cout << endl
         << "Welcome to integer sorter .\nit's free terminal app for windows by M.H.Rohani1385 ." << endl;

    getInputs();

    while (1)
    {

        cout << "If your oprates ended , input 'exit' . else type '1', then press Enter to start new operate ." << endl << endl;

        string in;
        cin >> in;

        if (in != "exit")
        {
            cout << "___________________________________________________________________________" << endl << endl;
            getInputs();
        }
        else
        {
            cout << endl;
            break;
        }
    }

    return 0;
}
