import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] v = new int[n];

        for (int i = 0; i < n; i++) {
            v[i] = Integer.parseInt(st.nextToken());
        }

        int[] dp = new int[n];

        dp[0] = v[0];

        for (int i = 1; i < n; i++) {
            dp[i] = v[i];
            for (int j = 0; j < i; j++) {
                if (v[j] <= v[i])
                    continue;

                dp[i] = Math.max(dp[i], dp[j] + v[i]);
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++)
            res = Math.max(res, dp[i]);

        System.out.println(res);
        br.close();
    }
}