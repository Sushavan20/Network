#include<iostream>
using namespace std;

int Even_Parity(int n[],int len,int cnt){
    if(cnt%2==0)
        n[len]=0;
    else
        n[len]=1;

    cout<<"Even Parity Code: ";
    for(int i=0;i<=len;i++)
        cout<<n[i];
    cout<<endl;
}

int Odd_Parity(int n[],int len,int cnt){
    if(cnt%2!=0)
        n[len]=0;
    else
        n[len]=1;

    cout<<"Odd Parity Code: ";
    for(int i=0;i<=len;i++)
        cout<<n[i];
    cout<<endl;
}

int EP_Error(int n[],int len,int cnt){
    if(cnt%2==0)
        n[len]=0;
    else
        n[len]=1;

    cout<<"Error Code: ";
    if(n[len]==0)
        n[len]=1;
    else
        n[len]=0;

    for(int i=0;i<=len;i++)
        cout<<n[i];
    cout<<endl;
}

int OP_Error(int n[],int len,int cnt){

    if(cnt%2!=0)
        n[len]=0;
    else
        n[len]=1;

    cout<<"Error Code: ";
    if(n[len]==0)
        n[len]=1;
    else
        n[len]=0;

    for(int i=0;i<=len;i++)
        cout<<n[i];
    cout<<endl;
}

int main(){

    //Sender Part
    int dec,i,j,Size=0,Count=0;
    int bin[30],num[30];
    int temp=dec;

    cout<<"Enter the number in decimal: ";
    cin>>dec;

    for(i=0;dec>0;i++){
        if(dec%2==1)
            Count+=1;
        bin[i]=dec%2;
        Size+=1;dec/=2;
    }

    cout<<"In Binary Number: ";
    for(i=0;i<Size;i++){
        num[i]=bin[Size-1-i];
        cout<<num[i];
    }
    cout<<endl;

    Even_Parity(num,Size,Count);
    Odd_Parity(num,Size,Count);

    //Receiver Part
    int ch,s;
    cout<<"1 for Odd.\n2 for Even."<<endl;
    cout<<"Enter your choice: ";
    cin>>s;

    switch(s){
        case 1:
            cout<<"1 for Error Code.\n2 for Errorless Code."<<endl;
            cout<<"Enter your choice: ";
            cin>>ch;
            switch(ch){
                case 1:
                    OP_Error(num,Size,Count);
                    cout<<"Rejected."<<endl;
                    break;
                case 2:
                    Odd_Parity(num,Size,Count);
                    cout<<"Accepted."<<endl;
                    break;
                default:
                    cout<<"Wrong Input."<<endl;
            }
            break;

        case 2:
            cout<<"1 for Error Code.\n2 for Errorless Code."<<endl;
            cout<<"Enter your choice: ";
            cin>>ch;
            switch(ch){
                case 1:
                    EP_Error(num,Size,Count);
                    cout<<"Rejected."<<endl;
                    break;
                case 2:
                    Even_Parity(num,Size,Count);
                    cout<<"Accepted."<<endl;
                    break;
                default:
                    cout<<"Wrong Input."<<endl;
            }
            break;

        default:
            cout<<"Wrong Input."<<endl;
    }

    return 0;
}



