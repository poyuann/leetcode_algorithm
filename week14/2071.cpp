class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
      
        int taskCount = tasks.size(), workerCount = workers.size();
        int left = 0, right = min(workerCount, taskCount);
      
        auto canAssignTasks = [&](int x) {
            int remainingPills = pills;
            deque<int> availableTasks;
            int taskIndex = 0;
            for (int workerIndex = workerCount - x; workerIndex < workerCount; ++workerIndex) {
                while (taskIndex < x && tasks[taskIndex] <= workers[workerIndex] + strength) {
                    availableTasks.push_back(tasks[taskIndex++]);
                }
                if (availableTasks.empty()) {
                    return false;
                }
                if (availableTasks.front() <= workers[workerIndex]) {
                    availableTasks.pop_front();
                } 
                else if (remainingPills > 0) {
                    --remainingPills;
                    availableTasks.pop_back();
                } 
                else {
                    return false;
                }
            }
            return true;
        };

        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (canAssignTasks(mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};
