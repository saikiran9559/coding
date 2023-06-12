import java.util.Scanner;

import javax.rmi.ssl.SslRMIClientSocketFactory;

import java.util.Arrays;

public class Fibi {
    static int recursive(int n){
        if(n<=1) return n;
        return recursive(n-1) + recursive(n-2);
    }

    static int memorization(int n, int[] dp ){
        if(n<=1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = memorization(n-1, dp) + memorization(n-2, dp);
        
    }

    static int tabulation(int n){
        int dp[] = new int[n+1];
        dp[0] = 0; 
        dp[1] = 1;
        for(int i=2; i<=n;  i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    static int space_complexity(int n){
        int prev2 = 0; 
        int prev = 1;
        for(int i=2; i<=n; i++){
            int cur = prev + prev2;
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();

        int dp [] = new int[n+1];
        Arrays.fill(dp,-1);

        System.out.println(recursive(n));
        System.out.println(memorization(n, dp));
        System.out.println(tabulation(n));
        System.out.println(space_complexity(n));
    }
}
