#include <iostream>
#include<string>
using namespace std;

string Ones_complement(string data)
{
    for (int i=0;i<data.length();i++){
        if (data[i]=='0')
            data[i]='1';
        else
            data[i]='0';
    }
    return data;
}


string checkSum(string data, int block_size)
{
    // Check data size is divisible by block_size Otherwise add '0' front of the data
    int n = data.length();
    if (n % block_size != 0){
        int pad_size=block_size-(n%block_size);
        for (int i=0;i<pad_size;i++){
            data='0'+data;
        }
    }

    string result = ""; // Binary addition of all blocks with carry

    // First block of data stored in result variable
    for (int i = 0; i < block_size; i++){
        result += data[i];
    }

    // Loop to calculate the block wise addition of data
    for (int i=block_size;i<n;i+=block_size){
        string next_block = ""; // Stores the data of the next block

        for (int j=i;j<i+block_size;j++)
            next_block += data[j];

        string additions = ""; // Stores the binary addition of two blocks
        int sum = 0, carry = 0;
        // Loop to calculate the binary addition of the current two blocks of k size
        for (int k=block_size-1;k>=0;k--)
        {
            sum+=(next_block[k]-'0') + (result[k] - '0');
            carry=sum/2;
            if (sum==0){
                additions='0'+additions;
                sum=carry;
            }
            else if (sum==1){
                additions='1'+additions;
                sum=carry;
            }
            else if (sum==2){
                additions='0'+additions;
                sum=carry;
            }
            else{
                additions='1'+additions;
                sum=carry;
            }
        }

        // After binary add of two blocks with carry, if carry is 1 then apply binary addition
        string final = "";

        if (carry==1){
            for (int l=additions.length()-1;l>=0;l--){
                if (carry==0)
                    final = additions[l] + final;

                else if (((additions[l]-'0')+carry)%2==0){
                    final = "0" + final;
                    carry=1;
                }
                else {
                    final = "1" + final;
                    carry=0;
                }
            }
            result = final;
        }
        else
            result=additions;
    }
    return Ones_complement(result);
}


bool allSame(string s)
{
    int n = s.length();
    for (int i = 1; i < n; i++){
        if (s[i] != 0)
            return false;
    }
    return true;
}


int main()
{
    string sent;
    cout<<"Enter the data: ";
    cin>>sent;

    int k=8;
    cout<<"Enter the block size: ";
    cin>>k;

    //cout<<checkSum(sent,k)<<endl;

    string recieve = sent + checkSum(sent,k);
    cout<<recieve<<endl;

    string final = checkSum(recieve,k);
    cout<<final<<endl;
    if(allSame(final))
        cout<<"Error!";
    else
        cout<<"No Error!";
    return 0;
}


