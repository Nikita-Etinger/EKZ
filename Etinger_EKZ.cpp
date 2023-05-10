

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define random(a,b) a+rand()%(b+1-a)
#define test 10
void foo1() {
    int a=0;
    int x;
    for (int i = 0; i < 4; i++) {
        cin >> x;
        a += x;
    }
    cout << x / 4 << endl;

}

void foo2() {
    for (int i = 1; i < 41; i++) {
        cout << i;
    }
    cout << endl;
}

void foo3() {
    int x;
    cin >> x;
    for (int i = 1, j = x; i < x+1; i++, j--) {
        for (int k = i; k > 0; k--) {
            cout << "*";
        }
        for (int k = j; k > 0; k--) {
            cout << " ";
        }
        cout <<endl;
    }
}

void foo4() {
    int x = 0;
    int count=0;
    cin >> x;
    while (x) {
        x /= 10;
        count++;
    }
    cout << count;
}

void foo5() {
    int size = 10;
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);

    //cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = random(a,b);
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i];
    }
    cout << endl;
}

void foo6() {
    int size = 5;
    int** arr = new int* [size];
    for (int i = 0; i < size; i++) {
        arr[i] = new int[size];
        for (int j = 0; j < size; j++) {
            arr[i][j] = random(1, 100);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int* arSize = new int[size] {};
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arSize[i]+= arr[i][j];
            
        }
        cout << arSize[i] << " "<<endl;
    }
    cout << endl;
    int x = 0;
    for (int i = 1; i < size; i++) {
        if (arSize[i] > arSize[0]) {
            arSize[0] = arSize[i];
                x = i;
        }
    }
    cout << "MAX: " << arSize[0] << " in " << "arr[" << x << "]"<<endl;



}

void foo7(int**& arr1,int**& arr2) {
    
    int size1 = _msize(arr1) / sizeof(arr1[0]);
    int size2 = _msize(arr1[0]) / sizeof(arr1[0][0]);

    arr2 = new int* [size1];
    //for (int i = 0; i < size1; i++) {

    //    for (int j = 0; j < size2; j++) {
    //        cout << arr1[i][j] << " ";
    //    }
    //    cout << endl;

    //}
    //cout << endl << endl;
    for (int i = 0; i < size1; i++) {
        arr2[i] = new int[size2];
        for (int j = 0; j < size2; j++) {
            arr2[i][j] = arr1[i][j];
        }

    }

    //for (int i = 0; i < size1; i++) {

    //    for (int j = 0; j < size2; j++) {
    //        cout << arr2[i][j] << " ";
    //    }
    //    cout << endl;

    //}
}

void foo8() {
    int* arr1 = new int[5]{ 1,2,3,4,5 };
    int size1 = _msize(arr1) / sizeof(arr1[0]);
    int x = 0;
    cin >> x;
    x--;
    int* buf = new int[size1 - 1];
    for (int i = 0; i < x; i++) {
        buf[i] = arr1[i];
        cout << buf[i] << " ";
    }
    for (int i = x + 1; i < size1; i++) {
        buf[i - 1] = arr1[i];
        cout << buf[i-1] << " ";

    }
    delete[] arr1;
    arr1 = buf;




}

void foo9() {
    int x;
    int siz1 = 3;
    int siz2 = 3;
    int** arr1 = new int* [siz1];
    for (int i = 0; i < siz1; i++) {
        arr1[i] = new int[siz2];
        for (int j = 0; j < siz2; j++) {
            arr1[i][j] = random(1, 5);
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
    cin >> x;
    
    int size1 = _msize(arr1)/sizeof(arr1[0]);
    int size2 = _msize(arr1[0]) / sizeof(arr1[0][0]);

    int* arr2 = new int[size2] {1, 1, 1};
    int** buf = new int* [size1 + 1];

    for (int i = 0; i < x; i++) {
        buf[i] = arr1[i];
    }
    buf[x] = arr2;

    for (int i = x; i < size1; i++) {
        buf[i+1] = arr1[i];
        cout << endl;
    }
    for (int i = 0; i < size1 + 1; i++) {
        for (int j = 0; j < size2; j++) {
            cout << buf[i][j] << " ";


        }
        cout << endl;
    }



}

void foo10() {
    int size1 = 10;
    int size2 = 5;
    int** arr = new int* [size1];
    for (int i = 0; i < size1; i++) {
        arr[i] = new int[size2];
        for (int j = 0; j < size2; j++) {
            arr[i][j] = random(1, 100);
        }

    }

    //int size1 = _msize(arr) / sizeof(arr[0]);
    //int size2 = _msize(arr[0]) / sizeof(arr[0][0]);

    for (int i = 0; i < size1; i++) {

        for (int j = 0; j < size2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    int x = 0;
    cin >> x;
    x--;
    int** buf = new int*[size1 - 1];
    for (int i = 0; i < x; i++) {
        buf[i] = arr[i];
    }
    for (int i = x + 1; i < size1; i++) {
        buf[i - 1] = arr[i];
    }

    delete[] arr[x];
    arr = buf;


    for (int i = 0; i < size1-1; i++) {

        for (int j = 0; j < size2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}

void foo11() {

}

int foo12() {
    string str1{ "hello my friend fristailo" };
    string str2{ "fri" };

    for (int i = 0; i < str1.length(); i++) {
        bool flag = 1;
        if (str1[i] == str2[0]) {
            for (int j = 1; j < str2.length(); j++) {
                if (str1[i + j] == str2[j]) continue;
                flag = 0;

            }
            if (flag) {
                return i;

            }

        }

    }
    return -1;

}

int foo13() {
    ifstream in;
    in.open("text.txt");
    if (in.is_open()) {
        string str="";
        int counter = 0;
        while (getline(in,str)) {
            for (int i = 0; i < str.length(); i++) {
                counter++;
            }

        }
        return counter;

    }




}


void foo14() {
    struct autom {
        string colour = "";
        string model = "";
        string show() {
            return "colour: " + colour + " model: " + model;
        }
    };
    struct park {

        autom* arr = nullptr;
        int counter = 0;
        void add(autom au) {
            autom* buf= new autom [counter + 1];
            for (int i = 0; i < counter; i++) {
                buf[i] = arr[i];
            }
            buf[counter] = au;
            counter++;
            delete[] arr;
            arr = buf;
        }
        void show() {
            for (int i = 0; i < counter; i++) {
                cout << arr[i].show() << endl;
            }
        }

    };




    autom a1={ "aaa","bbb" };
    autom a2 = { "ccc","dddd" };
    autom a3 = { "eeee","ffff" };
    park par1;
    par1.add(a1);
    par1.add(a2);
    par1.add(a3);
    par1.show();

}




int main()
{
    srand(time(NULL));
#if test ==1
    foo1();
#elif test==2
    foo2();
#elif test==3
    foo3();
#elif test==4
    foo4();
#elif test==5
    foo5();
#elif test==6
    foo6();
#elif test==7
    int size1 = 10;
    int size2 = 5;
    int** arr = new int* [size1];
    for (int i = 0; i < size1; i++) {
        arr[i] = new int[size2];
        for (int j = 0; j < size2; j++) {
            arr[i][j] =random(1,100);
        }

    }

    int** arr2 = new int* [size1];
    for (int i = 0; i < size1; i++) {
        arr2[i] = new int[size2];
    }
    foo7(arr,arr2);
#elif test==8
    foo8();
#elif test==9
    foo9();
#elif test==10
    foo10();
#elif test==11
    foo11();
#elif test==12
    cout<<foo12();
#elif test==13
    cout<<foo13();
#elif test==14
    foo14();
#endif 
}
