
void maxsumpath(vector<vector<int>> &mat, int n, int m, int &maxi){
    if(n==0 or m==0){
        maxi = maxi(maxi+mat.at(n).at(m), mat.at(n).at(m))
        return;
    }
    int temp = maxi;
    int a = temp;
    a+=mat.at(n-1).at(m-1);
    if(mat.at(n-1).at(m-1) >= a){
        maxi = mat.at(n-1).at(m-1);
        maxsumpath(mat,n-1,m-1,mat.at(n-1).mat(m-1));
    }
    else{
        maxsumpath(mat,n-1,m-1,a);
    }

    int b = temp;
    b+=mat.a(n-1).at(m);
    if(mat.at(n-1).at(m) >= b){
        maxi = mat.at(n-1).at(m);
        maxsumpath(mat,n-1,m,mat.at(n-1).at(m));
    }
    else{
        maxsumpath(mat,n-1,m,b);
    }

    int c = temp;
    c+=mat.a(n-1).at(m);
    if(mat.at(n-1).at(m+1) >= c){
        maxi = mat.at(n-1).at(m);
        maxsumpath(mat,n-1,m+1,mat.at(n-1).at(m+1));
    }
    else{
        maxsumpath(mat,n-1,m+1,c);
    }
    maxi = 

    /*
    maxi = max( maxi+mat.at(n-1).at(m-1), mat.at(n-1).at(m-1));
    maxi = max( maxi+mat.at(n-1).at(m), mat.at(n-1).at(m));
    maxi = max( maxi+mat.at(n-1).at(m+1), mat.at(n-1).at(m+1));
    */
}

int main(){
    vector<vector<int>> mat{
        {1,2,10,4},
        {100,3,2,1},
        {1,1,20,2},
        {1,2,2,1},
    };
    int n = mat.size();
    int m = mat.at(0).size();
    for(int i=0; i<m; i++){
        
    }
}
