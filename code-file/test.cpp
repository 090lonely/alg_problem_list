// //this file is only for test,you know sometimes i might get mycode wrong.
// #include<bits/stdc++.h>
// using namespace std;
// void print(int a[]){
//     for(int i=0;i<3;i++)cout<<a[i]<<endl;
// }
// int main(){
//     int a[3]={1,2,3};
//     print(a);
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

const int N = 155;
struct Sensor {
    double L, R, T;
};

Sensor sensors[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        double D;
        cin >> n >> D;

        for (int i = 0; i < n; ++i) {
            cin >> sensors[i].L >> sensors[i].R >> sensors[i].T;
        }

        // Sort sensors by starting point L
        sort(sensors, sensors + n, [](const Sensor &a, const Sensor &b) {
            return a.L < b.L;
        });

        vector<double> points;  // Change points
        vector<double> speeds;  // Speeds at change points

        double currentPosition = 0.0;
        for (int i = 0; i < n; ++i) {
            if (currentPosition < sensors[i].L) {
                // There's a gap before this sensor's range, set speed to cover this gap
                points.push_back(sensors[i].L);
                speeds.push_back((sensors[i].L - currentPosition) / (sensors[i].L - currentPosition)); // speed to move to the sensor's range
                currentPosition = sensors[i].L;
            }

            // Calculate the required speed for this sensor
            double requiredSpeed = (sensors[i].R - sensors[i].L) / sensors[i].T;
            points.push_back(sensors[i].R);
            speeds.push_back(requiredSpeed);
            currentPosition = sensors[i].R;
        }

        // Check if there's a gap between the last sensor and the end point
        if (currentPosition < D) {
            points.push_back(D);
            speeds.push_back((D - currentPosition) / (D - currentPosition));
        }

        // Output the results
        int m = points.size();
        cout << m << endl;
        for (double point : points) {
            cout << fixed << setprecision(7) << point << " ";
        }
        cout << endl;
        for (double speed : speeds) {
            cout << fixed << setprecision(7) << speed << " ";
        }
        cout << endl;
    }
    return 0;
}
