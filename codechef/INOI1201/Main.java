package INOI1201;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

class Reader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    Reader() {
        reader = new BufferedReader(new InputStreamReader(System.in));
    }

    public int getInt() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException();
            }
        }
        return Integer.parseInt(tokenizer.nextToken());
    }
}

class ActivityTime {
    int cobolTime;
    int poleVaultTime;
    int doughnutsTime;

    public int getCobolTime() {
        return cobolTime;
    }

    public int getPoleVaultTime() {
        return poleVaultTime;
    }

    public int getDoughnutsTime() {
        return doughnutsTime;
    }

    public ActivityTime(int cobolTime, int poleVaultTime, int doughnutsTime) {
        this.cobolTime = cobolTime;
        this.poleVaultTime = poleVaultTime;
        this.doughnutsTime = doughnutsTime;
    }
}

public class Main {
    public static void main(String args[]) {
        List<ActivityTime> activityTimes = new ArrayList<>();
        Reader reader = new Reader();
        int N = reader.getInt();
        for (int i = 0; i < N; i++) {
            int c = reader.getInt();
            int p = reader.getInt();
            int d = reader.getInt();
            activityTimes.add(new ActivityTime(c, p, d));
        }
        System.out.println(minTime(activityTimes));
    }

    private static int minTime(List<ActivityTime> activityTimes) {
        Collections.sort(activityTimes, (l, r) -> (r.poleVaultTime + r.doughnutsTime) - (l.poleVaultTime + l.doughnutsTime));
        int max = -1;
        int startTime = 0;
        for (int i = 0; i < activityTimes.size(); i++) {
            int currentEndTime = startTime + activityTimes.get(i).getCobolTime() + activityTimes.get(i).getPoleVaultTime() + activityTimes.get(i).getDoughnutsTime();
            max = Math.max(max, currentEndTime);
            startTime = startTime + activityTimes.get(i).getCobolTime();
        }
        return max;
    }
}