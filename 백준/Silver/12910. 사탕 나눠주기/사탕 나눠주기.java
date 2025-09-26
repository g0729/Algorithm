import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int[] v = new int[51];
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(st.nextToken());

            v[a] += 1;
        }

        int res = 0;

        for (int i = 1; i <= 50; i++) {
            int temp = 1;
            for (int j = 1; j <= i; j++) {
                temp *= v[j];
            }

            res += temp;
        }

        System.out.println(res);

        br.close();
    }
}