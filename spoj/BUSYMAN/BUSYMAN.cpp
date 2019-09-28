#include<stdio.h>
#include<algorithm>
#define MAX_N 100009

using namespace std;

struct Activity {
	int start;
	int finish;
};

bool compareActivityInterval(Activity firstActivity, Activity secondActivity) {
	return firstActivity.finish < secondActivity.finish;
}

int maxNumberOfActivitiesThatCanBePerformed(Activity * activities, int numberOfActivities) {
	sort(activities, activities + numberOfActivities, compareActivityInterval);
	int maxActivities = 1;
	int lastIncludedInSet = 0;
	for (int i = 1; i < numberOfActivities; i++) {
		if (activities[i].start >= activities[lastIncludedInSet].finish) {
			maxActivities++;
			lastIncludedInSet = i;
		}
	}
	return maxActivities;
}

int main() {
	int t, N;
	Activity activities[MAX_N];
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &activities[i].start, &activities[i].finish);
		}
		printf("%d\n", maxNumberOfActivitiesThatCanBePerformed(activities, N));
	}
}