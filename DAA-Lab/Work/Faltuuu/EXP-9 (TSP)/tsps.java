import java.util.*;

public class tsps {
    static int N;
    static int[][] adj;
    static int final_path[] = new int[N + 1];
    static boolean visited[] = new boolean[N];
    static int min_cost = Integer.MAX_VALUE;

    static void copyToFinal(int path[]) {
        for (int i = 0; i < N; i++)
            final_path[i] = path[i];
        final_path[N] = path[0];
    }

    static int firstMin(int adj[][], int i) {
        int min = Integer.MAX_VALUE;
        for (int k = 0; k < N; k++)
            if (adj[i][k] < min && i != k)
                min = adj[i][k];
        return min;
    }

    static int secondMin(int adj[][], int i) {
        int first = Integer.MAX_VALUE, second = Integer.MAX_VALUE;
        for (int j = 0; j < N; j++) {
            if (i == j)
                continue;
            if (adj[i][j] <= first) {
                second = first;
                first = adj[i][j];
            } else if (adj[i][j] <= second &&
                    adj[i][j] != first)
                second = adj[i][j];
        }
        return second;
    }

    static void TSPRec(int adj[][], int bound, int weight, int level, int path[]) {
        if (level == N) {
            if (adj[path[level - 1]][path[0]] != 0) {
                int curr_res = weight + adj[path[level - 1]][path[0]];
                if (curr_res < min_cost) {
                    copyToFinal(path);
                    min_cost = curr_res;
                }
            }
            return;
        }
        for (int i = 0; i < N; i++) {
            if (adj[path[level - 1]][i] != 0 && visited[i] == false) {
                int temp = bound;
                weight += adj[path[level - 1]][i];
                if (level == 1) {
                    bound -= ((firstMin(adj, path[level - 1]) + firstMin(adj, i)) / 2);
                } else {
                    bound -= ((secondMin(adj, path[level - 1]) + firstMin(adj, i)) / 2);
                }
                if (bound + weight < min_cost) {
                    path[level] = i;
                    visited[i] = true;
                    TSPRec(adj, bound, weight, level + 1, path);
                }
                weight -= adj[path[level - 1]][i];
                bound = temp;
                Arrays.fill(visited, false);
                for (int j = 0; j <= level - 1; j++) {
                    visited[path[j]] = true;
                }
            }
        }
    }

    static void TSP(int adj[][]) {
        int path[] = new int[N + 1];
        int bound = 0;
        Arrays.fill(path, -1);
        Arrays.fill(visited, false);
        for (int i = 0; i < N; i++)
            bound += (firstMin(adj, i) + secondMin(adj, i));
        bound = (bound == 1) ? bound / 2 + 1 : bound / 2;
        visited[0] = true;
        path[0] = 0;
        TSPRec(adj, bound, 0, 1, path);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of cities: ");
        N = sc.nextInt();
        adj = new int[N][N];
        final_path = new int[N + 1];
        visited = new boolean[N];
        min_cost = Integer.MAX_VALUE;
        System.out.println("Enter the adjacency matrix:");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                adj[i][j] = sc.nextInt();
            }
        }
        TSP(adj);
        System.out.println("\nMinimum cost: " + min_cost);
        System.out.println("Final Path:");
        for (int i = 0; i <= N; i++) {
            System.out.print(final_path[i] + " ");
        }
    }
}