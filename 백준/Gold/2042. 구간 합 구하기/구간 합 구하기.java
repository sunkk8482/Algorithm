import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N;

    static int M, K;

    static long[] arr, tree;

    static int S;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        S = 1;
        while (S < N) {
            S *= 2;
        }

        tree = new long[S * 2];

        arr = new long[N + 1];
        for (int i = 1; i <= N; i++) {
            arr[i] = Long.parseLong(br.readLine());
        }

        init();

        for (int i = 0; i < M + K; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            long c = Long.parseLong(st.nextToken());

            if (a == 2) {
                long ret = queryBU(b,(int)c);
                System.out.println(ret);
            } else if (a == 1) {
                updateBU(b,c);
            }
        }


    }

    static void init() { //bottom up
        // leaf는 data로
        for (int i = 0; i < N; i++) {
            tree[S + i] = arr[i+1];
        }
        // 내부노드는 자식의 합
        for (int i = S - 1; i > 0; i--) {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }

    static void updateBU(int target, long value) {
        int node = S + target - 1;
        tree[node] = value;
        node /= 2;
        while (node > 0) {
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
            node /= 2;
        }
    }

    static long queryBU(int queryLeft, int queryRight) {
        long sum = 0;
        int left = S + queryLeft - 1;
        int right = S + queryRight - 1;

        while (left <= right) {
            if (left % 2 == 1) {
                sum += tree[left++];
            }
            if (right % 2 == 0) {
                sum += tree[right--];
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }
}
