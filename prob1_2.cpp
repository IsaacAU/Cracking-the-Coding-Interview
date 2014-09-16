#include <iostream>
#include <cstring>
using namespace std;

void reverse_Cstr(char *arr){
    int len = strlen(arr);
    char tmp;
    for(int i = 0; i != len/2; ++i){
        tmp = arr[i];
        arr[i] = arr[len-1-i];
        arr[len-1-i] = tmp;
    }
}

int main()
{
    char arr[] = "abcd";
    cout<<arr<<endl;
    reverse_Cstr(arr);
    cout<<arr<<endl;
    return 0;
}
