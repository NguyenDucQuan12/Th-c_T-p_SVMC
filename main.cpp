 #include<iostream>
 using namespace std;
 int main(){
	freopen("input.txt","r",stdin);

	int n,t=0,j,i,a[1000];
    cin>>n;  //so phan tu cua mang
    for(i=0;i<n;i++)
    cin>>a[i];   //nhap mang
 
     
    
    for(j=2;j<n-2;j++)    //bỏ 2 khối đầu và 2 khối cuối dều = 0
    {
       //tìm tòa nhà cao nhất trong 5 tòa nhà liên tiếp
        int max=a[j-2];
        for(i=j-1;i<=j+2;i++)
        {if(a[i]>max) max=a[i];}
       
        
        int min=a[j]-a[j-2];   //min = số block thỏa mãn trống 2 bên
        
        if(a[j]==max)          //kiểm tra xem khối thứ 3 trong 5 khối liên tiếp có cao nhất không
        {
            
            if(a[j]-a[j-1]<min) min=a[j]-a[j-1];
             if(a[j]-a[j+1]<min) min=a[j]-a[j+1];
              if(a[j]-a[j+2]<min) min=a[j]-a[j+2];
        }
        else min=0;
     t=t+min;
    }
    cout<<t;
    
}