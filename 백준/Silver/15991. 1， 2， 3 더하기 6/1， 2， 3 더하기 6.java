import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        int[] v = new int[100001];
        int MOD = 1000000009;
        v[0] = 1;
        v[1] = 1;
        v[2] = 2;
        v[3] = 2;
        for (int i = 4; i < 100001; i++) {
            for (int j = i - 2; j >= (i - 6) && j >= 0; j -= 2) {
                v[i] = (v[i] + v[j]) % MOD;
            }
        }
        while (t > 0) {
            int n = Integer.parseInt(br.readLine());
            System.out.println(v[n]);
            t--;
        }
        br.close();
    }
}