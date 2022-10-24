#include<iostream>
using namespace std;
int main(){

    freopen("input.txt","r", stdin);
    int T;
    cin>>T;

    for(int test_case=1;test_case<=T;test_case++){
        int m;
        cin>>m;

        int max=0;
        int **arr = new int*[m+1];
        for(int i = 0; i<m+1; i++)
            arr[i] = new int[m+1];

        for(int r=0;r<m;r++){
            for(int c=0;c<m;c++){
                cin>>arr[r][c];
            }
        }

       /* for(int r=0;r<m;r++){
            cout<<endl;
            for(int c=0;c<m;c++){
                cout<<arr[r][c]<<" ";
            }
        }*/

        //tinh tong cua tung hang
        for(int r=0;r<m;r++){
            arr[r][m]=0;
            for(int c=0;c<m;c++){
                arr[r][m]=arr[r][m]+arr[r][c];
            }
        }

        //tinhs tong cua tung cot
        for(int r=0;r<m;r++){
            arr[m][r]=0;
            for(int c=0;c<m;c++){
                arr[m][r]=arr[m][r]+arr[c][r];
            }
        }
        //tinh tong duong cheo chinh
        arr[m][m]=0;
        for(int r=0;r<m;r++){
            arr[m][m]=arr[m][m]+arr[r][r];
        }

        //tinh tong duong cheo phu
        for(int r=0;r<m;r++){
            for(int c=0;c<m;c++){
              if((r+c)==m-1) max+=arr[r][c];
            }
        }

        //tim max
        for(int r=0;r<m+1;r++){
            for(int c=0;c<m+1;c++){
              if(arr[r][c]>max) max=arr[r][c];
            }
        }
        for(int i = 0; i<m+1; i++)
            delete []arr[i];
            delete []arr;
        cout<<"#"<<test_case<<": ";
        cout<<max<<endl;

    }

}