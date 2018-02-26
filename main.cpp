
#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include<cstdlib>  // for clear screen command
#include<conio.h>  // for getch command


class rle
{
    public:
        void compress();
        void decompress();
};


void rle::compress()
{
    char key,ch;
    string str;
    int freq=1;

    ifstream fin("poem.txt");     //file to be compressed
    ofstream fcom("com.txt");
// file into which the compressed data will be stored

    fin>>key;

    while (getline(fin,str))
// to read the data line-by-line till all lines are read
    {

        for (int i=0;i<=str.length();i++)
// read one character at time from the string
        {
            if (i==str.length())
// if all characters from the string have been read
            {
                fcom<<key<<freq<<endl;
                key=fin.peek();
                freq=0;
                break;
            }
            else if (key==str[i])
            {
                freq++;
            }
            else
            {
                fcom<<key<<freq;
                key=str[i];
                freq=1;
            }
        }
    }

    fin.close();
    fcom.close();

    cout<<"COMPRESSION SUCCESSFUL!"<<endl;
}



void rle::decompress()
{
    string str;
    int freq;
    int index;
    char key;

    ifstream fcom("com.txt");      // file to be decompressed
    ofstream fdecom("decom.txt");
// file into which decompressed data will be stored

    while (getline(fcom,str))
    {
        for (int i=0;i<str.length();i+=2)
// reading two bits of the string in one iteration, so steps of 2
        {
            key=str[i];
            freq=str[i+1]-48;
// to convert the ascii value of the numbers into integer

            index=1;
            while (index<=freq)
            {
                fdecom<<key;
                index++;
            }
        }
        fdecom<<endl;
    }

    fcom.close();
    fdecom.close();

    cout<<"DECOMPRESSION SUCCESSFUL!"<<endl;
}



int main()
{
    rle r;
    int choice;

    while (1)
    {
        system("cls");

        cout<<"******************************************************"<<endl;
        cout<<"                 RUN-LENGTH ENCODING                  "<<endl;
        cout<<"******************************************************"<<endl;

        cout<<endl<<endl;
        cout<<"     1. Compress a file "<<endl;
        cout<<"     2. Decompress a file"<<endl;
        cout<<"     3. Exit"<<endl;
        cout<<"Enter your choice here : ";
        cin>>choice;

        switch(choice)
        {
            case 1: // compress
                r.compress();
                getch();
                break;
            case 2: // decompress
                r.decompress();
                getch();
                break;
            case 3: //exit
                exit(0);
            default:
                cout<<"ERROR : Please enter a valid option!"<<endl;
        }
    }
    return 0;
}
