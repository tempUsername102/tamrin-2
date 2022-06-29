#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

pair<vector<string>, vector<int>> read_input(vector<string> ar, vector<int> inp,int n) {
    string a;
    int b;

    for (int i = 0; i < n; ++i) {
        cin >> a;
        ar.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        cin >> b;
        inp.push_back(b);
    }

    return {ar, inp};
}

pair<vector<int>, bool> process(vector<string> ar, vector<int> inp, int n, int m) {
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (ar[i][j] != '-') {
                if (ar[i][j] < 'a' || ar[i][j] > 'z') {
                    cout << "Invalid Network\n";
                    return {inp, false};
                }
                else {
                    int cnt = 1;
                    for (int k = i + 1; k < n; k++) {
                        if (ar[i][j] == ar[k][j]) {
                            cnt++;
                            if (inp[i] > inp[k]) {
                                char temp = inp[i];
                                inp[i] = inp[k];
                                inp[k] = temp;
                            }
                        }
                    }
                    if (cnt != 2) {
                        cout << "Invalid Network\n";
                        return {inp, false};
                    }
                }
            }
        }
    }
    return {inp, true};
}

void generate_output(vector<int> inp, int n) {
    bool srtd = true;
    for (int i = 0; i < n - 1; i++){
        if (inp[i] > inp[i+1]) {
            cout << "Not sorted\n";
            srtd = false;
            break;
        }
    }
    if (srtd) {
        cout << "Sorted\n";
    }
}

int main() {
    int n,
        m;
    vector<string> ar;
    vector<int> inp;
    bool ok;
   
    cin >> n >> m;
    
    tie(ar, inp) = read_input(ar, inp, n);

    tie(inp, ok) = process(ar, inp, n, m);
    
    if (ok) {
        generate_output(inp, n);
    }

    return 0;
}