package algorithm.boj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/*
 * weight[i] : i번째 물건의 무게 
 * value[i] : i번째 물건의 가치
 * dp[i][j] : i번째 물건까지 선택했고, 현재 배낭의 무게가 j일때의 최대 가치
 * 
 * 점화식
 * - i번째 물건을 선택할 때 배낭의 무게(j)가 i번째 물건의 무게보다 크거나 같을 경우
 * dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i])
 * 
 * - i번째 물건을 선택할 때 배낭의 무게(j)가 i번째 물건의 무게보다 작을 경우
 * dp[i][j] = dp[i-1][j] 
 */

public class Q12865_평범한배낭 {
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

    static int solve(int n, int k, int[] weight, int[] value){
        int[][] dp = new int[n+1][k+1];

        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(j-weight[i]>=0)
                    dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        int ret = 0;
        for(int i=0;i<=k;i++)
            ret = Math.max(ret, dp[n][i]);
        return ret;
    }

    public static void main(String[] args) throws IOException{
        StringTokenizer st = new StringTokenizer(in.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] weight = new int[n+1];
        int[] value = new int[n+1];

        for(int i=1;i<=n;i++){
            st = new StringTokenizer(in.readLine());

            weight[i] = Integer.parseInt(st.nextToken());
            value[i] = Integer.parseInt(st.nextToken());
        }

        int ans = solve(n, k, weight, value);

        out.write(String.valueOf(ans));
        out.flush();
        out.close();
    }
}
