#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

class Worker
{
public:
    Worker(int id) : id(id), release_time(0) {}

    int id;
    ll release_time;

    friend bool operator<(const Worker& a, const Worker &b)
    {
        if (a.release_time == b.release_time)
            return a.id > b.id;
        return a.release_time > b.release_time;
    }

    // bool operator>(Worker &other)
    // {
    //     if (this->release_time == other.release_time)
    //         return this->id < other.id;
    //     return this->release_time < other.release_time;
    // }
};

class JobQueue
{
private:
    int num_workers_;
    vector<int> jobs_;

    vector<int> assigned_workers_;
    vector<long long> start_times_;

    void WriteResponse() const
    {
        for (int i = 0; i < jobs_.size(); ++i)
        {
            cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
        }
    }

    void ReadData()
    {
        int m;
        cin >> num_workers_ >> m;
        jobs_.resize(m);
        assigned_workers_.resize(m);
        start_times_.resize(m);
        for (int i = 0; i < m; ++i)
            cin >> jobs_[i];
    }

    void AssignJobs()
    {
        priority_queue<Worker> q;
        for (int i = 0; i < num_workers_; i++)
            q.push(Worker(i));
        for (int i = 0; i < jobs_.size(); i++)
        {
            Worker current = q.top();
            q.pop();
            assigned_workers_[i] = current.id;
            start_times_[i] = current.release_time;
            current.release_time += jobs_[i];
            q.push(current);
        }
    }

public:
    void Solve()
    {
        ReadData();
        AssignJobs();
        WriteResponse();
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    JobQueue job_queue;
    job_queue.Solve();
    return 0;
}
