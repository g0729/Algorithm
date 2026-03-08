import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    // 6행 7열 게임판 (인덱스 편의를 위해 크기를 +1씩 여유있게 잡음)
    static int[][] board = new int[7][8];
    // 각 열(1~7)에 쌓인 김밥의 개수를 추적
    static int[] height = new int[8];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        boolean gameEnded = false;
        String winner = "ss";
        int winRound = -1;

        // 총 21번의 턴 진행
        for (int i = 1; i <= 21; i++) {
            String line = br.readLine();
            if (line == null) break;
            
            StringTokenizer st = new StringTokenizer(line);
            int s = Integer.parseInt(st.nextToken()); // 상근이의 열
            int j = Integer.parseInt(st.nextToken()); // 정인이의 열

            // 1. 상근이 턴 (참치 김밥: 1)
            int r1 = ++height[s];
            board[r1][s] = 1;
            // 아직 게임이 안 끝났고, 상근이가 이번에 승리 조건을 만족했다면
            if (!gameEnded && checkWin(r1, s, 1)) {
                gameEnded = true;
                winner = "sk";
                winRound = i;
            }

            // 2. 정인이 턴 (김치 김밥: 2)
            int r2 = ++height[j];
            board[r2][j] = 2;
            // 아직 게임이 안 끝났고, 정인이가 이번에 승리 조건을 만족했다면
            if (!gameEnded && checkWin(r2, j, 2)) {
                gameEnded = true;
                winner = "ji";
                winRound = i;
            }
        }

        // 결과 출력
        if (gameEnded) {
            System.out.println(winner + " " + winRound);
        } else {
            System.out.println("ss"); // 무승부
        }
    }

    // (r, c) 위치에 놓인 김밥을 기준으로 4개 연속 여부 확인
    static boolean checkWin(int r, int c, int player) {
        // 검사할 4개의 축 (가로, 세로, 대각선 /, 대각선 \)
        int[][] dirs = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}};
        
        for (int[] dir : dirs) {
            int count = 1; // 방금 놓은 돌 1개 포함
            
            // 정방향 탐색
            int nr = r + dir[0];
            int nc = c + dir[1];
            while (nr >= 1 && nr <= 6 && nc >= 1 && nc <= 7 && board[nr][nc] == player) {
                count++;
                nr += dir[0];
                nc += dir[1];
            }
            
            // 역방향 탐색
            nr = r - dir[0];
            nc = c - dir[1];
            while (nr >= 1 && nr <= 6 && nc >= 1 && nc <= 7 && board[nr][nc] == player) {
                count++;
                nr -= dir[0];
                nc -= dir[1];
            }
            
            // 4개 이상 연속되었다면 승리
            if (count >= 4) return true;
        }
        return false;
    }
}