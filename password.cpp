/*
cho dãy số, kiểm tra xem dãy số đó có đúng là password cảu điện thoại ko, password là mật khẩu điện thoại bằng cách vẽ hình
dòng đàu tiên là tổng các test_case, dòng tiếp theo là n-số password cần kiểm tra, n dòng tiếp theo là password
output sẽ là:
#test_case2 10110
#test_case3 101101011
#test_case4 1
1 là pass hợp lệ, 0 là pass sai( ví dụ đã vẽ qua số 3 thì ko thể quay lại vẽ tiếp)
*/
#include <iostream>
using namespace std;
int main()
{

    freopen("inputpassword.txt", "r", stdin);
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++)
    {
        int dem;
        cin >> dem;
        cout<<"#"<<test_case<<" ";
        for (int k = 0; k < dem; k++)
        {
            int N;
            cin >> N;
            int arr[9] = {0};
            int x = 0;
            while (N != 0)
            {
                arr[x] = N % 10;
                N = N / 10;
                x++;
            }

            int pass[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

            int answer = 1;
            
            bool out = false;

            for (int i = 0; i < x; i++)
            {
                for (int j = i + 1; j < x; j++)
                {
                    if (arr[i] == arr[j])
                    {
                        answer = 0;
                        out = true;
                        break;
                    }
                }
                if (out)
                    break;
            }

            int index;
            int dx, dy, dx1, dy1;

            for (int i = 0; i < 3; i++)
            {
                bool outloop = false;
                for (int j = 0; j < 3; j++)
                {
                    if (arr[x - 1] == pass[i][j])
                    {
                        dx = i;
                        dy = j;
                        pass[i][j] = 0;
                        outloop = true;
                        break;
                    }
                }
                if (outloop)
                    break;
            }
            if (out != 1)
            {
                for (int i = x - 2; i >= 0; i--)
                {
                    index = arr[i];

                    for (int i = 0; i < 3; i++)
                    {
                        bool outloop = false;
                        for (int j = 0; j < 3; j++)
                        {
                            if (index == pass[i][j])
                            {
                                dx1 = i;
                                dy1 = j;
                                pass[i][j] = 0;
                                outloop = true;
                                break;
                            }
                        }
                        if (outloop)
                            break;
                    }
                    if ((dx + dx1) % 2 == 0 && (dy + dy1) % 2 == 0)
                    {
                        if (pass[(dx + dx1) / 2][(dy + dy1) / 2] != 0)
                        {
                            answer = 0;
                            break;
                        }
                    }
                    dx = dx1;
                    dy = dy1;
                }
            }

            cout << answer;
        }
        cout<<endl;
    }

}