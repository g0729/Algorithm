import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] v = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++)
            v[i] = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(br.readLine());

        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += v[i] == a ? 1 : 0;

        System.out.println(sum);
        br.close();
    }
}