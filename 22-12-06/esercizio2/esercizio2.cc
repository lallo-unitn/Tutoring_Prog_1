using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

const int NMaxL{81};
const int scarto = 'A' - 'a';

int main(int argc, char* argv[]){

    if(argc != 3) {
        cerr << "Error, usage : ./a.out <sourcefile> <targetfile>" << endl;
        exit(0);
    }

    fstream myin, myout;

    myin.open(argv[1], ios::in);
    myout.open(argv[2], ios::out);

    if(myin.fail()){
        cerr << "Error " << argv[1] << "does not exist" << endl;
        exit(0);
    }

    char stringa[NMaxL];
    bool nextup{true};

    while(myin >> stringa){
        if(nextup == true){
            if(stringa[0] >= 'a' && stringa[0] <= 'z'){
                stringa[0] = stringa[0] + scarto;
            }
        }
        if(stringa[strlen(stringa)-1] == '!' || stringa[strlen(stringa)-1] == '?' || stringa[strlen(stringa)-1] == '.'){
            nextup = true;
            myout << stringa;
            myout << endl;
        }
        else{
            nextup = false;
            myout << stringa << ' ';
        }
    }

    myin.close();
    myout.close();

    return 0;

}