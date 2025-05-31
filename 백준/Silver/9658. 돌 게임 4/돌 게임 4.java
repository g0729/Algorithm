import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        boolean[] v = new boolean[1001];
        v[1] = false;
        v[2] = true;
        v[3] = false;
        v[4] = true;

        for (int i = 5; i <= n; i++) {
            if (!v[i - 1] || !v[i - 3] || !v[i - 4])
                v[i] = true;
            else
                v[i] = false;
        }

        if (v[n])
            System.out.println("SK");
        else
            System.out.println("CY");
        br.close();
    }
}