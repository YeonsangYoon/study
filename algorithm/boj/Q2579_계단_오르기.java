package algorithm.boj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

/*
 * dp[i] : i번째 계단까지 오르는 데의 획득한 최고 점수
 * stair[i] : i번째 계단의 점수
 * 
 * 3칸 연속 계단을 밟지 못하면 3칸 위로 이동하는 방법을 생각해보자
 * - 3칸 아래에서 두칸 -> 한칸씩 이동
 * - 2칸 아래에서 두칸 이동
 * 
 * => dp[i] = max(dp[i-3] + stair[i-1], dp[i-2]) + stair[i]
 */

public class Q2579_계단_오르기 {
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

    static int solve(int n, int[] stair){
        int[] dp = new int[301];
        dp[1] = stair[1];
        dp[2] = stair[1] + stair[2];

        for(int i=3;i<=n;i++){
            dp[i] = Math.max(dp[i-2], dp[i-3]+stair[i-1]) + stair[i];
        }
        return dp[n];
    }

    public static void main(String[] args) throws IOException{
        int n = Integer.parseInt(in.readLine());
        int[] stair = new int[301];
        for(int i=1;i<=n;i++)
            stair[i] = Integer.parseInt(in.readLine());
        
        out.write(String.valueOf(solve(n, stair)));
        out.flush();
        out.close();
    }
}
