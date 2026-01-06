import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        int[] v = new int[n + 1];
        int[] acc = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            v[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 1; i <= n; i++) {
            acc[i] = acc[i - 1] + v[i];
        }
        int sum = acc[x];
        int maxVal = sum;
        for (int i = x + 1; i <= n; i++) {
            sum += (v[i] - v[i - x]);
            maxVal = Math.max(sum, maxVal);
        }
        if (maxVal == 0) {
            System.out.println("SAD");
            return;
        }
        sum = acc[x];
        int res = (maxVal == sum ? 1 : 0);

        for (int i = x + 1; i <= n; i++) {
            sum += (v[i] - v[i - x]);
            res += (sum == maxVal ? 1 : 0);
        }

        System.out.println(maxVal);
        System.out.println(res);
    }
}