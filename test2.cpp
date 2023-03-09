#include <iostream>
#include <vector>

using namespace std;

int compute(vector<int>& v, int root) {
    if (root == -1) return 0;
    int ret = 1, match = 1;
    int l = v.size();
    int start = root - 1, end = root + 1;
    // cout << "init start:" << start << "; end: " << end << "; count: " << ret << "; match: " << match << endl;

    int nexti;
    while (start >= 0 && end < l) {
        // cout << "start:" << start << "; end: " << end << "; count: " << ret << "; match: " << match << endl;
        match++;
        if (v[start] > v[end]) {
            nexti = v[end];
            while (end <= l - 2 && v[end + 1] < nexti) {
                match++;
                end++;
            }
            if (match == nexti) ret++;
            end++;
        } else {
            nexti = v[start];
            while (start >= 1 && v[start - 1] < nexti) {
                match++;
                start--;
            }
            if (match == nexti) ret++;
            start--;
        }
    }

    while (end < l) {
        // cout << "### start:" << start << "; end: " << end << "; count: " << ret << "; match: " << match << endl;
        nexti = v[end];
        match++;
        while (end <= l - 2 && v[end + 1] < nexti) {
            match++;
            end++;
        }
        // cout << "!!! match: " << match << "; nexti:" << nexti << endl;
        if (match == nexti) ret++;
        end++;
    }

    while (start >= 0) {
        // cout << "*** start:" << start << "; end: " << end << "; count: " << ret << "; match: " << match << endl;
        nexti = v[start];
        match++;
        while (start >= 1 && v[start] < nexti) {
            match++;
            start--;
        }
        if (match == nexti) ret++;
        start--;
    }
    return ret;
}


int main() {
    int t;
    // t = 1;
    // cout << "t: " << endl;
    cin >> t;
    vector<int> res(t);
    int curr = 0;
    while (curr < t) {
        int n;
        // cout << "n: " << endl;
        cin >> n;
        vector<int> data(n);
        // vector<int> data{2,1,5,3,4};
        int root = -1;
        // root = 1;
        for (int i = 0; i < n; i++) {
            int d;
            // cout << "data[" << i << "]: " << endl;
            cin >> d;
            data[i] = d;
            if (d == 1) root = i;
        }
        res[curr++] = compute(data, root);
        // res[curr] = compute(data, root);
        // cout << res[curr++] << endl;
    }

    cout << "results: " << endl;
    for (int i = 0; i < t; i++)
        cout << res[i] << endl;
    return 0;
}
