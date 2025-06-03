import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long c = Integer.parseInt(st.nextToken()), d = Integer.parseInt(st.nextToken());

        if ((n == 1 || m == 1) && (a != c || b != d))
            System.out.println("NO");
        else if ((a + b) % 2 == (c + d) % 2)
            System.out.println("YES");
        else
            System.out.println("NO");
        br.close();
    }
}