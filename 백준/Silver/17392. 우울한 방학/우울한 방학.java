import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static long f(long k) {
        if (k <= 0) {
            return 0;
        }
        return k * (k + 1) * (2 * k + 1) / 6;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] v = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            v[i] = Integer.parseInt(st.nextToken());
        }
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += v[i] + 1;
        }
        int left = m - sum;
        int slot = n + 1;
        if (left <= 0) {
            System.out.println(0);
        } else {
            long res = (left % slot) * f(left / slot + 1)
                    + (slot - left % slot) * f(left / slot);
            System.out.println(res);
        }
        br.close();
    }
}