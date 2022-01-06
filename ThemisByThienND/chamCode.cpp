// #include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

#define numNum 2

class chamCode{
private:
    string task;
    int numTest, point = 0;
    vector<bool> ok;

    // convert integer to string
    // exemple: 1 -> "01", 2 -> "02"
    string getNum(int n){
        string res = to_string(n);
        while(res.size() < numNum) res = "0" + res;

        // optimal
        res += '/';
        return res;
    }

    void getInfo(){
        cout << "\n-------------------------------------\n";
        cout << "-------------Test's info------------\n";
        cout << "Task's name: ";
        cin >> task;
        cout << "Num tests: ";
        cin >> numTest;
    }

    void submitTestInRange(int lf, int rt){
        point = 0;
        for(int i = lf; i <= rt; i ++){
            system(("cp Test/" + task + "/test" + getNum(i) + task + ".inp " + task + ".inp").c_str());
            system(("./" + task).c_str());
            if(system(("diff -Z Test/" + task + "/test" + getNum(i) + task + ".out " + task + ".out").c_str())){
                ok[i] = 0;
            }
            else {
                ok[i] = 1;
                point ++;
            }
        }

        // print

        cout << "\n-----------------------------------------\n";
        cout << "Point: " << point << " / " << rt - lf + 1 << "\n";
        for(int i = lf; i <= rt; i ++){
            cout << "Test" << getNum(i) << ": " << (ok[i] ? "Accept!": "Wrong Answer!") << "\n";
        }
        cout << "\n-----------------------------------------\n";
    }

    bool submitTest(int id){
        system(("cp Test/" + task + "/test" + getNum(id) + task + ".inp " + task + ".inp").c_str());
        system(("./" + task).c_str());
        if(system(("diff -Z Test/" + task + "/test" + getNum(id) + task + ".out " + task + ".out").c_str())){
            return 0;
        }
        else {
            ok[id] = 1;
            return 1;
        }
        return 0;
    }

public:
    chamCode(){
        getInfo();
        ok.resize(numTest + 1);

        // debug
        // task = "demo";
        // numTest = 3;

        // copy code to main
        system(("cp Code/" + task + ".cpp " + task + ".cpp").c_str());
        system(("g++ " + task + ".cpp -o " + task).c_str());

        cout << "Chose your operators: \n";
        cout << "1. Submit all test.\n";
        cout << "2. Submit a test.\n";
        cout << "3. Submit tests in range.\n";
        cout << "4. Exit.\n";
        cout << "\n-----------------------------------------\n";

        while(1){
            int t, x;
            cout << "Nhap: ";
            cin >> t;
            if(t == 1){
                submitTestInRange(1, numTest);
            }
            else if(t == 2){
                cout << "Test's ID: ";
                cin >> x;
                if(submitTest(x)) cout << "Test " << x << ": Accept! \n";
                else cout << "Test " << x << ": Wrong Answer! \n";
            }
            else if(t == 3){
                int lf, rt;
                cout << "Test range [left, right]. (1 <= Left <= Right <= Numtest) \n";
                cout << "Left: ";
                cin >> lf;
                cout << "Right: ";
                cin >> rt;
                submitTestInRange(lf, rt);
            }
            else break;
            cout << "\n-----------------------------------------\n";
        }

    }

    ~chamCode(){
        // distroy 
        cout << "Killed !\n";

        system(("rm " + task + ".cpp").c_str());
        system(("rm " + task + ".inp").c_str());
        system(("rm " + task + ".out").c_str());
        system(("rm " + task ).c_str());
    }

};

int main(){
    chamCode oj;
    return 0;
}
