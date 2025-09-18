import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[][] A = new int[5][5];
        int[][] B = new int[5][5];

        StringTokenizer st;
        for (int i = 0; i < 5; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 5; j++) {
                A[i][j] = Integer.parseInt(st.nextToken());
            }

        }

        for (int i = 0; i < 5; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 5; j++) {
                B[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        String[] name = { "Inseo", "Junsuk", "Jungwoo", "Jinwoo", "Youngki" };

        int[] sum = new int[5];

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    sum[i] += A[i][k] * B[k][j];
                }
            }
        }

        int MIN = (int) 1e9;
        int idx = -1;

        for (int i = 0; i < 5; i++) {
            if (sum[i] < MIN) {
                MIN = sum[i];
                idx = i;
            } else if (sum[i] == MIN) {
                if (name[idx].compareTo(name[i]) < 0) {
                    idx = i;
                }
            }
        }

        System.out.println(name[idx]);
    }

}