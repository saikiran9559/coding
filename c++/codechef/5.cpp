#include<bits/stdc++.h>
using namespace std;
int zeroes(int a, int b, int c){
    int count=0;
    if(a==0) count++;
    if(b==0) count++;
    if(c==0) count++;
    return count;
}

int out(int a, int b, int c){
    if(a==0){
        if(b==c){
            return 1;
        }
        return 0;
    }
    else if(b==0){
        if(c==a) return 1;
        return 0;
    }
    if(a==b) return 1;
    return 0;
}
int getcount(char a,char b, char c){
    int count=0;
    if(a=='0') count++;
    if(b=='0') count++;
    if(c=='0') count++;
    if(count==2) return -1;
    if(count==3 or count==1) return 1;
    if(count==0) return 4; 
}


int main(){
    int t;
    cin>>t;

    while(t--){
        int p,q,r;
        cin>>p>>q>>r;
        int c = zeroes(p,q,r);
        if(c==1)
            cout<<out(p,q,r)<<endl;
        else if(c==2)
            cout<<0<<endl;
        else if(c==3) cout<<1<<endl;
        else{

            string s1 = bitset<20>(p).to_string();
            string s2 = bitset<20>(q).to_string();
            string s3 = bitset<20>(r).to_string();
            int count=1;
            int flag=1;
            for(int i=0;i<20;i++){
                int a = getcount(s1.at(i), s2.at(i), s3.at(i));
                if(a==-1){
                    flag=0;
                    break;
                }
                count*=a;
            }
            if(flag){
                cout<<count<<endl;
            }
            else{
                cout<<0<<endl;
            }

        }
    }
}
