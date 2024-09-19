#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // For setting precision in output

using namespace std;

struct Process {
    int at, bt, ct, ta, wt, btt;
    string pro_id;
};

bool compareArrival(const Process &a, const Process &b) {
    return a.at < b.at;
}

bool compareBurst(const Process &a, const Process &b) {
    return a.bt < b.bt;
}

int main() {
    vector<Process> pro;
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the Process ID, Arrival Time, and Burst Time:" << endl;
    for (int i = 0; i < n; i++) {
        Process p;
        cin >> p.pro_id >> p.at >> p.bt;
        p.btt = p.bt;
        pro.push_back(p);
    }

    // Sort by arrival time
    sort(pro.begin(), pro.end(), compareArrival);

    int currentTime = 0, completedProcesses = 0;
    float totalTAT = 0, totalWT = 0;

    while (completedProcesses < n) {
        // Select processes that have arrived by currentTime
        vector<Process*> readyQueue;
        for (auto &p : pro) {
            if (p.at <= currentTime && p.bt > 0) {
                readyQueue.push_back(&p);
            }
        }

        if (!readyQueue.empty()) {
            // Sort readyQueue by burst time
            sort(readyQueue.begin(), readyQueue.end(), [](Process* a, Process* b) {
                return a->bt < b->bt;
            });

            Process* currentProcess = readyQueue.front();
            currentProcess->bt--;
            currentTime++;

            if (currentProcess->bt == 0) {
                currentProcess->ct = currentTime;
                currentProcess->ta = currentProcess->ct - currentProcess->at;
                currentProcess->wt = currentProcess->ta - currentProcess->btt;
                totalTAT += currentProcess->ta;
                totalWT += currentProcess->wt;
                completedProcesses++;
            }
        } else {
            // Move time forward if no process is ready
            currentTime++;
        }
    }

    cout << "ProID\tAtime\tBtime\tCtime\tTtime\tWtime\n";
    for (const auto &p : pro) {
        cout << p.pro_id << "\t" << p.at << "\t" << p.btt << "\t" 
             << p.ct << "\t" << p.ta << "\t" << p.wt << endl;
    }

    // Calculate and print average Turnaround Time (TAT) and Waiting Time (WT)
    float avgTAT = totalTAT / n;
    float avgWT = totalWT / n;

    cout << fixed << setprecision(2);
    cout << "Average Turnaround Time (TAT): " << avgTAT << endl;
    cout << "Average Waiting Time (WT): " << avgWT << endl;

    return 0;
}