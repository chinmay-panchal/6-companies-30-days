#include<bits./stdc++.h>
using namespace std;

int main(){

    string secret = "1807";   // secret
    string guess = "7810";   // guess

        map<int,int> mi;
        map<int,int> mj;

        int bulls = 0; 
        int cows = 0;

        int i=0, j=0; 
        while(i<secret.length() && j<guess.length()){
            if(secret[i]==guess[i]){
                mi[i]=1; mj[j]=1;
                bulls++;
            }
            i++; j++;
        }

        for(int i=0; i<secret.length(); i++){
            for(int j=0; j<guess.length(); j++){
                if(mi[i]!=1 && mj[j]!=1){
                    if(secret[i]==guess[j]){
                        // cout<<i<<" "<<j<<endl;
                        mi[i]=1; mj[j]=1;
                        cows++;
                    }
                }
            }
        }

        string ans = to_string(bulls)+"A"+to_string(cows)+"B";
        cout<<ans;
    return 0;
}