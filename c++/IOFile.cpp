#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

//"one two three four" -> ["one", "two", "three", "four"]
void splitRow(string data, int columnNo, string* arr){
    int i = 0;
    stringstream ssin(data);
    while (ssin.good() && i < columnNo){
        ssin >> arr[i];
        ++i;
    }
}

void createNew(string filename){
    fstream fp;
    fp.open(filename, ios::trunc | ios::out);
    
    fp.close();
}

void addData(string filename, string data){
    fstream fp;
    fp.open(filename, ios::app);
    fp << data;
    fp.close();
}

void addLineData(string filename, string data){
    fstream fp;
    fp.open(filename, ios::app);
    fp << "\r" << data;
    fp.close();
}

bool searchLine(string filename, string data){
    bool found = false;
    fstream fp;
    fp.open(filename, ios::in);
    string item;
    while(!fp.eof()){
        fp >> item;
        if(item == data){
            found = true;
        }
    }

    fp.close();

    return found;
}


int main(int argc, char const *argv[])
{
    string result[4];
    splitRow("n i n e", 4, result);
    int i = 0;
    for (size_t i = 0; i < 4; i++)
    {
        cout << result[i];
    }
    
    
    
    return 0;
}
