import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer> v = new ArrayList<>();

        for (int i = 0; i < n; i++)
            v.add(Integer.parseInt(br.readLine()));

        Collections.sort(v);

        StringBuilder sb = new StringBuilder();

        for (int a : v)
            sb.append(a + "\n");

        System.out.println(sb);
        br.close();
    }
}