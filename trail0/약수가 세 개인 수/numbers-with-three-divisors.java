import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {

    public static boolean isPrime(int n){
        if(n<=1) return false;
    
        for(int i =2 ; i * i <= n; i++){
            if(n%i==0) return false;
        }

        return true;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());

        int idx = (int)Math.sqrt(start);

        if(idx * idx < start) idx++;
        int res=0;

        for(; idx*idx <= end ; idx++){
            if(isPrime(idx)) res++;
        }

        System.out.println(res);
        br.close();
    }
}