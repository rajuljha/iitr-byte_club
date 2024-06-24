// #include<iostream>
// #include<queue>
// using namespace std;

// struct Process {
//     int id;
//     int burst_time;
// };

// void findCompletionTime(queue<Process> q, int n, int quantum, int ct[]) {
//     int rem_bt[n];
//     for (int i = 0; i < n; i++)
//         rem_bt[i] = q.front().burst_time;
//     int t = 0;
//     while (1) {
//         bool done = true;
//         for (int i = 0; i < n; i++) {
//             if (rem_bt[i] > 0) {
//                 done = false;
//                 if (rem_bt[i] > quantum) {
//                     t += quantum;
//                     rem_bt[i] -= quantum;
//                 }
//                 else {
//                     t = t + rem_bt[i];
//                     ct[i] = t;
//                     rem_bt[i] = 0;
//                 }
//             }
//         }
//         if (done == true)
//             break;
//     }
// }

// int main() {
//     queue<Process> q;
//     int quantum;
//     cout << "Enter time quantum: ";
//     cin >> quantum;
//     int exec_time1, exec_time2, exec_time3;
//     cout << "Enter execution times for three programs: ";
//     cin >> exec_time1 >> exec_time2 >> exec_time3;
//     Process p1 = {1, exec_time1};
//     Process p2 = {2, exec_time2};
//     Process p3 = {3, exec_time3};
//     q.push(p1);
//     q.push(p2);
//     q.push(p3);
//     int ct[3];
//     findCompletionTime(q, q.size(), quantum, ct);
//     cout << "Completion times are: " << ct[0] << ", " << ct[1] << ", " << ct[2];
//     return 0;
// }

#include<iostream>
#include<queue>
using namespace std;

struct Process {
    int id;
    int burst_time;
};

void findCompletionTime(queue<Process>& q, int n, int quantum, int ct[]) {
    int time = 0;
    while (!q.empty()) {
        Process proc = q.front();
        q.pop();
        if (proc.burst_time > quantum) {
            time += quantum;
            proc.burst_time -= quantum;
            q.push(proc);
        } else {
            time += proc.burst_time;
            ct[proc.id - 1] = time;
        }
    }
}

int main() {
    queue<Process> q;
    int quantum;
    cout << "Enter time quantum: ";
    cin >> quantum;
    int exec_time1, exec_time2, exec_time3;
    cout << "Enter execution times for three programs: ";
    cin >> exec_time1 >> exec_time2 >> exec_time3;
    Process p1 = {1, exec_time1};
    Process p2 = {2, exec_time2};
    Process p3 = {3, exec_time3};
    q.push(p1);
    q.push(p2);
    q.push(p3);
    int ct[3] = {0};
    findCompletionTime(q, q.size(), quantum, ct);
    cout << "Completion times are: " << ct[0] << ", " << ct[2] << ", " << ct[1];
    return 0;
}