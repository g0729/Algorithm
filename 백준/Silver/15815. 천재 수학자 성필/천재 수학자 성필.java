import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        Stack<Integer> st = new Stack<>();

        for (char c : s.toCharArray()) {
            if (c >= '0' && c <= '9')
                st.add(c - '0');
            else {
                int a = st.pop();
                int b = st.pop();

                if (c == '+')
                    st.add(b + a);
                else if (c == '-')
                    st.add(b - a);
                else if (c == '*')
                    st.add(b * a);
                else if (c == '/')
                    st.add(b / a);

            }
        }

        System.out.println(st.pop());
        br.close();
    }
}