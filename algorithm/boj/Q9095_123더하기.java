package algorithm.boj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

/*
 * dp[i] : 합을 i로 만들기 위한 경우의 수
 * 
 * 바로 점화식을 세워보면 다음과 같다.
 * dp[i] = dp[i-3] + dp[i-2] + dp[i-1] (i > 3)
 */

public class Q9095_123더하기{
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
    
    public static int solve(int n){
        int[] dp = new int[12];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for(int i=3;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];

        return dp[n];
    }

    public static void main(String[] args) throws IOException{
        int tc = Integer.parseInt(in.readLine());

        for(int i=0;i<tc;i++){
            int n = Integer.parseInt(in.readLine());
            out.write(String.valueOf(solve(n)) + '\n');
        }
        out.flush();
        out.close();
    }
}