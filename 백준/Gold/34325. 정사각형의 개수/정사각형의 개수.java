import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long n = Integer.parseInt(st.nextToken());
        long k = Integer.parseInt(st.nextToken());
        long MOD = 1000000007;

        long[] v = new long[(int) n + 1];

        for (int i = 1; i <= n; i++) {
            long size = n - i + 1;
            v[i] += (size * size) % MOD;
        }

        for (int i = 1; i <= n; i++) {
            long temp = (n - i) / 2;
            v[i] = (v[i] + (n - temp - i) * temp * 4 % MOD) % MOD;
        }

        long multiplier = k;
        long res = 0;
        for (int i = 1; i <= n; i++) {
            res = (res + v[i] * multiplier % MOD) % MOD;
            multiplier = multiplier * k % MOD;
        }

        System.out.println(res);
        br.close();
    }
}