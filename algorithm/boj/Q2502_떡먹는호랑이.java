package algorithm.boj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/*
 * 초기값이 정해져 있지 않는 피보나치
 * - 1 : a
 * - 2 : b 
 * 라고 가정했을 때 
 * 
 * d번째 날의 개수를 a, b로 이루어진 방정식을 만들어야함
 * 방정식을 만들기 위해 각 날짜 a, b의 계수를 int 배열에 저장하고 피보나치를 수행
 * 
 * D번째 날의 a와 b의 계수를 구한 뒤 역으로 a, b를 추적한다.
 * a에 1, 2, 3 ... 을 대입해보면서 가능한 (a, b)쌍을 구한다.
 */

public class Q2502_떡먹는호랑이 {
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] solve(int d, int k){
        int[] retval = new int[2];

        int[] yesterday = {1, 0};
        int[] today = {0, 1};

        for(int i=3;i<=d;i++){
            int[] tomorrow = {yesterday[0] + today[0], yesterday[1] + today[1]};
            yesterday[0] = today[0];
            yesterday[1] = today[1];
            today[0] = tomorrow[0];
            today[1] = tomorrow[1];
        }

        for(int a = 1;;a++){
            if((k - a * today[0]) % today[1] == 0){
                retval[0] = a;
                retval[1] = (k - a * today[0]) / today[1];
                break;
            }
        }

        return retval;
    }

    static boolean isCorrect(int[] ans, int d, int k){
        for(int i=3;i<=d;i++){
            int tmp = ans[0] + ans[1];
            ans[0] = ans[1];
            ans[1] = tmp;
        }
        return k == ans[1];
    }

    public static void main(String[] args) throws IOException{
        StringTokenizer st = new StringTokenizer(in.readLine());
        int d = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[] result = solve(d, k);

        out.write(String.valueOf(result[0]) + '\n' + String.valueOf(result[1]));
        // out.write('\n' + String.valueOf(isCorrect(result, d, k)));
        out.flush();
        out.close();
    }
}
