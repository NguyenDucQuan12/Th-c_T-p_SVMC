#include<iostream>
using namespace std;
int main(){

    freopen("input2.txt","r", stdin);
    int T;
    cin>>T;

    for(int test_case=1;test_case<=T;test_case++){

        int n;
        int min=0;
        int result=0;
        cin>>n;
        int *arr=new int [n];
        for (int i=0;i<n;i++){
            cin>>arr[i];
        }

        for(int x=2;x<n-2;x++){
            min=arr[x]-arr[x-2];
            for(int y=x-2;y<=x+2;y++){
                if(arr[x]-arr[y]<=min&&x!=y) min=arr[x]-arr[y];
                if(arr[x]-arr[y]<0){
                    min=0;
                    break;
                }
            }
            result+=min;
        }
        cout<<"#"<<test_case<<": ";
    cout<<result<<endl;
    delete []arr; 
        
    }
}