import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String[] v = { "apple", "banana", "grape", "blueberry", "orange" };
        int res = 0;

        char c = st.nextToken().charAt(0);
        for (String s : v) {
            if (s.charAt(2) == c || s.charAt(3) == c) {
                System.out.println(s);
                res++;
            }
        }

        System.out.println(res);
        br.close();
    }
}