#include <bits/stdc++.h>
using namespace std;


void solve(long long H, long long W, std::vector<std::vector<long long>> A, std::vector<std::vector<long long>> B){
    vector<vector<int>> C(H);

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            C[i].emplace_back(abs(A[i][j]-B[i][j]));
        }
    }


    int max = 80 *80 * 2;
    bool dp[H+1][W+1][max];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            for(int k=0;k<max;k++){
                dp[i][j][k] = false;
            }
        }
    }
   
    dp[0][0][C[0][0]] = true;
    // cout << dp[0][0][C[0][0]]<< endl;

    // if(dp[H][W][0]){
    //     cout << "a" << endl;
    // }


    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            for(int k=0;k<max;k++){
                if(dp[i][j][k]){
                    if(i < H-1){
                        dp[i+1][j][k+C[i+1][j]] = true;
                        dp[i+1][j][abs(k-C[i+1][j])] = true;
                    }
                    if(j < W-1){
                        dp[i][j+1][k+C[i][j+1]] = true;
                        dp[i][j+1][abs(k-C[i][j+1])] = true;
                    }
                }
            }
        }
    }

    for(int k=0;k<=max;k++){
        if(dp[H-1][W-1][k]){
            cout << k << endl;
            return;
        }
    }
}

// Generated by 1.1.6 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main(){
    long long H;
    cin >> H;
    long long W;
    cin >> W;
    std::vector<std::vector<long long>> A(H, std::vector<long long>(W));
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            int a;
            cin >> a;
            A[i][j] = a;
        }
    }
    std::vector<std::vector<long long>> B(H, std::vector<long long>(W));
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            int b;
            cin >> b;
            B[i][j] = b;
        }
    }
    solve(H, W, std::move(A), std::move(B));
    return 0;
}
