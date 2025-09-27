import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();

        int[] acc_sum = new int[n + 1];

        for (int i = 1; i <= s.length(); i++) {
            acc_sum[i] = acc_sum[i - 1] + (s.charAt(i - 1) == 'B' ? 1 : 0);
        }
        int res = (int) 1e9;
        for (int i = 0; i <= n; i++) {
            int temp = (i - acc_sum[i]) + (acc_sum[n] - acc_sum[i]);
            res = Math.min(res, temp);
        }

        System.out.println(res);
        br.close();
    }
}