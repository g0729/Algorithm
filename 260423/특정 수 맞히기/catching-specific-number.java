import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());

            if (n < 25)
                System.out.println("Higher");
            else if (n > 25)
                System.out.println("Lower");
            else if (n == 25) {
                System.out.println("Good");
                break;
            }
        }
        br.close();
    }
}