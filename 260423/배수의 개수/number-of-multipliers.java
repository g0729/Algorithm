import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int res3 = 0, res5 = 0;
        for (int i = 0; i < 10; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());

            res3 += n % 3 == 0 ? 1 : 0;
            res5 += n % 5 == 0 ? 1 : 0;

        }

        System.out.println(res3 + " " + res5);
        br.close();
    }
}