import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int sum = 0;
        for (int i = 1; i <= 100; i++) {
            sum += i;

            if (sum >= n) {
                System.out.println(i);
                break;
            }
        }
        br.close();
    }
}