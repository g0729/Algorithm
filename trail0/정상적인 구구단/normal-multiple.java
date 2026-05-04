import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());

        for(int i = 1 ; i <= n ; i++ ){
            for(int j = 1 ; j <= n ; j++){
                System.out.printf("%d * %d = %d",i,j,i*j);

                if(j != n)
                    System.out.printf(", ");
            }
            System.out.println();
        }
        br.close();
    }
}